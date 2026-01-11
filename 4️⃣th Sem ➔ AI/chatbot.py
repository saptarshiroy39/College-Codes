def simple_chatbot():
    print("Chatbot: Hello!\n")
    while True:
        user_input = input("You: ").strip().lower()

        if user_input == "hello" or user_input == "hi":
            print("Chatbot: Hi! How can I help you?\n")

        elif user_input == "how are you":
            print("Chatbot: I'm just a bot, but I'm doing well! How about you?\n")

        elif user_input == "what's your name":
            print("Chatbot: I'm a simple chatbot created to assist you!\n")

        elif user_input == "what can you do":
            print("Chatbot: I can have a basic conversation with you!\n")

        elif user_input == "tell me a joke":
            print("Chatbot: Why did the scarecrow win an award?")
            print("Because he was outstanding in his field!\n")

        elif user_input == "who made you":
            print("Chatbot: I was created by Mr. Roy.\n")

        elif user_input == "thank you" or user_input == "thanks":
            print("Chatbot: You're welcome! Happy to help.\n")

        elif user_input == "help":
            print("Chatbot: You can ask me questions like:")
            print("1. Hello or Hi")
            print("2. How are you")
            print("3. What's your name")
            print("4. What can you do")
            print("5. Tell me a joke")
            print("6. Who made you")
            print("7. Thank you or Thanks")
            print("8. Bye")
            print("9. Help\n")

        elif user_input == "bye":
            print("Chatbot: Goodbye! Have a nice day.")
            break

        else:
            print("Chatbot: Sorry, I don't understand that.")


simple_chatbot()
