#include <stdio.h>
#include <string.h>
//#include <bsd/string.h>
#include "../srcs/libft.h"

/*
int strncmp(const char *s1, const char *s2, size_t n);

DESCRIPTION
       The strcmp() function compares the two strings s1 and s2.  
	   The locale is not taken into account (for a locale-aware comparison, see strcoll(3)).  
	   It returns an integer less than, equal to, or greater than zero if  s1  is found, 
	   respectively (when less than, when match, or when greater than s2).

       The strncmp() function is similar, except it compares only the first (at most) n bytes 
	   of s1 and s2.

RETURN VALUE
       The strcmp() and strncmp() functions return an integer less than, equal to, or 
	   greater than zero if s1 (or the first n bytes thereof) is found, respectively (when 
	   less than, when match, or when greater than s2).

TEST ERRORS WARMACHINE
	test2   ft_strncmp("test", "testss", 7)      -1
	test 3  ft_strncmp("testss", "test", 7)       1
	test 11 ft_strncmp("test\200", "test\0", 6)   1
*/
//// ODL VERSION ///////////////////////////////////////////////////////////

int ft_strncmp2(const char *s1, const char *s2, size_t n)
{
	unsigned int i;

	i = 0;
	if (n == 0)
		return (0);
	while (s1[i] == s2[i] && s1[i] != '\0' && s2[i] != '\0' && i < n - 1)
		i++;
	return (s1[i] - s2[i]);
}
////////////////////////////////////////////////////////////////////////

int	ft_strncmp3(const char *s1, const char *s2, size_t n)
{
	size_t i;  // prej je bil unsigned int

	i = 0;
	if (n == 0)
		return (0);
	while (i < n - 1 && s1[i] != '\0' && s2[i] != '\0') // WHY n -1 ???  ,ZARADI ZADNJE VRSTICE   
	{				  //                       KO JE i == n-1 ,TAKRAT SE LOOP USTAVI, AMPAK i JE ZE POVECAN NA i++
					  // 					     NATO V ZADNJI VRSTICI ODSTEJE NASLEDNJA 2 ZNAKA, TOREJ ZADNJA DVA 
					  // 					   CE JE n == 4 , POTEM PRIMERJA s[3] == s[3]
		if (s1[i] == s2[i])
			i++;
		else
		{   // THIS SEEMS TO BE CRUCIAL IN THE CASE OF INPUT test\100, test\200, test\300
			// WITHOUT CASTING INTO unsigned char IT GIVES WRONG RESULT
			//printf("normal: %d, unsigned: %d\n", s1[i], (unsigned char)s1[i]);
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
		}
	}
	//printf("%d, %d\n", s1[i], (unsigned char)s1[i]);
	return (s1[i] - s2[i]);
}

int main(void)
//int ft_strncmp_main(void) 
{
	printf("\n------------------------------------------------------------");
	printf("\n--- FT_STRNCMP ---------------------------------------------\n\n");

	printf("TEST WARMACHINE\n");
	printf("Test 02:  test   testss\n");
  	printf("	orig:  %d\n",     strncmp("test", "testss", 7));
	printf("	mine: %d\n\n", ft_strncmp("test", "testss", 7));

	printf("Test 03:  testss   test\n");
  	printf("	orig:  %d\n",     strncmp("testss", "test", 7));
	printf("	mine: %d\n\n", ft_strncmp("testss", "test", 7));

	printf("Test 08:  'abcdefgh', 'abcdwxyz', 4\n");
  	printf("	orig:  %d\n",     strncmp("abcdefgh", "abcdwxyz", 4));
	printf("	mine: %d\n\n", ft_strncmp("abcdefgh", "abcdwxyz", 4));
    
    printf("Test 11:  test\\200   test\\0 ?? What is this???\n");
    printf("    orig:  %d\n",     strncmp("test\200", "test\0", 6));
    printf("    mine: %d\n\n", ft_strncmp("test\200", "test\0", 6));

	printf("TEST UNIT\n");
	printf("Test 08:  test   testss\n");
  	printf("	orig:  %d\n",     strncmp("\200", "\0", 1));
	printf("	mine: %d\n\n", ft_strncmp("\200", "\0", 1));
/*
	Test code: Unit test 08:
	char *s1 = "\200";
	char *s2 = "\0";
	int i1 = ((strncmp(s1, s2, 1) > 0) ? 1 : ((strncmp(s1, s2, 1) < 0) ? -1 : 0));
	int i2 = ((ft_strncmp(s1, s2, 1) > 0) ? 1 : ((ft_strncmp(s1, s2, 1) < 0) ? -1 : 0));

	if (i1 == i2)
		exit(TEST_SUCCESS);
	exit(TEST_FAILED);

Diffs:
     strncmp: |1|
  ft_strncmp: |-1|
  */

  	return (0);
}
