# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: jaka <jaka@student.codam.nl>                 +#+                      #
#                                                    +#+                       #
#    Created: 2022/09/21 18:29:17 by jaka          #+#    #+#                  #
#    Updated: 2022/12/03 19:38:18 by jaka          ########   odam.nl          #
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
CFLAGS		=	-std=c++98 -Wall -Wextra -Werror  #  -Wshadow -Wno-shadow     -O2   -Ofast


CPP_FILES	=	main.cpp	\
				Warlock.cpp	\
				SpellBook.cpp \
				ASpell.cpp Fwoosh.cpp Hokus.cpp Polymorph.cpp Fireball.cpp \
				ATarget.cpp Dummy.cpp BrickWall.cpp \
				TargetGenerator.cpp
				
				

OBJ_DIR 	=	obj_dir
OBJ_FILES	=	$(patsubst %, $(OBJ_DIR)/%, $(CPP_FILES:.cpp=.o))

HEADERS		= 	Warlock.hpp \
				SpellBook.hpp \
				ASpell.hpp Fwoosh.hpp Hokus.hpp Polymorph.hpp Fireball.hpp \
				ATarget.hpp Dummy.hpp BrickWall.hpp \
				TargetGenerator.hpp




all:		$(NAME)
	@printf "$(GRN)DONE\n$(RES)"
	@printf "$(YEL)\n --- CPP EXAM 05 - EX01 --- \n\n$(RES)"

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
