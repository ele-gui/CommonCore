from alchemy.grimoire.dark_validator import dark_validate_ingredients


def dark_spell_allowed_ingredients() -> list[str]:
    dark_allowed_ingredients = [
        'bats',
        'frogs',
        'arsenic',
        'eyeball'
    ]
    return dark_allowed_ingredients


def dark_spell_record(spell_name: str, ingredients: str):
    
    result = str(f"{spell_name} ({dark_validate_ingredients(ingredients)})")


    if "VALID" in result:
        return str(
            f"Dark spell recorded: {result}"
        )
    
    else:
        return str(
            f"Dark spell rejected: {result}"
        )