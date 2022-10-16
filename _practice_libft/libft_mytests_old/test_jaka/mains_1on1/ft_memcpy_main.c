#include <stdio.h>
#include <string.h>
#include "../srcs/libft.h"

/*
SYNOPSIS
       #include <string.h>

       void *memcpy(void *dest, const void *src, size_t n);

DESCRIPTION
       The  memcpy()  function  copies  n  bytes from memory area src to memory area dest.  
	   						???? overlap
	   The memory areas must not overlap.  Use memmove(3) if the memory areas do overlap.

RETURN VALUE
       The memcpy() function returns a pointer to dest.
*/


void *ft_memcpy2(void *dest, const void *src, size_t n)
{
	size_t i;
	char *d;
	const char *s;

  	if (!dest && !src)
    	return (NULL);
	d = dest; // NE VEM ZAKAJ MORA BIT POINTER, ZGLEDA DA DELA TUDI BREZ 
	s = src;
	i = 0;
	while (i < n)
	{
		d[i] = s[i];
		i++;
	}
	//ptr[i] = '\0';  // it is not in original
	return (d);
}

int main(void)
//int ft_memcpy_main(void) 
{
	printf("\n-----------------------------------------------------------");
	printf("\n--- FT_MEMCPY ---------------------------------------------\n\n");

	printf("TEST 01\n");
	const char src[50] = "ABCDEF";
	char dest1a[50]    = "aaaaaaaaaaa";
	//char dest1b[50]    = "aaaaaaaaaaa";
	char dest1c[50]    = "aaaaaaaaaaa";
	printf("   orig: %s\n",       (char*)memcpy(dest1a, src, 3));
	//printf("  clone: %s\n",   ft_memcpy2(dest1b, src, 3));
	printf("   mine: %s\n\n",  (char*)ft_memcpy(dest1c, src, 3));

	printf("TEST 02\n");
	const char src2[50] = "XXX";
	char dest2a[50]    = "";
	//char dest2b[50]    = "";
	char dest2c[50]    = "";
	printf("   orig: %s\n",       (char*)memcpy(dest2a, src2, 3));
	//printf("  clone: %s\n",   ft_memcpy2(dest2b, src2, 3));
	printf("   mine: %s\n\n",  (char*)ft_memcpy(dest2c, src2, 3));

	printf("TEST 03\n");
	const char src3[50] = "";
	char dest3a[50]    = "abcdef";
	//char dest3b[50]    = "abcdef";
	char dest3c[50]    = "abcdef";
	printf("   orig: %s\n",       (char*)memcpy(dest3a, src3, 3));
	//printf("  clone: %s\n",   ft_memcpy2(dest3b, src3, 3));
	printf("   mine: %s\n\n",  (char*)ft_memcpy(dest3c, src3, 3));
   
   return(0);
}
