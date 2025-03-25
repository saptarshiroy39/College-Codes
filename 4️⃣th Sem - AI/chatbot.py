def simple_chatbot():
    print("Chatbot: Hello! Type something to start a conversation. Type 'Bye' to exit.")

    while True:
        user_input = input("You: ").strip().lower()

        if user_input == "hello" or user_input == "hi":
            print("Chatbot: Hi! How can I help you?")
        elif user_input == "how are you":
            print("Chatbot: I'm just a bot, but I'm doing well! How about you?")
        elif user_input == "what's your name":
            print("Chatbot: I'm a simple chatbot created to assist you!")
        elif user_input == "bye":
            print("Chatbot: Goodbye! Have a nice day.")
            break
        else:
            print("Chatbot: Sorry, I don't understand that.")


simple_chatbot()
