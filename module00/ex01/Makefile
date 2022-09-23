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



LIBFT_DIR		=	libft
# LIBFT_SRC		=	$(LIBFT_DIR)/ft_atoi.c
# LIBFT_OBJ		=	$(LIBFT_SRC:%.c=%.o)
LIBFT_A			=	$(LIBFT_DIR)/libft.a


CPP_FILES	=	main.cpp				\
				utils.cpp				\
				get_name_and_number.cpp 
#				ft_atoi.cpp				\
#				ft_isdigit.cpp


OBJ_DIR 	=	obj_dir
OBJ_FILES	=	$(patsubst %, $(OBJ_DIR)/%, $(CPP_FILES:.cpp=.o))

HEADERS		=	utils.hpp


all:		$(NAME)


# $(LIBFT_A):	$(LIBFT_OBJ) $(LIBFT_DIR)/libft.h
$(LIBFT_A):					$(LIBFT_DIR)/libft.h
	cd $(LIBFT_DIR); make ; cd -;



#compile the objects
$(OBJ_DIR)/%.o:		%.cpp	$(HEADERS)
#	@printf "$(GRN)  make object \n\n$(RES)"
	@if [ ! -d "$(OBJ_DIR)" ]; then \
		mkdir -p $(OBJ_DIR)/; \
	fi;
	@c++ -c $(CFLAGS) -o $@ $<


#compile the executable
$(NAME):	$(LIBFT_A) $(OBJ_FILES)
# $(NAME):			   $(OBJ_FILES)
	@c++ $(CFLAGS) $(OBJ_FILES) $(LIBFT_A) -o $(NAME)
	# @c++ $(CFLAGS) $(OBJ_FILES)  		   -o $(NAME)
	@printf "$(GRN)\n --- CPP MODULE00, EX01: PHONEBOOK --- \n\n$(RES)"


#clean rule
clean:
	rm -f $(OBJ_FILES)
	rm -rf $(OBJ_DIR)


#fclean rule
fclean: libftclean clean
	rm -f $(NAME)

libftclean:
	cd $(LIBFT_DIR); make fclean; cd - ;

re: fclean all

.PHONY: all clean fclean re
