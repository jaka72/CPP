#include <stdio.h>
#include <string.h>
#include "../srcs_eval/libft.h"
#include "../libft_mains.h"
/*			  
#include <string.h>

int   memcmp(const void *s1, const void *s2, size_t n);

DESCRIPTION
The memcmp() function compares byte string s1 against byte string s2.  
       Both strings are assumed to be n bytes long. ???????
   ??? Different source: n −> This is the number of bytes to be compared. ???


RETURN VALUES
The memcmp() function returns zero if the two strings are identical, 
otherwise returns the difference between the first two differing bytes (treated 
as unsigned char values, so that `\200' is greater than `\0', for example).  
Zero-length strings are always identical.  
This behavior is not required by C and portable code should only depend on the 
sign of the returned value.

ORIGINAL IS BEHAVING DIFFERENTLY THAN MINE AND CLONE AT FOLLOWING PARAMS:
  s1 = "aa", s2 = "ab", n = 2


*/

int ft_memcmp3(const char *s1, const char *s2, int n)
{
	const unsigned char *str1;         // why is this necessary ???
	const unsigned char *str2;

    str1 = (const unsigned char *)s1;  // why is this necessary ???
	str2 = (const unsigned char *)s2;  

	if (n == 0)
		return (0);

	while (n > 0)
	{
		//printf("str1 - str2: %d\n", *str1 - *str2);
		if (*str1 != *str2)
			return (*str1 - *str2);
		n--;
		str1++;
		str2++;
	}
	return (0);
}

int		clone_memcmp(const void *s1, const void *s2, size_t n)
{
	const unsigned char		*str1;
	const unsigned char		*str2;

	if (s1 == s2 || n == 0)
		return (0);
	str1 = (const unsigned char *)s1;
	str2 = (const unsigned char *)s2;
	while (n--)
	{
		if (*str1 != *str2)
			return (*str1 - *str2);
		if (n)
		{
			str1++;
			str2++;
		}
	}
	return (0);
}

int ft_memcmp2(const char *str1, const char *str2, size_t n)
{
	const unsigned char *s1;
	const unsigned char *s2;

	s1 = (const unsigned char*)str1;
	s2 = (const unsigned char*)str2;
	if (n == 0)
		return (0);
	while (n > 0)
	{
		printf("compare: %c : %c\n", *s1, *s2);
		if (*s1 != *s2)
			return (*s1 - *s2);
		n--;
		s1++;
		s2++;
		
	}
	return (0);
}

// SIMILAR FUNCTION STRNCMP VS MEMCMP
/*int	ft_strncmp(const char *str1, const char *str2, size_t n)
{
	const unsigned char *s1;
	const unsigned char *s2;

	s1 = (const unsigned char*)str1;
	s2 = (const unsigned char*)str2;
	if (n == 0)
		return (0);
	while (n > 0 && *s1 != '\0' && *s2 != '\0')
	{
		if (*s1 == *s2)
		{
			s1++;
			s2++;
			n--;
		}
		else
			return (*s1 - *s2);
	}
	return (*s1 - *s2);
}
*/




int main(void)
{
	printf(HYEL"\n------------------------------------------------------------");
	printf("\n--- FT_MEMCMP ---------------------------------------------\n\n"RESET);

	char *str1a = "aaa";
	char *str1b = "aaa";
	int n = 8;
	printf(MAG"Test 01:  %s : %s\n"RESET, str1a, str1b);
  	printf("   orig: %d\n",       memcmp(str1a, str1b, n));
    //printf("  clone: %d\n", clone_memcmp(str1a, str1b, n));
    printf("   mine: %d\n\n", ft_memcmp(str1a, str1b, n));

	char *str2a = "aad";
	char *str2b = "aaa";
	n = 5;
	printf(MAG"Test 02:  %s : %s\n"RESET, str2a, str2b);
  	printf("   orig: %d\n",       memcmp(str2a, str2b, n));
    //printf("  clone: %d\n", clone_memcmp(str2a, str2b, n));
    printf("   mine: %d\n\n", ft_memcmp(str2a, str2b, n));

	char *str3a = "aad";
	char *str3b = "aaa";
	n = 5;
	printf(MAG"Test 03:  %s : %s\n"RESET, str3a, str3b);
  	printf("   orig: %d\n",       memcmp(str3a, str3b, n));
    //printf("  clone: %d\n", clone_memcmp(str3a, str3b, n));
    printf("   mine: %d\n\n", ft_memcmp(str3a, str3b, n));

	char *str4a = "test";
	char *str4b = "testss";
	n = 7;
	printf(MAG"Test 04:  %s : %s\n"RESET, str4a, str4b);
  	printf("   orig: %d\n",       memcmp(str4a, str4b, n));
    //printf("  clone: %d\n", clone_memcmp(str4a, str4b, n));
    printf("   mine: %d\n\n", ft_memcmp(str4a, str4b, n));

	char *str5a = "testss";
	char *str5b = "test";
	n = 7;
	printf(MAG"Test 05:  %s : %s\n"RESET, str5a, str5b);
  	printf("   orig: %d\n",       memcmp(str5a, str5b, n));
    //printf("  clone: %d\n", clone_memcmp(str5a, str5b, n));
    printf("   mine: %d\n\n", ft_memcmp(str5a, str5b, n));

	char *str6a = "test\200";
	char *str6b = "test\0";
	n = 6;
	printf(MAG"Test 06:  %s\\200 : %s\\0\n"RESET, str6a, str6b);
  	printf("   orig: %d\n",       memcmp(str6a, str6b, n));
    //printf("  clone: %d\n", clone_memcmp(str6a, str6b, n));
    printf("   mine: %d\n\n", ft_memcmp(str6a, str6b, n));


	char *str7a = "abc\200def";
	char *str7b = "abc\0def";
	n = 1;
	printf(MAG"OCTAL NOTATION  [%s]  [%s] \n"RESET,  str7a,  str7b);
	printf(MAG"OCTAL NOTATION  [%s]  [%s] \n"RESET,  "abc\112klm",  "abc\130klm");
	printf("   orig: %d\n",       memcmp(str7a, str7b, n));
	printf("  clone: %d\n", clone_memcmp(str7a, str7b, n));
	printf("   mine: %d\n\n", ft_memcmp(str7a, str7b, n));



	printf(MAG"Octal with 2 backslashes: '\\200'   '\\0'  \n"RESET);
	printf(MAG"Octal with 2 backslashes:  \\200     \\0   \n\n"RESET);

	printf(MAG"One backslash, single quotes:  '\130'    '\100'  \n"RESET);
	printf(MAG"One backslash, no quotes:       \130      \100   \n\n"RESET);  // THESE ARE ASCII


//										OCTAL	 OCTAL
//										  J        @										
	printf(MAG"Octal '\\112' and '\\100':  '\112'    '\100'  \n"RESET);
	printf(MAG"Octal  \\112  and  \\100:    \112      \100   \n\n"RESET);

//										 9      €    ‰
	printf(MAG"What is this notation?   \071  \200  \211         \n\n"RESET);


//	printf(MAG"What is this notation?  '\97'   '\0'   \n"RESET);
//	printf(MAG"What is this notation?   \97     \0    \n\n"RESET);




  	return (0);
}


