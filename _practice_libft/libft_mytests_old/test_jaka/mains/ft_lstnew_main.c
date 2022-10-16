#include "libft.h"
#include <stdlib.h>
#include <stdio.h>
#include "../libft_mains.h"
/*

/// LSTNEW ///////////////////////

t_list *ft_lstnew(void *content);

Allocates (with malloc(3)) and returns a new element. 
The variable ’content’ is initialized with the 
value of the parameter ’content’. 
The variable ’next’ is initialized to NULL.

*/

t_list	*ft_lstnew(void const *content)
{
	t_list	*newlink;
	void	*newcontent;

	newlink = (t_list *)malloc(sizeof(t_list));
	if (!newlink)
		return (NULL);

	if (content != NULL)
	{
		newcontent = (void*)content;
		newlink->content = newcontent;
	}
	else
		newlink->content = NULL;
	newlink->next = NULL;
	return (newlink);
}

int ft_lstnew_main(void)
{
	int a = 55;
	char *str = "hello";
	t_list *list1 = ft_lstnew((void*)a);
	t_list *list2 = ft_lstnew(str); 
	
	printf("some_tlist1: %d\n", (int)list1->content);
	printf("some_tlist1: %s\n",      list2->content);
	return 0;
}