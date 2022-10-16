/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strncmp_main.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: jaka <jaka@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/14 11:29:28 by jaka          #+#    #+#                 */
/*   Updated: 2022/10/14 11:36:46 by jaka          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <string.h>
#include <string.h>

int ft_strncmp2(const char *s1, const char *s2, size_t n)
{
	unsigned int i;

	i = 0;
	if (n == 0)
		return (0);
	while (s1[i] == s2[i] && s1[i] != '\0' && s2[i] != '\0' && i < n - 1)
		i++;
	return (s1[i] - s2[i]);
}
////////////////////////////////////////////////////////////////////////

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

#include "colors.h"
int main(void)
{
	printf(HYEL"\n------------------------------------------------------------");
	printf("\n--- FT_STRNCMP ---------------------------------------------\n\n"RES);

	printf(MAG"Test 01:  strncmp('dcba', 'dcbb', 7)\n"RES);
  	printf("	orig:  %d\n",      strncmp("abcde", "a", 7));
	printf("	eval:  %d\n\n", ft_strncmp("abcde", "a", 7));
//	printf("	mine:  %d\n\n", ft_strncmp3("test", "testss", 7));

}