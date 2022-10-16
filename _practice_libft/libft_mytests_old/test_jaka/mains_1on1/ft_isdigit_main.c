#include <stdio.h>
#include <ctype.h>
#include "../srcs/libft.h"

//int ft_isdigit_main(void) 
int main(void)
{
	printf("\n------------------------------------------------------------");
	printf("\n--- FT_ISDIGIT ---------------------------------------------\n\n");

	printf("TEST 01:\n");
	char n = '8';
	int result1;
	int result3;

	result1 =       isdigit(n);
	result3 =    ft_isdigit(n);
	printf("Character: '%c'\n", n);
	printf("   orig:   %d\n", result1);  
	printf("   mine:   %d\n", result3);
    
	return(0);
}