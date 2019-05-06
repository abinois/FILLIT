# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abinois <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/05/03 14:39:50 by abinois           #+#    #+#              #
#    Updated: 2019/05/03 15:49:08 by edillenb         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit
CFLAGS = -Wall -Werror -Wextra
CC = gcc

SRC = $(addsuffix .c, check_input list board fillit print)

OBJ = $(SRC:.c=.o)

LIBDIR = libft

LIB = libft/libft.a

VERT = \033[32m
VIOLET = \033[35m
ROUGE = \033[31m
JAUNE = \033[33m
NOCOLOR = \033[0m

all: $(NAME)

$(NAME): Makefile fillit.h $(OBJ)
	@echo "$(VIOLET)///// COMPILATION DE LA LIB /////$(JAUNE)"
	@make -C $(LIBDIR)
	@echo "$(VERT)>>>>>> OK ! <<<<<<$(NOCOLOR)"
	@echo "$(VIOLET)///// COMPILATION DES . C /////$(JAUNE)"
	$(CC) $(CFLAGS) $(OBJ) $(LIB) -o $(NAME)
	@echo "$(VERT)>>>>>> OK ! <<<<<<$(NOCOLOR)"

clean:
	@echo "$(VIOLET)///// SUPPR DES OBJETS /////$(ROUGE)"
	rm -f $(OBJ)
	make clean -C $(LIBDIR)
	@echo "$(VERT)>>>>>> OK ! <<<<<<$(NOCOLOR)"

fclean: clean
	@echo "$(VOILET)///// SUPPR DE L'EXE /////$(ROUGE)"
	rm -f $(NAME)
	make fclean -C $(LIBDIR)
	@echo "$(VERT)>>>>>> OK ! <<<<<<$(NOCOLOR)"

re: fclean all
	@echo "$(VIOLET)///// RELINKING /////$(NOCOLOR)"
	@echo "$(VERT)>>>>>> OK ! <<<<<<$(NOCOLOR)"

.PHONY: all clean fclean re
