#include "Board.h"

Board::Board(const Config& c) : m_Config(c), v_PixelsVec(m_Config.uSimWidth * m_Config.uSimHeight) {}

//Each cell is 4 vertices read in as a quad. All these vertices are stored in v_pixels
//Done this way as it should be less intense than iterating through a 2d grid
void Board::AddQuad(const unsigned& x, const unsigned& y, const sf::Color& colour)
{
	sf::Vertex topLeft;
	sf::Vertex topRight;
	sf::Vertex bottomLeft;
	sf::Vertex bottomRight;

	float pixelX = x * m_Config.uQuadSize;
	float pixelY = y * m_Config.uQuadSize;

	topLeft.position = { pixelX, pixelY };
	topRight.position = { pixelX + m_Config.uQuadSize, pixelY };
	bottomLeft.position = { pixelX, pixelY + m_Config.uQuadSize };
	bottomRight.position = { pixelX + m_Config.uQuadSize, pixelY + m_Config.uQuadSize };

	topLeft.color = colour;
	topRight.color = colour;
	bottomLeft.color = colour;
	bottomRight.color = colour;

	v_PixelsVec.push_back(topLeft);
	v_PixelsVec.push_back(bottomLeft);
	v_PixelsVec.push_back(bottomRight);
	v_PixelsVec.push_back(topRight);
}

unsigned Board::GetQuadIndex(const unsigned& x, const unsigned& y) const
{
	return (y * m_Config.uSimWidth + x) * 4;
}

void Board::ChangeQuadColour(const unsigned& x, const unsigned& y, const sf::Color& colour)
{
	unsigned quadIndex = GetQuadIndex(x, y);

	v_PixelsVec[quadIndex].color = colour;
	v_PixelsVec[quadIndex + 1].color = colour;
	v_PixelsVec[quadIndex + 2].color = colour;
	v_PixelsVec[quadIndex + 3].color = colour;

}