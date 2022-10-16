#include "../libft_mains.h" // THIS IS ONLY TO READ ...mains();
                            // OTHER FUNCTION FILES DON'T NEED LIBRARY libft_mains

// GCC TO COMPILE DOES NOT NEED TO INCLUDE libft_mains.h
//    gcc -Wall -Werror -Wextra srcs/main.c libft.a libft_mains.h -lbsd
//    gcc -Wall -Werror -Wextra srcs/main.c libft.a      ???      -lbsd

int main(void)
{
    printf(HGRN"\n\n --------------------------------------------------------------\n");
    printf(" --- JAKA TEST ------------------------------------------------\n");
    printf(" --------------------------------------------------------------\n"RESET);

    ft_strjoin_main();
    ft_memccpy_main();  // causes abort when a.out on mac
    ft_memset_main();
    ft_isalpha_main();
    ft_isdigit_main();
    ft_calloc_main();
    ft_memchr_main();
    ft_memmove_main();  // causes abort when a.out on mac
    ft_strdup_main();
    ft_strlcat_main();
    ft_strlcpy_main();
    ft_strncmp_main();
    ft_split_main();
    ft_strtrim_main();
    ft_strchr_main();
    ft_substr_main();
    ft_itoa_main();
    ft_atoi_main();
    /*ft_strnstr_main();
    ft_memcmp_main();
    ft_strmapi_main();
    ft_strrchr_main();
    ft_strlen_main();
    ft_isalnum_main();
    ft_tolower_main();
    //ft_bzero_main();   NOT CREATED YET
    ft_memcpy_main();  // NOT WORKING on school mac, IMPLICIT DECLARATION - VERY STRANGE ???
    //ft_strcpy_main();  TA NI V LIBFT
*/

    printf(HYEL"\n\n\n\n\n --- END OF JAKA TEST -------------------------------------------------\n");
    printf(" --------------------------------------------------------------\n\n\n"RESET);
    return (0);
}
