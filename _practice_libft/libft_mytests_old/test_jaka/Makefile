.PHONY: all clean fclean re

NAME = libft_mains.a

CC = gcc
CFLAGS = -g -Wall -Wextra -Werror -I$(INC_DIR)# -lbsd

SRC_DIR = ./srcs_eval/
MAINS_DIR = ./mains/

MAINS = $(addprefix $(MAINS_DIR), $(MAIN))
SRCS = $(addprefix $(SRC_DIR), $(SRC))

MAIN =	\
		main.c \
		ft_strlen_main.c \
		ft_isalpha_main.c \
		ft_tolower_main.c \
		ft_isalnum_main.c \
		ft_memccpy_main.c \
		ft_memchr_main.c \
		ft_memmove_main.c \
		ft_memset_main.c \
		ft_strdup_main.c \
		ft_strjoin_main.c \
		ft_strlcat_main.c \
		ft_strlcpy_main.c \
		ft_strncmp_main.c \
		ft_split_main.c \
		ft_strtrim_main.c \
		ft_itoa_main.c \
		ft_strchr_main.c \
		ft_substr_main.c \
		ft_atoi_main.c \
		ft_isdigit_main.c \
		ft_strnstr_main.c \
		ft_memcmp_main.c \
		ft_strmapi_main.c \
		ft_strrchr_main.c \
		ft_memcpy_main.c \
		ft_calloc_main.c 

SRC =	\
		ft_strlen.c \
		ft_isalpha.c \
		ft_tolower.c \
		ft_isalnum.c \
		ft_memccpy.c \
		ft_memchr.c \
		ft_memmove.c \
		ft_memset.c \
		ft_strdup.c \
		ft_strjoin.c \
		ft_strlcat.c \
		ft_strlcpy.c \
		ft_strncmp.c \
		ft_split.c \
		ft_strtrim.c \
		ft_itoa.c \
		ft_strchr.c \
		ft_substr.c \
		ft_atoi.c \
		ft_isdigit.c \
		ft_strnstr.c \
		ft_memcmp.c \
		ft_strmapi.c \
		ft_strrchr.c \
		ft_memcpy.c \
		ft_calloc.c
		#ft_strcpy_bonus.c

OBJ_DIR = ./obj/
OBJ_DIR_PRINTF = $(OBJ_DIR)ft_printf/
OBJS = $(addprefix $(OBJ_DIR), $(OBJ))
OBJ = $(MAIN:.c=.o) $(SRC:.c=.o)

INC_DIR = ./includes/
INCS = $(addprefix $(INC_DIR), $(INC))
INC = libft.h get_next_line.h ft_printf.h

all: $(NAME)

$(NAME): $(OBJ_DIR) $(OBJS)
	ar rc $(NAME) $(OBJS)
	ranlib $(NAME)

$(OBJ_DIR)%.o: $(SRC_DIR)%.c $(INCS)
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_DIR)%.o: $(MAINS_DIR)%.c $(INCS)
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)
	@mkdir -p $(OBJ_DIR_PRINTF)

clean:
	@rm -f $(OBJS)
	@rm -rf $(OBJ_DIR)

fclean: clean
	@rm -f $(NAME)

re: fclean all
