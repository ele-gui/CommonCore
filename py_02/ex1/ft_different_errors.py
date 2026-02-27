def value_error():
    try:
        value = int("abc")  # This will raise a ValueError
    except ValueError as e:
        raise ValueError("Caught ValueError: invalid literal for int()\n")


def division_error():
    try: 
        res = 10 / 0
    except ZeroDivisionError as e:
        raise ZeroDivisionError("Caught ZeroDivisionError: division by zero\n")


def file_error():
    try:
        open("missing.txt")
    except FileNotFoundError as e:
        raise FileNotFoundError("Caught FileNotFoundError: No such file 'missing.txt'\n")


def key_error():
    try:
        my_dict = {
            "Flower": "Rose",
            "Tree": "Oak"
        }        
        plant = "missing\_plant"
        print(my_dict[plant])

    except KeyError as e:
        raise Exception("Caught KeyError: 'missing\_plant'\n")
        ##per KeyError e' normale stampare con le virgolette.
        #per evitarlo usare raise Exception oppure print() invece di raise


def garden_operations():
    try:
        print("Testing ValueError...")
        value_error()
    except ValueError as e:
        print(e)

    try: 
        print("Testing ZeroDivisionError...")
        division_error()
    except ZeroDivisionError as e:
        print(e)
    
    try:
        print("Testing FileNotFoundError...")
        file_error()
    except FileNotFoundError as e:
        print(e)
    
    try:
        print("Testing KeyError...")
        key_error()
    except KeyError as e:
        print(e)

    
    




def test_error_types():
    
    print("=== Garden Error Types Demo ===\n")
    try:
        garden_operations()
    
    except ValueError as e:
        print(e)
    except ZeroDivisionError as e:
        print(e)

    except FileNotFoundError as e:
        print(e)

    except Exception as e:
        print(e)
    
    print("Testing multiple errors together...")
    for func in [value_error, division_error, file_error, key_error]:
        try:
            func()
        except (ValueError, ZeroDivisionError, FileNotFoundError, Exception):
            print("Caught an error, but program continues!")

#da sistemare la stampa

if __name__ == "__main__":
    test_error_types()