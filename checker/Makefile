# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: amansour <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/10/17 11:35:32 by amansour          #+#    #+#              #
#    Updated: 2017/10/31 15:58:10 by amansour         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = checker

LDFLAGS_LIB = -L ../libft
LDLIBS = -lft
LDFLAGS_LIST = -L ../liblist
LDLIST = -llist
FLAGS = -Werror -Wall -Wextra

SRC_PATH = ./src
OBJ_PATH = ./obj
INCLUD  = checker.h
LIB = ../libft/libft.a
LIBLIST = ../liblist/liblist.a
SRC = main.c fill_stack.c\
	  check_order.c instructions.c\
      read_steps.c apply.c\


OBJ = $(addprefix $(OBJ_PATH)/,$(SRC:.c=.o))

all: $(NAME)

$(NAME): $(LIB) $(LIBLIST) $(OBJ)
	gcc $(OBJ) $(LDFLAGS_LIB) $(LDLIBS) $(LDFLAGS_LIST) $(LDLIST) -o $(NAME)
	@echo "\033[1;34mChecker\t\t\033[1;33mCompilation\t\033[0;32m[OK]\033[0m"

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
