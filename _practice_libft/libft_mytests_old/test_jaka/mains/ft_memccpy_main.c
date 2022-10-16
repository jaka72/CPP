#include <stdio.h>
#include <string.h>
//#include <bsd/string.h> // not found on Mac
#include "../srcs_eval/libft.h"
#include "../libft_mains.h"


/*
The memccpy() function copies n bytes from string src to string dst.  
(c should be converted to an unsigned char).

If the character c occurs in the string src, the copy stops and a pointer 
to the byte after the copy of c in the string dst is returned. 

Otherwise, n  bytes are copied, and a NULL pointer is returned.


The source and destination strings should not overlap, as the behavior is undefined.

!!! n SHOULD NOT BE LARGER THAN sizeof(source), or it will abort.

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





int main(void) 
{
	printf(HYEL"\n------------------------------------------------------------");
	printf("\n--- FT_MEMCCPY ---------------------------------------------\n\n"RESET);

	printf(MAG"Test 00\n"RESET);
	char   dest1aa[20] = "destination";
	char   dest1bb[20] = "destination";
	char *source11     = "XYQ";
	char            c = 'Q';
	size_t          n = 2;
	printf(" dest: %s, source: %s, c: %c, n: %lu\n", dest1aa, source11, c, n);
	printf(HWHT"   orig: %s\n",          (char*)memccpy(dest1aa, source11, c, n));
    printf("   mine: %s\n"RESET,      (char*)ft_memccpy(dest1bb, source11, c, n));
    printf("   orig dest after copy: %s\n"RESET,   dest1aa);
	printf("   mine dest after copy: %s\n\n"RESET, dest1bb);


	printf(MAG"Test 01\n"RESET);
	char   dest1a[20] = "destination";
	char   dest1b[20] = "destination";
	char *source1     = "XYQ";
		            c = 'X';
		            n = 6;
	printf(" dest: %s, source: %s, c: %c, n: %lu\n", dest1a, source1, c, n);
	printf(HWHT"   orig: %s\n",       (char*)memccpy(dest1a, source1, c, n));
//  printf("   mine: %s\n"RESET, (char*)ft_memccpy(dest1b, source1, c, n));
    printf("   mine: %s\n"RESET,          ft_memccpy(dest1b, source1, c, n));
    printf("   orig dest after copy: %s\n"RESET, dest1a);
    printf("   mine dest after copy: %s\n\n"RESET, dest1b);


	printf(MAG"Test 02\n"RESET);
	char   dest2a[20] = "destination";
	char   dest2c[20] = "destination";
	char *source2     = "XYQ";
	                c = 'Z';
		            n = 8;
	printf(" dest: %s, source: %s, c: %c, n: %lu\n", dest2a, source2, c, n);
	printf(HWHT"   orig: %s\n",       (char*)memccpy(dest2a, source2, c, n));
    printf("   mine: %s\n\n"RESET, (char*)ft_memccpy(dest2c, source2, c, n));

	printf(MAG"Test 03\n"RESET);
	char   dest3a[20] = "";
	char   dest3c[20] = "";
	char *source3     = "XYQ";
	                c = 'Z';
		            n = 8;
	printf(" dest: %s, source: %s, c: %c, n: %lu\n", dest3a, source3, c, n);
	printf(HWHT"   orig: %s\n",       (char*)memccpy(dest3a, source3, c, n));
    printf("   mine: %s\n\n"RESET, (char*)ft_memccpy(dest3c, source3, c, n));

	printf(MAG"Test 04\n"RESET);
	char   dest4a[20] = "destination";
	char   dest4c[20] = "destination";
	char *source4     = "XYQ";
	                c = 'Y';
		            n = 5;
	printf(" dest: %s, source: %s, c: %c, n: %lu\n", dest4a, source4, c, n);
	printf(HWHT"   orig: %s\n",       (char*)memccpy(dest4a, source4, c, n));
    printf("   mine: %s\n\n"RESET,  (char*)ft_memccpy(dest4c, source4, c, n));


	printf(MAG"Test 05\n"RESET);
	char   dest5a[20] = "destination";
	char   dest5c[20] = "destination";
	char *source5     = "XYQ";
	                c = 's';
		            n = 5;
	printf(" dest: %s, source: %s, c: %c, n: %lu\n", dest5a, source5, c, n);
	printf(HWHT"   orig: %s\n",       (char*)memccpy(dest5a, source5, c, n));
    printf("   mine: %s\n\n"RESET,  (char*)ft_memccpy(dest5c, source5, c, n));
	printf("   orig dest after copy: %s\n"RESET,   dest5a);
	printf("   mine dest after copy: %s\n\n"RESET, dest5c);

  	return (0);
}
