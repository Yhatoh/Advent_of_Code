#file = open("test", "r")
file = open("input", "r")

dicc = {'|': [[1, 0], [-1, 0]],
        '-': [[0, 1], [0, -1]],
        'L': [[-1, 0], [0, 1]],
        'J': [[-1, 0], [0, -1]],
        '7': [[1, 0], [0, -1]],
        'F': [[1, 0], [0, 1]]}
dicc_rev = dict()
for key, value in dicc.items():
    dicc_rev[str(value)] = key

def create(n, m):
    ret = []
    for i in range(n):
        row = []
        for j in range(m):
            row.append([])
        ret.append(row)
    return ret

vis = []

grid = [l.strip() for l in file]
n = len(grid)
m = len(grid[0])
matrix = create(n, m)

import sys
sys.setrecursionlimit(500000)
for i in range(n):
    row = []
    for j in range(m):
        row.append(0)
    vis.append(row)

def dfs(matrix, i, j, oi, oj):
    global vis
    vis[i][j] = 1
    for ni, nj in matrix[i][j]:
        if vis[ni][nj] == 0:
            return dfs(matrix, ni, nj, oi, oj)
        elif ni == oi and nj == oj:
            return [i, j]
    return [-1, -1]


s_i = 0
s_j = 0
for i in range(n):
    for j in range(m):
        if grid[i][j] != '.' and grid[i][j] != 'S':
            for x, y in dicc[grid[i][j]]:
                nx = i + x
                ny = j + y
                if nx >= 0 and nx < n and ny >= 0 and ny < m:
                    matrix[i][j].append([nx, ny])
        elif grid[i][j] == 'S':
            s_i, s_j = [i, j]
moves = [[1, 0], [-1, 0], [0, 1], [0, -1]]
save = []
for x, y in moves:
    vis = []
    for i in range(n):
        row = []
        for j in range(m):
            row.append(0)
        vis.append(row)
    vis[s_i][s_j] = 1
    ns_i, ns_j = [s_i + x, s_j + y]
    if ns_i >= 0 and ns_i < n and ns_j >= 0 and ns_j < m:
        f_i, f_j = dfs(matrix, ns_i, ns_j, s_i, s_j)
        if f_i != -1:
            save = [[ns_i, ns_j], [f_i, f_j]]
            break

vis = []
for i in range(n):
    row = []
    for j in range(m):
        row.append(1000000000000)
    vis.append(row)

vis[s_i][s_j] = 0
vis[save[0][0]][save[0][1]] = 1
vis[save[1][0]][save[1][1]] = 1
queue = [save[0], save[1]]
while queue != []:
    next_i, next_j = queue[0]
    queue = queue[1:]
    for vi, vj in matrix[next_i][next_j]:
        if vis[vi][vj] > vis[next_i][next_j] + 1:
            vis[vi][vj] = vis[next_i][next_j] + 1
            queue.append([vi, vj])
maxi = 0
for i in range(n):
    for j in range(m):
        if vis[i][j] != 1000000000000:
            maxi = max(maxi, vis[i][j])
print(maxi)
