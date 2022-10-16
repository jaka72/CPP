#include <stdio.h>
#include <string.h>
//#include <bsd/string.h>
#include "../srcs_eval/libft.h"
#include "../libft_mains.h"


/*
??? IT IS NOT IN THE STANDARD LIBRARY ???

Description STRNSTR
The strnstr() function locates the	first occurrence of the	null-termi-
     nated string little in the	string big, where not more than	len characters
     are searched.  Characters that appear after a `\0'	character are not
     searched.	Since the strnstr() function is	a FreeBSD specific API,	it
     should only be used when portability is not a concern.

RETURN VALUES
     If	little is an empty string, big is returned; if little occurs nowhere
     in	big, NULL is returned; otherwise a pointer to the first	character of
     the first occurrence of little is returned.


*/

char *ft_strnstr3(const char *hay, const char *needle, int size)
{
	const char *h;
	const char *n;
	int s;

	if (*needle == '\0')
		return (char*)(hay);
	while (*hay != '\0' && size > 0)
	{
		h = hay;
		n = needle;
		s = size;
		while (*n != '\0' && *h == *n && s > 0)
		{
			h++;
			n++;
			s--;
		}
		if (*n == '\0')
			return (char*)(hay);
		hay++;
		size--;
	}
	return (0);
}



// gcc main.c ft_strnstr.c -lbsd
// VAJA 



int ft_strnstr_main(void) 
{
	printf(HYEL"\n\n------------------------------------------------------------");
	printf("\n--- FT_STRNSTR ---------------------------------------------\n\n"RESET);

	char dest1[20] = "abcdefgh\0";
	char  *src 	   = "e";
	char size      = 5;
	printf(MAG"TEST 01: %s, %s, %d\n"RESET, dest1, src, size);
    printf(" orig: %s\n",      strnstr(dest1, src, size));
	//printf("clone: %s\n",  ft_strnstr2(dest1, src, size));
	printf(" mine: %s\n\n", ft_strnstr(dest1, src, size));

	char dest2[20] = "abcdefgh\0";
	char  *src2    = "e";
	size		   = 2;
	printf(MAG"TEST 02: %s, %s, %d\n"RESET, dest2, src2, size);
    printf(" orig: %s\n",      strnstr(dest2, src2, size));
	//printf("clone: %s\n",  ft_strnstr2(dest2, src2, size));
	printf(" mine: %s\n\n", ft_strnstr(dest2, src2, size));

	char dest3[20] = "abcdefgh\0";
	char  *src3    = "X";
	size		   = 10;
	printf(MAG"TEST 03: %s, %s, %d\n"RESET, dest3, src3, size);
    printf(" orig: %s\n",      strnstr(dest3, src3, size));
	//printf("clone: %s\n",  ft_strnstr2(dest3, src3, size));
	printf(" mine: %s\n\n", ft_strnstr(dest3, src3, size));

  	return (0);
}