NAME		= main

CC			= c++
FLAGS		= -Wall -Werror -Wextra -std=c++98

H_FILES		=	Weapon.hpp HumanA.hpp HumanB.hpp


C_FILES		=	main.cpp	\
				Weapon.cpp	\
				HumanA.cpp	\
				HumanB.cpp

O_FILES		= $(C_FILES:.cpp=.o)



all:		$(NAME)

$(NAME):	$(O_FILES)
	$(CC) $(FLAGS) -o $(NAME) $(O_FILES)
