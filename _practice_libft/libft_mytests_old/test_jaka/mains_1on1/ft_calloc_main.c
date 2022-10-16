#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "../srcs/libft.h"
//int	ft_lenint(int nbr);
void	*ft_memset2(void *b, int c, size_t len);
// Prototype: void *calloc(size_t nmemb, size_t size);
/*
The calloc() function allocates memory for an array of nmemb elements of size bytes each 
and returns a pointer to the allocated memory.  
The memory is set to zero.  If nmemb or size is  0,  then  calloc()  returns  either NULL,  
or  a  unique  pointer value that can later be successfully passed to free().  
If the multiplication of nmemb and size would result in integer overflow, then calloc() returns an  error.   
By  contrast,  an  integer overflow  would  not  be detected in the following call to malloc(), 
with the result that an incorrectly sized block of memory would be allocated:

           malloc(nmemb * size);

The malloc() and calloc() functions return a pointer to the allocated memory, which is  suitably  
aligned  for any  built-in type.  
On error, these functions return NULL.  NULL may also be returned by a successful call to malloc() 
with a size of zero, or by a successful call to calloc() with nmemb or size equal to zero.
*/

void	*clone_calloc(size_t count, size_t size)
{
	void	*ptr;

	ptr = malloc(count * size);
	if (ptr == 0)
		return (NULL);
	ptr = ft_memset(ptr, 'x', count * size);
	return (ptr);
}

void *ft_calloc2(int count, int size)
{
	char *pt;
	int i;

	if (count == 0)
		return (NULL);
	i = 0;
	if (!(pt = malloc(count * sizeof(size)))) // ?? sizeof(size) ???
		return (NULL);	// it is not clear, what is the difference, 
	 					// have memory with ints or with chars ???
	while (i < count)
	{
		pt[i] = 'x';  // CHANGE TO ZERO 
		i++;
	}
	return (pt);
}

// VAJA
void *ft_calloc3(int count, int size)
{
	int i;
	char *pt;

	if (count == 0)
		return (NULL);
	if (!(pt = malloc(count * size)))
		return (NULL);
	i = 0;
	while (i < count)
	{
		pt[i] = 'w';
		i++;
	}
	return (pt);
}





//int ft_calloc_main(void) 
int main(void)
{
	printf("\n------------------------------------------------------------");
	printf("\n--- FT_CALLOC ---------------------------------------------\n\n");

	char *str1, *str3;
/*
	printf("sizeof char     %lu\n", sizeof(char));  // WHY CHAR HERE IS 1 ???
	printf("sizeof int      %lu\n", sizeof(int));
	printf("sizeof long int %lu\n", sizeof(long int));
	printf("sizeof  4       %lu\n", sizeof(4));
	printf("sizeof 'a'      %lu\n", sizeof('a'));   // BUT HERE CHAR IS 4 ???
	printf("sizeof \"a\"      %lu\n\n", sizeof("a"));

*/
	//ft_memset(str1, 'X', 9);
	
	printf(" orig: %s\n",   str1 =      calloc(5, sizeof(char)));
	//printf("clone: %s\n",   str2 = clone_calloc(5, sizeof(char)));
   	printf(" mine: %s\n\n", str3 =   ft_calloc(5, sizeof(char)));
	
    return(0);
}

////////////////////////////////////////////////////////////////////////

// FILLS THIS MEMORY WITH SPECIFIC CHARACTER OR 0
void	*ft_memset2(void *b, int c, size_t len)
{
	unsigned char *ptr;

	ptr = (unsigned char*)b;
	while (len > 0)
	{
		*ptr = (unsigned char)c;
		ptr++;
		len--;
	}
	return (b);
}

// USEFUL FUNCTION TO COUNT CIFERS IN A NUMBER, LENGTH
/*
int	ft_lenint(int nbr) 
{
	int len;

	len = 0;
	len = (nbr <= 0 ? 1 : 0);
	while (nbr != 0)
	{
		nbr = nbr / 10;
		len++;
	}
	return (len);
}

*/