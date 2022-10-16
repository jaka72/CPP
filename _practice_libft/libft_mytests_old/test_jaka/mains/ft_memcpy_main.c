#include <stdio.h>
#include <string.h>
#include "../srcs_eval/libft.h"
#include "../libft_mains.h"
/*
SYNOPSIS
       #include <string.h>

       void *memcpy(void *dest, const void *src, size_t n);

DESCRIPTION
       The  memcpy()  function  copies  n  bytes from memory area src to memory area dest.  
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
{
	printf(HYEL"\n-----------------------------------------------------------");
	printf("\n--- FT_MEMCPY ---------------------------------------------\n\n");

	printf(MAG"TEST 01\n");
	const char src[50] = "ABCDEF";
	char dest1a[50]    = "abcdefghijk";
	char dest1c[50]    = "abcdefghijk";
	printf(" dest: %s,  src: %s,  n=3\n"RESET, dest1a, src);
	printf("   orig: %s\n",       (char*)memcpy(dest1a, src, 3));
	printf("   mine: %s\n\n",  (char*)ft_memcpy(dest1c, src, 3));

	printf(MAG"TEST 02\n");
	const char src2[50] = "XXX";
	char dest2a[50]    = "";
	char dest2c[50]    = "";
	printf(" dest: %s,  src: \"\",  n=3\n"RESET, src2);
	printf("   orig: %s\n",       (char*)memcpy(dest2a, src2, 3));
	printf("   mine: %s\n\n",  (char*)ft_memcpy(dest2c, src2, 3));

	printf(MAG"TEST 03\n");
	const char src3[50] = "";
	char dest3a[50]    = "abcdef";
	char dest3c[50]    = "abcdef";
	printf(" dest: \"\",  src: \"\",  n=3\n"RESET);
	printf("   orig: %s\n",       (char*)memcpy(dest3a, src3, 3));
	printf("   mine: %s\n\n",  (char*)ft_memcpy(dest3c, src3, 3));
   
   return(0);
}
