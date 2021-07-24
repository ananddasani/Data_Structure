// program to implement linked list
/*
                                             ALGO
                                             
                             ALGORITHM FOR INSERTING A NODE
Insert a Node at the beginning
1. Input DATA to be inserted
2. Create a NewNode
3. NewNode → DATA = DATA
4. If (START equal to NULL)
(a) NewNode → Link = NULL
5. Else
(a) NewNode → Link = START
6. START = NewNode
7. Exit

Insert a Node at the end
1. Input DATA to be inserted
2. Create a NewNode
3. NewNode → DATA = DATA
4. NewNode → Next = NULL
8. If (START equal to NULL)
(a) START = NewNode
9. Else
(a) TEMP = START
(b) While (TEMP → Next not equal to NULL)
(i) TEMP = TEMP → Next
10. TEMP → Next = NewNode
11. Exit

Insert a Node at any specified position
1. Input DATA and POS to be inserted
2. initialise TEMP = START; and j = 0
3. Repeat the step 3 while( k is less than POS)
(a) TEMP = TEMP è Next
(b) If (TEMP is equal to NULL)
 (i) Display “Node in the list less than the position”
 (ii) Exit
(c) k = k + 1
4. Create a New Node
5. NewNode → DATA = DATA
6. NewNode → Next = TEMP → Next
7. TEMP → Next = NewNode
8. Exit

                            ALGORITHM FOR DELETING A NODE
1. Input the DATA to be deleted
2. if ((START → DATA) is equal to DATA)
(a) TEMP = START
(b) START = START → Next
(c) Set free the node TEMP, which is deleted
(d) Exit
3. HOLD = START
4. while ((HOLD → Next → Next) not equal to NULL))
(a) if ((HOLD → NEXT → DATA) equal to DATA)
 (i) TEMP = HOLD → Next
 (ii) HOLD → Next = TEMP → Next
(iii) Set free the node TEMP, which is deleted
(iv) Exit
(b) HOLD = HOLD → Next
5. if ((HOLD → next → DATA) == DATA)
(a) TEMP = HOLD → Next
(b) Set free the node TEMP, which is deleted
(c) HOLD → Next = NULL
(d) Exit
6. Disply “DATA not found”
7. Exit

                                ALGORITHM FOR SEARCHING A NODE
1. Input the DATA to be searched
2. Initialize TEMP = START; POS =1;
3. Repeat the step 4, 5 and 6 until (TEMP is equal to NULL)
4. If (TEMP → DATA is equal to DATA)
(a) Display “The data is found at POS”
(b) Exit
5. TEMP = TEMP → Next
6. POS = POS+1
7. If (TEMP is equal to NULL)
(a) Display “The data is not found in the list”
8. Exit

                                ALGORITHM FOR DISPLAY ALL NODES
1. If (START is equal to NULL)
(a) Display “The list is Empty”
(b) Exit
2. Initialize TEMP = START
3. Repeat the step 4 and 5 until (TEMP == NULL )
4. Display “TEMP → DATA”
5. TEMP = TEMP → Next
6. Exit
 */
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
} * head, *last_node;

void insert_beg();
void insert_loc();
void insert_end();
void delete_beg();
void delete_loc();
void delete_end();
void display();
int length();
void search();

int main()
{
    int ch, len;
    printf("\n\t\tLINKED LIST IMPLEMENT \n\n");
    while (1)
    {
        printf("\nMAIN MENU");
        printf("\n1. INSERT AT FRONT\n2. INSERT AT LOCATION\n3. INSERT AT END");
        printf("\n4. DELETE AT FRONT\n5. DELETE AT LOCATION\n6. DELETE AT END");
        printf("\n7. SEARCH\n8. DISPLAY\n9. LENGTH\n10. EXIT");
        printf("\nenter your choice: ");
        scanf("%d", &ch);

        switch (ch)
        {
        case 1:
            insert_beg();
            break;

        case 2:
            insert_loc();
            break;

        case 3:
            insert_end();
            break;

        case 4:
            delete_beg();
            break;

        case 5:
            delete_loc();
            break;

        case 6:
            delete_end();
            break;

        case 7:
            search();
            break;

        case 8:
            display();
            break;

        case 9:
            len = length();
            printf("\nLENGTH OF LL :: %d\n", len);
            break;

        case 10:
            printf("\nexiting...\n\n");
            exit(0);
            break;

        default:
            printf("\ninvalid choice :(\n");
            break;
        }
    }
    return 0;
}

