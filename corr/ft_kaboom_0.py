import alchemy.grimoire


def main() -> None:
    print("=== Kaboom 0 ===")
    print("Using grimoire module directly")
    result = alchemy.grimoire.light_spell_record(
            'Fantasy',
            'Earth, wind and fire'
        )

    print(
        f"Testing record light spell: {result}"
    )


if __name__ == "__main__":
    main()



circular dependency

🔥 What is happening (clean explanation)

When you run:

from alchemy.grimoire.dark_spellbook import dark_spell_record

Python does:

Starts loading dark_spellbook

Finds:

from dark_validator import dark_validate_ingredients
Starts loading dark_validator

Finds:

from dark_spellbook import dark_spell_allowed_ingredients
❌ But dark_spellbook is not fully loaded yet

👉 So Python sees:

“I don’t know this function yet”

💥 → crash
