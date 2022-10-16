#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "../srcs/libft.h"

int ft_tolower2(int c)
{
	if (c >= 'A' && c <= 'Z')
		return (c - ('A' - 'a'));
//		return (c + 32);  // THIS DOES NOT PASS UNIT TEST 
	else
		return (c);

}

int main(void)
//int ft_tolower_main(void) 
{
	char c1 = 'Q';
	char c2 = 'Q';
	char c3 = 'Q';

	c1 =    tolower(c1);
    c2 = ft_tolower2(c2);
	c3 = ft_tolower(c3);
	

  	printf("orig:  %c\n", c1);
    printf("mine2: %c\n", c2);
    printf("mine:  %c\n", c3);
  	return (0);
}

