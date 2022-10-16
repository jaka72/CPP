#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "../srcs_eval/libft.h"
#include "../libft_mains.h"

int	ft_isalpha2(int c)
{
	if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
		return (1);
	else
		return (0);
}



int main(void) 
{
	printf(HYEL"\n------------------------------------------------------------");
	printf("\n--- FT_ISALPHA ---------------------------------------------\n\n"RESET);

	printf(MAG"TEST 01:\n"RESET);
	char n = 'A';
	int result1;
	int result3;

	result1 =       isalpha(n);
	result3 =    ft_isalpha(n);
	printf("Character: '%c'\n", n);
	printf(HWHT"   orig:   %d\n", result1);
	printf("   mine:   %d\n"RESET, result3);

    return(0);
}