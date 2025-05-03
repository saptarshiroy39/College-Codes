def print_board(board):
    for row in board:
        print(" | ".join(row))


def check_win(board, player):
    for row in board:
        if all(cell == player for cell in row):
            return True
    for col in range(3):
        if all(board[row][col] == player for row in range(3)):
            return True
    if board[0][0] == player and board[1][1] == player and board[2][2] == player:
        return True
    if board[0][2] == player and board[1][1] == player and board[2][0] == player:
        return True
    return False


def is_full(board):
    return all(cell != " " for row in board for cell in row)


def minimax(board, depth, is_maximizing):
    if check_win(board, "O"):
        return 1
    if check_win(board, "X"):
        return -1
    if is_full(board):
        return 0

    if is_maximizing:
        best = -float("inf")
        for row in range(3):
            for col in range(3):
                if board[row][col] == " ":
                    board[row][col] = "O"
                    best = max(best, minimax(board, depth + 1, False))
                    board[row][col] = " "
        return best
    else:
        best = float("inf")
        for row in range(3):
            for col in range(3):
                if board[row][col] == " ":
                    board[row][col] = "X"
                    best = min(best, minimax(board, depth + 1, True))
                    board[row][col] = " "
        return best


def best_move(board):
    best_val = -float("inf")
    move = (-1, -1)
    for row in range(3):
        for col in range(3):
            if board[row][col] == " ":
                board[row][col] = "O"
                move_val = minimax(board, 0, False)
                board[row][col] = " "
                if move_val > best_val:
                    move = (row, col)
                    best_val = move_val
    return move


def tic_tac_toe():
    board = [[" " for _ in range(3)] for _ in range(3)]
    print("Tic-Tac-Toe! You are X, AI is O.")
    print_board(board)

    while True:
        # Player's move
        row, col = map(int, input("\nEnter your move (row col): ").split())
        if board[row][col] != " ":
            print("Invalid move. Try again.")
            continue
        board[row][col] = "X"
        print_board(board)
        if check_win(board, "X"):
            print("You win!")
            break
        if is_full(board):
            print("It's a draw!")
            break

        # AI's move
        print("AI is making a move...")
        ai_row, ai_col = best_move(board)
        board[ai_row][ai_col] = "O"
        print_board(board)
        if check_win(board, "O"):
            print("AI wins!")
            break
        if is_full(board):
            print("It's a draw!")
            break


tic_tac_toe()
