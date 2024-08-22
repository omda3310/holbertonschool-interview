#!/usr/bin/python3
"""
Module: 0-island_perimeter
Contains the function that calculates the perimeter
of an island in a grid.
"""


def island_perimeter(grid):
    """
    Calculate the perimeter of an island described in a grid.
    """
    perimeter = 0
    rows = len(grid)
    cols = len(grid[0]) if rows > 0 else 0

    for i in range(rows):
        for j in range(cols):
            if grid[i][j] == 1:
                perimeter += 4

                if i > 0 and grid[i - 1][j] == 1:
                    perimeter -= 2

                if j > 0 and grid[i][j - 1] == 1:
                    perimeter -= 2

    return perimeter
