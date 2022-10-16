/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_calloc.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: evan-der <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/29 11:54:44 by evan-der      #+#    #+#                 */
/*   Updated: 2021/10/22 13:05:34 by jaka          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "stdint.h"


void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*ptr;

	if (size && (SIZE_MAX / size) < nmemb)
		return NULL;

	ptr = (void *)malloc(size * nmemb);
	if (!ptr)
		return (0);
	ft_bzero(ptr, size * nmemb);
	return (ptr);
}
