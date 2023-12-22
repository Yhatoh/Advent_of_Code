#file = open("test", "r")
file = open("input", "r")

def rec(nums, l):
    flag = True
    for num in nums:
        if num != 0:
            flag = False
            break
    if flag:
        return 0
    diff = [0] * (l - 1)
    for i in range(l - 1):
        diff[i] = nums[i + 1] - nums[i]
    ret = rec(diff, l - 1)
    return nums[0] - ret

histories = [list(map(int, l.strip().split(" "))) for l in file]
print(sum([rec(history, len(history)) for history in histories]))
