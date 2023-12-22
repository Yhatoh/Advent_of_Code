#!/usr/bin/env python3

file = open("test", "r")
#file = open("input", "r")

def hash(w):
    res = 0
    for c in w:
        res += ord(c)
        res *= 17
        res %= 256
    return res

words = [l.strip().split(",") for l in file][0]

hop = []
for word in words:
    if word[-1] == "-":
        hop.append((hash(word[:len(word) - 1]), word[-1], word[:len(word) - 1]))
    else:
        hop.append((hash(word[:len(word) - 2]), word[-2] + word[-1], word[:len(word) - 2]))
boxes = [[] for _ in range(256)]
dicc = dict()
for w_hash, op, label in hop:
    if op[0] == "-":
        if label in boxes[w_hash]:
           boxes[w_hash].remove(label)
           del dicc[label]
    else:
        if label in boxes[w_hash]:
            dicc[label] = int(op[1])
        else:
            boxes[w_hash].append(label)
            dicc[label] = int(op[1])

print(sum([sum([(i + 1) * (j + 1) * dicc[boxes[i][j]] for j in range(len(boxes[i]))]) for i in range(256)]))
