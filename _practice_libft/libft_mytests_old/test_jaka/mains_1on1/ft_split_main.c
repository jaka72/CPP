/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_split.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: jmurovec <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/03 12:44:38 by jmurovec      #+#    #+#                 */
/*   Updated: 2020/11/03 12:44:38 by jmurovec      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
//#include <bsd/string.h>
#include "../libft_mains.h"
#include "../srcs_eval/libft.h"


static void		*free_arr2(char **splitted, int i)
{
	int	n;

	n = 0;
	while (n < i)
	{
		free(splitted[i]);
		i++;
	}
	free(splitted);
	return (NULL);
}

static int		count_words2(char const *s, char c)
{
	int		i;
	int		words;

	words = 0;
	i = 0;
	while (s[i])
	{
		if (s[i] != c && (s[i + 1] == c || s[i + 1] == '\0'))
			words++;
		i++;
	}
	return (words);
}

static int		words_len2(char const *s, char c)
{
	int		i;
	int		len;

	i = 0;
	len = 0;
	while (s[i] != c && s[i] != '\0')
	{
		i++;
		len++;
	}
	return (len);
}

static char		**fill2(char const *s, int words, char c, char **splitted)
{
	int		i;
	int		j;
	int		len;

	i = 0;
	while (i < words)
	{
		while (*s == c)
			s++;
		len = words_len2(s, c);
		splitted[i] = (char *)malloc(sizeof(char) * (len + 1));
		if (!splitted)
			return (free_arr2(splitted, i));
		j = 0;
		while (j < len)
		{
			splitted[i][j] = *s;
			j++;
			s++;
		}
		splitted[i][j] = '\0';
		i++;
	}
	splitted[i] = NULL;
	return (splitted);
}

char			**ft_split2(char	const *s, char c)
{
	char	**splitted;
	int		words;

	if (!s)
		return (NULL);
	words = count_words2(s, c);
	splitted = (char **)malloc(sizeof(char*) * (words + 1));
	if (!splitted)
		return (NULL);
	splitted = fill2(s, words, c, splitted);
	return (splitted);
}

int main(void)
//int ft_split_main(void)
{
	printf("\n------------------------------------------------------------");
	printf("\n--- FT_SPLIT -----------------------------------------------\n\n");
	
	int i = 0;
	printf(MAG"TEST 01\n");
	char dl = '-';
	char **arr;
	char *str1 = "---asd---qwe---wer---ert---dfg---";
	printf("   String to split: %s\n   Delimiter: %c\n"RESET, str1, dl);
	printf("\n      clone: ");
	arr = ft_split2(str1, dl);
	while (arr[i] != NULL)
	{	printf("%s ", arr[i]);  i++; }
	i = 0;
	while (arr[i] != NULL)
	{	free(arr[i]);	i++; }
	free(arr[i]);
	free(arr);

	printf("\n       mine: ");
	i = 0;
	dl = '-';
	char **arr2;
	char *str2 = "---asd---qwe---wer---ert---dfg---";
	arr2 = ft_split(str2, dl);
	while (arr2[i] != NULL)
	{	printf("%s ", arr2[i]); i++; }
	i = 0;
	while (arr2[i] != NULL)
	{	free(arr2[i]);	i++; }
	free(arr2[i]);
	free(arr2);

	// TEST 02 /////////////////////////////////////////////////////////////////////////

	printf(MAG"\n\nTEST 02\n");
	i = 0;
	dl = '-';
	char **arr2a;
	char *str2a = "---oneword---";
	printf("   String to split: %s\n   Delimiter: %c\n"RESET, str2a, dl);
	printf("\n      clone: ");
	arr2a = ft_split2(str2a, dl);
	while (arr2a[i] != NULL)
	{	printf("%s ", arr2a[i]);  i++; }
	i = 0;
	while (i < 1)
	{	free(arr2a[i]);	i++; }
	free(arr2a);

	printf("\n       mine: ");
	i = 0;
	dl = '-';
	char **arr2b;
	char *str2b = "---oneword---";
	arr2b = ft_split(str2b, dl);
	while (arr2b[i] != NULL)
	{	printf("%s ", arr2b[i]); i++; }
	i = 0;
	while (i < 1)
	{   free(arr2b[i]);  i++; }
	free(arr2b);

	// TEST 03 /////////////////////////////////////////////////////////////////////////

	printf(MAG"\n\nTEST 03\n");
	i = 0;
	dl = '-';
	char **arr3a;
	char *str3a = "----------";
	printf("   String to split: %s\n   Delimiter: %c\n"RESET, str3a, dl);
	printf("\n      clone: ");
	arr3a = ft_split2(str3a, dl);
	while (arr3a[i] != NULL)
	{	printf("%s ", arr3a[i]);  i++; }
	i = 0;
	while (i < 1)
	{	free(arr3a[i]);	i++; }
	free(arr3a);

	printf("\n       mine: ");
	i = 0;
	dl = '-';
	char **arr3b;
	char *str3b = "----------";
	arr3b = ft_split(str3b, dl);
	while (arr3b[i] != NULL)
	{	printf("%s ", arr3b[i]); i++; }
	i = 0;
	while (i < 1)
	{   free(arr3b[i]);  i++; }
	free(arr3b);

	// TEST 04 /////////////////////////////////////////////////////////////////////////

	printf(MAG"\n\nTEST 04\n");
	i = 0;
	dl = '-';
	char **arr4a;
	char *str4a = "abcd efgh ijkl mnop rstu";
	printf("   String to split: %s\n   Delimiter: %c\n"RESET, str4a, dl);
	printf("\n      clone: ");
	arr4a = ft_split2(str4a, dl);
	while (arr4a[i] != NULL)
	{	printf("%s ", arr4a[i]);  i++; }
	i = 0;
	while (i < 1)
	{	free(arr4a[i]);	i++; }
	free(arr4a);

	printf("\n       mine: ");
	i = 0;
	dl = '-';
	char **arr4b;
	char *str4b = "abcd efgh ijkl mnop rstu";
	arr4b = ft_split(str4b, dl);
	while (arr4b[i] != NULL)
	{	printf("%s ", arr4b[i]); i++; }
	i = 0;
	while (i < 1)
	{   free(arr4b[i]);  i++; }
	free(arr4b);

	// TEST 05 /////////////////////////////////////////////////////////////////////////

	printf(MAG"\n\nTEST 05\n");
	i = 0;
	dl = '-';
	char **arr5a;
	char *str5a = "abcd---efgh";
	printf("   String to split: %s\n   Delimiter: %c\n"RESET, str5a, dl);
	printf("\n      clone: ");
	arr5a = ft_split2(str5a, dl);
	while (arr5a[i] != NULL)
	{	printf("%s ", arr5a[i]);  i++; }
	i = 0;
	while (i < 1)
	{	free(arr5a[i]);	i++; }
	free(arr5a);

	printf("\n       mine: ");
	i = 0;
	dl = '-';
	char **arr5b;
	char *str5b = "abcd---efgh";
	arr5b = ft_split(str5b, dl);
	while (arr5b[i] != NULL)
	{	printf("%s ", arr5b[i]); i++; }
	i = 0;
	while (i < 1)
	{   free(arr5b[i]);  i++; }
	free(arr5b);

	// TEST 06 /////////////////////////////////////////////////////////////////////////

	printf(MAG"\n\nTEST 06\n");
	i = 0;
	dl = ' ';
	char **arr6a;
	char *str6a = "   lorem   ipsum dolor     sit amet, consectetur   adipiscing elit. Sed non risus. Suspendisse   ";
	printf("   String to split: %s\n   Delimiter: %c\n"RESET, str6a, dl);
	printf("\n      clone: ");
	arr6a = ft_split2(str6a, dl);
	while (arr6a[i] != NULL)
	{	printf("%s ", arr6a[i]);  i++; }
	i = 0;
	while (i < 1)
	{	free(arr6a[i]);	i++; }
	free(arr6a);

	printf("\n       mine: ");
	i = 0;
	dl = ' ';
	char **arr6b;
	char *str6b = "   lorem   ipsum dolor     sit amet, consectetur   adipiscing elit. Sed non risus. Suspendisse   ";
	arr6b = ft_split(str6b, dl);
	while (arr6b[i] != NULL)
	{	printf("%s ", arr6b[i]); i++; }
	i = 0;
	while (i < 1)
	{   free(arr6b[i]);  i++; }
	free(arr6b);	


	printf("\n------------------------------------------------------------\n");

	return (0);
}


