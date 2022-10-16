#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "../srcs_eval/libft.h"
#include "../libft_mains.h"

int main(void) 
{
	printf(HYEL"\n------------------------------------------------------------");
	printf("\n--- FT_ISALNUM ---------------------------------------------\n\n"RESET);

	printf(MAG"TEST 01:\n");
	char n = 'A';

	printf(MAG"Character: '%c'\n"RESET, n);
	printf("   orig:   %d\n",      isalnum(n));
	printf("   mine:   %d\n\n", ft_isalnum(n));

    n = '4';
    printf(MAG"Character: '%c'\n"RESET, n);
	printf("   orig:   %d\n",      isalnum(n));
	printf("   mine:   %d\n\n", ft_isalnum(n));

    n = '@';
    printf(MAG"Character: '%c'\n"RESET, n);
	printf("   orig:   %d\n",      isalnum(n));
	printf("   mine:   %d\n\n", ft_isalnum(n));

    return(0);
}