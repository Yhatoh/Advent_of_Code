#file = open("test", "r")
file = open("input", "r")

def index_no(grid, row=1):
    ret = []
    if row:
        for i in range(len(grid)):
            flag = True
            for j in range(len(grid[0])):
                if grid[i][j] != '.':
                    flag = False
                    break
            if flag:
                ret.append(i)
    else:
        for j in range(len(grid[0])):
            flag = True
            for i in range(len(grid)):
                if grid[i][j] != '.':
                    flag = False
                    break
            if flag:
                ret.append(j)
    return ret

def bin_search(arr, x):
    l = 0
    r = len(arr)
    while l < r:
        mid = (l + r) // 2
        if arr[mid] < x:
            l = mid + 1
        else:
            r = mid
    return r

grid = [l.strip() for l in file]

index_rows = index_no(grid)
index_cols = index_no(grid, 0)

points = []
for i in range(len(grid)):
    for j in range(len(grid[0])):
        if grid[i][j] == '#':
            points.append([i, j])

suma = 0
for i in range(len(points)):
    for j in range(i + 1, len(points)):
        cx1, cy1 = points[i]
        cx2, cy2 = points[j]
        left_row = bin_search(index_rows, cx1)
        right_row = bin_search(index_rows, cx2)
        left_col = bin_search(index_cols, cy1)
        right_col = bin_search(index_cols, cy2)
        suma += (abs(left_col - right_col) + abs(left_row - right_row) + abs(cx1 - cx2) +
                 abs(cy1 - cy2))
print(suma)
