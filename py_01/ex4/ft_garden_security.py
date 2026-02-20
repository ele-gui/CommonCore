class Plant:
    def __init__(self, name, height, age):
        self.name = name
        self.height = height
        self.age = age
	
	def set_height(self, new_height:
		self.height = new_height

	def set_age(self, new_age):
		self.age = new_age

	def encapsulation(self):
		return (f"Plant created: {self.name}")

	def get_height(self):
		return self.height

	def get_age(self):
		return self.age

"""	def set_height(self):

	def set_age(self):

	def encapsulation(self)
		return (f"Plant creted: {self.name}")"""


def ft_garden_security():
	print("=== Garden Security System ===")
    p1 = Plant("Rose", 25, 30)

    print(f"Current plant: ")



if __name__ == "__main__":
	ft_garden_security()