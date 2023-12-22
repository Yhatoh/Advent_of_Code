#file = open("test", "r")
file = open("input", "r")

def match_beginning(data, length):
    return all(x != "." for x in data[:length]) and ((len(data) == length) or data[length] != "#")

memo = dict()
def count(data, blocks):
    total = sum(blocks)
    mini = sum([x == "#" for x in data])
    maxi = sum([x != "." for x in data])
    if str((data, blocks)) in memo.keys():
        return memo[str((data, blocks))]
    if mini > total or maxi < total:
        return 0
    if total == 0:
        return 1
    if data[0] == ".":
        return count(data[1:], blocks)
    if data[0] == "#":
        l = blocks[0]
        if match_beginning(data, l):
            if l == len(data):
                return 1
            return count(data[l + 1:], blocks[1:])
        return 0
    case = ["#"]
    case.extend(data[1:])
    memo[str((data, blocks))] = count(data[1:], blocks) + count(case, blocks)
    return memo[str((data, blocks))]

conditions = [[condition, list(map(int, groups.split(",")))] for condition, groups in [l.strip().split(" ") for l in file]]
print(sum([count(condition, group) for condition, group in conditions]))
