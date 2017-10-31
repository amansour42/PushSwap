# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: amansour <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/10/30 10:28:05 by amansour          #+#    #+#              #
#    Updated: 2017/10/31 16:09:42 by amansour         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

LDFLAGS_LIB = -L ../libft
LDLIBS = -lft
LDFLAGS_LIST = -L ../liblist
LDLIST = -llist
FLAGS = -Werror -Wall -Wextra

SRC_PATH = ./src
OBJ_PATH = ./obj
INCLUD  = pushswap.h
LIB = ../libft/libft.a
LIBLIST = ../liblist/liblist.a
SRC = algo_min.c algo_max.c algo_med.c algo_normal.c checking.c display_stack.c\
	  display_steps.c env.c main.c fill_stack.c instructions.c push_to_a.c\
	  quick_sort.c sort.c\

OBJ = $(addprefix $(OBJ_PATH)/,$(SRC:.c=.o))

all: $(NAME)

$(NAME): $(LIB) $(LIBLIST) $(OBJ)
	gcc $(OBJ) $(LDFLAGS_LIB) $(LDLIBS) $(LDFLAGS_LIST) $(LDLIST) -o $(NAME)
	@echo "\033[1;34mPushswap\t\033[1;33mCompilation\t\033[0;32m[OK]\033[0m"

$(LIB):
	@make -C ../libft

$(LIBLIST):
	@make -C ../liblist/.

$(OBJ_PATH)/%.o: $(SRC_PATH)/%.c
	@mkdir -p $(OBJ_PATH)
	gcc $(FLAGS) -I $(INCLUD) -o $@ -c $<

clean:
	@rm -rf $(OBJ)
	@rm -rf $(OBJ_PATH)
	@make -C ../libft clean
	@make -C ../liblist clean

fclean: clean
	@rm -f $(NAME) $(LIB) $(LIBLIST)

re: fclean all
