#!/usr/bin/python3
"""
Function to calculate the perimeter of an island
"""


def island_perim(grid):
    """
    Calculate the perimeter of an island represented in a grid.

    Args:
        grid (list of list of int): The grid representing the island and water.

    Returns:
        int: The perimeter of the island.
    """
    if not grid or not grid[0]:
        return 0

    rows, cols = len(grid), len(grid[0])
    perim = 0

    for i in range(rows):
        for j in range(cols):
            if grid[i][j] == 1:
                perim += 4

                if i > 0 and grid[i - 1][j] == 1:
                    perim -= 2
                if j > 0 and grid[i][j - 1] == 1:
                    perim -= 2

    return perim
