import sys


def parse_scores(scores):
    try:
        return [int(score) for score in scores]
    except ValueError:
        print("Invalid score detected. Please ensure all scores are numeric.")
        # sys.exit(1)


if __name__ == "__main__":
    print("=== Player Score Analytics ===")
    if len(sys.argv) < 2:
        print("No scores provided. Usage: python3 ft_score_analytics.py <score1> <score2> ...")

    if (len(sys.argv) > 1):
        scores = parse_scores(sys.argv[1:])
        print(f"Scores processed: {scores}")

        print(f"Total players: {len(sys.argv) - 1}")

        print(f"Total score: {sum(scores)}")

        print(f"Average score: {sum(scores) / (len(sys.argv) - 1)}")

        print(f"High score: {max(scores)}")

        print(f"Low score: {min(scores)}")

        score_range = max(scores) - min(scores)
        print(f"Score range: {score_range}")
