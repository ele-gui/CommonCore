# parte 3
from alchemy.transmutation.recipes import lead_to_gold

__all__ = ["lead_to_gold"]
# exposes lead_to_gold on the alchemy.transmutation namespace,
# so ft_transmutation_1.py can do
# import alchemy.transmutation
# alchemy.transmutation.lead_to_gold()

# from alchemy import lead_to_gold crea circular import
# alchemy imports transmutation, transmutation imports alchemy
