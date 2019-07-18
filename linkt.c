#include<stdio.h> 
#include<stdlib.h>

typedef struct link{
    int data;
    struct link *next;
}node;

void insert(node **head)
{
    int d;
    scanf("%d", &d);
    node *newnode = (node *)malloc(sizeof(node));
    newnode->data = d ;
    newnode->next = *head ;
    *head = newnode ;
}

void del(node *h)
{
    node *t = h;
    h = t->next;
    // t->next = r ;
    free(t);
}

void display(node *h)
{
    for(node *i=h ; i != NULL ; i = i->next)
        printf("%d\n", i->data);
        // cout << i->data << endl ;
}

int main()
{
    node *head=NULL;
    // r->data = 23;
    // r->next = NULL;
    int ch;
    do{
        printf("1. Insert\n2. Delete\n3. Display\n4. Exit") ;
        scanf("%d", &ch) ;
        switch (ch)
        {
        case 1:
            insert(&head);
            break;
        case 2:
            del(head);
            break;
        case 3:
            display(head);
            break;
        case 4:
            exit(0);
        }
    }while (ch != 4);
    // end:
    // cout << r->data;
    // insert(&head);
    return 0;
}