import argparse
import random
import subprocess
import time

SCRIPT_PATH = "/Users/andrewbianchini/code/bored/python/goodmorning/"

RANDOM_GOOD_MORNINGS = [
    "Good morning, beautiful! Hope your day is as bright and gorgeous as your smile.",
    "Waking up and thinking of you is the highlight of my morning.",
    "Every day is a blessing with you. Have a great morning, my love.",
    "May your day be filled with love, laughter, and countless joys!",
    "Just wanted to start your day with a little ‘I love you’ message.",
    "The sun is up, the sky is blue, today is beautiful, and so are you.",
    "Morning, my love! Your smile is my daily dose of inspiration.",
    "May your coffee be strong, your day productive, and your spirit radiant.",
    "Open your eyes and embrace the new day. Good morning to the woman who makes my heart skip a beat.",
    "With you, every morning is a good morning. Sending you love and hugs.",
    "Let’s make today incredible. Good morning, sunshine!",
    "Sending you a smile and a warm hug to brighten your morning.",
    "Thinking of you keeps me awake, dreaming of you keeps me asleep, being with you keeps me alive. Good morning!",
    "Start your day knowing you are loved beyond measure. Have a fantastic morning!",
    "Wake up, my love. A beautiful day awaits, filled with endless possibilities and love.",
    "Good morning, my love! Remember, you have what it takes to conquer anything.",
    "Another day, another adventure with you. Excited for what’s in store today!",
    "Morning! Today’s forecast: 100% chance of joy and laughter with you by my side.",
    "Wishing you a day as sweet and lovely as you are. Good morning, my love!",
]


def craft_good_morning_text() -> str:
    rval = random.choice(RANDOM_GOOD_MORNINGS)

    return rval


def main(phones):
    text = craft_good_morning_text()

    time.sleep(45)

    for recipient in phones:
        print(str(recipient))

        subprocess.run(
            ["osascript", f"{SCRIPT_PATH}send_message.scpt", str(recipient), text]
        )


if __name__ == "__main__":
    parser = argparse.ArgumentParser(description="Good morning messager")
    parser.add_argument(
        "-r", "--recipients", required=True, help="Comma separated list of recipients"
    )

    args, _ = parser.parse_known_args()

    recipients = args.recipients.split(",")

    main(recipients)
