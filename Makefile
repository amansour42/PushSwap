# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: amansour <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/10/30 10:23:40 by amansour          #+#    #+#              #
#    Updated: 2017/10/31 16:09:24 by amansour         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

BIN		= ./executable/

all:
	mkdir -p $(BIN)
	@echo " __      __      __         __   __ "
	@echo "|__)| | |_  |_| |__  | | | |__| |__)" 
	@echo "|   |_| __| | |  __| |_|_| |  | |   " 
	@echo "~~ ~~~ ~~~ ~~~ ~~~~ ~~~~~ ~~~~  ~~~ "
	make -C checker
	cp ./checker/checker $(BIN)
	make -C push_swap
	cp ./push_swap/push_swap $(BIN)

clean:
	rm -rf $(BIN)
	make -C checker clean
	make -C push_swap clean

fclean:
	rm -rf $(BIN)
	make -C checker fclean
	make -C push_swap fclean

re: fclean all
