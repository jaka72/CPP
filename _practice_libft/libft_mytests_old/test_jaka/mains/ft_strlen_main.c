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

#include <stdio.h>
#include "../srcs_eval/libft.h"
#include "../libft_mains.h"

int ft_strlen_main(void)
{
	printf(HYEL"\n------------------------------------------------------------");
	printf("\n--- FT_STRLEN ---------------------------------------------\n\n"RESET);

	printf(MAG"TEST 01\n"RESET);
	int	len;
	len = ft_strlen("ABCDE");
	printf("String: %s, length: %d\n", "ABCDE", len);
	//write(1, "X\n", 2);
	return (0);
}
