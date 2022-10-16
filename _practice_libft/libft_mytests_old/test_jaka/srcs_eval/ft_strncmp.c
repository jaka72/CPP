/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strncmp.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: evan-der <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/03 16:51:05 by evan-der      #+#    #+#                 */
/*   Updated: 2021/10/26 14:58:11 by jmurovec      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"



// mine
int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t i;  // prej je bil unsigned int

	i = 0;
	if (n == 0)
		return (0);
	while (i < n - 1 && s1[i] != '\0' && s2[i] != '\0') // WHY n -1 ???  ,ZARADI ZADNJE VRSTICE   
	{				  //                       KO JE i == n-1 ,TAKRAT SE LOOP USTAVI, AMPAK i JE ZE POVECAN NA i++
					  // 					     NATO V ZADNJI VRSTICI ODSTEJE NASLEDNJA 2 ZNAKA, TOREJ ZADNJA DVA 
					  // 					   CE JE n == 4 , POTEM PRIMERJA s[3] == s[3]
		if (s1[i] == s2[i])
			i++;
		else
		{   // THIS SEEMS TO BE CRUCIAL IN THE CASE OF INPUT test\100, test\200, test\300
			// WITHOUT CASTING INTO unsigned char IT GIVES WRONG RESULT
			//printf("normal: %d, unsigned: %d\n", s1[i], (unsigned char)s1[i]);
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
		}
	}
	//printf("%d, %d\n", s1[i], (unsigned char)s1[i]);
	return (s1[i] - s2[i]);
}



// int	ft_strncmp(const char *s1, const char *s2, size_t n)
// {
// 	size_t	i;

// 	i = 0;
// 	while (i < n && s1[i] && s2[i])
// 	{
// 		if (s1[i] == s2[i])
// 			i++;
// 		else
// 			return (*(unsigned char *)(s1 + i) - *(unsigned char *)(s2 + i));
// 	}
// 	if (i < n)
// 		return (*(unsigned char *)(s1 + i) - *(unsigned char *)(s2 + i));
// 	return (0);
// }
