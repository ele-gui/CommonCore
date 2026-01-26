# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    ft_harvest_total.py                                :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: elguiduc <elguiduc@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/01/24 18:25:42 by elguiduc          #+#    #+#              #
#    Updated: 2026/01/24 18:28:27 by elguiduc         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

def ft_harvest_total():
    d1 = int(input("Day 1 harvest: "))
    d2 = int(input("Day 2 harvest: "))
    d3 = int(input("Day 3 harvest: "))
    sum = d1 + d2 + d3
    print("Total harvest:", sum)
