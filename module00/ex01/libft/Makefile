# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: jmurovec <jmurovec@student.codam.nl>         +#+                      #
#                                                    +#+                       #
#    Created: 2020/11/29 18:54:57 by jmurovec      #+#    #+#                  #
#    Updated: 2022/09/24 16:11:20 by jaka          ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

# colors
RES		=	\033[0m
GRN		=	\033[32m
YEL		=	\033[33m
BLU	=	\033[34m
RED		=	\033[31m
# UP		=	\033[A
# CUT		=	\033[K


NAME			= libft.a
CC				= c++
# CC			= gcc
CFLAGS			= -Wall -Wextra -Werror -I.
RM				= rm -f

# MAKEFLAGS		+= --no-print-directory 


CPP_FILES	       =	ft_atoi.cpp \
						ft_isdigit.cpp

OBJ_DIR			= obj_dir
OBJ_FILES		= $(patsubst %, $(OBJ_DIR)/%, $(CPP_FILES:.cpp=.o))
# OBJ_FILES			= $(C_FILES:.c=.o)

HEADERS			= libft.h


all:	$(NAME)
	@printf "$(GRN)LIBFT DONE\n$(RES)"


$(OBJ_DIR)/%.o:			%.cpp	$(HEADERS)
	@printf "$(BLU)  make $@\n$(RES)"
	@if [ ! -d "$(OBJ_DIR)" ]; then \
		mkdir -p $(OBJ_DIR)/; \
	fi;
	@$(CC) -c $(CFLAGS) -o $@ $<




$(NAME):	$(OBJ_FILES)
	@ar rcs $(NAME) $(OBJ_FILES)
	


clean:
	@$(RM) -rf $(OBJ_DIR)

fclean:			clean
	@$(RM) $(NAME)

re:				fclean $(NAME)

.PHONY:			all clean fclean re
