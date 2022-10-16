#include <stdio.h>
#include <string.h>
//#include <bsd/string.h>
#include <stdlib.h>
#include "../srcs_eval/libft.h"
#include "../libft_mains.h"

// FT_STRTRIM WITH COMMENTS
char	*ft_strtrim_comments(char const *s1, char const *set)
{
	int			len;
	char		*newstring; // malloc will be made in substr()

	if (!s1 || !set)
		return (NULL);
	while (*s1 && ft_strchr(set, *s1)) 	// looping set for each *s ,if *s matches any set, is good
		s1++; 							// stops at position, where no ch from set matches s1 (returns NULL)
	len = ft_strlen(s1); // new length, from first unmatched ch till end

	while (len && ft_strchr(set, s1[len]))
		len--;  // checks each ch from the end of s1,
				// returns position, where no s1 matches set anymore
				// so len is diminished by matched characters
	newstring = ft_substr((char*)s1, 0, len + 1);
	return (newstring);
}




char	*strtrim2(char const *str, char const *set)
{
	int		len;
	char	*trimmedstr;

	if (!str)
		return (NULL);
	if (!set)
		return ((char*)str);
	while (*str && ft_strchr(set, *str))
		str++;
	len = ft_strlen(str);
	while (len && ft_strchr(set, str[len]))
		len--;
	trimmedstr = ft_substr(str, 0, len + 1);
	return (trimmedstr);
}



int main(void)
{
	printf(HYEL"\n\n\n------------------------------------------------------------");
	printf("\n--- FT_STRTRIM -------------------------------------------------\n\n"RESET);

	printf(MAG"TEST 01    str: ---+++abcdef---+++    set: +-\n"RESET);
	char *str1 = "---+++abcdef---+++";
	char *set1 = "-+"; 
	printf("   clone: %s\n",      strtrim2(str1, set1));
	printf("    mine: %s\n\n",   ft_strtrim(str1, set1));

	printf(MAG"TEST 02    str: ---+++abcdef---+++    set: -+\n"RESET);
	char *str11 = "---+++abcdef---+++";
	char *set11 = "-+"; 
	printf("   clone: %s\n",      strtrim2(str11, set11));
	printf("    mine: %s\n\n",   ft_strtrim(str11, set11));

	printf(MAG"TEST 03    str: ---+++abcdef---+++    set: \"\"\n"RESET);
	char *str2 = "---+++abcdef---+++";
	char *set2 = ""; 
	printf("   clone: %s\n",      strtrim2(str2, set2));
	printf("    mine: %s\n\n",   ft_strtrim(str2, set2));


// NOT WORKING WITH SET NULL, SEGFAULT ???
	printf(MAG"TEST 04    str: ---+++abcdef---+++    set: NULL\n"RESET);
	char *str3 = "---+++abcdef---+++";
	char *set3 = NULL; 
	printf("   clone: %s\n",      strtrim2(str3, set3));
	printf("A1\n");

	printf("    mine: %s\n\n",   ft_strtrim(str3, set3));
//	printf("   clone: %s\n",      strtrim2(str3, set3));




	printf(MAG"TEST 05    str: \"\"    set: +-\n"RESET);
	char *str4 = "";
	char *set4 = "+-"; 
	printf("   clone: %s\n",      strtrim2(str4, set4));
	printf("    mine: %s\n\n",   ft_strtrim(str4, set4));
	return 0;
}