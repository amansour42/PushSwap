# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: amansour <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/10/17 11:35:32 by amansour          #+#    #+#              #
#    Updated: 2017/10/19 15:51:21 by amansour         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

LDFLAGS = -L libft
LDLIBS = -lft
FLAGS = -Werror -Wall -Wextra -g

SRC_PATH = ./src
OBJ_PATH = ./obj
INCLUD  = ./include
LIB = libft/libft.a

SRC = add_end_lists.c algo.c delete_alink.c display_stack.c find_pairs.c\
	  main.c nbr_cases.c tools_lists.c add_first_lists.c check_order.c\
	  delete_list.c fill_pile.c instructions.c msg.c sort.c short_way.c\


OBJ = $(addprefix $(OBJ_PATH)/,$(SRC:.c=.o))

all: $(NAME)

$(NAME): $(LIB) $(OBJ)
	gcc $(OBJ) $(LDFLAGS) $(LDLIBS) -o $(NAME)
	@echo "\033[1;34mChecker\t\033[1;33mCompilation\t\033[0;32m[OK]\033[0m"

$(LIB):
	@make -C libft

#extra:
#	@mkdir -p $(OBJ_PATH)

$(OBJ_PATH)/%.o: $(SRC_PATH)/%.c
	@mkdir -p $(OBJ_PATH)
	gcc $(FLAGS) -I $(INCLUD) -o $@ -c $<

clean:
	@rm -rf $(OBJ)
	@rm -rf $(OBJ_PATH)
	@make -C libft clean

fclean: clean
	@rm -f $(NAME) $(LIB)

re: fclean all
