def diagnose(symptoms):
    symptoms = [sym.lower().strip() for sym in symptoms]

    def has(symptom_keywords):
        return all(any(keyword in user_symptom for user_symptom in symptoms) for keyword in symptom_keywords)

    if has(["fever", "cough", "fatigue"]):
        return "You may have the flu."
    elif has(["fever", "headache", "stiff neck"]):
        return "You may have meningitis. Please consult a doctor immediately."
    elif has(["sneezing", "runny nose", "sore throat"]):
        return "You may have a common cold."
    elif has(["chest pain", "shortness of breath"]):
        return "You may have a heart problem. Seek medical attention immediately."
    elif has(["abdominal pain", "diarrhea"]):
        return "You may have a stomach infection."
    elif has(["itchy eyes", "sneezing", "runny nose"]):
        return "You may be experiencing an allergic reaction."
    else:
        return "Diagnosis not found. Please consult a healthcare professional."

def main():
    print("Welcome to the Medical Diagnosis Expert System.")
    print("Enter your symptoms separated by commas (e.g. fever, headache, sore throat):\n")

    input_symptoms = input("Enter symptoms: ")
    user_symptoms = input_symptoms.split(",")

    if any(user_symptoms):
        result = diagnose(user_symptoms)
        print("\nDiagnosis:", result)
    else:
        print("No symptoms entered. Unable to diagnose.")

if __name__ == "__main__":
    main()




# def diagnose(symptoms):
#     # Normalize user input
#     symptoms = [sym.lower().strip() for sym in symptoms]

#     # Knowledge base: disease → list of symptoms
#     diseases = {
#         "Flu": ["fever", "cough", "fatigue"],
#         "Meningitis": ["fever", "headache", "stiff neck"],
#         "Common Cold": ["sneezing", "runny nose", "sore throat"],
#         "Heart Problem": ["chest pain", "shortness of breath"],
#         "Stomach Infection": ["abdominal pain", "diarrhea"],
#         "Allergic Reaction": ["itchy eyes", "sneezing", "runny nose"],
#     }

#     diagnosis_results = []

#     for disease, disease_symptoms in diseases.items():
#         match_count = sum(any(ds in us for us in symptoms) for ds in disease_symptoms)
#         match_percentage = match_count / len(disease_symptoms)

#         if match_count > 0:
#             diagnosis_results.append(
#                 (disease, match_count, len(disease_symptoms), match_percentage)
#             )

#     # Sort by best match
#     diagnosis_results.sort(key=lambda x: x[3], reverse=True)

#     if diagnosis_results:
#         print("\nPossible Diagnoses (based on your symptoms):")
#         for disease, matched, total, percent in diagnosis_results:
#             match_level = f"{matched}/{total} symptoms matched"
#             print(f"- {disease}: {match_level} ({round(percent * 100)}%)")
#     else:
#         print("\nNo possible diagnosis found. Please consult a doctor.")


# def main():
#     print("🩺 Welcome to the Medical Diagnosis Expert System 🧠")
#     print("Enter your symptoms separated by commas (e.g. fever, throat, cough):\n")

#     input_symptoms = input("Enter symptoms: ")
#     user_symptoms = input_symptoms.split(",")

#     if any(user_symptoms):
#         diagnose(user_symptoms)
#     else:
#         print("No symptoms entered. Unable to diagnose.")


# if __name__ == "__main__":
#     main()
