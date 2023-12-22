#file = open("test.txt", "r")
file = open("input.txt", "r")

high = ['A', 'K', 'Q', 'J', 'T', '9', '8', '7', '6', '5', '4', '3', '2']

def type(card):
    count = dict()
    for x in card:
        if x not in count.keys():
            count[x] = 0
        count[x] += 1

    if len(count.keys()) == 1:
        return 0

    if len(count.keys()) == 2:
        if [v for v in count.values() if v == 4] != []:
            return 1
        else:
            return 2

    if len(count.keys()) == 3:
        if [v for v in count.values() if v == 3] != []:
            return 3
        else:
            return 4

    if [v for v in count.values() if v == 2] != []:
        return 5
    else:
        return 6

def card_to_nums(card):
    return [high.index(c) for c in card]

cards = [[a, int(b)] for a, b in [l.strip().split(" ") for l in file]]

cards = sorted(cards, key=lambda c: (type(c[0]), card_to_nums(c[0])), reverse=True)
ans = 0
for i in range(len(cards)):
    ans += cards[i][1] * (i + 1)
print(ans)
