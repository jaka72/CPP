#include <stdio.h>
#include <string.h>
#include "../srcs/libft.h"

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
//int ft_strchr_main(void) 
{
	printf("\n------------------------------------------------------------");
	printf("\n --- FT_STRCHR ---------------------------------------------\n\n");

	printf("TEST 01\n");
	char *str = "string";
	char c = '\0';
  	printf("   orig:  %s\n",      strchr(str, c));
	printf("   mine:  %s\n\n", ft_strchr(str, c));

	printf("TEST 02\n");
	c = 'X';
	char *str1 = "bXbbbbXb";
	printf("   orig:  %s\n",      strchr(str1, c));
	printf("   mine:  %s\n\n", ft_strchr(str1, c));

	printf("TEST 03\n");
	c = 'X';
	char *str2 = "aaaaaXa";
	printf("   orig:  %s\n",      strchr(str2, c));
	printf("   mine:  %s\n\n", ft_strchr(str2, c));

  	return (0);
}


