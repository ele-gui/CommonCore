# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    ft_count_harvest_iterative.py                      :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: elguiduc <elguiduc@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/01/24 18:46:25 by elguiduc          #+#    #+#              #
#    Updated: 2026/01/24 18:50:15 by elguiduc         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

def ft_count_harvest_iterative():
    d_harvest = int(input("Days until harvest: "))
    count = 1
    while count <= d_harvest:
        print("Day ", count)
        count += 1
    print("Harvest time!")