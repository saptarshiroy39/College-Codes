def number_guessing_ai():
    print("Think of a number between 1 and 100.")
    print("I will try to guess it!")

    low, high = 1, 100
    tries = 0

    while low <= high:
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

    if low > high:
        print("Hmm, something doesn't seem right. Let's try again.")


number_guessing_ai()
