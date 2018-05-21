Conway's game of life cellular automation for C++ practice!

Probably the most well known cellular automaton, Conway's Game of life works like this:

The world is made up of squares called cells. Cells can either be alive (white) or dead (black).

On each iteration, each cell checks how many of it's neighbours are alive.

If a living cell has fewer than two, or more than three living neighbours, it dies.
If a dead cell has three living neighbours, it turns back on. This simulated reproduction.

I've also made the world wrap vertically and horizontally, I think it looks more interesting this way.

With just these few rules you get some amazing behaviour!
