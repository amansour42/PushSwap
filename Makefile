# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: amansour <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/10/30 10:23:40 by amansour          #+#    #+#              #
#    Updated: 2017/11/10 12:20:50 by amansour         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

all:
	@echo "|__)| | |_  |_| |__  | | | |__| |__)" 
	@echo "|   |_| __| | |  __| |_|_| |  | |   " 
	@echo "~~ ~~~ ~~~ ~~~ ~~~~ ~~~~~ ~~~~  ~~~ "
	make -C check
	cp ./check/checker .
	make -C push
	cp ./push/push_swap .

clean:

	make -C check clean
	make -C push clean

fclean:
	rm -f push_swap
	rm -f checker
	make -C check fclean
	make -C push fclean

re: fclean all
