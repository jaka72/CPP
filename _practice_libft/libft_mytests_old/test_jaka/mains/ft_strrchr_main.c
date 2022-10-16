#include <stdio.h>
#include <string.h>
#include "../srcs_eval/libft.h"
#include "../libft_mains.h"


// Locates the LAST c in a string, also \0. Returns pointer to located c, 
// or NULL if c not found.

char	*ft_strrchr_clone(const char *str, int c)
{
	char *found;

	found = 0;
	while (*str)
	{
		if (*str == c)
			found = (char *)str;
		str++;
	}
	if (found)
		return (found);
	else if (c == '\0')
		return (char *)str;
	return (NULL);
}


// CE ZNAK NI NAJDEN, VRNE NULL
// CE JE ZNAK \0, VRNE PRAZNO ???, MORALO BI PA VRNIT STRIN STR ???
char *ft_strrchr3(const char *str, char c)
{
	char *found;

	found = NULL;  // HOW CAN *char BE NUL? THIS MUST BE SO!
	while (*str)
	{
		if (*str == c)
			found = (char*)str;
		str++;
	}
	if (found)
		return (found);
	else if (c == '\0') 
		return ((char*)str); // IT MUST RETURN END OF THIS STR						 // NOT JUST ANY \0
	return (NULL);
}






char *ft_strrchr2(const char *str, char c)
{
	char *found;

	found = NULL;
	while (*str)
	{
		if (c == *str)
			found = (char*)str;
		str++;
	}
	if (c == '\0')
		return (char*)(str);
	return (found);
}






int ft_strrchr_main (void) 
{
	printf(HYEL"\n\n------------------------------------------------------------");
	printf("\n --- FT_STRRCHR ----------------------------------------------\n\n"RESET);
	
	printf(MAG"TEST 01\n");
	char *str = "string";
	char c = '\0';
	printf(" str: %s, c: '\\0'%c\n"RESET, str, c);
  	printf("    orig:  %s\n",      strrchr(str, c));
	printf("    mine:  %s\n\n", ft_strchr(str, c));

	printf(MAG"TEST 02\n");
	c = 'X';
	char *str1 = "bbbXbbb";
	printf(" str: %s, c: %c\n"RESET, str1, c);
	printf("    orig:  %s\n",      strrchr(str1, c));
	printf("    mine:  %s\n\n", ft_strrchr(str1, c));

	printf(MAG"TEST 03\n");
	c = 'X';
	char *str2 = "aaaaaAa";
	printf(" str: %s, c: %c\n"RESET, str2, c);
	printf("    orig:  %s\n",      strrchr(str2, c));
	printf("    mine:  %s\n\n", ft_strrchr(str2, c));
    
   return(0);
}
