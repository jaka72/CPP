##############################################
#	DEFAULT
##############################################

NAME		=	megaphone
CC			=	c++
CFLAGS		=	-std=c++98 -g -Wall -Wextra -Werror 

CPP_FILES	=	megaphone.cpp


OBJ_DIR 	=	obj_dir
# OBJ_FILES	=	$(CPP_FILES:.cpp=.o)
# OBJ			=	$(addprefix $(OBJ_DIR)/, $(OBJ_FILES))
OBJ_FILES	=	$(patsubst %, $(OBJ_DIR)/%, $(CPP_FILES:.cpp=.o))


all:	$(NAME)

#compile the objects
$(OBJ_DIR)/%.o:		%.cpp
	@if [ ! -d "$(OBJ_DIR)" ]; then \
		mkdir -p $(OBJ_DIR)/; \
	fi;
	$(CC) -c $(CFLAGS) -o $@ $<


#compile the executable
$(NAME):	$(OBJ_FILES)
	c++ $(CFLAGS) $(OBJ_FILES) -o $(NAME)
	@printf "$(GRN)\n --- CPP MODULE 04, EX00 --- \n\n$(RES)"


#clean rules
clean:
	rm -f $(OBJ_FILES)
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
