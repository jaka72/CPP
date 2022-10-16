#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "../srcs/libft.h"

int	ft_lenint(int nbr)
{
	int len;

	len = 0;
	len = (nbr <= 0 ? 1 : 0);
	while (nbr != 0)
	{
		nbr = nbr / 10;
		len++;
	}
	return (len);
}
/*
char		*clone_itoa(int n)
{
	unsigned int	nbr;
	char			*str;
	int				sign;
	int				size;

	sign = (n < 0 ? 1 : 0);
	str = NULL;
	size = ft_lenint(n);
	nbr = (n < 0 ? -n : n);
	if (!(str = (char *)malloc(sizeof(char) * size + 1)))
		return (NULL);
	str[size--] = '\0';
	while (size >= 0)
	{
		str[size] = nbr % 10 + '0';
		nbr = nbr / 10;
		size--;
	}
	if (sign == 1)
		str[0] = '-';
	return (str);
}
*/
/*
char	*ft_itoa2(int n)
{
	char	*pt;
	int		len;
	int		temp;

	temp = n;
	len = 1;
	while ((temp = temp / 10))
		len++;
	pt = malloc(sizeof(char) * (len + 1));
	if (!pt)
		return (NULL);
	pt[len] = '\0';
	len--;
	while (len >= 0)
	{
		pt[len] = (n % 10) + '0';
		n = n / 10;
		len--;
	}
	return (pt);
}

char	*ft_itoa3(int n)
{
	char	*pt;
	int		len;
	int		temp;

	temp = n;
	len = 1;
	while ((temp = temp / 10))
		len++;
	if (!(pt = malloc(sizeof(char) * (len + 1))))
		return (NULL);
	if (n < 0)
	{
		pt[0] = '-';
		n = n * (-1);	
		len = len + 1;
	}
	pt[len] = '\0';
	len--;
	while (len > 0)
	{
		pt[len] = (n % 10) + '0';
		n = n / 10;
		len--;
	}
	return (pt);
}
*/

int main(void)
//int ft_itoa_main (void) 
{
	printf("\n------------------------------------------------------------");
	printf("\n--- FT_ITOA ------------------------------------------------\n\n");

	printf("Test 01:   0\n");
	//printf("   clone:  %s\n",  clone_itoa(0));
   	printf("    mine:  %s\n\n",   ft_itoa(0));

	printf("Test 02:   9\n");
	//printf("   clone:  %s\n",  clone_itoa(9));
   	printf("    mine:  %s\n\n",  ft_itoa(9));

	printf("Test 03:   -9\n");
	//printf("   clone:  %s\n",  clone_itoa(-9));
   	printf("    mine:  %s\n\n",  ft_itoa(-9));
	 
	printf("Test 04:   10\n");
	//printf("   clone:  %s\n",  clone_itoa(10));
   	printf("    mine:  %s\n\n",  ft_itoa(10));

	printf("Test 05:   -10\n");
	//printf("   clone:  %s\n",  clone_itoa(-10));
   	printf("    mine:  %s\n\n",  ft_itoa(-10));

	printf("Test 06:   8124\n");
	//printf("   clone:  %s\n",  clone_itoa(8124));
   	printf("    mine:  %s\n\n",  ft_itoa(8124));

	printf("Test 07:   -9874\n");
	//printf("   clone:  %s\n",  clone_itoa(-9874));
   	printf("    mine:  %s\n\n",  ft_itoa(-9874));

	printf("Test 08:   543000\n");
	//printf("   clone:  %s\n",  clone_itoa(543000));
   	printf("    mine:  %s\n\n",  ft_itoa(543000));

	printf("Test 09:   -2147483648LL\n");
	//printf("   clone:  %s\n",  clone_itoa(-2147483648LL));
   	printf("    mine:  %s\n\n",  ft_itoa(-2147483648LL));

	printf("Test 10:   2147483647\n");
	//printf("   clone:  %s\n",  clone_itoa(2147483647));
   	printf("    mine:  %s\n\n",  ft_itoa(2147483647));

    printf("Test 11:   -2147483648\n");
	//printf("   clone:  %s\n",  clone_itoa(-2147483648));
   	printf("    mine:  %s\n\n",  ft_itoa(-2147483648));

    return(0);
}

