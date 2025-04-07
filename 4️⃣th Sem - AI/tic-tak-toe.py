import math


def show(b):
    [print("|".join(r)) or print("-" * 5) for r in b]


def win(b):
    lines = (
        b
        + [list(c) for c in zip(*b)]
        + [[b[i][i] for i in range(3)], [b[i][2 - i] for i in range(3)]]
    )
    for l in lines:
        if l[0] != " " and l.count(l[0]) == 3:
            return l[0]
    return "Draw" if all(c != " " for r in b for c in r) else None


def mini(b, ai):
    r = win(b)
    if r:
        return {"X": -1, "O": 1, "Draw": 0}[r]
    scores = []
    for i in range(3):
        for j in range(3):
            if b[i][j] == " ":
                b[i][j] = "O" if ai else "X"
                scores.append(mini(b, not ai))
                b[i][j] = " "
    return max(scores) if ai else min(scores)


def best(b):
    m, s = None, -math.inf
    for i in range(3):
        for j in range(3):
            if b[i][j] == " ":
                b[i][j] = "O"
                val = mini(b, False)
                b[i][j] = " "
                if val > s:
                    m, s = (i, j), val
    return m


def play():
    b = [[" "] * 3 for _ in range(3)]
    print("You → X & AI → O")
    while True:
        show(b)
        try:
            x, y = map(int, input("Move (row col): ").split())
            if b[x][y] != " ":
                continue
            b[x][y] = "X"
        except:
            continue
        if r := win(b):
            show(b)
            print("Draw!" if r == "Draw" else f"{r} wins!")
            break
        i, j = best(b)
        b[i][j] = "O"
        if r := win(b):
            show(b)
            print("Draw!" if r == "Draw" else f"{r} wins!")
            break


play()
