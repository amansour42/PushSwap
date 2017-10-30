# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: amansour <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/10/30 10:28:05 by amansour          #+#    #+#              #
#    Updated: 2017/10/30 13:40:04 by amansour         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = liblist.a

FLAGS = -Werror -Wall -Wextra

INCLUDS  = liblist.h

SRC = add_stack.c add_steps.c delete_steps.c delete_stack.c\
	  stack_properties.c steps_properties.c\
	  ft_strdup.c ft_strcpy.c ft_strlen.c\

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME):
	gcc $(FLAGS) -c $(SRC) -I $(INCLUDS)
	ar rc $(NAME) $(OBJ)
	ranlib $(NAME)

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all
