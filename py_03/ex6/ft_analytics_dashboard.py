if __name__ == "__main__":
    print("=== Game Analytics Dashboard ===\n")

    print("=== List Comprehension Examples ===")


    dict_list = [
        {
            "name": "alice",
            "score": 2300,
            "status": "active",
            "achievements": {
                "first_kill",
                "level_10",
                "treasure_hunter",
                "speed_demon"
            },
            "region": "north"
        },
        {
            "name": "bob",
            "score": 1800,
            "status": "active",
            "achievements": {
                "first_kill",
                "level_10",
                "boss_slayer",
                "collector"
            },
            "region": "south"
        },
        {
            "name": "charlie",
            "score": 2150,
            "status": "active",
            "achievements": {
                "level_10",
                "treasure_hunter",
                "boss_slayer",
                "speed_demon",
                "perfectionist",
            },
            "region": "north"
        },
        {
            "name": "diana",
            "score": 2200,
            "status": "inactive",
            "achievements": {
                "level_10",
                "treasure_hunter",
                "boss_slayer",
                "perfectionist",
            },
            "region": "west"
        },
        {
            "name": "ellie",
            "score": 1950,
            "status": "inactive",
            "achievements": {
                "level_10",
                "treasure_hunter",
                "boss_slayer",
                "speed_demon",
            },
            "region": "north"
        }
    ]


    high_scores_player = [player["name"] for player in dict_list if player["score"] > 2000]
    print(f"High scorers (>2000): {high_scores_player}")

    double_score = [player["score"] * 2 for player in dict_list]
    print(f"Scores doubled: {double_score}")

    status_player = [player["name"] for player in dict_list if player["status"] == "active"]
    print(f"Active players: {status_player}")


    print("\n=== Dict Comprehension Examples ===")
    players_dict = {player["name"]: player["score"] for player in dict_list}
    print(f"Player scores: {players_dict}")

    score_categories = {"high" if player["score"] > 2000 else "medium" if player["score"] > 1900 else "low": sum([player["score"] for player in dict_list if player["score"] > 2000]) for player in dict_list}
    print(f"Score categories: {score_categories}") #DA SISTEMARE

    achievement_count = {player["name"]: len(player["achievements"]) for player in dict_list}
    print(f"Achievement counts: {achievement_count}")


    print("\n=== Set Comprehension Examples ===")
    unique_players = {player["name"] for player in dict_list}
    print(f"Unique players: {unique_players}")

    unique_achievements = {achievement for player in dict_list for achievement in player["achievements"]}
    print(f"Unique achievements: {unique_achievements}")


    active_region = {player["region"] for player in dict_list for region in player["region"]}
    print(f"Active regions: {active_region}")


    print("\n=== Combined Analysis ===")
    print(f"Total players: {len(unique_players)}")
    total_unique_achievements = len(unique_achievements)
    print(f"Total unique achievements: {total_unique_achievements}")
    average_score = sum(player["score"] for player in dict_list) / len(dict_list)
    print(f"Average score: {average_score:.2f}")
    top_performer = max(player["score"] for player in dict_list)
    n_achievements = max(len(player["achievements"]) for player in dict_list)
    top_player = max(dict_list, key=lambda p: p["score"])
    print(f"Top performer: {top_player['name']} ({top_performer} points, {n_achievements} achievements)")





