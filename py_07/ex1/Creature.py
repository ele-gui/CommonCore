from ex0.Creature import Creature
from ex1.Capability import HealCapability, TransformCapability


class Sproutling(Creature, HealCapability):
    
    def __init__(self):
        Creature.__init__(self, "Sproutling", "Grass")

    def attack(self):
        return f"{self.creature_name} uses Vine Whip!"

    def heal(self, target=None):
        if target:
            return f"{self.creature_name} heals {target}"
        return f"{self.creature_name} heals itself for a small amount"


class Bloomelle(Creature, HealCapability):
    def __init__(self):
        Creature.__init__(self, "Bloomelle", "Grass/Fairy")

    def attack(self):
        return f"{self.creature_name} uses Petal Dance!"

    def heal(self, target=None):
        if target:
            return f"{self.creature_name} heals {target}"
        return f"{self.creature_name} heals itself and others for a large amount"


class Shiftling(Creature, TransformCapability):
    def __init__(self):
        Creature.__init__(self, "Shiftling", "Normal")
        TransformCapability.__init__(self)

    def attack(self) -> str:
        if self.transformed:
            return "Shiftling performs a boosted strike!"
        return "Shiftling attacks normally."

    def transform(self) -> str:
        self.transformed = True
        return "Shiftling shifts into a sharper form!"

    def revert(self) -> str:
        self.transformed = False
        return "Shiftling returns to normal."


class Morphagon(Creature, TransformCapability):
    def __init__(self):
        Creature.__init__(self, "Morphagon", "Normal/Dragon")
        TransformCapability.__init__(self)

    def attack(self) -> str:
        if self.transformed:
            return "Morphagon unleashes a devastating morph strike!"
        return "Morphagon attacks normally."

    def transform(self) -> str:
        self.transformed = True
        return "Morphagon morphs into a dragonic battle form!"

    def revert(self) -> str:
        self.transformed = False
        return "Morphagon stabilizes its form."