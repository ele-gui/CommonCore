def ft_count_harvest_recursive():
    def countdown(day, max_day):
        if day > max_day:
            print("Harvest time!")
            return
        print("Day ", day)
        countdown(day + 1, max_day)

    d_harvest = int(input("Days until harvest: "))
    countdown(1, d_harvest)


ft_count_harvest_recursive()
