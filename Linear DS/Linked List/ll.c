#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
} * head;

void insert();
void delete ();
void display();

int main()
{
    int ch;

    while (1)
    {
        printf("\nMAIN MENU\n");
        printf("1. INSERT\n2.  INSERT AT END\n3.DISPLAY\n4. EXIT\n");
        printf("enter your choice: ");
        scanf("%d", &ch);

        switch (ch)
        {
        case 1:
            insert();
            break;

        case 2:
            insert_end();
            break;

        case 3:
            display();
            break;

        case 4:
            exit(0);
            break;

        default:
            printf("invalid choice \n");
            break;
        }
    }
    return 0;
}

void insert()
{
    struct node *ptr = (struct node *)malloc(sizeof(struct node)); // node created
    ptr->next = NULL;

    printf("enter the data :: ");
    scanf("%d", &ptr->data);

    if (head == NULL)
    {
        head = ptr;
        printf("\nfirst node created successfully :)\n");
    }
    else
    {
        ptr->next = head;
        head = ptr;
        printf("\nnode inserted at the beginning successfully :)\n");
    }
}

void insert_end()
{
    struct node *temp = head;
    struct node *ptr = (struct node *)malloc(sizeof(struct node)); // node created
    ptr->next = NULL;

    printf("\nenter the data :: ");
    scanf("%d", &ptr->data);

    while (temp->next != NULL)
        temp = temp->next;

    temp->next = ptr;
    printf("node inserted at the end successfully :)\n");
}

void display()
{
    struct node *temp = head;

    while (temp != NULL)
    {
        printf("%d  ", temp->data);
        temp = temp->next;
    }
}