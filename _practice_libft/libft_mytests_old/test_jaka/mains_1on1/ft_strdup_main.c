#define _POSIX_C_SOURCE 200809L
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
//#include <bsd/string.h>
#include "../srcs/libft.h"

/*
char *strdup(const char *s1);

DESCRIPTION
     The strdup() function allocates sufficient memory for a copy of the string s1, 
	 does the copy, and returns a pointer to it.  
	 The pointer may subsequently be used as an argument to the function
     free(3).

     If insufficient memory is available, NULL is returned and errno is set to ENOMEM.
*/

char *ft_strdup2(const char *s1)
{
	int i;
	char *pt;

	i = 0;
	pt = malloc(ft_strlen(s1) * (sizeof(pt) + 1));
	if (pt == NULL)
		return (NULL);
	//printf("len: %lu\n", strlen(pt));
	//printf("size: %lu\n", sizeof(pt));
	while (s1[i])
	{
		pt[i] = s1[i]; // to se lahko zamenja s strcpy
		i++;
	}
	pt[i] = '\0';

	//printf("i: %d\n", i);
	//printf("len s1: %lu\n", strlen(s1));
	//printf("len pt: %lu\n", strlen(pt));
	//printf("size s1: %lu\n", sizeof(s1));
	//printf("size pt: %lu\n", sizeof(pt));
	
	return (pt);
}

int main(void)
//int ft_strdup_main(void) 
{
	printf("\n------------------------------------------------------------");
	printf("\n--- FT_STRDUP ----------------------------------------------\n\n");
	char *source = "this is\0 a normal test";

	printf("TEST 01\n");
    printf("   orig:  %s\n", strdup(source));
	//printf("clone: %s\n", ft_strdup2(source));
    printf("   mine:  %s\n\n", ft_strdup(source));
  	return (0);
}
