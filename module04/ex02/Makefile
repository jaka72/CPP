# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: jaka <jaka@student.codam.nl>                 +#+                      #
#                                                    +#+                       #
#    Created: 2022/09/21 18:29:17 by jaka          #+#    #+#                  #
#    Updated: 2022/10/21 13:28:18 by jmurovec      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

# colors
RES		=	\033[0m
GRN		=	\033[32m
YEL		=	\033[33m
BLU		=	\033[34m
RED		=	\033[31m
# UP		=	\033[A
# CUT		=	\033[K



NAME		=	a.out

CC			=	c++
CFLAGS		=	-std=c++98 -Wall -Wextra -Werror		# -Wshadow -Wno-shadow		-O2 -Ofast

CPP_FILES	=	main.cpp Animal.cpp Cat.cpp Dog.cpp WrongAnimal.cpp WrongCat.cpp Brain.cpp
				
OBJ_DIR		=	obj_dir
OBJ_FILES	=	$(patsubst %, $(OBJ_DIR)/%, $(CPP_FILES:.cpp=.o))


HEADERS		=	Animal.hpp Cat.hpp Dog.hpp WrongAnimal.hpp WrongCat.hpp Brain.hpp



all:		$(NAME)
	@printf "$(GRN)DONE\n$(RES)"
	@printf "$(YEL)\n --- CPP MODULE04, EXCERCISE 00 --- \n\n$(RES)"


#compile the objects
$(OBJ_DIR)/%.o:		%.cpp	$(HEADERS)
	@printf "$(BLU)  make $@ \n$(RES)"
	@if [ ! -d "$(OBJ_DIR)" ]; then \
		mkdir -p $(OBJ_DIR)/; \
	fi;
	@c++ -c $(CFLAGS) -o $@ $<


#compile the executable
$(NAME):	$(OBJ_FILES)
	@c++ $(CFLAGS) $(OBJ_FILES) -o $(NAME)


#clean rule
clean:
	rm -f $(OBJ_FILES)
	rm -rf $(OBJ_DIR)


#fclean rule
fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
