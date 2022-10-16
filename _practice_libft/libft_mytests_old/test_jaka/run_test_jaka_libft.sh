#define BLKB "\e[40m"
HYEL="\e[0;93m"
#define HGRN "\e[0;92m"
#define HWHT "\e[0;97m"
#define YEL   "\e[0;33m"
#define RED   "\x1B[31m"
#define GRN   "\x1B[32m"
#define BLU   "\x1B[34m"
#define MAG   "\x1B[35m"
#define CYN   "\x1B[36m"
#define WHT   "\x1B[37m"
RESET="\x1B[0m"

clear

cd srcs_eval

# TESTS NORMINETTE
# printf "${HYEL}-----------------------------------------------------------------------\n${RESET}"
# printf "${HYEL}--- NORMINETTE --------------------------------------------------------\n\n${RESET}"
# norminette	ft_bzero.c ft_memset.c ft_memchr.c ft_calloc.c ft_memcpy.c \
# 				ft_memccpy.c ft_memmove.c ft_memcmp.c ft_strlen.c \
# 				ft_strdup.c ft_strlcpy.c ft_strchr.c ft_strrchr.c \
# 				ft_strnstr.c ft_strncmp.c ft_isalpha.c ft_isalnum.c \
# 				ft_isascii.c ft_isprint.c ft_toupper.c ft_tolower.c \
# 				ft_strmapi.c ft_substr.c ft_strjoin.c ft_strtrim.c \
# 				ft_split.c ft_itoa.c ft_putstr_fd.c ft_putendl_fd.c \
# 				ft_putnbr_fd.c ft_strlcat.c ft_atoi.c ft_isdigit.c \
# 				ft_putchar_fd.c

# TEST MAKE AND FCLEAN
# printf "\n\n${HYEL}---------------------------------------------------------------------\n${RESET}"
# printf "${HYEL}--- MAKEFILE make --------------------------------------------------------\n${RESET}"
# make
#cd srcs_eval
# printf "${HYEL}\n\n--- MAKEFILE fclean --------------------------------------------------------\n${RESET}"
# make fclean
# printf "${HYEL}\n\n--- MAKEFILE make --------------------------------------------------------\n${RESET}"
# make
# printf "${HYEL}\n\n--- MAKEFILE make 2nd time --------------------------------------------------------\n${RESET}"
# make
# printf "${HYEL}\n\n--- MAKEFILE make re --------------------------------------------------------\n${RESET}"
# make re

# cd ..


#cd mains

#title="FT_ATOI"
#printtitle
#checkdiff

#title="FT_TOLOWER"
# gcc mains/ft_tolower_main.c		srcs_eval/ft_tolower.c		srcs_eval/libft.h && ./a.out

# title="FT_TOUPPER"
# gcc mains/ft_toupper_main.c		srcs_eval/ft_toupper.c		srcs_eval/libft.h && ./a.out

# #title="FT_ISALNUM"
# gcc mains/ft_isalnum_main.c		srcs_eval/ft_isalnum.c		srcs_eval/ft_isdigit.c		srcs_eval/ft_isalpha.c		srcs_eval/libft.h && ./a.out

# #title="FT_ISALPHA"
# gcc mains/ft_isalpha_main.c		srcs_eval/ft_isalpha.c		srcs_eval/libft.h && ./a.out

# #title="FT_ISDIGIT"
# gcc mains/ft_isdigit_main.c		srcs_eval/ft_isdigit.c		srcs_eval/libft.h && ./a.out

# #title="FT_ATOI"
# gcc mains/ft_atoi_main.c srcs_eval/ft_atoi.c srcs_eval/ft_isdigit.c		srcs_eval/libft.h && ./a.out

# #title="FT_ITOA"
# gcc mains/ft_itoa_main.c		srcs_eval/ft_itoa.c		srcs_eval/libft.h && ./a.out

# #title="FT_MEMCCPY"
# gcc mains/ft_memccpy_main.c		srcs_eval/ft_memccpy.c		srcs_eval/libft.h && ./a.out

# #title="FT_MEMCHR"
# gcc mains/ft_memchr_main.c		srcs_eval/ft_memchr.c		srcs_eval/libft.h && ./a.out

# #title="FT_MEMCMP"
# gcc mains/ft_memcmp_main.c		srcs_eval/ft_memcmp.c		srcs_eval/libft.h && ./a.out

# #title="FT_MEMCPY"
# gcc mains/ft_memcpy_main.c srcs_eval/ft_memcpy.c srcs_eval/libft.h && ./a.out

# #title="FT_MEMMOVE"
# gcc mains/ft_memmove_main.c srcs_eval/ft_memmove.c		srcs_eval/ft_memcpy.c		srcs_eval/libft.h && ./a.out

# #title="FT_MEMSET"
# gcc mains/ft_memset_main.c		srcs_eval/ft_memset.c		srcs_eval/libft.h && ./a.out

# #title="FT_CALLOC"
# gcc mains/ft_calloc_main.c		srcs_eval/ft_calloc.c	srcs_eval/ft_memset.c	srcs_eval/libft.h && ./a.out

# #title="FT_SPLIT"
# gcc mains/ft_split_main.c		srcs_eval/ft_split.c 	srcs_eval/libft.h && ./a.out

# #title="FT_STRCHR"
# gcc mains/ft_strchr_main.c 		srcs_eval/ft_strchr.c srcs_eval/ft_strlen.c		 srcs_eval/libft.h && ./a.out

# #title="FT_STRTRIM"
# gcc mains/ft_strtrim_main.c		 srcs_eval/ft_strtrim.c srcs_eval/ft_strlen.c srcs_eval/ft_strchr.c srcs_eval/ft_substr.c srcs_eval/ft_strlcpy.c srcs_eval/ft_strdup.c srcs_eval/ft_memcpy.c srcs_eval/libft.h && ./a.out

# #title="FT_SUBSTR"
# gcc mains/ft_substr_main.c srcs_eval/ft_substr.c srcs_eval/ft_strlen.c srcs_eval/ft_strlcpy.c srcs_eval/libft.h && ./a.out

printf "${HYEL}\n\n--- END OF TEST --------------------------------------------------------\n\n${RESET}"

cd ..

