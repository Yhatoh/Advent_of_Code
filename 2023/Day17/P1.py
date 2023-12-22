#!/usr/bin/env python3

import queue

class PriorityQueue:
    def __init__(self):
        self.queue = queue.PriorityQueue()

    def push(self, item, priority):
        self.queue.put((priority, item))

    def pop(self):
        if not self.is_empty():
            return self.queue.get()
        else:
            raise IndexError("Queue is empty")

    def is_empty(self):
        return self.queue.empty()

    def size(self):
        return self.queue.qsize()

def left_dire(dire):
    if dire[0] == 1:
        return (0, 1)
    if dire[1] == 1:
        return (-1, 0)
    if dire[0] == -1:
        return (0, -1)
    if dire[1] == -1:
        return (1, 0)

def right_dire(dire):
    if dire[0] == 1:
        return (0, -1)
    if dire[1] == 1:
        return (1, 0)
    if dire[0] == -1:
        return (0, 1)
    if dire[1] == -1:
        return (-1, 0)

def valid_coord(x, y, grid):
    return x >= 0 and x < len(grid) and y >= 0 and y < len(grid[0])
file = open("test", "r")
#file = open("input", "r")

grid = [[int(c) for c in l.strip()] for l in file]

dists = [[1000000000000 for _ in range(len(grid[0]))] for _ in range(len(grid))]
dists[0][0] = grid[0][0]
pq = PriorityQueue()
pq.push((0, 0, (1, 0), 1), dists[0][0])
pq.push((0, 0, (0, 1), 1), dists[0][0])
while not pq.is_empty():
    d, c = pq.pop()
    x, y, dire, cont = c
    if d > dists[x][y]:
        continue
    if cont != 3:
        vx, vy = (x + dire[0], y + dire[1])
        if valid_coord(vx, vy, grid):
            if dists[vx][vy] > dists[x][y] + grid[vx][vy]:
                dists[vx][vy] = dists[x][y] + grid[vx][vy]
                pq.push((vx, vy, dire, cont + 1), dists[vx][vy])

    left = left_dire(dire)
    lvx, lvy = (x + left[0], y + left[1])
    if valid_coord(lvx, lvy, grid):
        if dists[lvx][lvy] > dists[x][y] + grid[lvx][lvy]:
            dists[lvx][lvy] = dists[x][y] + grid[lvx][lvy]
            pq.push((lvx, lvy, left, 1), dists[lvx][lvy])

    right = right_dire(dire)
    rvx, rvy = (x + right[0], y + right[1])
    if valid_coord(rvx, rvy, grid):
        if dists[rvx][rvy] > dists[x][y] + grid[rvx][rvy]:
            dists[rvx][rvy] = dists[x][y] + grid[rvx][rvy]
            pq.push((rvx, rvy, right, 1), dists[rvx][rvy])

print(dists[-1][-1])
