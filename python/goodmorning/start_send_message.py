import argparse
import subprocess


def craft_good_morning_text() -> str:
    rval = f"Good morning!\nToday's events include:\nEvents go here..."

    return rval


def main(phones):
    text = craft_good_morning_text()

    for recipient in phones:
        print(str(recipient))

        subprocess.run(["osascript", "send_message.scpt", str(recipient), text])


if __name__ == "__main__":
    parser = argparse.ArgumentParser(description="Good morning messager")
    parser.add_argument(
        "-r", "--recipients", required=True, help="Comma separated list of recipients"
    )

    args, _ = parser.parse_known_args()

    recipients = args.recipients.split(",")

    main(recipients)
