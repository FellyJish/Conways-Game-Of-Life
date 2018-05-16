#include "CellAutomation.h"
#include <random>


CellAutomation::CellAutomation(const Config& c) : m_Config(c), m_Board(m_Config), m_Window(sf::VideoMode(m_Config.uScreenWidth, m_Config.uScreenHeight), "Conways Game of Life"), m_CellsVec(m_Config.uSimHeight * m_Config.uSimWidth)
{

	std::mt19937 rng(std::time(nullptr));
	CellForEach([&](unsigned x, unsigned y)
	{			
		std::uniform_int_distribution<int> dist(0, 1);
		Cell& cell = m_CellsVec[GetCellIndex(x, y)];
		cell = (Cell)dist(rng);
		m_Board.AddQuad(x, y, GetCellColor(cell));
	});
}

const sf::Color CellAutomation::GetCellColor(const Cell& c) const
{
	switch (c)
	{
	case Cell::Alive:
		return sf::Color::White;
		break;

	case Cell::Dead:
		return sf::Color::Black;
		break;
	}
}

Cell CellAutomation::GetCell(const unsigned& x, const unsigned& y) const
{
	unsigned index = (x * m_Config.uSimWidth) + y;
	return m_CellsVec[index];
}

void CellAutomation::Run()
{
	m_Window.setFramerateLimit(m_Config.uFrameRate);
	while (m_Window.isOpen())
	{
		m_Window.clear();
		sf::Event event;
		while (m_Window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				m_Window.close();
		}
		UpdateWorld();
		m_Window.draw(m_Board.v_PixelsVec.data(), m_Board.v_PixelsVec.size(), sf::Quads);
		m_Window.display();		
	}
}

unsigned CellAutomation::GetCellIndex(const unsigned& x, const unsigned& y) const
{
	return (y * m_Config.uSimWidth + x);
}

void CellAutomation::UpdateWorld()
{
	std::vector<Cell> newCells(m_Config.uSimWidth * m_Config.uSimHeight);

	//Count all of the live neighbours beside each cell
	CellAutomation::CellForEach([&](unsigned x, unsigned y)
	{
		unsigned uLiveNeighbours = 0;
		for (int neighbourX = -1; neighbourX <= 1; neighbourX++)
		{
			for (int neighbourY = -1; neighbourY <= 1; neighbourY++)
			{
				int newX = neighbourX + x;
				int newY = neighbourY + y;

				if (newX == -1 || newX == m_Config.uSimWidth ||
					newY == -1 || newY == m_Config.uSimHeight ||
					(newX == x && newY == y))
				{
					continue;
				}

				Cell& cell = m_CellsVec[GetCellIndex(newX, newY)];
				if (cell == Cell::Alive)
					uLiveNeighbours++;
			}
		}

		//Don't change the cell itself!
		Cell& cell = m_CellsVec[GetCellIndex(x, y)];
		Cell& updateCell = newCells[GetCellIndex(x, y)];
		updateCell = cell;

		//Enact game of life rules
		switch (cell)
		{
		case Cell::Alive:
			if (uLiveNeighbours < 2 || uLiveNeighbours > 3)
			{
				updateCell = Cell::Dead;
			}
			break;

		case Cell::Dead:
			if (uLiveNeighbours == 3)
			{
				updateCell = Cell::Alive;
			}
			break;
		}		
		//update board with change
		m_Board.ChangeQuadColour(x, y, GetCellColor(updateCell));
	});

	//Once all cells have been checked, set current cells equal to updated cells
	m_CellsVec = std::move(newCells);	
}