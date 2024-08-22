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
    value = 0
    rows = len(grid)
    cols = len(grid[0])

    def is_water(x, y):
        return x < 0 or y < 0 or x >= rows or y >= cols or grid[x][y] == 0

    for column in range(rows):
        for row in range(cols):
            if grid[column][row] == 1:
                value += is_water(column - 1, row)
                value += is_water(column + 1, row)
                value += is_water(column, row + 1)
                value += is_water(column, row - 1)

    return value
