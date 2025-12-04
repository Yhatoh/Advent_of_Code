import math

#file = open("test.txt", "r")
file = open("input.txt", "r")

def fun(tf, d):
    part = math.sqrt(tf * tf - 4 * d)
    return sorted([(tf + part) / 2, (tf - part) / 2])

lines = [l.strip() for l in file]
times = list(map(int, [ele for ele in lines[0][5:].split(" ") if ele != ""]))
distances = list(map(int, [ele for ele in lines[1][9:].split(" ") if ele != ""]))


eqs = []
for i in range(len(times)):
    ret = fun(times[i], distances[i] + 1)
    eqs.append([math.ceil(ret[0]), math.floor(ret[1])])
print(math.prod([b - a + 1 for a, b in eqs]))
