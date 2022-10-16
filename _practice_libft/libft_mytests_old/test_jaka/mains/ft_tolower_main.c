#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "../srcs_eval/libft.h"
#include "../libft_mains.h"

int ft_tolower2(int c)
{
	if (c >= 'A' && c <= 'Z')
		return (c - ('A' - 'a'));
//		return (c + 32);  // THIS DOES NOT PASS UNIT TEST 
	else
		return (c);

}

int main(void) 
{
	printf(HYEL"\n-----------------------------------------------------------");
	printf("\n--- FT_TOLOWER ---------------------------------------------\n\n"RESET);
	char c1 = 'Q';
	char c2 = 'Q';

	printf(MAG "Character: '%c'\n" RESET, c1);
  	printf(HWHT"   orig:  %c\n",      tolower(c1));
    printf("   mine:  %c\n\n"RESET, ft_tolower(c2));

  	return (0);
}

