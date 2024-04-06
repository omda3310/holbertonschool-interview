#!/usr/bin/python3
"""
N queens puzzle
"""

import sys


if len(sys.argv) != 2:
    print("Usage: nqueens N")
    sys.exit(1)

try:
    N = int(sys.argv[1])
except ValueError:
    print("N must be a number")
    sys.exit(1)

if N < 4:
    print("N must be at least 4")
    sys.exit(1)


def is_safe(board, row, col, N):
    for i in range(col):
        if board[row][i] == 1:
            return False

    for i, j in zip(range(row, -1, -1), range(col, -1, -1)):
        if board[i][j] == 1:
            return False

    for i, j in zip(range(row, N, 1), range(col, -1, -1)):
        if board[i][j] == 1:
            return False
    return True


def solve_nqueens(N):
    board = [[0 for _ in range(N)] for _ in range(N)]
    solutions = []

    def solve_util(col):
        if col == N:
            sol = []
            for i in range(N):
                for j in range(N):
                    if board[i][j] == 1:
                        sol.append([i, j])
            solutions.append(sol)
            return True
        res = False
        for i in range(N):
            if is_safe(board, i, col, N):
                board[i][col] = 1
                res = solve_util(col + 1) or res
                board[i][col] = 0
        return res
    solve_util(0)
    return solutions


solutions = solve_nqueens(N)

for sol in solutions:
    print(sol)
