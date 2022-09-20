##
## HOW TO MAKE THE OBJECT FOLDER, BEFORE MAKING OBJECT FILES
##	BUT TO STILL PRINT OUT "nothing to be done for all" - WHICH DOES NOT SHOW UP
##	IF I FIRST MAKE THE FOLDER
##

# colors
RES		=	\033[0m
GRN		=	\033[32m
YELLOW	=	\033[33m
BLUE	=	\033[34m
RED		=	\033[31m
# UP		=	\033[A
# CUT		=	\033[K



NAME		=	phonebook
CC			=	c++
CFLAGS		=	-std=c++98 -Wall -Wextra -Werror 

CPP_FILES	=	main.cpp	\
				utils.cpp	\
				get_name_and_number.cpp

OBJ_DIR 	=	obj_dir
OBJ_FILES	=	$(patsubst %, $(OBJ_DIR)/%, $(CPP_FILES:.cpp=.o))

HEADERS		=	utils.hpp




all:		$(NAME)

#compile the objects
$(OBJ_DIR)/%.o:		%.cpp	$(HEADERS)
#	@printf "$(GRN)  make object \n\n$(RES)"
	@if [ ! -d "$(OBJ_DIR)" ]; then \
		mkdir -p $(OBJ_DIR)/; \
	fi;
	@c++ -c $(CFLAGS) -o $@ $<


#compile the executable
$(NAME):	$(OBJ_FILES)
	@c++ $(CFLAGS) $(OBJ_FILES) -o $(NAME)
	@printf "$(GRN)\n --- CPP MODULE 04, EX01 --- \n\n$(RES)"


#clean rule
clean:
	rm -f $(OBJ_FILES)
	rm -rf $(OBJ_DIR)


#fclean rule
fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
