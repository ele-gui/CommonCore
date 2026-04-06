from alchemy.elements import create_air
from alchemy.potions import healing_potion, strength_potion
from alchemy.transmutation.recipes import lead_to_gold  # noqa: E402
from alchemy.grimoire.light_spellbook import (  # noqa: E402
    light_spell_allowed_ingredients,
    light_spell_record,
)
from alchemy.grimoire.light_validator import validate_ingredients  # noqa: E402

heal = healing_potion

__all__ = [
    "create_air",
    "healing_potion",
    "strength_potion",
    "heal",
    "lead_to_gold",
    "light_spell_allowed_ingredients",
    "light_spell_record",
    "validate_ingredients",
]

# # file che trasforma una directory in un pacchetto riconoscibile
# # dall'interprete permettendo di importare i moduli al suo interno

# # il file esegue automaticamente codice di inizializzazione ogni
# # volta che il pacchetto viene importato

# # Esportazione selettiva: può definire la variabile __all__
# # per controllare quali nomi vengono esposti quando si usa
# # from package import *

# # parte 1
# from alchemy.elements import create_air
# # partially import the alchemy module

# # parte 2
# from alchemy.potions import healing_potion, strength_potion
# heal = healing_potion  # alias

# # parte 3
# from alchemy.transmutation.recipes import lead_to_gold
# # exposes lead_to_gold on the alchemy namespace,
# # so ft_transmutation_2.py can do
# # import alchemy
# # alchemy.lead_to_gold()

# #  parte 4
# from alchemy.grimoire.light_spellbook import (
#     light_spell_allowed_ingredients, light_spell_record
# )
# from alchemy.grimoire.light_validator import validate_ingredients

# # from alchemy.grimoire.dark_spellbook import dark_spell_allowed_ingredients,
# # dark_spell_record
# # from alchemy.grimoire.dark_validator import validate_ingredients

# È un commento speciale che dice a flake8 di ignorare quella riga.
# noqa sta per "no quality assurance".

# È una lista speciale di Python che dichiara esplicitamente quali
# nomi un modulo vuole esportare pubblicamente. Serve a due cose:
# 1. Dire a flake8 che l'import è intenzionale
# — se un nome è in __all__, flake8 capisce che non è "unused",
# è una re-export.
# 2. Controllare cosa viene importato con from module import *
