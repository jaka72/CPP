# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: jaka <jaka@student.codam.nl>                 +#+                      #
#                                                    +#+                       #
#    Created: 2022/09/21 18:29:17 by jaka          #+#    #+#                  #
#    Updated: 2022/09/25 18:49:30 by jaka          ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

# colors
RES		=	\033[0m
GRN		=	\033[32m
YEL	=	\033[33m
BLU	=	\033[34m
RED		=	\033[31m
# UP		=	\033[A
# CUT		=	\033[K



NAME		=	brainz
CC			=	c++
CFLAGS		=	-std=c++98 -Wall -Wextra -Werror 

CPP_FILES	=	main.cpp		\
				newZombie.cpp	\
				randomChump.cpp	\
				Zombie.cpp

OBJ_DIR 	=	obj_dir
OBJ_FILES	=	$(patsubst %, $(OBJ_DIR)/%, $(CPP_FILES:.cpp=.o))

HEADERS		=	Zombie.hpp

PRINT_MSG	= print_start

all:		$(PRINT_MSG) $(NAME)
	@printf "$(GRN)BRAINZ DONE\n$(RES)"
	@printf "$(YEL)\n --- CPP MODULE01, EX00:  BraiiinnnzzzZ --- \n\n$(RES)"


print_start:
	@printf "$(GRN)MAKE BRAINZ \n$(RES)"



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
