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

def dfs(matrix, i, j, pi, pj, oi, oj):
    global vis
    vis[i][j] = 1
    for ni, nj in matrix[i][j]:
        if vis[ni][nj] == 0:
            ret = dfs(matrix, ni, nj, i, j, oi, oj)
            ret.append([i, j])
            return ret
        elif pi != oi and pj != oj and ni == oi and nj == oj:
            return [[oi,oj],[i, j]]
    return [-1]

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
        f_i = dfs(matrix, ns_i, ns_j, s_i, s_j, s_i, s_j)
        if f_i[0] != -1:
            f_i.append([s_i, s_j])
            save = f_i
            break

area = 0
for i in range(len(save) - 1):
    area += (save[i][1] + save[i + 1][1]) * (save[i][0] - save[i + 1][0])
area = area // 2
print(area - (len(save) // 2) + 1)
