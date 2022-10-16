#include <stdio.h>
#include <string.h>
#include <bsd/string.h>
#include "../srcs/libft.h"

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


int main(void)
//int ft_strnstr_main(void) 
{
	printf("\n\n------------------------------------------------------------");
	printf("\n--- FT_STRNSTR ---------------------------------------------\n\n");

	char dest1[20] = "abcdefgh\0";
	char  *src 	   = "e";
	char size      = 5;
	printf("TEST 01: %s, %s, %d\n", dest1, src, size);
    printf("   orig: %s\n",      strnstr(dest1, src, size));
	//printf("clone: %s\n",  ft_strnstr2(dest1, src, size));
	printf("   mine: %s\n\n", ft_strnstr(dest1, src, size));

	char dest2[20] = "abcdefgh\0";
	char  *src2    = "e";
	size		   = 2;
	printf("TEST 02: %s, %s, %d\n", dest2, src2, size);
    printf("   orig: %s\n",      strnstr(dest2, src2, size));
	//printf("clone: %s\n",  ft_strnstr2(dest2, src2, size));
	printf("   mine: %s\n\n", ft_strnstr(dest2, src2, size));

	char dest3[20] = "abcdefgh\0";
	char  *src3    = "X";
	size		   = 10;
	printf("TEST 03: %s, %s, %d\n", dest3, src3, size);
    printf("   orig: %s\n",      strnstr(dest3, src3, size));
	//printf("clone: %s\n",  ft_strnstr2(dest3, src3, size));
	printf("   mine: %s\n\n", ft_strnstr(dest3, src3, size));

	char dest4[20] = "destination\0";
	char  *src4    = "tina";
	size		   = 15;
	printf("TEST 04: %s, %s, %d\n", dest4, src4, size);
    printf("   orig: %s\n",      strnstr(dest4, src4, size));
	//printf("clone: %s\n",  ft_strnstr2(dest4, src4, size));
	printf("   mine: %s\n\n", ft_strnstr(dest4, src4, size));

	char dest4a[20] = "destination\0";
	char  *src4a    = "tion";
	size		   = 15;
	printf("TEST 05: %s, %s, %d\n", dest4a, src4a, size);
    printf("   orig: %s\n",      strnstr(dest4a, src4a, size));
	//printf("clone: %s\n",  ft_strnstr2(dest4a, src4a, size));
	printf("   mine: %s\n\n", ft_strnstr(dest4a, src4a, size));

	char dest5[30] = "xxxxxxABCxxxxxxxABCxxxxxxx\0";
	char  *src5    = "ABC";
	size		   = 25;
	printf("TEST 06: %s, %s, %d\n", dest5, src5, size);
    printf("   orig: %s\n",      strnstr(dest5, src5, size));
	//printf("clone: %s\n",  ft_strnstr2(dest5, src5, size));
	printf("   mine: %s\n\n", ft_strnstr(dest5, src5, size));

	char dest6[30] = "xxxxxxABCxxxxxxxABCxxxxxxx\0";
	char  *src6    = "AB";
	size		   = 25;
	printf("TEST 07: %s, %s, %d\n", dest6, src6, size);
    printf("   orig: %s\n",      strnstr(dest6, src6, size));
	//printf("clone: %s\n",  ft_strnstr2(dest6, src6, size));
	printf("   mine: %s\n\n", ft_strnstr(dest6, src6, size));

  	return (0);
}