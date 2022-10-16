#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "../srcs/libft.h"

int	ft_isalpha2(int c)
{
	if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
		return (1);
	else
		return (0);
}



//int ft_isalpha_main(void) 
int main(void)
{
	printf("\n------------------------------------------------------------");
	printf("\n--- FT_ISALPHA ---------------------------------------------\n\n");

	printf("TEST 01:\n");
	char n = 'A';
	int result1;
	int result3;

	result1 =       isalpha(n);
	result3 =    ft_isalpha(n);
	printf("Character: '%c'\n", n);
	printf("   orig:   %d\n", result1);
	printf("   mine:   %d\n", result3);

    return(0);
}