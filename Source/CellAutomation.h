#pragma once
#include "Config.h"
#include "board.h"
#include <chrono>

enum class Cell : uint8_t
{
	Dead,
	Alive
};

struct Timer
{
	const char* m_szOperation;
	std::chrono::time_point<std::chrono::steady_clock> m_tstart, m_tend;
	std::chrono::duration<float> duration;

	Timer(const char* job) : m_szOperation(job)
	{
		m_tstart = std::chrono::high_resolution_clock::now();
	}

	~Timer()
	{
		m_tend = std::chrono::high_resolution_clock::now();
		duration = m_tend - m_tstart;

		float ms = duration.count() * 1000.0f;
		printf("Timer took %dms to perform %c\n", ms, m_szOperation);
	}
	
};

class CellAutomation
{
public:
	CellAutomation(const Config& c);
	void Run();

private:
	const Config m_Config;
	std::vector<Cell> m_CellsVec;
	Board m_Board;
	sf::RenderWindow m_Window;

	const sf::Color GetCellColor(const Cell& c) const;
	Cell CellAutomation::GetCell(const unsigned& x, const unsigned& y) const;
	unsigned GetCellIndex(const unsigned& x,const unsigned& y) const;
	void UpdateWorld();

	template<typename F>
	void CellForEach(F f);
	
};

//Template to pass lambdas to for shorthand looping through the grid
template<typename F>
void CellAutomation::CellForEach(F f)
{
	for (unsigned y = 0; y < m_Config.uSimHeight; y++)
	{
		for (unsigned x = 0; x < m_Config.uSimWidth; x++)
		{
			f(x, y);
		}
	}
}
