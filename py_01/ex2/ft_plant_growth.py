# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    ft_plant_growth.py                                 :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: elguiduc <elguiduc@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/01/25 11:34:02 by elguiduc          #+#    #+#              #
#    Updated: 2026/01/25 12:32:18 by elguiduc         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

import sys
import os

sys.path.append(os.path.abspath(os.path.join(os.path.dirname(__file__), "..")))

from ex1.ft_garden_data import Plant

# aggiungo i metodi grow() e age() alla classe Plant
def add_behaviour(plant):
	def grow():
		plant.height += 1
	def age_one_day():
		plant.age += 1
	plant.grow = grow
	plant.age_one_day = age_one_day
	return (plant)

if __name__ == "__main__":
	print("=== Day 1 ===")
	p1 = Plant("Rose", 25, 30)
	# p2 = Plant("Sunflower", 80, 45)
	# p3 = Plant("Cactus", 15, 120)
	# plants = [p1, p2, p3]
	print(p1.get_info())
	height_before = p1.height
	p1 = add_behaviour(p1)

	print("=== Day 7 ===")
	for day in range(0, 6):
		p1.grow()
		p1.age_one_day()
	print(p1.get_info())
	height_after = p1.height
	
	growth = height_after - height_before
	print(f"Growth this week: +{growth}cm")
