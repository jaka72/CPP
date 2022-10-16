/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strtrim.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: evan-der <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/14 14:18:23 by evan-der      #+#    #+#                 */
/*   Updated: 2021/10/26 14:17:11 by jmurovec      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// mine


char	*ft_strtrim(char const *str, char const *set)
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



/*
evan-der

static int	ft_search_set(char const *set, char check)
{
	int	i;

	i = 0;
	while (set[i])
	{
		if (check == set[i])
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*s2;
	int		begin;
	int		end;

	begin = 0;
	if (!s1)
		return (0);
	end = ft_strlen(s1);
	while (s1[begin] && ft_search_set(set, s1[begin]))
		begin++;
	while (end > begin && ft_search_set(set, s1[end - 1]))
		end--;
	s2 = (char *)malloc(sizeof(char) * (end - begin + 1));
	if (!s2)
		return (0);
	ft_strlcpy(s2, &s1[begin], end - begin + 1);
	return (s2);
}
*/