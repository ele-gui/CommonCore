from elements import create_fire, create_water
from alchemy.elements import create_earth, create_air


def strength_potion() -> str:
    fire = create_fire()
    water = create_water()
    return str(f"Strength potion brewed with '{fire}' and '{water}'")


def healing_potion() -> str:
    earth = create_earth()
    air = create_air()
    return str(f"Healing potion brewed with '{earth}' and '{air}'")
