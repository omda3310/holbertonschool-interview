#!/usr/bin/python3
"""
Function to calculate the perimeter of an island
"""


def island_perimeter(grid):
    """
    Calculate the perimeter of an island represented in a grid.

    Args:
        grid (list of list of int): The grid representing the island and water.

    Returns:
        int: The perimeter of the island.
    """
    perim = 0
    rows = len(grid)
    cols = len(grid[0]) if rows > 0 else 0

    for i in range(rows):
        for j in range(cols):
            if grid[i][j] == 1:

                if i == 0 or grid[i - 1][j] == 0:
                    perim += 1

                if i == rows - 1 or grid[i + 1][j] == 0:
                    perim += 1

                if j == 0 or grid[i][j - 1] == 0:
                    perim += 1

                if j == cols - 1 or grid[i][j + 1] == 0:
                    perim += 1

    return perim
