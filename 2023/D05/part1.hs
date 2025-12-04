file = open("input.txt", "r")
#file = open("test.txt", "r")

lines = []
for line in file:
    lines.append(line.strip())

seeds = list(map(int, lines[0][7:].split(" ")))

groups = []
group = []
for i in range(2, len(lines)):
    if lines[i] == "":
        groups.append([list(map(int, l.split(" "))) for l in group[1:]])
        group = []
    else:
        group.append(lines[i])

if group != []:
    groups.append([list(map(int, l.split(" "))) for l in group[1:]])

mini = -1
for seed in seeds:
    for group in groups:
        found = False
        for d, s, l in group:
            if s <= seed and s + l >= seed:
                found = True
                seed = d + seed - s
                break
    mini = min(seed, mini) if mini != -1 else seed

print(mini)
