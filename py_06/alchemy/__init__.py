# file che trasforma una directory in un pacchetto riconoscibile
# dall'interprete permettendo di importare i moduli al suo interno

# il file esegue automaticamente codice di inizializzazione ogni
# volta che il pacchetto viene importato

# Esportazione selettiva: può definire la variabile __all__
# per controllare quali nomi vengono esposti quando si usa
# from package import *


# parte 1
from alchemy.elements import create_air
# partially import the alchemy module

# parte 2
from alchemy.potions import healing_potion, strength_potion
""" This exposes create_air, strength_potion, heal through
the alchemy package interface — but not create_earth """
heal = healing_potion  # alias

# parte 3
from alchemy.transmutation.recipes import lead_to_gold

#  parte 4
from alchemy.grimoire.light_spellbook import light_spell_allowed_ingredients, light_spell_record
from alchemy.grimoire.light_validator import validate_ingredients

# from alchemy.grimoire.dark_spellbook import dark_spell_allowed_ingredients, dark_spell_record
# from alchemy.grimoire.dark_validator import validate_ingredients