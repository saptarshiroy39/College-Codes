import math


def init_board():
    return [[" " for _ in range(3)] for _ in range(3)]


def print_board(board):
    for i, row in enumerate(board):
        print("|".join(row))
        if i < 2:
            print("-" * 5)


def check_winner(board):
    for i in range(3):
        if board[i][0] == board[i][1] == board[i][2] != " ":
            return board[i][0]
        if board[0][i] == board[1][i] == board[2][i] != " ":
            return board[0][i]
    if board[0][0] == board[1][1] == board[2][2] != " ":
        return board[0][0]
    if board[0][2] == board[1][1] == board[2][0] != " ":
        return board[0][2]
    if all(cell != " " for row in board for cell in row):
        return "Draw"
    return None


def minimax(board, depth, is_maximizing):
    winner = check_winner(board)
    if winner == "X":
        return -1
    elif winner == "O":
        return 1
    elif winner == "Draw":
        return 0

    best_score = -math.inf if is_maximizing else math.inf
    for i in range(3):
        for j in range(3):
            if board[i][j] == " ":
                board[i][j] = "O" if is_maximizing else "X"
                score = minimax(board, depth + 1, not is_maximizing)
                board[i][j] = " "
                best_score = (
                    max(score, best_score) if is_maximizing else min(score, best_score)
                )
    return best_score


def best_move(board):
    best_score, move = -math.inf, (-1, -1)
    for i in range(3):
        for j in range(3):
            if board[i][j] == " ":
                board[i][j] = "O"
                score = minimax(board, 0, False)
                board[i][j] = " "
                if score > best_score:
                    best_score, move = score, (i, j)
    return move


def play_game():
    board = init_board()
    print("You are X, AI is O")
    while True:
        print_board(board)
        try:
            row, col = map(int, input("Enter move (row col): ").split())
            if not (0 <= row < 3 and 0 <= col < 3) or board[row][col] != " ":
                print("Invalid move. Try again.")
                continue
            board[row][col] = "X"
        except (ValueError, IndexError):
            print("Invalid input. Use format: row col (e.g., 0 1)")
            continue

        if result := check_winner(board):
            print_board(board)
            print("Draw!" if result == "Draw" else f"{result} wins!")
            break

        board[best_move(board)[0]][best_move(board)[1]] = "O"
        if result := check_winner(board):
            print_board(board)
            print("Draw!" if result == "Draw" else f"{result} wins!")
            break


play_game()

# ----------------------------------------------------------------------------------------------------
# import random

# def print_board(board):
#     for row in board:
#         print(" | ".join(row))


# def check_win(board, player):
#     for row in board:
#         if all(cell == player for cell in row):
#             return True
#     for col in range(3):
#         if all(board[row][col] == player for row in range(3)):
#             return True
#     if board[0][0] == player and board[1][1] == player and board[2][2] == player:
#         return True
#     if board[0][2] == player and board[1][1] == player and board[2][0] == player:
#         return True
#     return False

# def is_full(board):
#     return all(cell != " " for row in board for cell in row)

# def best_move(board):
#     empty_cells = [(r, c) for r in range(3) for c in range(3) if board[r][c] == " "]
#     return random.choice(empty_cells)

# def play_game():
#     board = [[" " for _ in range(3)] for _ in range(3)]
#     print("Tic-Tac-Toe! You are X, AI is O.")
#     print_board(board)

#     while True:
#         # Player's move
#         row, col = map(int, input("Enter your move (row col): ").split())
#         if board[row][col] != " ":
#             print("Invalid move. Try again.")
#             continue
#         board[row][col] = "X"
#         print_board(board)
#         if check_win(board, "X"):
#             print("You win!")
#             break
#         if is_full(board):
#             print("It's a draw!")
#             break

#         # AI's move
#         print("AI is making a move...")
#         ai_row, ai_col = best_move(board)
#         board[ai_row][ai_col] = "O"
#         print_board(board)
#         if check_win(board, "O"):
#             print("AI wins!")
#             break
#         if is_full(board):
#             print("It's a draw!")
#             break

# play_game()


# ---------------------------------------------------------------------------------------------------------------------------------------------------------------------

# import math


# def show(b):
#     [print("|".join(r)) or print("-" * 5) for r in b]


# def win(b):
#     lines = (b + [list(c) for c in zip(*b)] + [[b[i][i] for i in range(3)], [b[i][2 - i] for i in range(3)]])

#     for l in lines:
#         if l[0] != " " and l.count(l[0]) == 3:
#             return l[0]

#     return "Draw" if all(c != " " for r in b for c in r) else None


# def mini(b, ai):
#     r = win(b)
#     if r:
#         return {"X": -1, "O": 1, "Draw": 0}[r]
#     scores = []

#     for i in range(3):
#         for j in range(3):
#             if b[i][j] == " ":
#                 b[i][j] = "O" if ai else "X"
#                 scores.append(mini(b, not ai))
#                 b[i][j] = " "

#     return max(scores) if ai else min(scores)


# def best(b):
#     m, s = None, -math.inf

#     for i in range(3):
#         for j in range(3):
#             if b[i][j] == " ":
#                 b[i][j] = "O"
#                 val = mini(b, False)
#                 b[i][j] = " "
#                 if val > s:
#                     m, s = (i, j), val

#     return m


# def play():
#     b = [[" "] * 3 for _ in range(3)]
#     print("You → X & AI → O")
#     while True:
#         show(b)
#         try:
#             x, y = map(int, input("Move (row col): ").split())
#             if b[x][y] != " ":
#                 continue
#             b[x][y] = "X"
#         except:
#             continue
#         if r := win(b):
#             show(b)
#             print("Draw!" if r == "Draw" else f"{r} wins!")
#             break
#         i, j = best(b)
#         b[i][j] = "O"
#         if r := win(b):
#             show(b)
#             print("Draw!" if r == "Draw" else f"{r} wins!")
#             break


