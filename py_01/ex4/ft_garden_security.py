class SecurePlant:
    def __init__(self, name) -> None:
        self.name = name
        self.__height = 0
        self.__age = 0
    
    def set_height(self, height) -> None:
        if height < 0:
            print(f"Invalid operation attempted: height {height}cm [REJECTED]")
            print("Security: Negative height rejected")
        else:
            self.__height = height
            print(f"Height updated: {height}cm [OK]")

    def get_height(self) -> int:
        return self.__height
    
    def set_age(self, age) -> None:
        if age < 0:
            print(f"Invalid operation attempted: age {age} days [REJECTED]")
            print("Security: Negative age rejected")
        else:
            self.__age = age
            print(f"Age updated: {age} days [OK]")

    def get_age(self) -> int:
        return self.__age
    
    def encapsulation(self):
        print (f"Current plant: {self.name} ({self.__height}cm, {self.__age} days)")


def ft_garden_security():
    print("=== Garden Security System ===")
    p1 = SecurePlant("Rose")
    print(f"Plant created: {p1.name}")
    p1.set_height(25)
    p1.set_age(30)
    print()
    p1.set_height(-5)
    print()
    p1.encapsulation()


if __name__ == "__main__":
    ft_garden_security()