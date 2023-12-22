#file = open("test.txt", "r")
file = open("input.txxt", "r")

lines = [l.strip() for l in file if l != "\n"]
moves = lines[0]

dicc = dict()
lines = lines[1:]
for line in lines:
    node, neighbors = line.split(" = ")
    n1, n2 = neighbors[1:len(neighbors) - 1].split(", ")
    dicc[node] = [n1, n2]

node = "AAA"
ans = 0
move = 0
while 1:
    if node == "ZZZ":
        break
    node = dicc[node][0] if moves[move] == 'L' else dicc[node][1]
    move = (move + 1) % len(moves)
    ans += 1
print(ans)
