#!/usr/bin/env python3

# file = open("test", "r")
file = open("input", "r")

grid = [l.strip() for l in file]

vis = [[0 for _ in range(len(grid[0]))] for _ in range(len(grid))]
d = "r"
queue = []
if grid[0][0] == "\\":
    d = "d"
elif grid[0][0] == "/":
    d = "u"
elif grid[0][0] == "|":
    queue.append((0,0, "u"))
    d = "d"
queue.append((0, 0, d))
vis[0][0] = 1

remember = [[[] for _ in range(len(grid[0]))] for _ in range(len(grid))]
while queue:
    x, y, d = queue.pop(0)
    if d in remember[x][y]:
        continue
    remember[x][y].append(d)
    if d == "r":
        if y + 1 < len(grid[0]):
            if grid[x][y + 1] == "/":
                vis[x][y + 1] = 1
                queue.append((x, y + 1, "u"))

            elif grid[x][y + 1] == "\\":
                vis[x][y + 1] = 1
                queue.append((x, y + 1, "d"))

            elif grid[x][y + 1] == "|":
                vis[x][y + 1] = 1
                queue.append((x, y + 1, "u"))
                queue.append((x, y + 1, "d"))

            elif grid[x][y + 1] == "-":
                vis[x][y + 1] = 1
                queue.append((x, y + 1, d))

            else:
                vis[x][y + 1] = 1
                queue.append((x, y + 1, d))
    if d == "l":
        if y - 1 >= 0:
            if grid[x][y - 1] == "/":
                vis[x][y - 1] = 1
                queue.append((x, y - 1, "d"))

            elif grid[x][y - 1] == "\\":
                vis[x][y - 1] = 1
                queue.append((x, y - 1, "u"))

            elif grid[x][y - 1] == "|":
                vis[x][y - 1] = 1
                queue.append((x, y - 1, "u"))
                queue.append((x, y - 1, "d"))

            elif grid[x][y - 1] == "-":
                vis[x][y - 1] = 1
                queue.append((x, y - 1, d))

            else:
                vis[x][y - 1] = 1
                queue.append((x, y - 1, d))

    if d == "u":
        if x - 1 >= 0:
            if grid[x - 1][y] == "/":
                vis[x - 1][y] = 1
                queue.append((x - 1, y, "r"))

            elif grid[x - 1][y] == "\\":
                vis[x - 1][y] = 1
                queue.append((x - 1, y, "l"))

            elif grid[x - 1][y] == "|":
                vis[x - 1][y] = 1
                queue.append((x - 1, y, d))

            elif grid[x - 1][y] == "-":
                vis[x - 1][y] = 1
                queue.append((x - 1, y, "r"))
                queue.append((x - 1, y, "l"))

            else:
                vis[x - 1][y] = 1
                queue.append((x - 1, y, d))

    if d == "d":
        if x + 1 < len(grid):
            if grid[x + 1][y] == "/":
                vis[x + 1][y] = 1
                queue.append((x + 1, y, "l"))

            elif grid[x + 1][y] == "\\":
                vis[x + 1][y] = 1
                queue.append((x + 1, y, "r"))

            elif grid[x + 1][y] == "|":
                vis[x + 1][y] = 1
                queue.append((x + 1, y, d))

            elif grid[x + 1][y] == "-":
                vis[x + 1][y] = 1
                queue.append((x + 1, y, "r"))
                queue.append((x + 1, y, "l"))

            else:
                vis[x + 1][y] = 1
                queue.append((x + 1, y, d))
print("\n".join(["".join(list(map(str, sub))).replace("0",".").replace("1","#") for sub in vis]))
print(sum([sum([x > 0 for x in sub]) for sub in vis]))
