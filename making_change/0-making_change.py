#!/usr/bin/python3
"""
Make change
"""


def makeChange(coins, total):
    """
    determine the fewest number of coins
    needed to meet a given amount total
    """

    if total <= 0:
        return 0
    
    coin_pile = [float('inf')] * (total + 1)
    coin_pile[0] = 0

    for coin in coins:
        for i in range(coin, total + 1):
            coin_pile[i] = min(coin_pile[i], coin_pile[i - coin] + 1)

    return coin_pile[total] if coin_pile[total] != float('inf') else -1
