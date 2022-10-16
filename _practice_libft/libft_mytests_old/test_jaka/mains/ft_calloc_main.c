#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "stdint.h"
#include "../srcs_eval/libft.h"
#include "../libft_mains.h"

//int	ft_lenint(int nbr);
void	*ft_memset2(void *b, int c, size_t len);
// Prototype: void *calloc(size_t nmemb, size_t size);
/*
The calloc() function allocates memory for an array of nmemb elements of size bytes each 
and returns a pointer to the allocated memory.

The memory is set to zero. 

If nmemb or size is  0,  then  calloc()  returns  either NULL,  
or  a  unique  pointer value that can later be successfully passed to free(). 

If the multiplication of nmemb and size would result in integer overflow, then calloc() returns an error.   
By  contrast,  an  integer overflow  would  not  be detected in the following call to malloc(), 
with the result that an incorrectly sized block of memory would be allocated:

           malloc(nmemb * size);

The malloc() and calloc() functions return a pointer to the allocated memory, which is  suitably  
aligned  for any  built-in type.  
On error, these functions return NULL.  NULL may also be returned by a successful call to malloc() 
with a size of zero, or by a successful call to calloc() with nmemb or size equal to zero.
*/

void		*ft_calloc_copy(size_t count, size_t size)
{
	char	*pt;

	if (size && (SIZE_MAX / size) < count)  // PROTECTION FOR OVERFLOW
		return NULL;

	pt = malloc(count * size);
	if (!pt)
		return (NULL);
	pt = ft_memset(pt, 0, count * size);
	return (pt);
}




int main(void) 
{
	printf(HYEL"\n------------------------------------------------------------");
	printf("\n--- FT_CALLOC ---------------------------------------------\n\n"RESET);

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
	
//	SIZE_MAX: 18446744073709551615
	printf("SIZE_MAX: %zu\n", SIZE_MAX);

	printf(" orig: %s\n",   str1 =      calloc(5, sizeof(char)));
	//printf("clone: %s\n",   str2 = clone_calloc(5, sizeof(char)));
   	printf(" mine: %s\n\n", str3 =   ft_calloc(5, sizeof(char)));
	
    return(0);
}
