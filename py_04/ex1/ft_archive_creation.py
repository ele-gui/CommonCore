if __name__ == "__main__":
    print("=== CYBER ARCHIVES - PRESERVATION SYSTEM ===\n")

    print("Initializing new storage unit: new_discovery.txt")
    filename = 'new_discovery.txt'
    try:
        file = open('new_discovery.txt', 'w')
        print("Storage unit created successfully...\n")
        print("Inscribing preservation data...")
        entry1 = '[ENTRY 001] New quantum algorithm discovered'
        entry2 = '[ENTRY 002] Efficiency increased by 347%'
        entry3 = '[ENTRY 003] Archived by Data Archivist trainee elguiduc'

        file.write(entry1 + '\n' + entry2 + '\n' + entry3)

        print(f'{entry1}\n{entry2}\n{entry3}')
        print("Preservation data inscribed successfully...")
        file.close()
    except Exception as e:
        print(f"Error occurred while creating storage unit: {e}")

    print("\nData inscription complete. Storage unit sealed.")
    print(f"Archive '{filename}.txt' ready for long-term preservation.")
