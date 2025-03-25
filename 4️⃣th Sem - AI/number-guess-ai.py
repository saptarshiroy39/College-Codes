def number_guessing_ai():
    print("Think of a number between 1 and 100, and I'll guess it!")

    low, high = 1, 100
    attempts = 0

    while low <= high:
        guess = (low + high) // 2
        attempts += 1

        print(f"Is your number {guess}? (Enter 'higher', 'lower', or 'correct')")
        response = input().strip().lower()

        if response == "correct":
            print(f"Yay! I guessed your number in {attempts} tries.")
            break
        elif response == "higher":
            low = guess + 1
        elif response == "lower":
            high = guess - 1
        else:
            print("Invalid input. Please enter 'higher', 'lower', or 'correct'.")

    if low > high:
        print("Something went wrong. Did you change your number?")


number_guessing_ai()
