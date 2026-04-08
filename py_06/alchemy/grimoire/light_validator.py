#  qui non importo nulla, altrimenti ho circular import

def validate_ingredients(ingredients: str) -> str:

    from .light_spellbook import light_spell_allowed_ingredients

    allowed = light_spell_allowed_ingredients()
    ingredients_lower = ingredients.lower()

    for item in allowed:
        if item in ingredients_lower:
            return str(f"{ingredients} - VALID")
    return str(f"{ingredients} - INVALID")
