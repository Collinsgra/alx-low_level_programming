#!/usr/bin/python3
"""Island Grid"""



def num_water_neighbors(grid, k, m):
    """number of water"""

    sum = 0

    if k <= 0 or not grid[k - 1][m]:
        sum += 1
    if m <= 0 or not grid[k][m - 1]:
        sum += 1
    if m >= len(grid[k]) - 1 or not grid[k][j + 1]:
        sum += 1
    if k >= len(grid) - 1 or not grid[k + 1][m]:
        sum += 1

    return sum


def island_perimeter(grid):
    """perimetre grid"""

    _perim = 0
    for k in range(len(grid)):
        for m in range(len(grid[k])):
            if grid[k][m]:
                _perim += num_water_neighbors(grid, k, m)

    return _perim
