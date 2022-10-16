#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include "../srcs_eval/libft.h"
#include "../libft_mains.h"

/*
ERRORS TEST UNIT

[KO]: your atoi does not work with over long max value
*/

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

int main(void)
{	
	int i;

	i = 0;

	printf(HYEL"\n------------------------------------------------------------");
	printf("\n--- FT_ATOI ------------------------------------------------\n\n"RESET);

	char *alpha= "123";
	printf(MAG"TEST %d: atoi(%s)\n"RESET, i++, alpha);
	printf("   orig: %d\n",    atoi(alpha));
	printf("   mine: %d\n\n", ft_atoi(alpha));

//9223372036854775807
	char *a21= "9223372036854775806"; // 18 cifers
	printf(MAG"TEST %d:   long long int \"%s\",  18 digits\n"RESET, i++, a21);
	printf("   orig: %d\n",      atoi(a21));
	printf("   mine: %d\n\n", ft_atoi(a21));

	char *a20= "9223372036854775807"; // 18 cifers
	printf(MAG"TEST %d:   long long int \"%s\",  18 digits\n"RESET, i++, a20);
	printf("   orig: %d\n",      atoi(a20));
	printf("   mine: %d\n\n", ft_atoi(a20));


	char *a2= "922337203685477588"; // 18 cifers
	printf(MAG"TEST %d:   long long int \"%s\",  18 digits\n"RESET, i++, a2);
	printf("   orig: %d\n",      atoi(a2));
	printf("   mine: %d\n\n", ft_atoi(a2));

	char *a3= "9223372036854775889"; // 19 cifers  
	printf(MAG"TEST %d:   long long int \"%s\",  19 digits\n"RESET, i++, a3);
	printf("   orig: %d\n",      atoi(a3));
	printf("   mine: %d\n\n", ft_atoi(a3));





	char *a4= "2147483647";
	printf(MAG"TEST %d:   int \"%s\" \n"RESET, i++, a4);
	printf("   orig:       %d\n",      atoi(a4));
	printf("   mine:       %d\n\n", ft_atoi(a4));

	char *a5= "2147483648";
	printf(MAG"TEST %d:   int \"%s\" \n"RESET, i++, a5);
	printf("   orig:      %d\n",      atoi(a5));
	printf("   mine:      %d\n\n", ft_atoi(a5));

	char *a6= "2147483649";
	printf(MAG"TEST %d:   int \"%s\" \n"RESET, i++, a6);
	printf("   orig:      %d\n",      atoi(a6));
	printf("   mine:      %d\n\n", ft_atoi(a6));

	char *a7= "-2147483648";
	printf(MAG"TEST %d:   int \"%s\" \n"RESET, i++, a7);
	printf("   orig:       %d\n",      atoi(a7));
	printf("   mine:       %d\n\n", ft_atoi(a7));

	char *a8= "-2147483649";
	printf(MAG"TEST %d:   int \"%s\" \n"RESET, i++, a8);
	printf("   orig:        %d\n",      atoi(a8));
	printf("   mine:        %d\n\n", ft_atoi(a8));
	return (0);
}