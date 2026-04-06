from alchemy.grimoire.light_validator import validate_ingredients


def light_spell_allowed_ingredients() -> list[str]:
    allowed_ingredients = [
        'earth',
        'air',
        'fire',
        'water'
    ]
    return allowed_ingredients


def light_spell_record(spell_name: str, ingredients: str) -> str:

    result = str(f"{spell_name} ({validate_ingredients(ingredients)})")

    if "VALID" in result:
        return str(
            f"Spell recorded: {result}"
        )

    else:
        return str(
            f"Spell rejected: {result}"
        )
