#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "../srcs_eval/libft.h"
#include "../libft_mains.h"

/*
memset -- fill a byte string with a byte value

DESCRIPTION
     The memset() function writes len bytes of value c (converted to an unsigned char) to
     the string b.
*/
/*
void *ft_memset2(void *str, int c, size_t n)
{
	size_t i;
	char *ptr;

	ptr = str;
	i = 0;
	while (i < n)
	{
		ptr[i] = c;
		i++;
	}
	return (str);
}
*/


int main(void)
{	printf(HYEL"\n------------------------------------------------------------");
	printf("\n--- FT_MEMSET ----------------------------------------------\n\n"RESET);

	printf(MAG"TEST 01:\n" RESET  "memset(str,'X', 7)\n Destination: ");
	char str[] = "ooooooooooooooooooooooooo";
	puts(str);
   	printf(HWHT"        orig: %s\n",       (char*)memset(str,'X', 7));
    printf("        mine: %s\n"RESET,   (char*)ft_memset(str,'X', 7));


	// printf(MAG"TEST 02:\n" RESET  "memset(str,'X', 7)\n Destination: ");
	// char str1[] = ".........................";
	// puts(str1);
   	// printf(HWHT"        orig: %s\n",       (char*)memset(str1,'X', 30));
    // printf("        mine: %s\n"RESET,   (char*)ft_memset(str1,'X', 30));



	return (0);
}
