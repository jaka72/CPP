#include <stdio.h>
#include <ctype.h>
#include "../srcs_eval/libft.h"
#include "../libft_mains.h"

int main(void) 
{
	printf(HYEL"\n------------------------------------------------------------");
	printf("\n--- FT_ISDIGIT ---------------------------------------------\n\n"RESET);

	printf(MAG"TEST 01:\n"RESET);
	char n = '8';
	int result1;
	int result3;

	result1 =       isdigit(n);
	result3 =    ft_isdigit(n);
	printf("Character: '%c'\n", n);
	printf(HWHT"   orig:   %d\n", result1);  
	printf("   mine:   %d\n"RESET, result3);
    
	return(0);
}