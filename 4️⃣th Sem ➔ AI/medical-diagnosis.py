def diagnose(symptoms):
    symptoms = [sym.lower().strip() for sym in symptoms]

    diseases = {
        "Flu": ["fever", "cough", "fatigue"],
        "Meningitis": ["fever", "headache", "stiff neck"],
        "Common Cold": ["sneezing", "runny nose", "sore throat"],
        "Heart Problem": ["chest pain", "shortness of breath"],
        "Stomach Infection": ["abdominal pain", "diarrhea"],
        "Allergic Reaction": ["itchy eyes", "sneezing", "runny nose"],
    }

    diagnosis_results = []

    for disease, disease_symptoms in diseases.items():
        match_count = sum(any(ds == us or ds in us.split() for us in symptoms) for ds in disease_symptoms)
        match_percentage = match_count / len(disease_symptoms)

        if match_count > 0:
            diagnosis_results.append((disease, match_count, len(disease_symptoms), match_percentage))

    diagnosis_results.sort(key=lambda x: x[3], reverse=True)

    if diagnosis_results:
        print("\nPossible Diagnoses (based on your symptoms):")
        for disease, matched, total, percent in diagnosis_results:
            match_level = f"{matched}/{total} symptoms matched"
            print(f"- {disease}: {match_level} ({round(percent * 100)}%)")
    else:
        print("\nNo possible diagnosis found. Please consult a doctor.")


def main():
    print("🩺 Welcome to the Medical Diagnosis Expert System 🧠")

    input_symptoms = input("Enter symptoms: ")
    user_symptoms = [sym.strip().lower() for sym in input_symptoms.split(",")]

    if any(user_symptoms):
        diagnose(user_symptoms)
    else:
        print("No symptoms entered. Unable to diagnose.")


main()
