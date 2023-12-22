#!/usr/bin/env python3
import math

#file = open("test", "r")
file = open("input", "r")

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

grid = [l.strip() for l in file]

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
