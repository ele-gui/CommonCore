from .dark_spellbook import dark_spell_allowed_ingredients


def dark_validate_ingredients(ingredients: str) -> str:
    allowed_ingredients = dark_spell_allowed_ingredients()
    ingredients_lower = ingredients.lower()

    for item in allowed_ingredients:
        if item in ingredients_lower:
            return f"{ingredients} - VALID"

    return f"{ingredients} - INVALID"
