import sys
import os
import site


# CAPIRE DA DOVE STO LANCIANDO IL PROGRAMMA
# Metodo 1: variabile d'ambiente
if os.environ.get("VIRTUAL_ENV"):
    print("\nMATRIX STATUS: Welcome to the construct")
    full_path = os.environ["VIRTUAL_ENV"]

    print("\nCurrent Python:", sys.executable)
    print("Virtual Environment:", os.path.basename(full_path))
    print("Environment Path:", full_path)

    print("\nSUCCESS: You're in an isolated environment!")
    print("Safe to install packages without affecting the global system.")

    print("\nPackage installation path:")
    print(site.getsitepackages()[0])
else:
    print("\nMATRIX STATUS: You're still plugged in")

    print("\nCurrent Python:", sys.executable)
    print("Virtual Environment: None detected")

    print("\nWARNING: You're in the global environment!")
    print("The machines can see everything you install.")

    print("\nTo enter the construct, run:")
    print("  python -m venv matrix_env")
    print("  source matrix_env/bin/activate  # On Unix")
    print("  matrix_env\\Scripts\\activate # On Windows")

    print("\nThen run this program again")

# # Metodo 2: confronta sys.prefix con sys.base_prefix
# if sys.prefix != sys.base_prefix:
#     print("Sei nel venv:", sys.prefix)
# else:
#     print("Sei nel Python di sistema")
