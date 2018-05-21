Conway's game of life cellular automation for C++ practice!

Probably the most well known cellular automaton, Conway's Game of life works like this:

On each iteration, have each cell check how many of it's neighbours are alive (white).

If a living cell has fewer than two, or more than three living neighbours, it dies. This simulates under/overpopulation.

If a dead cell has three living neighbours, it turns back on. This simulated reproduction.

I've also made the world wrap vertically and horizontally, I think it looks more interesting this way.

With just these few rules you get some amazing behaviour!
