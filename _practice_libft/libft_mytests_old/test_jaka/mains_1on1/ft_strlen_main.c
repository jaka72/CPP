/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strlen_main.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: jmurovec <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/10/30 11:33:09 by jmurovec      #+#    #+#                 */
/*   Updated: 2020/10/30 11:33:09 by jmurovec      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../srcs/libft.h"

int main(void)
//int ft_strlen_main(void)
{
	printf("\n------------------------------------------------------------");
	printf("\n--- FT_STRLEN ---------------------------------------------\n\n");

	printf("TEST 01\n");
	int	len;
	len = ft_strlen("ABCDE");
	printf("String: %s, length: %d\n", "ABCDE", len);
	//write(1, "X\n", 2);
	return (0);
}