# play()

# ----------------------------------------------------------------------------------------------------------------------------------------------------------------------

# def print_board(board):
#     for row in board:
#         print(" | ".join(row))
#         print("-" * 5)

# def check_win(board, player):
#     for row in board:
#         if all(cell == player for cell in row):
#             return True
#     for col in range(3):
#         if all(board[row][col] == player for row in range(3)):
#             return True
#     if board[0][0] == player and board[1][1] == player and board[2][2] == player:
#         return True
#     if board[0][2] == player and board[1][1] == player and board[2][0] == player:
#         return True
#     return False

# def is_full(board):
#     return all(cell != " " for row in board for cell in row)

# def minimax(board, depth, is_maximizing):
#     if check_win(board, "O"):
#         return 1
#     if check_win(board, "X"):
#         return -1
#     if is_full(board):
#         return 0

#     if is_maximizing:
#         best = -float('inf')
#         for row in range(3):
#             for col in range(3):
#                 if board[row][col] == " ":
#                     board[row][col] = "O"
#                     best = max(best, minimax(board, depth + 1, False))
#                     board[row][col] = " "
#         return best
#     else:
#         best = float('inf')
#         for row in range(3):
#             for col in range(3):
#                 if board[row][col] == " ":
#                     board[row][col] = "X"
#                     best = min(best, minimax(board, depth + 1, True))
#                     board[row][col] = " "
#         return best

# def best_move(board):
#     best_val = -float('inf')
#     move = (-1, -1)
#     for row in range(3):
#         for col in range(3):
#             if board[row][col] == " ":
#                 board[row][col] = "O"
#                 move_val = minimax(board, 0, False)
#                 board[row][col] = " "
#                 if move_val > best_val:
#                     move = (row, col)
#                     best_val = move_val
#     return move

# def tic_tac_toe():
#     board = [[" " for _ in range(3)] for _ in range(3)]
#     print("Tic-Tac-Toe! You are X, AI is O.")
#     print_board(board)

#     while True:
#         # Player's move
#         row, col = map(int, input("Enter your move (row col): ").split())
#         if board[row][col] != " ":
#             print("Invalid move. Try again.")
#             continue
#         board[row][col] = "X"
#         print_board(board)
#         if check_win(board, "X"):
#             print("You win!")
#             break
#         if is_full(board):
#             print("It's a draw!")
#             break

#         # AI's move
#         print("AI is making a move...")
#         ai_row, ai_col = best_move(board)
#         board[ai_row][ai_col] = "O"
#         print_board(board)
#         if check_win(board, "O"):
#             print("AI wins!")
#             break
#         if is_full(board):
#             print("It's a draw!")
#             break

# # Start the game
# tic_tac_toe()


# def print_board(board):
#     for row in board:
#         print(" | ".join(row))
#         print("-" * 5)

# def check_win(board, player):
#     for row in board:
#         if all(cell == player for cell in row):
#             return True
#     for col in range(3):
#         if all(board[row][col] == player for row in range(3)):
#             return True
#     if board[0][0] == player and board[1][1] == player and board[2][2] == player:
#         return True
#     if board[0][2] == player and board[1][1] == player and board[2][0] == player:
#         return True
#     return False

# def is_full(board):
#     return all(cell != " " for row in board for cell in row)

# def minimax(board, depth, is_maximizing):
#     if check_win(board, "O"):
#         return 1
#     if check_win(board, "X"):
#         return -1
#     if is_full(board):
#         return 0

#     if is_maximizing:
#         best = -float('inf')
#         for row in range(3):
#             for col in range(3):
#                 if board[row][col] == " ":
#                     board[row][col] = "O"
#                     best = max(best, minimax(board, depth + 1, False))
#                     board[row][col] = " "
#         return best
#     else:
#         best = float('inf')
#         for row in range(3):
#             for col in range(3):
#                 if board[row][col] == " ":
#                     board[row][col] = "X"
#                     best = min(best, minimax(board, depth + 1, True))
#                     board[row][col] = " "
#         return best

# def best_move(board):
#     best_val = -float('inf')
#     move = (-1, -1)
#     for row in range(3):
#         for col in range(3):
#             if board[row][col] == " ":
#                 board[row][col] = "O"
#                 move_val = minimax(board, 0, False)
#                 board[row][col] = " "
#                 if move_val > best_val:
#                     move = (row, col)
#                     best_val = move_val
#     return move

# def tic_tac_toe():
#     board = [[" " for _ in range(3)] for _ in range(3)]
#     print("Tic-Tac-Toe! You are X, AI is O.")
#     print_board(board)

#     while True:
#         # Player's move
#         row, col = map(int, input("Enter your move (row col): ").split())
#         if board[row][col] != " ":
#             print("Invalid move. Try again.")
#             continue
#         board[row][col] = "X"
#         print_board(board)
#         if check_win(board, "X"):
#             print("You win!")
#             break
#         if is_full(board):
#             print("It's a draw!")
#             break

#         # AI's move
#         print("AI is making a move...")
#         ai_row, ai_col = best_move(board)
#         board[ai_row][ai_col] = "O"
#         print_board(board)
#         if check_win(board, "O"):
#             print("AI wins!")
#             break
#         if is_full(board):
#             print("It's a draw!")
#             break

# # Start the game
# tic_tac_toe()
