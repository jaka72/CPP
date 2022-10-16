#include <stdio.h>
#include <string.h>
#include <string.h>
#include <bsd/string.h>
#include "../srcs/libft.h"


/*
size_t strlcpy(char *restrict dst, 
			   const char *restrict	src, size_t dstsize);

strlcpy() and strlcat() take the full size of the buffer (not just the length).
They guarantee to NUL-terminate the result (as long as size is larger than 0).
In case of strlcat() it will NULL-terminate as long as there is at least one byte free in dst). 
The byte for the NUL should be included in size. 
															????
Also note that strlcpy() and strlcat() only operate on true ''C'' strings. 
This means that for strlcpy() src must be NUL-terminated.
For strlcat() both src and dst must be NUL-terminated.

The strlcpy() function copies up to size - 1 characters from the NUL-terminated 
string src to dst, NUL-terminating the result.

Return Values
The strlcpy() returns the total length of the string it tried to create. 
That means the length of src. 

QUESTIONS:
- memcpy vs strncpy - is there any difference?  yes, about overlapping etc ...

TESTS: dest == "rrrrrr000000000"
	else if (atoi(argv[1]) == 3)
		ft_print_result(ft_strlcpy(dest, "lorem ipsum", 3));
		lorrr

	else if (atoi(argv[1]) == 4)
		ft_print_result(ft_strlcpy(dest, "lorem ipsum dolor sit amet", 15));
		orig output: lorem ipsum do%

	else if (atoi(argv[1]) == 5)
		ft_print_result(ft_strlcpy(dest, "lorem ipsum dolor sit amet", 0));
		orig output: rrrrrr%

*/


size_t    ft_strlcpy3(char *dest, const char *src, size_t size)
{	
	size_t	i;
	size_t len;

	if (!dest || !src)
		return (0);
	len = ft_strlen(src);
	i = 0;
	if (size <= 0)
		return (len);
	while (i < size-1 && *src != '\0')
	{
		*dest = *src;
		i++;
		dest++;
		src++;
	}
	*dest = '\0';
	return (len);
}


// VAJA PONAVLJANJE ///////////////////////////////////////////////


size_t ft_strlcpy2(char *dest, const char *src, size_t size)
{
	size_t i;
	size_t len;

	if (!src || !dest)
		return (0);
	len = ft_strlen(src);
	i = 0;
	if (size <= 0)
		return (len);
	while (*src != '\0' && i < size - 1)
	{
		*dest = *src;
		dest++;
		src++;
		i++;	
	}
	*dest = '\0';
	return (len);
}




int main(void)
//int ft_strlcpy_main(void) 
{
	printf("\n------------------------------------------------------------");
	printf("\n--- FT_STRLCPY ---------------------------------------------\n\n");

	printf("Test 01\n");
	char dest1a[15] = "rrrrrr000000000";
	//char dest1b[15] = "rrrrrr000000000";
	char dest1c[15] = "rrrrrr000000000";
	char  *src1     = "lorem ipsum dolor";
	char size       = 6;
	printf("   orig: length: %lu, dest: %s\n",       strlcpy(dest1a, src1, size), dest1a);
	//printf("  clone: length: %lu, dest: %s\n",   ft_strlcpy2(dest1b, src1, size), dest1b);
	printf("   mine: length: %lu, dest: %s\n\n", ft_strlcpy(dest1c, src1, size), dest1c);

	printf("Test 02\n");
	char  *src2 = "";
	size        = 15;
	printf("   orig: length: %lu, dest: %s\n",       strlcpy(dest1a, src2, size), dest1a);
	//printf("  clone: length: %lu, dest: %s\n",   ft_strlcpy2(dest1b, src2, size), dest1b);
	printf("   mine: length: %lu, dest: %s\n\n",  ft_strlcpy(dest1c, src2, size), dest1c);

	printf("Test 03\n");
	char  *src3 = "lorem ipsum";
	size        = 3;
	printf("   orig: length: %lu, dest: %s\n",       strlcpy(dest1a, src3, size), dest1a);
	//printf("  clone: length: %lu, dest: %s\n",   ft_strlcpy2(dest1b, src3, size), dest1b);
	printf("   mine: length: %lu, dest: %s\n\n",  ft_strlcpy(dest1c, src3, size), dest1c);


	printf("Test 04\n");
	char  *src4 = "lorem ipsum dolor sit amet";
	size        = 15;
	printf("   orig: length: %lu, dest: %s\n",       strlcpy(dest1a, src4, size), dest1a);
	//printf("  clone: length: %lu, dest: %s\n",   ft_strlcpy2(dest1b, src4, size), dest1b);
	printf("   mine: length: %lu, dest: %s\n\n",  ft_strlcpy(dest1c, src4, size), dest1c);

	printf("Test 05\n");
	char  *src5 = "lorem ipsum dolor sit amet";
	size        = 0;
	printf("   orig: length: %lu, dest: %s\n",       strlcpy(dest1a, src5, size), dest1a);
	//printf("  clone: length: %lu, dest: %s\n",   ft_strlcpy2(dest1b, src5, size), dest1b);
	printf("   mine: length: %lu, dest: %s\n\n",  ft_strlcpy(dest1c, src5, size), dest1c);

  	return (0);
}