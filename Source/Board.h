#pragma once
#include <SFML/Graphics.hpp>
#include "Config.h"

class Board
{
public:
	Board(const Config& c);
	std::vector<sf::Vertex> v_PixelsVec;

	void AddQuad(const unsigned& x, const unsigned& y, const sf::Color& color);
	void ChangeQuadColour(const unsigned& x, const unsigned& y, const sf::Color& colour);

private:
	const Config m_Config;
	unsigned GetQuadIndex(const unsigned& x, const unsigned& y) const;
};