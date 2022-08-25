##
## HOW TO MAKE THE OBJECT FOLDER, BEFORE MAKING OBJECT FILES
##	BUT TO STILL PRINT OUT "nothing to be done for all" - WHICH DOES NOT SHOW UP
##	IF I FIRST MAKE THE FOLDER

## MinGW32-make    Make on Windows


NAME		=	phonebook

OBJ_DIR 	=	obj_dir

CPP_FILES	=	main.cpp	\
				utils.cpp
OBJ_FILES	=	$(patsubst %, $(OBJ_DIR)/%, $(CPP_FILES:.cpp=.o))
#OBJ_FILES	=	$(CPP_FILES:.cpp=.o)


# HEADER	=	someheader.h			\
# 				typedef.h

CFLAGS		=	-std=c++98 -Wall -Wextra -Werror 


# all:		make_obj_dir	$(NAME)
all:		$(NAME)


### for folders for object files
# make_obj_dir:
# 	@mkdir -p $(OBJ_DIR)/


# $(NAME):	$(LIBFT_A) $(OBJ) 	$(HEADER)
$(NAME):	$(OBJ_FILES)	#$(HEADER)
	@c++ $(CFLAGS) $(OBJ_FILES) -o $(NAME)
#	gcc $(CFLAGS) $(OBJ) -I$(RLFLAG)/include -L$(RLFLAG)/lib -lreadline $(LIBFT_A) -o $(NAME)



$(OBJ_DIR)/%.o:		%.cpp 	#$(HEADER)
	@c++ -c $(CFLAGS) -o $@ $<
#	gcc -c $(CFLAGS) -I$(RLFLAG)/include -o $@ $<

clean:
	rm -f $(OBJ_FILES)
#	rm -rf $(OBJ_DIR)

fclean: clean
	rm -f $(NAME)

re: fclean all
