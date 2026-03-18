# if __name__ == "__main__":
#     print("=== CYBER ARCHIVES - DATA RECOVERY SYSTEM ===\n")

#     print("Accessing Storage Vault: ancient_fragment.txt")

#     try:
#         file = open("data-generator-tools/ancient_fragment.txt")
#         print("Connection established...")
#     except FileNotFoundError as e:
#         print("ERROR: Storage vault not found")

#     print("\nRECOVERED DATA:")
#     print(file.read())

#     file.close()
#     print("\nData recovery complete. Storage unit disconnected.")


if __name__ == "__main__":
    print("=== CYBER ARCHIVES - DATA RECOVERY SYSTEM ===\n")

    print("Accessing Storage Vault: ancient_fragment.txt")

    try:
        with open("data-generator-tools/ancient_fragment.txt") as file:
            print("Connection established...")
            print("\nRECOVERED DATA:")
            print(file.read())
            file.close()
        print("\nData recovery complete. Storage unit disconnected.")
    except FileNotFoundError as e:
        print("ERROR: Storage vault not found")

    
