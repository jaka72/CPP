#include <stdio.h>
#include <string.h>
//#include <bsd/string.h>
#include <stdlib.h>
#include <ctype.h>
#include "../srcs_eval/libft.h"
#include "../libft_mains.h"


// SUBSTR - THERE IS NO ORIGINAL ???

// Prototype
//char *ft_substr(char const *s, unsigned int start, size_t len);

/*

Returns a chunk (substring) of the original string

- Check if string exists
- put \0 at the end of returning string
- do we need to check that length does not go over the end of original string?
   - i discovered that in this case it's correct if i return pointer pt[0] = '\0'


ERRORS:
Test 05 gives error, it is weird, something with 400 bytes and a word Bullshit

*/

// SIMILAR TO SUBSTR:
char	*ft_strnstr_comparison(const char *hay, const char *needle, size_t size)
{
	const char	*h;
	const char	*n;
	size_t		s;

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


/// CLONE /////
char	*ft_substr2(char const *s, unsigned int start, size_t n)
{
	char	*pt;
	size_t	i;

	if (!s)
		return (NULL);
	if (n > ft_strlen(s))
		n = ft_strlen(s);
	pt = malloc((n + 1) * sizeof(char));
	if (!pt)
		return (NULL);
	if (start >= ft_strlen(s))
	{
		pt[0] = '\0';
		return (pt);
	}
	i = 0;
	while (i < n && s[start] != '\0')
	{
		pt[i] = s[start];
		i++;
		start++;
	}
	pt[i] = '\0';
	return (pt);
}





// VAJA PONAVLJANJE SUBSTR ////////////////////////////////




int main(void) 
{	
	printf(HYEL"\n-----------------------------------------------------------");
	printf("\n--- FT_SUBSTR ---------------------------------------------\n\n"RESET);

	char *str1 = "lorem ipsum dolor sit amet";

	printf(MAG"TEST STRING \"lorem ipsum dolor sit amet\"\n\n"RESET);
	printf(MAG"                        start    len\n"RESET);
	printf(MAG"Test 01    substr(str1,   0,     10)\n"RESET);
	//printf("  orig: %s\n",         substr(str1, 0, 10));
   	printf("  clone: %s\n",    ft_substr2(str1, 0, 10));   
 	printf("   mine: %s\n\n",    ft_substr(str1, 0, 10));  

	printf(MAG"Test 02   substr(str1, 7, 10)\n"RESET);
	//printf("  clone: %s\n", substr(str1, 7, 10));
   	printf("  clone: %s\n",     ft_substr2(str1, 7, 10));   
 	printf("   mine: %s\n\n",    ft_substr(str1, 7, 10)); 

	printf(MAG"Test 03   substr(str1, 7, 0)\n"RESET);
	//printf("  clone: %s\n", substr(str1, 7, 0));
   	printf("  clone: %s\n",     ft_substr2(str1, 7, 0));   
 	printf("   mine: %s\n\n",    ft_substr(str1, 7, 0));

	printf(MAG"Test 04   substr(str1, 0, 0)\n"RESET);
	//printf("  clone: %s\n", substr(str1, 0, 0));
   	printf("  clone: %s\n",     ft_substr2(str1, 0, 0));   
 	printf("   mine: %s\n\n",    ft_substr(str1, 0, 0)); 

	printf(MAG"Test 05   substr(str1, 400, 20)\n"RESET);
	//printf("  clone: %s\n", substr(str1, 400, 20));
   	printf("  clone: %s\n",     ft_substr2(str1, 400, 20));   
 	printf("   mine: %s\n\n",    ft_substr(str1, 400, 20)); 

	printf(MAG"Test 06   substr(str1, 0, 0)\n"RESET);
	//printf("  clone: %s\n", substr(str1, 0, 0));
   	printf("  clone: %s\n",     ft_substr2(str1, 17, 20));   
 	printf("   mine: %s\n\n",    ft_substr(str1, 17, 20)); 

	printf(MAG"Test 07   substr(str1, 24, 5) (length is longer than substring from start to end)\n"RESET);
	//printf("  clone: %s\n", substr(str1, 0, 0));
   	printf("  clone: %s\n",     ft_substr2(str1, 24, 5));   
 	printf("   mine: %s\n\n",    ft_substr(str1, 24, 5)); 

    return(0);
}
