# requirements.txt (for pip) and pyproject.toml (for Poetry)

import sys
import importlib


# Check which dependencies are available and return status dict
def check_dependencies():

    required = {
        "pandas": "Data manipulation",
        "numpy": "Numerical computation",
        "matplotlib": "Visualization"
    }

    optional = {
        "requests": "Network access"
    }

    status = {}
    required_ok = True

    for package, description in required.items():
        spec = importlib.util.find_spec(package)
        if spec is not None:
            mod = importlib.import_module(package)
            version = getattr(mod, "__version__", "unknown")
            print(f"  [OK] {package} ({version}) - {description} ready")
            status[package] = True

        else:
            print(f"  [MISSING] {package} - {description} NOT available")
            status[package] = False
            required_ok = False

    for package, description in optional.items():
        spec = importlib.util.find_spec(package)
        if spec is not None:
            mod = importlib.import_module(package)
            version = getattr(mod, "__version__", "unknown")
            print(f"  [OK] {package} ({version}) - {description} ready")
            status[package] = True
        else:
            status[package] = False

    return status, required_ok


def show_install_instructions(status):
    """Show installation instructions for missing packages."""
    pass


def compare_package_managers():
    """Print a comparison of pip vs Poetry."""
    pass


def run_analysis():
    """Run Matrix data analysis using numpy, pandas, and matplotlib."""
    pass


def main():
    pass


# main() — entry point, orchestra tutto. Chiama le altre in sequenza.
# check_dependencies() — controlla quali pacchetti sono installati, restituisce (status, all_ok).
# show_install_instructions() — chiamata solo se mancano pacchetti, stampa i comandi pip/Poetry e fa sys.exit(1).
# compare_package_managers() — stampa la tabella comparativa pip vs Poetry.
# run_analysis() — il cuore del programma: genera i dati con numpy, li elabora con pandas, salva il grafico con matplotlib