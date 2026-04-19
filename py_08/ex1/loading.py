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
        try:
            mod = importlib.import_module(package)
            version = getattr(mod, "__version__", "unknown")
            print(f"  [OK] {package} ({version}) - {description} ready")
            status[package] = True
        except ImportError:
            print(f"  [MISSING] {package} - {description} NOT available")
            status[package] = False
            required_ok = False

    for package, description in optional.items():
        try:
            mod = importlib.import_module(package)
            version = getattr(mod, "__version__", "unknown")
            print(f"  [OK] {package} ({version}) - {description} ready")
            status[package] = True
        except ImportError:
            status[package] = False

    return status, required_ok


# chiamata solo semancano dei pacchetti
def show_install_instructions(status):
    """Show installation instructions for missing packages."""
    missing_package = [
        package
        for package, ok in status.items()
        if not ok and package != "requests"
    ]
    if not missing_package:
        return

    print("\n" + "=" * 60)
    print("MISSING DEPENDENCIES - Installation Instructions")
    print("=" * 60)

    print("\n--- Using pip ---")
    print("  pip install -r requirements.txt")
    print("  python3 loading.py")

    print("\n--- Using Poetry ---")
    print("  poetry install")
    print("  poetry run python loading.py")

    print("\nMissing packages:", ", ".join(missing_package))
    print("=" * 60)


def compare_package_managers():
    """Print a comparison of pip vs Poetry."""
    print("\n--- Package Manager Comparison ---")
    print(
        f"  {'Feature':<30} {'pip':<20} {'Poetry':<20}"
    )
    print("  " + "-" * 70)
    comparisons = [
        ("Dependency file", "requirements.txt", "pyproject.toml"),
        ("Lock file",       "manual",           "poetry.lock (auto)"),
        ("Virtual env",     "manual",           "automatic"),
        ("Install command", "pip install -r …", "poetry install"),
        ("Run",             "python loading.py", "poetry run python"),
    ]
    for feature, pip_val, poetry_val in comparisons:
        print(f"  {feature:<30} {pip_val:<20} {poetry_val:<20}")
    print()


def run_analysis():
    print("Processing 1000 data points...")
    import numpy as np
    import pandas as pd
    import matplotlib.pyplot as plt
    # genero i dati cpn numpy
    # li elaboro con pandas
    # salvo in un grafico con matplot
    # produce un matrix_analysis.png

    # questo crea il generatore di numeri
    rng = np.random.default_rng(42)

    data = {
        "Group A": rng.random(1000),
        "Group B": rng.random(1000)
    }
    # 2 dimensional data structure,
    # like a 2 dimensional array, or a table with rows and columns.
    df = pd.DataFrame(data)
    for line in str(df).split("\n"):
        print("     " + line)

    print("\nGenerating visualization...\n")
    df.plot(kind="hist", bins=30, alpha=0.7)
    plt.savefig("matrix_analysis.png")
    print("Analysis complete!")
    print("Results saved to: matrix_analysis.png")


def main():
    print("LOADING STATUS: Loading programs...")
    print()
    print("Checking dependencies:")

    status, required_ok = check_dependencies()

    if not required_ok:
        show_install_instructions(status)
        sys.exit(1)

    compare_package_managers()

    print("Analyzing Matrix data...")
    run_analysis()


if __name__ == "__main__":
    main()
