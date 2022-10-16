#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include "../srcs_eval/libft.h"

int	ft_atoi2(const char *str)
{
	int	i;
	int	num;
	int	sign;

	i = 0;
	sign = 1;
	while (str[i] == ' ' || str[i] == '\t' || str[i] == '\n' || str[i] == '\v' || str[i] == '\f' || str[i] == '\r')
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-') 
			sign = -1;
		i++;
	}
	num = 0;
	while (str[i] && ft_isdigit(str[i]))
	{
		num = num * 10 + str[i] - '0'; 
		i++;
	}
	return (num * sign);
}

//int ft_atoi_main(void)
int main(void)
{	
	printf("\n------------------------------------------------------------");
	printf("\n--- FT_ATOI ------------------------------------------------\n\n");

	printf("TEST 01:\n");
	char *alpha= "123";
	printf("   orig: %d\n",    atoi(alpha));
	printf("   mine: %d\n", ft_atoi(alpha));
	return (0);
}