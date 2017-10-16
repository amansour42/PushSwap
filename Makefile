# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: amansour <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/05/03 18:46:13 by amansour          #+#    #+#              #
#    Updated: 2017/10/16 15:51:25 by amansour         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

LDFLAGS = -L libft
LDLIBS = -lft
FLAGS = -Werror -Wall -Wextra

SRC_PATH = ./pushswap
OBJ_PATH = ./obj
INCLUD  = ./include
LIB = libft/libft.a

SRC = main.c fill_pile.c msg.c digit_test.c\
	  nbr_cases.c sort.c check_order.c\
	  algo_steps.c instructions.c to_write.c\

OBJ = $(addprefix $(OBJ_PATH)/,$(SRC:.c=.o))

all: $(NAME)

$(NAME): $(LIB) $(OBJ)
	gcc $(OBJ) $(LDFLAGS) $(LDLIBS) -o $(NAME)

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

re: fclean
	make
