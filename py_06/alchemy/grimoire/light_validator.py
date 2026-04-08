#  qui non importo nulla, altrimenti ho circular import

def validate_ingredients(ingredients: str) -> str:

    allowed_ingredients = [  # non devo specificare gli elementi qui
        'earth',
        'air',
        'fire',
        'water'
    ]

    allowed_ingredients_lower = ingredients.lower()

    for item in allowed_ingredients:
        if item in allowed_ingredients_lower:
            return str(f"{ingredients} - VALID")
    return str(f"{ingredients} - INVALID")
