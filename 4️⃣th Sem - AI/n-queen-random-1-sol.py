import random


def is_safe(board, row, col):
    for i in range(row):
        if board[i] == col or abs(board[i] - col) == abs(i - row):
            return False
    return True


def solve_n_queens(n):
    board = [-1] * n
    cols = list(range(n))
    random.shuffle(cols)

    def backtrack(row):
        if row == n:
            return True
        random.shuffle(cols)
        for col in cols:
            if is_safe(board, row, col):
                board[row] = col
                if backtrack(row + 1):
                    return True
                board[row] = -1
        return False

    return board if backtrack(0) else None


def print_board(board):
    if board:
        for row in board:
            print(" ".join("Q" if i == row else "." for i in range(len(board))))
        print()


n = int(input("Enter Queen Count (N): "))
if n < 4:
    print("No solution exists for N < 4")
    exit()
else:
    solution = solve_n_queens(n)
    print_board(solution)
