from alchemy.elements import create_air  # absolute
from ..potions import strength_potion, create_fire  # relative


def lead_to_gold() -> str:
    air = create_air()
    strength = strength_potion()
    fire = create_fire()
    return str(
        f"Recipe transmuting Lead to Gold: brew "
        f"'{air}' and '{strength}' mixed with '{fire}'"
    )


# from alchemy.elements import create_air   # absolute — from project root
# from ..elements import create_air         # relative to current package
