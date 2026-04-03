# parte 3
from alchemy.transmutation.recipes import lead_to_gold

# from alchemy import lead_to_gold crea circular import
# alchemy imports transmutation, transmutation imports alchemy



""" 
alchemy/__init__.py
    └── imports from alchemy.transmutation.recipes  ✓

alchemy/transmutation/__init__.py
    └── imports from alchemy.transmutation.recipes  ✓  (not from alchemy!)
"""