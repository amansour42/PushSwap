# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: amansour <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/10/17 11:35:32 by amansour          #+#    #+#              #
#    Updated: 2017/10/18 09:21:27 by amansour         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = check

LDFLAGS = -L libft
LDLIBS = -lft
FLAGS = -Werror -Wall -Wextra -g

SRC_PATH = ./checker
OBJ_PATH = ./obj
INCLUD  = ./include
LIB = libft/libft.a

SRC = main.c fill_pile.c msg.c digit_test.c\
	  nbr_cases.c check_order.c instructions.c\
      read_steps.c apply.c add_lists.c add_first.c\
      delete_alink.c delete_list.c isempty_list.c\

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

re: fclean all
