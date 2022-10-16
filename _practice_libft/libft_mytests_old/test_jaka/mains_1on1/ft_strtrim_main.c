#include <stdio.h>
#include <string.h>
//#include <bsd/string.h>
#include <stdlib.h>
#include "../srcs/libft.h"


//size_t	ft_strlen(const char *str);
//char	*ft_strchr(const char *s, int c);


char	*clone_strtrim(char const *s1, char const *set)
{
	int			len;
	char		*newstring; // malloc will be made in substr()

	if (!s1 || !set)
		return (NULL);
	while (*s1 && ft_strchr(set, *s1)) // looping set for each *s
		s1++; // returns position, where no ch from set matches s1
	len = ft_strlen(s1); // new length, from first unmatched ch till end

// WHY IS HERE NOT len-- ???    BECAUSE s[len] NOW POINTS TO \0 ,IT SHOULD RETURN FALSE ??? 

	while (len && ft_strchr(set, s1[len]))
		len--;  // checks each ch from the end of s1,
				// returns position, where no s1 matches set anymore
				// so len is diminished by matched characters
	newstring = ft_substr((char*)s1, 0, len + 1);
	return (newstring);
}


char	*ft_strtrim2(char const *str, char const *set)
{
	int		len;
	char	*trimmedstr;

	if (!str)
		return (NULL);
	if (!set)
		return (ft_strdup(str));
	while (*str && ft_strchr(set, *str))
		str++;
	len = ft_strlen(str);
	while (len && ft_strchr(set, str[len]))
		len--;
	trimmedstr = ft_substr(str, 0, len + 1);
	return (trimmedstr);
}



int main(void)
//int ft_strtrim_main(void)
{
	printf("\n\n\n------------------------------------------------------------");
	printf("\n--- FT_STRTRIM -------------------------------------------------\n\n");

	printf("TEST 01    str: ---+++abcdef---+++    set: +-\n");
	char *str1 = "---+++abcdef---+++";
	char *set1 = "-+"; 
	printf("   clone: %s\n",      strtrim2(str1, set1));
	printf("    mine: %s\n\n",   ft_strtrim(str1, set1));

	printf("TEST 02    str: ---+++abcdef---+++    set: \"\"\n");
	char *str2 = "---+++abcdef---+++";
	char *set2 = ""; 
	printf("   clone: %s\n",      strtrim2(str2, set2));
	printf("    mine: %s\n\n",   ft_strtrim(str2, set2));

	printf("TEST 03    str: ---+++abcdef---+++    set: NULL\n");
	char *str3 = "---+++abcdef---+++";
	char *set3 = NULL; 
	printf("   clone: %s\n",      strtrim2(str3, set3));
	printf("    mine: %s\n\n",   ft_strtrim(str3, set3));

	printf("TEST 04    str: \"\"    set: +-\n");
	char *str4 = "";
	char *set4 = "+-"; 
	printf("   clone: %s\n",      strtrim2(str4, set4));
	printf("    mine: %s\n\n",   ft_strtrim(str4, set4));


	return 0;
}