if __name__ == "__main__":
    print("=== CYBER ARCHIVES - VAULT SECURITY SYSTEM ===\n")

    print("Initiating secure vault access...\n")

    with open("data-generator-tools/classified_data.txt", 'r') as file1:
        print("SECURE EXTRACTION:")
        print(file1.read())

    with open("data-generator-tools/security_protocols.txt", 'w') as file2:
        print("\nSECURE PRESERVATION:")
        file2.write("[CLASSIFIED] New security protocols archived")

    with open("data-generator-tools/security_protocols.txt", 'r') as file2:
        print(file2.read())

    print("Vault automatically sealed upon completion")

    print("\nAll vault operations completed with maximum security.")
