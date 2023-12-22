#!/usr/bin/env python3
import math
import copy

file = open("test", "r")
#file = open("input", "r")

def bs(arr, x):
    l = 0
    r = len(arr) - 1
    while l < r:
        mid = math.ceil((r + l) / 2)
        if arr[mid] > x:
            r = mid - 1
        else:
            l = mid
    return l

def move(grid, m):
    if m == "u":
        for i in range(len(grid)):
            for j in range(len(grid[0])):
                if grid[i][j] == "O":
                    x = i
                    while x > 0:
                        if grid[x - 1][j] != ".":
                            break
                        grid[x - 1][j] = "O"
                        grid[x][j] = "."
                        x -= 1
    elif m == "l":
        for j in range(len(grid[0])):
            for i in range(len(grid)):
                if grid[i][j] == "O":
                    x = j
                    while x > 0:
                        if grid[i][x - 1] != ".":
                            break
                        grid[i][x - 1] = "O"
                        grid[i][x] = "."
                        x -= 1
    elif m == "r":
        for j in range(len(grid[0]) - 1, -1, -1):
            for i in range(len(grid)):
                if grid[i][j] == "O":
                    x = j
                    while x < len(grid[0]) - 1:
                        if grid[i][x + 1] != ".":
                            break
                        grid[i][x + 1] = "O"
                        grid[i][x] = "."
                        x += 1
    else:
        for i in range(len(grid) - 1, -1, -1):
            for j in range(len(grid[0])):
                if grid[i][j] == "O":
                    x = i
                    while x < len(grid) - 1:
                        if grid[x + 1][j] != ".":
                            break
                        grid[x + 1][j] = "O"
                        grid[x][j] = "."
                        x += 1

    return grid
grid = [[c for c in l.strip()] for l in file]

moves = ["u", "l", "d", "r"]
start = 0
finish = 0
pyt = "\n".join(["".join(sg) for sg in grid])
check = dict()
check[pyt] = 0
cycles = 1000000000
i = 0
while i < cycles:
    for m in moves:
        grid = move(grid, m)
    i += 1
    pyt = "\n".join(["".join(sg) for sg in grid])
    if pyt in check.keys():
        start = check[pyt]
        finish = i
        len_c = finish - start
        for gridx, idx in check.items():
            if idx >= start and start % len_c == cycles % len_c:
                grid = gridx
                break
        break
    else:
        pyt = "\n".join(["".join(sg) for sg in grid])
        check[pyt] = i

positions = []
for i in range(len(grid[0])):
    column = [0]
    for j in range(len(grid)):
        if grid[j][i] == "#":
            column.append(j + 1)
    positions.append(column)

suma = 0
for i in range(len(grid[0])):
    for j in range(len(grid)):
        if grid[j][i] == "O":
            pos = bs(positions[i], j + 1)
            suma += (len(grid) - positions[i][pos])
            positions[i].insert(pos + 1, positions[i][pos] + 1)
print(suma)
