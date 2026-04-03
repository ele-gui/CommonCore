#  qui non importo nulla, altrimenti ho circular import

def validate_ingredients(ingredients: str) -> str:

    allowed_ingredients = [
        'earth',
        'air',
        'fire',
        'water'
    ]

    allowed_ingredients_lower = ingredients.lower()
    
    for item in allowed_ingredients:
        if item in allowed_ingredients_lower:
            return str(f"{ingredients} - VALID")
        else:
            return str(f"{ingredients} - INVALID")
