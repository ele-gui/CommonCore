def ft_count_harvest_iterative():
    d_harvest = int(input("Days until harvest: "))
    count = 1
    while count <= d_harvest:
        print("Day ", count)
        count += 1
    print("Harvest time!")


ft_count_harvest_iterative()
