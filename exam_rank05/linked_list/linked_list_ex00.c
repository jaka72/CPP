#include <stdio.h>
#include <stdlib.h>



struct node 
{
    int data;                        //Data of the node
    struct node *next;           //Address of the next node
} *firstNode;





void createNodeList(int n)
{
    struct node *newNode, *tmp;
    int data, i;
    firstNode = (struct node *)malloc(sizeof(struct node)); // needs checking if NULL


    firstNode->data = 5;      
    firstNode->next = NULL; // links the address field to NULL
    tmp = firstNode;


    for (i = 0; i < n; i++)
    {
        newNode = (struct node *)malloc(sizeof(struct node));    // Creating n nodes and adding to linked list

        newNode->data = i + 10;        // links the data field of newNode with data
        newNode->next = NULL;     // links the address field of newNode with NULL

        tmp->next = newNode;      // links previous node i.e. tmp to the newNode
        tmp = tmp->next; 
        
    }
}




void displayList()
{
    struct node *tmp;
    if (firstNode == NULL)
        printf(" List is empty.");
    else
    {
        tmp = firstNode;
        while(tmp != NULL)
        {
            printf(" Data = %d\n", tmp->data);       // prints the data of current node
            tmp = tmp->next;                     // advances the position of current node
        }
    }
} 





int main()
{
    int n;
		printf("\n Linked List : To create and display Singly Linked List :\n");
		printf("-------------------------------------------------------------\n");
		

    createNodeList(3);
    printf("\n Data entered in the list : \n");
    displayList();
    //system("leaks a.out");
    return 0;
}
