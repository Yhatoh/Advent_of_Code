#!/usr/bin/env python3

#!/usr/bin/env python3

def bfs(grid, x, y, d):
    vis = [[0 for _ in range(len(grid[0]))] for _ in range(len(grid))]
    queue = []
    if d == "r":
        if grid[x][y] == "\\":
            d = "d"
        elif grid[x][y] == "/":
            d = "u"
        elif grid[x][y] == "|":
            queue.append((x,y, "u"))
            d = "d"
    elif d == "d":
        if grid[x][y] == "\\":
            d = "r"
        elif grid[x][y] == "/":
            d = "l"
        elif grid[x][y] == "-":
            queue.append((x,y, "l"))
            d = "r"
    elif d == "l":
        if grid[x][y] == "\\":
            d = "u"
        elif grid[x][y] == "/":
            d = "d"
        elif grid[x][y] == "|":
            queue.append((x,y, "u"))
            d = "d"
    elif d == "u":
        if grid[x][y] == "\\":
            d = "l"
        elif grid[x][y] == "/":
            d = "r"
        elif grid[x][y] == "-":
            queue.append((x,y, "l"))
            d = "r"
    queue.append((x, y, d))
    vis[x][y] = 1

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
    return sum([sum([x > 0 for x in sub]) for sub in vis])
#file = open("test", "r")
file = open("input", "r")

grid = [l.strip() for l in file]

maxi = 0
for i in range(len(grid)):
    ret = bfs(grid, i, 0, "r")
    maxi = max(ret, maxi)
    ret = bfs(grid, 0, i, "d")
    maxi = max(ret, maxi)
    ret = bfs(grid, i, len(grid[0]) - 1, "l")
    maxi = max(ret, maxi)
    ret = bfs(grid, len(grid) - 1, i, "u")
    maxi = max(ret, maxi)
print(maxi)
