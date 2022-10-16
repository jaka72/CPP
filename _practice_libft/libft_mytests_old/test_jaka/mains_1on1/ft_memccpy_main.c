#include <stdio.h>
#include <string.h>
#include <bsd/string.h>
#include "../srcs/libft.h"
/*
The memccpy() function copies n bytes from string src to string dst.  
(c should be converted to an unsigned char).
If the character c occurs in the string src, the copy stops and a pointer 
to the byte after the copy of c in the string dst is returned. 

Otherwise, n  bytes are copied, and a NULL pointer is returned.


The source and destination strings should not overlap, as the behavior is undefined.

SOMEONE SUGGESTED THAT n SHOULD NOT BE LARGER THAN sizeof(source) !!!

#include <string.h>
  void *  memccpy(void *restrict dst, const void *restrict src, int c, size_t n);

*/
/*
 cat test03.output
	jjj
	zyxwvutsrqponmlkjihgfedcbajjja
 cat user_output_test03
	zyxwvutsrqponmlkjihgfedcbajjj
	zyxwvutsrqponmlkjihgfedcbajjjj
*/

void	*ft_memccpy2(void *dest, const void *src, int c, size_t size)
{
	char		*d;
	const char	*s;
	size_t		i;

	d = (char *)dest;
	s = (const char *)src;  // SKOPIRA V NOTRANJE VARS
	i = 0;
	while (i < size && s[i] != '\0')
	{
		d[i] = s[i];
		if (s[i] == (const char)c)
			return ((char *)dest + 1);
		i++;
		dest++;
	}
	return (0);
}





// VAJA PONAVLJANJE ///////////////////////////////////////////////////

void *ft_memccpy3(void *dest, const void *src, char c, size_t n)
{
	size_t i;
	char *d;
	const char *s;

	d = (char*)dest;
	s = (const char*)src;
	i = 0;
	while (i < n && s[i] != '\0')
	{
		d[i] = s[i];
		if ((const char)c == s[i])
			return ((char*)dest + 1);
		i++;
		dest++;
	}
	return (0);
}


int main(void)
//int ft_memccpy_main(void) 
{
	printf("\n------------------------------------------------------------");
	printf("\n--- FT_MEMCCPY ---------------------------------------------\n\n");

	printf("Test 01\n");
	char   dest1a[20] = "abcdef";
	char   dest1b[20] = "abcdef";
	char *source1     = "DEF";
	char            c = 'F';
	size_t          n = 30;
	printf(" dest: %s, source: %s, c: %c, n: %lu\n", dest1a, source1, c, n);
	printf("   orig: %s\n",       (char*)memccpy(dest1b, source1, c, n));
    printf("   mine: %s\n\n", (char*)ft_memccpy(dest1b, source1, c, n));


	printf("Test 02\n");
	char   dest2a[20] = "abcdef";
	char   dest2c[20] = "abcdef";
	char *source2     = "DEF";
	                c = 'X';
		            n = 30;
	printf(" dest: %s, source: %s, c: %c, n: %lu\n", dest2a, source2, c, n);
	printf("   orig: %s\n",       (char*)memccpy(dest2a, source2, c, n));
    printf("   mine: %s\n\n", (char*)ft_memccpy(dest2c, source2, c, n));

	printf("Test 03\n");
	char   dest3a[20] = "";
	char   dest3c[20] = "";
	char *source3     = "DEF";
	                c = 'X';
		            n = 30;
	printf(" dest: %s, source: %s, c: %c, n: %lu\n", dest3a, source3, c, n);
	printf("   orig: %s\n",       (char*)memccpy(dest3a, source3, c, n));
    printf("   mine: %s\n\n", (char*)ft_memccpy(dest3c, source3, c, n));

	printf("Test 04\n");
	char   dest4a[20] = "abcdefghijkl";
	char   dest4c[20] = "abcdefghijkl";
	char *source4     = "DEF";
	                c = 'E';
		            n = 5;
	printf(" dest: %s, source: %s, c: %c, n: %lu\n", dest4a, source4, c, n);
	printf("   orig: %s\n",       (char*)memccpy(dest4a, source4, c, n));
    printf("   mine: %s\n\n",  (char*)ft_memccpy(dest4c, source4, c, n));

  	return (0);
}
