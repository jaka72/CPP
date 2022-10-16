/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_atoi.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: evan-der <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/07 14:06:55 by evan-der      #+#    #+#                 */
/*   Updated: 2021/10/22 12:37:32 by jaka          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"



// long long 9223372036854775807
//      the last digit 7 is taken away and then checked
// int 2147483647, int -2147483648
// int 214748364  ,to check, delete last digit
static int	overflow(int sign, long long int num, const char *str, int i)
//static int	overflow(int sign, int num, const char *str, int i)
{
	if (ft_isdigit(str[i + 1]))
		return (-1);
	if (sign == -1 && str[i] > '8')
		return (-1);
	if (sign == -1 && num > 214748364)
		return (-1);
	if (sign == 1 && str[i] > '7')
		return (-1);
	if (sign == 1 && num > 214748364)
		return (-1);
	else
	{
		num = (num * 10) + (str[i] - '0');
		return (num * sign);
	}
}

void	check_sign(int *i, const char *str, int *sign)
{
	while (str[*i] == ' ' || (str[*i] >= '\t' && str[*i] <= '\r'))
		(*i)++;
	if (str[*i] == '-' || str[*i] == '+')
	{
		if (str[*i] == '-')
			*sign = -1;
		(*i)++;
	}
}

//int	ft_atoi(const char *str, int *flag_overflow)
int	ft_atoi(const char *str)
{
	int	i;
	int	sign;
	int	num;

	i = 0;
	sign = 1;
	check_sign(&i, str, &sign);
	num = 0;
//	*flag_overflow = 0;
	while (str[i] && ft_isdigit(str[i]))
	{
		if (num >= 214748364)
		{
			if (overflow(sign, num, str, i) == -1)
				{ ; } //*flag_overflow = 1;
		}
		num = num * 10 + str[i] - '0';
		i++;
	}
	return (num * sign);
}


// MINE OLD
// static int	overflow(int sign, long long num, const char *str, int i)
// {
// 	if (sign == -1 && str[i] > '8')
// 		return (0);
// 	if (sign == -1 && num > 922337203685477580)
// 		return (0);
// 	if (sign == 1 && str[i] > '7')
// 		return (-1);
// 	if (sign == 1 && num > 922337203685477580)
// 		return (-1);
// 	else
// 	{
// 		num = (num * 10) + (str[i] - '0');
// 		return (num * sign);
// 	}
// }

// int			ft_atoi(const char *str)
// {
// 	int			i;
// 	int			sign;
// 	long long	num;

// 	i = 0;
// 	sign = 1;
// 	while (str[i] == ' ' || (str[i] >= '\t' && str[i] <= '\r'))
// 		i++;
// 	if (str[i] == '-' || str[i] == '+')
// 	{
// 		if (str[i] == '-')
// 			sign = -1;
// 		i++;
// 	}
// 	num = 0;
// 	while (str[i] && ft_isdigit(str[i]))
// 	{
// 		if (num >= 922337203685477580)
// 			return (overflow(sign, num, str, i));
// 		num = num * 10 + str[i] - '0';
// 		i++;
// 	}
// 	return (num * sign);
// }


// #include "libft.h"

// FROM SOMEONE
// static int	ft_changer(const char *str, int i)
// {
// 	int	changed;
// 	int	result;

// 	result = 0;
// 	while (str[i] && str[i] >= '0' && str[i] <= '9')
// 	{
// 		changed = str[i] - '0';
// 		result = (result * 10) + changed;
// 		i++;
// 	}
// 	return (result);
// }

// int	ft_atoi(const char *str)
// {
// 	int	i;
// 	int	pos_neg;
// 	int	result;

// 	i = 0;
// 	pos_neg = 1;
// 	while (str[i] == '\n' || str[i] == '\t' || str[i] == '\v'
// 		|| str[i] == '\f' || str[i] == '\r' || str[i] == ' ')
// 		i++;
// 	if (str[i] == '-' || str[i] == '+')
// 	{
// 		if (str[i] == '-')
// 			pos_neg = -1;
// 		i++;
// 	}
// 	if (!(str[i] && str[i] >= '0' && str[i] <= '9'))
// 		return (0);
// 	else
// 		result = ft_changer(str, i);
// 	return (result * pos_neg);
// }
