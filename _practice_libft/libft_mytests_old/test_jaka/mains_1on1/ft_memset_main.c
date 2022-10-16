#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "../srcs/libft.h"

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
//int ft_memset_main(void)
{	printf("\n------------------------------------------------------------");
	printf("\n--- FT_MEMSET ----------------------------------------------\n\n");

	printf("TEST 01:\n\n  Destination:");
	char str[] = "eeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeee";
	puts(str);
   	printf("        orig: %s\n",      (char*)memset(str,'X', 7));
    printf("        mine: %s\n",   (char*)ft_memset(str,'X', 7));
    //ft_memset2(str,'X', 7);

	return (0);
}
