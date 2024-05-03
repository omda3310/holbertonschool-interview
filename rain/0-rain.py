#!/usr/bin/python3
"""
Return number of units of water after it rains
"""


def rain(walls):
    """
    Total amount of rainwater retained.
    """
    if not walls:
        return 0

    n = len(walls)
    left = [0] * n
    right = [0] * n

    left[0] = walls[0]
    for i in range(1, n):
        left[i] = max(left[i-1], walls[i])

    right[n-1] = walls[n-1]
    for i in range(n-2, -1, -1):
        right[i] = max(right[i+1], walls[i])

    total_water = 0
    for i in range(n):
        water_level = min(left[i], right[i])
        total_water += max(0, water_level - walls[i])

    return total_water
