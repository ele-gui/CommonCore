def validate_ingredients(ingredients: str) -> str:
    # con questo evito circular dependency
    # cosi' l'import avviene solo quando
    # la funzione viene chiamata
    from .light_spellbook import light_spell_allowed_ingredients

    allowed = light_spell_allowed_ingredients()
    ingredients_lower = ingredients.lower()

    for item in allowed:
        if item in ingredients_lower:
            return str(f"{ingredients} - VALID")
    return str(f"{ingredients} - INVALID")
