##
## HOW TO MAKE THE OBJECT FOLDER, BEFORE MAKING OBJECT FILES
##	BUT TO STILL PRINT OUT "nothing to be done for all" - WHICH DOES NOT SHOW UP
##	IF I FIRST MAKE THE FOLDER
##

# colors
RES		=	\033[0m
GRN		=	\033[32m
YEL		=	\033[33m
BLU	=	\033[34m
RED		=	\033[31m
# UP		=	\033[A
# CUT		=	\033[K



NAME		=	phonebook
CC			=	c++
CFLAGS		=	-std=c++98 -Wall -Wextra -Werror 

MAKEFLAGS		+= --no-print-directory 


LIBFT_DIR		=	libft
LIBFT_A			=	$(LIBFT_DIR)/libft.a


CPP_FILES	=	main.cpp				\
				utils.cpp				\
				get_name_and_number.cpp 


OBJ_DIR 	=	obj_dir
OBJ_FILES	=	$(patsubst %, $(OBJ_DIR)/%, $(CPP_FILES:.cpp=.o))

HEADERS		=	utils.hpp


all:		$(NAME)
	@printf "$(GRN)PHONEBOOK DONE\n$(RES)"
	@printf "$(YEL)\n --- CPP MODULE00, EX01: PHONEBOOK --- \n\n$(RES)"


##### $(LIBFT_A):	$(LIBFT_OBJ) $(LIBFT_DIR)/libft.h
#  $(LIBFT_A):					$(LIBFT_DIR)/libft.h
 $(LIBFT_A):
	@printf "$(GRN)MAKE LIBFT \n$(RES)"
	@cd $(LIBFT_DIR); make ; cd -;
	@printf "$(GRN)MAKE PHONEBOOK \n$(RES)"



#compile the objects
$(OBJ_DIR)/%.o:		%.cpp	$(HEADERS)
	@printf "$(BLU)  make $@ \n$(RES)"
	@if [ ! -d "$(OBJ_DIR)" ]; then \
		mkdir -p $(OBJ_DIR)/; \
	fi;
	@c++ -c $(CFLAGS) -o $@ $<


#compile the executable
$(NAME):	$(LIBFT_A) $(OBJ_FILES)
	@c++ $(CFLAGS) $(OBJ_FILES) $(LIBFT_A) -o $(NAME)


#clean rule
clean:
	@rm -f $(OBJ_FILES)
	@rm -rf $(OBJ_DIR)


#fclean rule
fclean: libftclean clean
	@rm -f $(NAME)

libftclean:
	@cd $(LIBFT_DIR); make fclean; cd - ;

re: fclean all

.PHONY: all clean fclean re
