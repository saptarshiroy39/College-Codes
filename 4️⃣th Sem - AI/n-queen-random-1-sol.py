import random


def solve_n_queens(N):
    board = [-1] * N

    def backtrack(row):
        if row == N:
            return True

        for col in random.sample(range(N), N):
            if all(board[i] != col and abs(board[i] - col) != row - i for i in range(row)):
                board[row] = col

                if backtrack(row + 1):
                    return True

                board[row] = -1

        return False

    backtrack(0)
    return board


def print_board(board):
    for r in board:
        row = ["."] * len(board)
        row[r] = "Q"
        print(" ".join(row))


N = int(input("Enter No. of Queen: "))
if N < 4:
    print("No solution for N < 4")

else:
    print_board(solve_n_queens(N))
