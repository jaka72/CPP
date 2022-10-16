#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "../srcs_eval/libft.h"
#include "../libft_mains.h"


int	ft_toupper3(int c)
{
	if (c >= 'a' && c <= 'z')
		return (c - 32);
	else
		return (c);
}

int main(void) 
{
	printf(HYEL"\n-----------------------------------------------------------");
	printf("\n--- FT_TOUPPER ---------------------------------------------\n\n"RESET);
	char c1 = 'w';
	char c2 = 'w';

	printf(MAG "Character: '%c'\n" RESET, c1);
  	printf(HWHT"   orig:  %c\n",      toupper(c1));
    printf("   mine:  %c\n\n"RESET, ft_toupper(c2));

  	return (0);
}

