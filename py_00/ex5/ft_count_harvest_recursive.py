# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    ft_count_harvest_recursive.py                      :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: elguiduc <elguiduc@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/01/24 18:51:00 by elguiduc          #+#    #+#              #
#    Updated: 2026/01/24 22:07:08 by elguiduc         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

def ft_count_harvest_recursive():
    def countdown(day, max_day):
        if day > max_day:
            print("Harvest time!")
            return
        print("Day ", day)
        countdown(day + 1, max_day)

    d_harvest = int(input("Days until harvest: "))
    countdown(1, d_harvest)
