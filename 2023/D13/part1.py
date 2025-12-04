#!/usr/bin/env python3

#file = open("test", "r")
file = open("input", "r")

def check_horizontal(grid):
    for x in range(len(grid) - 1):
        flag = True
        i = x
        j = i + 1
        n = len(grid)
        m = len(grid[0])
        while i >= 0 and j < n:
            row_1 = grid[i]
            row_2 = grid[j]
            for k in range(m):
                if row_1[k] != row_2[k]:
                    flag = False
            i -= 1
            j += 1
        if flag:
            return x + 1
    return -1

def check_vertical(grid):
    for x in range(len(grid[0]) - 1):
        flag = True
        i = x
        j = i + 1
        n = len(grid)
        m = len(grid[0])
        while i >= 0 and j < m:
            for k in range(n):
                if grid[k][i] != grid[k][j]:
                    flag = False
            i -= 1
            j += 1
        if flag:
            return x + 1
    return -1


grid = [l.strip() for l in file]

patterns = []
pattern = []
for row in grid:
    if row == "":
        patterns.append(pattern)
        pattern = []
    else:
        pattern.append(row)

patterns.append(pattern)
suma = 0
for pattern in patterns:
    hor = check_horizontal(pattern)
    ver = check_vertical(pattern)
    if hor != -1:
        suma += hor * 100
    if ver != -1:
        suma += ver
print(suma)
