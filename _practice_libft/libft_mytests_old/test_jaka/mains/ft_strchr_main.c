#include <stdio.h>
#include <string.h>
#include "../srcs_eval/libft.h"
#include "../libft_mains.h"
/*			  
     #include <string.h>
     char *strchr(const char *s, int c);   // find first c
     char *strrchr(const char *s, int c);  // find last c

DESCRIPTION
     The strchr() function locates the first occurrence of c (converted to a char) in the 
	 string pointed to by s.  
	 The terminating null character is considered to be part of the string; therefore if 
	 c is `\0', the functions locate the terminating `\0'.

RETURN VALUES
     The functions strchr() and strrchr() return a pointer to the located character, or 
	 NULL if the character does not appear in the string.
*/

char *ft_strchr2(const char *s, int c)
{
	int i;
	char *str;

	str = (char*)s;  // TREBA CAST V POMOZNO VARIABLO
	i = 0;
	while (str[i] != '\0') // get length i
		i++;
	if (c == '\0')
		return (str + i);  // return the end of this string
	while (*str)
	{
		if (c == *str)
			return (str);
		str++;
	}
	return (NULL);
}


int main(void) 
{
	printf(HYEL"\n------------------------------------------------------------");
	printf("\n --- FT_STRCHR ---------------------------------------------\n\n"RESET);

	
	char *str = "string";
	char c = '\0';
	printf(MAG"TEST 01, str: %s, c: '\\0'\n"RESET, str);
  	printf("   orig:  [%s]\n",      strchr(str, c));
	printf("   mine:  [%s]\n\n", ft_strchr(str, c));

	
	c = 'X';
	char *str1 = "bXbbbbXb";
	printf(MAG"TEST 02, str: %s, c: %c\n"RESET, str1, c);
	printf("   orig:  [%s]\n",      strchr(str1, c));
	printf("   mine:  [%s]\n\n", ft_strchr(str1, c));

	
	c = 'X';
	char *str2 = "aaaaaXa";
	printf(MAG"TEST 03, str: %s, c: %c\n"RESET, str2, c);
	printf("   orig:  [%s]\n",      strchr(str2, c));
	printf("   mine:  [%s]\n\n", ft_strchr(str2, c));

	c = '\n';
	char *str3 = "aaa\naaa";
	printf(MAG"TEST 04, str: %s, c: %c\n"RESET, str3, c);
	printf("   orig:  [%s]\n",      strchr(str3, c));
	printf("   mine:  [%s]\n\n", ft_strchr(str3, c));

  	return (0);
}


