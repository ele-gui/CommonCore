if __name__ == "__main__":
    print("=== CYBER ARCHIVES - CRISIS RESPONSE SYSTEM ===\n")

    filename = "lost_archive.txt"
    print("CRISIS ALERT: Attempting access to 'lost_archive.txt'...")
    try:
        with open(filename, "r") as file:
            content = file.read()
        print("SUCCESS: Archive recovered ")
    except FileNotFoundError:
        print("RESPONSE: Archive not found in storage matrix")
    except PermissionError:
        print("RESPONSE: Security protocols deny access")
    except Exception:
        print("RESPONSE: Security protocols deny access")
    finally:
        print("STATUS: Crisis handled, system stable")

    filename = "classified_vault.txt"
    print(f"\nCRISIS ALERT: Attempting access to '{filename}'...")
    try:
        with open(filename, "r") as file:
            content = file.read()
        print("RESPONSE: Archive recovered")
    except (FileNotFoundError, PermissionError, Exception): #prende come errore filenotfound
        print("RESPONSE: Security protocols deny access")
    finally:
        print("STATUS: Crisis handled, security maintained")

    filename = "standard_archive.txt"
    print(f"\nROUTINE ACCESS: Attempting access to '{filename}'...")
    try:
        with open(filename, "r") as file:
            content = file.read()
        print(f"SUCCESS: Archive recovered - ''{content}''")
    except (FileNotFoundError, PermissionError, Exception):
        print("RESPONSE: Security protocols deny access")
    finally:
        print("STATUS: Normal operations resumed")

    print("\nAll crisis scenarios handled successfully. Archives secure.")