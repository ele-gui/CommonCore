from alchemy.grimoire.dark_spellbook import dark_spell_allowed_ingredients


def dark_validate_ingredients(ingredients: str) -> str:

    allowed_ingredients = [
        'bats',
        'frogs',
        'arsenic',
        'eyeball'
    ]

    allowed_ingredients_lower = ingredients.lower()
    
    for item in allowed_ingredients:
        if item in allowed_ingredients_lower:
            return str(f"{ingredients} - VALID")
        else:
            return str(f"{ingredients} - INVALID")
