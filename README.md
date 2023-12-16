# 15 Puzzle Game
Note: This project is Windows OS specific

This is a console-based 15 Puzzle Game implemented in C. The game provides a shuffled grid of numbers, and the player needs to rearrange them in ascending order using arrow keys.

## Table of Contents
- [Introduction](#introduction)
- [How to Play](#how-to-play)
- [Features](#features)
- [Controls](#controls)
- [Compilation](#compilation)
- [Acknowledgments](#acknowledgments)

## Introduction<a name="introduction"></a>

Welcome to the 15 Puzzle Game! This simple console game challenges players to solve a shuffled puzzle by moving numbered tiles using arrow keys. The objective is to arrange the tiles in ascending order.

## How to Play<a name="how-to-play"></a>

To play the game, follow these steps:

1. Run the program.
2. Use arrow keys (UP, DOWN, LEFT, RIGHT) to move the empty space and rearrange the tiles.
3. Try to organize the numbers in ascending order.
4. Press the Escape key to quit the game at any time.

## Features<a name="features"></a>

- Shuffled puzzle for each new game
- Arrow key controls for moving tiles
- Quit option with the Escape key
- Moves counter
- Saving scores with player names
- Option to view saved scores

## Controls<a name="controls"></a>

- Use **UP** arrow key to move the empty space UP.
- Use **DOWN** arrow key to move the empty space DOWN.
- Use **LEFT** arrow key to move the empty space LEFT.
- Use **RIGHT** arrow key to move the empty space RIGHT.
- Press **Escape** to quit the game.

## Compilation<a name="compilation"></a>
Make sure you have C compiler installed.
To compile the code, use the following commands:

```bash
gcc 15_Puzzle.c -o 15_puzzle
./15_puzzle
