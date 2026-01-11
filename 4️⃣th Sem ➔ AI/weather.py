def weather_advice():
    print("Welcome to the Weather Advice Program!")
    print("Options:")
    print( "hot, sunny, stormy, thunder, rainy, humid, cloudy, windy, foggy, cold, snowy")
    weather = input("Enter the current weather condition: ").strip().lower()

    if weather == "hot":
        print("It's hot! 🌡️ Dress in light clothes, carry water & seek shade.")
    elif weather == "stormy":
        print("It's stormy! ⛈️ Stay indoors if possible & avoid open areas.")
    elif weather == "sunny":
        print("It's sunny! ☀️ Wear sunglasses & apply sunscreen.")

    elif weather == "thunder":
        print("It's thundering! ⚡ Stay indoors & avoid electrical appliances.")
    elif weather == "rainy":
        print("It's raining! 🌧️ Take an umbrella & wear a raincoat.")
    elif weather == "humid":
        print("It's humid! 💦 Wear light, breathable clothing & stay hydrated.")

    elif weather == "cloudy":
        print("It's cloudy! ☁️ Bring a light jacket & be prepared for rain.")

    elif weather == "windy":
        print("It's windy! 🍃 Wear a windbreaker & secure loose items.")
    elif weather == "foggy":
        print("It's foggy! 🌫️ Drive slowly & use fog lights when traveling.")

    elif weather == "cold":
        print("It's cold! ❄️ Wear a warm jacket & gloves.")
    elif weather == "snowy":
        print("It's snowy! 🌨️ Wear warm clothing & be careful on roads.")

    else:
        print("Sorry, ⚠️ I don't have advice for that weather condition.")


weather_advice()
