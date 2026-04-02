# file che trasforma una directory in un pacchetto riconoscibile
# dall'interprete permettendo di importare i moduli al suo interno

# il file esegue automaticamente codice di inizializzazione ogni
# volta che il pacchetto viene importato

# Esportazione selettiva: può definire la variabile __all__
# per controllare quali nomi vengono esposti quando si usa
# from package import *

from alchemy.elements import create_air
from alchemy.potions import healing_potion, strength_potion
""" This exposes create_air, strength_potion, heal through
the alchemy package interface — but not create_earth """

heal = healing_potion  # alias

""" .
|-- alchemy
| |-- __init__.py
| |-- elements.py
| |-- grimoire
| | |-- __init__.py
| | |-- dark_spellbook.py
| | |-- dark_validator.py
| | |-- light_spellbook.py
| | ‘-- light_validator.py
| |-- potions.py
| ‘-- transmutation
| |-- __init__.py
| ‘-- recipes.py
|-- elements.py
|-- ft_alembic_0.py
|-- ft_alembic_1.py
|-- ft_alembic_2.py
|-- ft_alembic_3.py
|-- ft_alembic_4.py
|-- ft_alembic_5.py
|-- ft_distillation_0.py
|-- ft_distillation_1.py
|-- ft_kaboom_0.py
|-- ft_kaboom_1.py
|-- ft_transmutation_0.py
|-- ft_transmutation_1.py
‘-- ft_transmutation_2.py
 """
