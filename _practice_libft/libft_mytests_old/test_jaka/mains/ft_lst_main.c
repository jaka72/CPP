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
t_list	*ft_lstnew(void const *content)
{
	t_list	*newlink;

	newlink = (t_list *)malloc(sizeof(t_list));
	if (!newlink)
		return (NULL);
	if (content != NULL)
		newlink->content = (void*)content;
	else
		newlink->content = NULL;
	newlink->next = NULL;
	return (newlink);
}

// ADD NEW MEMBER/LINK TO THE LIST, WITHOUT ANY CONTENT
void	ft_lstadd_front(t_list **list, t_list *newnode)
{
	if (!*list) // ZAKAJ 1 ZVEZDICA? MORDA JE TO PRVI NODE V **list
	{
		*list = newnode; // CE JE LISTA PRAZNA, DOBI ZDAJ PRVI NODE
		return ;
	}
	if (!newnode)
		return ;
	newnode->next = *list;  // ROSADA: TRENUTNI PRVI NODE POSTANE NASLEDNJI
	*list = newnode;        //         NOVI NODE POSTANE PRVI
}

///////////////////////////////////////////////////////////

int ft_lstsize(t_list *list)
{
	int i;
	i = 0;
	if (!list)
		return (i); // NOT NECESSARY
	i++;
	while (list) // ALSO te
	{	
		list = list->next;
		i++;
		printf("  i: %d\n", i);
	}
	return (i);
}

///////////////////////////////////////////////////////////////////

t_list *ft_lstlast(t_list *list)
{
	if (!list)
		return (NULL);
	while (list->next) // WITHOUT next IS SEGFAULT ??
	{
		list = list->next;
		printf("content: %p\n", list);
	}
	return (list); // ZGLEDA DA SME VRNIT NULL, POTEM JE SEGFAULT
}

////////////////////////////////////////////////////////////////

void ft_lstadd_back(t_list **list, t_list *newnode)
{
	t_list *temp;

	if (!*list) // ZAKAJ 1 ZVEZDICA? MORDA JE TO PRVI NODE V **list
	{
		*list = newnode; // CE JE LISTA PRAZNA, DOBI ZDAJ PRVI NODE
		return ;
	}
	temp = *list;
	while (temp->next)
	{
		temp = temp->next;
	}
	temp->next = newnode;
	newnode->next = NULL;
}


// LSTDELONE ///////////////
// It first frees member of node, and then the whole node
void del_list(void *something)
{
	something = NULL;
	free(something);  // CALLED ARG IS A MEMBER list->content
}


void ft_lstdelone(t_list *list, void (*del_list)(void *))
{
	if (!list)
		return ;
	if (del_list)  // NAJPREJ ZBRISE SAMO CONTENT PREKO DRUGE FUNKCIJE
		del_list(list->content);
	free(list);	   // NATO  ZBRISE CEL NODE
}


// MAIN ////////////////////////////////////////////////////////////////////////

int ft_lst_main(void)
{

	int number = 55;
	void *pt = &number;
	char *str1 = "AAAAA";
	//t_list *list1 = ft_lstnew(number);
	t_list *list1 = ft_lstnew(str1); 
	printf("list1->content: %s\n",  list1->content);
	printf("list1->next: %p\n",  list1->next);


	// ADD FRONT ///////////////////
	char *str2 = "BBBBB";
	t_list *list2 = ft_lstnew(str2);
	ft_lstadd_front(&list1, list2);
	printf("list1->content: %s\n",  list1->content);
	printf("list2->content: %s\n",  list2->content);
	printf("list1->next->next: %p\n",  list1->next->next);

	char *str3 = "CCCCC";
	t_list *list3 = ft_lstnew(str3);
	ft_lstadd_front(&list1, list3);
	printf("list1->content: %s\n\n",  list1->content);


	// ADD BACK //////////////////
	t_list *list4 = ft_lstnew("DDDDD");
	ft_lstadd_back(&list1, list4);
	printf("list4: %s\n", list4->content);


	// GET LSTSIZE
	t_list *empty;  // THIS GIVES SEGFAULT, HOW TO PROTECT THIS THEN?
	empty = ft_lstnew("empty");
	int i = ft_lstsize(list1);
	printf("list1, nr of nodes: %d\n", i);

	// GET LAST NODE
	t_list *lastnode = ft_lstlast(list1);
	printf("lastnode: %s\n", lastnode->content);

	
	//printf("list1->content:             %s\n",      list3->content);
	//printf("list1->next->content:       %s\n",      list3->next->content);
	printf("list1->content:          %s\n",      list1->content);
	printf("list1-> ->content:       %s\n",      list1->next->content);
	printf("list1-> -> ->content:    %s\n",      list1->next->next->content);
	printf("list1-> -> -> ->content: %s\n",      list1->next->next->next->content);

	t_list *list5;  // THIS GIVES SEGFAULT, HOW TO PROTECT THIS THEN?
	list5 = ft_lstnew("EEEEE");
	printf("list5->content: %s\n", list5->content);
	ft_lstdelone(list5, del_list);
	//printf("list5->content: %s\n", list5->content);

	return 0;
}