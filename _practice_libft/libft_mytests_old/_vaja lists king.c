#include<stdio.h>
#include<stdlib.h>
#include <string.h>

// funkcija vrne novi pointer, ki kaže na novi memory block (node) z novim value
//   pointer "first" začne kazat na ta novi node
//   ta novi node pa zdaj kaže na prejšnji node
//   vedno se na začetek vrine novi node, na katerega zdaj kaze variabla First
// MOŽNO JE first UPORABIT TUDI KOT POINTER TO POINTER

struct node {
  int value;
  struct node *next;
};

struct node *first = NULL;
struct node *read_numbers(struct node **first);
//struct node *add_to_list(struct node *first, int n); // NO POINTER
void add_to_list(struct node **first, int n);		   // WITH POINTER
struct node *searchlist(struct node* first, int n);

// LINKED LIST - SEARCHING WITH FOR OR WHILE
// VARIANTS C AND D



int main(void)
{
//  first = add_to_list(first, 10);  // namesto tega je zdaj posebna funkcija
    read_numbers(&first);                  //    read_numbers() ,ki nalaga cifre v listo

// VARIANT C, like B but shorter (CAN BE ALSO SEPARATE IN A FUNCTION)
    struct node* p;  // nujno p, drugače se spremeni originalni first

    for ( p = first; p!=NULL; p=p->next) { // PRINT THE WHOLE LIST
            printf("  %d", p->value);
    }
 //   printf("C Found: %d\n", p->value);

//    searchlist(first, 4);

/*    printf("%d ", first->value);
    printf("%d ", first->next->value);
    printf("%d ", first->next->next->value); */

    return 0;
}

//  VARIANT D - WITH WHILE
struct node *searchlist(struct node* first, int n)
{
    while (first != NULL && first->value != n ) {
        first = first->next;
    }
    printf("D Found: %d\n", first->value);
    return first;
}

struct node* read_numbers(struct node **first)
{
    int n;
    printf("Enter integers (0 to terminate):\n");

    for ( ; ; ) {
        scanf("%d", &n);
        if (n==0)
            return *first;
        //first = add_to_list(first, n);	   // no pointer
		add_to_list(first, n);  // with pointer
    }
}


// VARIANTA BREZ ALI S POINTERJEM
// struct node* add_to_list(struct node *first, int n)
void add_to_list(struct node **first, int n)
{
    struct node *newnode;
    newnode = malloc(sizeof(struct node));
    if (newnode == NULL) {
        printf("Error: malloc failed in add-to-list\n");
        exit(EXIT_FAILURE);
    }
/*    newnode->value = n;     // BREZ POINTERJA
    newnode->next = first;
    return newnode; */
	newnode->value = n; 	  // S POINTERJEM, NE RABI RETURN
    newnode->next = *first;
	*first = newnode;		  // CALL: add_to_list(&first, 10);
}