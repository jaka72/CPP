/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_lstadd_front.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: jmurovec <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/25 22:01:57 by jmurovec      #+#    #+#                 */
/*   Updated: 2020/11/25 22:01:57 by jmurovec      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>
#include <stdio.h>
#include "../libft_mains.h"
/*

/// LLSTADD_FRONT ///////////////////////

void ft_lstadd_front(t_list **lst, t_list *new);


Adds the element ’new’ at the beginning of the
list.

(old: Allocates (with malloc(3)) and returns a new element. 
The variable ’content’ is initialized with the 
value of the parameter ’content’. 
The variable ’next’ is initialized to NULL.)

*/


// MAKE NEW LIST, INITIALIZED WITH CONTENT AND NEXT NULL 
t_list	*ft_lstnew2(void const *content)
{
	t_list	*newlink;

	newlink = (t_list *)malloc(sizeof(t_list));
	if (!newlink)
		return (NULL);

	if (content != NULL)
	{
		newlink->content = (void*)content;
	}
	else
		newlink->content = NULL;
	newlink->next = NULL;
	return (newlink);
}

// ADD NEW MEMBER/LINK TO THE LIST, WITHOUT ANY CONTENT
t_list *ft_lstadd_front(t_list **list, t_list *new)
{
	t_list *newlist;

	newlist = malloc(sizeof(t_list)); // mogoce treba cast malloc
	if (!newlist)
		return (NULL);
	newlist->next = *list;
	*list = newlist;
}

int main(void)
{
	int aaa = 55;
	void *pt = &aaa;
	char *str = "hello";
	t_list *list1 = ft_lstnew(aaa);
	t_list *list2 = ft_lstnew(str); 
	
	printf("some_tlist1: %d\n", (int)list1->content);
	printf("some_tlist1: %s\n",      list2->content);


/////////////////////
	t_list list3;
	ft_lstadd_front(&list2, &list3);



	return 0;
}