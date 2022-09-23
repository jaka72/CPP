# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: jmurovec <jmurovec@student.codam.nl>         +#+                      #
#                                                    +#+                       #
#    Created: 2020/11/29 18:54:57 by jmurovec      #+#    #+#                  #
#    Updated: 2022/09/23 18:49:35 by jaka          ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME			= libft.a

MANDATORY       =	ft_atoi.c \
					ft_isdigit.c

OBJS			= $(MANDATORY:.c=.o)

CC				= c++ #gcc
RM				= rm -f
CFLAGS			= -Wall -Wextra -Werror -I.

.c.o:
				${CC} ${CFLAGS} -g -c $< -o ${<:.c=.o}

all:			$(NAME)

$(NAME):		$(OBJS)
				ar rcs $(NAME) $(OBJS)
so:
				gcc -fPIC -Wall -Werror -Wextra -c libft.h $(MANDATORY)
				gcc -shared -o libft.so $(OBJS)

clean:
				$(RM) $(OBJS)

fclean:			clean
				$(RM) $(NAME)

re:				fclean $(NAME)

bonus:			$(OBJS)
				ar rcs $(NAME) $(OBJS)

.PHONY:			all clean fclean re bonus
