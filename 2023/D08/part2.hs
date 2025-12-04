import math
#file = open("test.txt", "r")
file = open("input.txxt", "r")

def fun(moves, node, dicc):
    move = 0
    ans = 0
    while 1:
        if node[-1] == 'Z':
            return ans
        node = dicc[node][0] if moves[move] == 'L' else dicc[node][1]
        move = (move + 1) % len(moves)
        ans += 1

lines = [l.strip() for l in file if l != "\n"]
moves = lines[0]

dicc = dict()
lines = lines[1:]
nodes_a = []
for line in lines:
    node, neighbors = line.split(" = ")
    if node[-1] == 'A':
        nodes_a.append(node)
    n1, n2 = neighbors[1:len(neighbors) - 1].split(", ")
    dicc[node] = [n1, n2]

print(math.lcm(*[fun(moves, node, dicc) for node in nodes_a]))
