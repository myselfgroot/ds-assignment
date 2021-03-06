#include <stdio.h>
#include <stdlib.h>

typedef struct nodetype
{
    int data;
    struct nodetype *next;
} node;

node *insert(node *);
node *concat(node *, node *);
void display(node *);

int main()
{
    node *first = NULL, *second = NULL, *both = NULL;
    int ch = 1;
    while (ch >= 1 && ch <= 3)
    {
        printf("\n1: create first list\n2: create second list\n3: display all Lists\n[Else Exit]\n");
        printf("Enter your choice: ");
        scanf("%d", &ch);

        if (ch == 1)
            first = insert(first);
        if (ch == 2)
            second = insert(second);
        if (ch == 3)
        {
            printf("First List: ");
            display(first);
            printf("\nSecond List: ");
            display(second);
            printf("\nBoth List: ");
            both = concat(first, second);
            display(both);
            printf("\n");
        }
    }
    return 0;
}

node *insert(node *O)
{
    node *P = malloc(sizeof(node));
    printf("Enter number: ");
    scanf("%d", &P->data);

    P->next = O; // inserting node at left side
    return P;    // returning the newly inserted node
}

node *concat(node *first, node *second)
{
    node *T = first; // storing first in tmp
    while (T->next != NULL)
        T = T->next;  // finding the last element of first
    T->next = second; // joining the first last to the second
    return first;     // returning the first
}

void display(node *P)
{
    while (P != NULL)
    {
        printf("%d ", P->data);
        P = P->next; // moving the node to the next node
    }
}