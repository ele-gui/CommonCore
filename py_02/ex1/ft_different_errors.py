



def garden_operations():
    try:
        value = int("abc")  # This will raise a ValueError
    except ValueError as e:
        print("Caught ValueError: invalid literal for int()")

    try: 
        res = 10 / 0
    except ZeroDivisionError as e:
        print("Caught ZeroDivisionError: division by zero")



def test_error_types():
