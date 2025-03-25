def weather_advice():
    weather = input(
        "Enter the current weather condition (sunny, rainy, cold, windy, snowy): "
    )

    if weather == "sunny":
        print("It's a bright day! Wear sunglasses and apply sunscreen.")
    elif weather == "rainy":
        print("It's raining! Take an umbrella and wear a raincoat.")
    elif weather == "cold":
        print("It's cold outside! Wear a warm jacket and gloves.")
    elif weather == "windy":
        print("It's windy! Wear a windbreaker and secure loose items.")
    elif weather == "snowy":
        print("It's snowy! Wear warm clothing and be careful on the roads.")
    else:
        print("Sorry, I don't have advice for this weather condition.")


weather_advice()
