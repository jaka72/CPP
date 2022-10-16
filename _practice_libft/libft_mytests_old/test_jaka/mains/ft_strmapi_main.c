#include <stdio.h>
#include <string.h>
//#include <bsd/string.h>
#include <stdlib.h>
#include "../srcs_eval/libft.h"
#include "../libft_mains.h"
/*
 WHY IS THIS f IN PARAMETERS WRITTEN AS A POINTER TO THE FUNCTION: char(*f)(unsigned int, char)
	IT IS ALSO WORKING: char  f(unsigned int, char)
*/
char f(unsigned int x, char ch)
{
	x = 0; // this is not used for anything, just to prevent "unused error"
	ch = ch - 32 + x;
	return (ch);
}

char *ft_strmapi2(char const *s, char (*f)(unsigned int, char))
{
	char *newstr;
	char c;

	int i;

	if (!s || (!(newstr = malloc((ft_strlen(s) + 1) * sizeof(char)))))
		return (NULL);
	i = 0;
	while (s[i])
	{
		c = f(i, s[i]);
		newstr[i] = c;
		i++;	
	}
	newstr[i] = '\0'; 
	return (newstr);
}



// VAJA PONAVLJANJE ///////////////////////////////////////



int ft_strmapi_main(void) 
{
	printf(HYEL"\n------------------------------------------------------------");
	printf("\n--- FT_STRMAPI ---------------------------------------------\n\n"RESET);

	printf(MAG"TEST 01 - Make abcde capital\n"RESET);
	const char *source = "abcde";
    //printf("   orig: %s\n",      strmapi(source, f));
	printf("  clone: %s\n",  ft_strmapi2(source, f));
	printf("   mine: %s\n\n", ft_strmapi(source, f));
  	return (0);
}