void insert_beg()
{
    struct node *ptr = (struct node *)malloc(sizeof(struct node));
    ptr->next = NULL;

    printf("\nenter data: ");
    scanf("%d", &ptr->data);

    if (head == NULL)
    {
        head = last_node = ptr;
        printf("\nfirst node with data %d created successfully !\n", ptr->data);
        display();
    }
    else
    {
        ptr->next = head;
        head = ptr;
        printf("\n%d inserted at beginning successfully !\n", ptr->data);
        display();
    }
}

void insert_loc()
{
    if (head == NULL)
        printf("\nLINKED LIST IS EMPTY :(\n");
    else
    {
        int loc, len = length();
        printf("\nenter location: ");
        scanf("%d", &loc);

        if (loc > len)
            printf("\nentered location exceed the length of linked list :(\n");
        else if (loc == 1)
            insert_beg();
        else if (loc == len)
            insert_end();
        else
        {
            struct node *ptr, *temp = head;
            ptr = (struct node *)malloc(sizeof(struct node));

            printf("\nenter data: ");
            scanf("%d", &ptr->data);
            ptr->next = NULL;

            int i = 1;
            while (i < loc - 1)
            {
                temp = temp->next;
                i++;
            }
            ptr->next = temp->next;
            temp->next = ptr;
            printf("\nnode inserted at location:%d with data:%d successfully !\n", i + 1, ptr->data);
            display();
        }
    }
}

void insert_end()
{
    if (head == NULL)
        insert_beg();
    else
    {
        struct node *ptr = (struct node *)malloc(sizeof(struct node));
        ptr->next = NULL;

        printf("\nenter data: ");
        scanf("%d", &ptr->data);
        last_node->next = ptr;
        last_node = ptr;
        printf("\nnode with data %d inserted at the end successfully !\n", ptr->data);
        display();
    }
}

void delete_beg()
{
    if (head == NULL)
        printf("\nlinked list is empty:(\n");
    else
    {
        if (head->next == NULL)
        {
            free(head);
            head = last_node = NULL;
            printf("\nthe only node is deleted , LL is empty now\n");
        }
        else
        {
            struct node *temp = head;
            head = head->next;
            temp->next = NULL;
            free(temp);
            printf("\nfirst node deleted successfully :)\n");
            display();
        }
    }
}

void delete_loc()
{
    if (head == NULL)
        printf("\nlinked list is empty\n");
    else
    {
        int loc, len = length();
        printf("\nenter location: ");
        scanf("%d", &loc);

        if (loc > len)
            printf("\nlocation exceed the length of liked list\n");
        else if (loc == 1)
            delete_beg();
        else if (loc == len)
            delete_end();
        else
        {
            struct node *p = head, *q = NULL;

            int i = 1;
            while (i < loc - 1)
            {
                p = p->next;
                i++;
            }            // p points to previous node of targeted node
            q = p->next; // q points to targeted node
            p->next = q->next;
            q->next = NULL;
            free(q);
            printf("\nnode at location %d deleted successfully !\n", i + 1);
            display();
        }
    }
}

void delete_end()
{
    if (head == NULL)
        printf("\nlinked list is empty :(\n");
    else if (head->next == NULL)
        delete_beg();
    else
    {
        struct node *temp = head;

        while (temp->next->next != NULL)
            temp = temp->next;
        free(temp->next);
        temp->next = NULL;
        last_node = temp;
        printf("\nlast node deleted successfully !\n");
        display();
    }
}

void display()
{
    if (head == NULL)
        printf("\nlinked list is empty :(\n");
    else
    {
        struct node *temp = head;

        printf("\nHEAD\n");
        while (temp != NULL)
        {
            printf("%d -> ", temp->data);
            temp = temp->next;
        }
        printf("NULL\n");
    }
}

int length()
{
    if (head == NULL)
        return 0;

    struct node *temp = head;
    int count = 0;

    while (temp != NULL)
    {
        count++;
        temp = temp->next;
    }
    return count;
}

void search()
{
    if (head == NULL)
        printf("\nlinked list is empty :(\n");
    else
    {
        int found = 0, key, count = 0;
        struct node *temp = head;

        printf("\nenter element you want to search : ");
        scanf("%d", &key);

        while (temp != NULL && !found)
        {
            count++;
            if (key == temp->data)
                found = 1;
            temp = temp->next;
        }
        if (!found)
            printf("\n%d is not present in the linked list :(\n", key);
        else
            printf("\n%d present at node number :: %d\n", key, count);
    }
}
