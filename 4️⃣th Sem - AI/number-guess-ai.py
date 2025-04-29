def number_guessing_ai():
    print("Think of a number between 1 and 100.")
    print("I will try to guess it!")

    low = 1
    high = 100
    tries = 0

    while True:
        guess = (low + high) // 2
        tries += 1

        print(f"\nIs it {guess}? ('higher', 'lower' or 'correct')")
        reply = input("→ ").strip().lower()

        if reply == "correct":
            print(f"I guessed it in {tries} tries!")
            break
        elif reply == "higher":
            low = guess + 1
        elif reply == "lower":
            high = guess - 1
        else:
            print("Please type exactly: 'higher', 'lower', or 'correct'.")

number_guessing_ai()
