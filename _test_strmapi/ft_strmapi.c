#include <stdlib.h>
#include <stdio.h>
// #include "libft.h"

#include <stddef.h>

size_t	ft_strlen(const char *str)
{
	size_t i;

	i = 0;
	while (*str)
	{
		i++;
		str++;
	}
	return (i);
}


char	*ft_strmapi(char const *s, char (*func)(unsigned int x, char c))
{
	char	*newstr;
	int		i;

	int x = 3;

	if (!s)
		return (NULL);
	newstr = malloc((ft_strlen(s) + 1) * sizeof(char));
	if (!newstr)
		return (NULL);
	i = 0;
	while (s[i])
	{
		newstr[i] = func(x, s[i]);
		i++;
	}
	newstr[i] = '\0';
	return (newstr);
}


char change(unsigned int n, char c)
{
    n = 2;
    c = c + 2;
    return (c);
}


int main()
{
    char *str = "abcde";

    char *str2;
    str2 = ft_strmapi(str, change(1, 'c'));
    printf("str2: %s\n", str2);
}
