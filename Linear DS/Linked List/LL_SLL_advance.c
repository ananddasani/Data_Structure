// in this program the head node will not global and will  be passed to each function everytime and lots of other changes
/*
                                                    ALGO
//This function will reverse the linked list
void Rev()
{
    struct node *p1, *p2, *p3;
    if (start->link == NULL) //only one element
        return;

    p1 = start;
    p2 = p1->link;
    p3 = p2->link;
    p1->link = NULL;
    p2->link = p1;
    
    while (p3 != NULL)
    {
        p1 = p2;
        p2 = p3;
        p3 = p3->link;
        p2->link = p1;
    }
    start = p2;
}
*/
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
} * last_node, *temp;
typedef struct node NODE;

NODE *get_node();
NODE *insert_bulk(NODE *);
void insert_before(NODE *);
void insert_after(NODE *);

void delete_before(NODE *);
void delete_at(NODE *);
void delete_after(NODE *);

void search(NODE *);
void swap();
NODE *reverse(NODE *);
void display(NODE *);
void mid(NODE *);

int main()
{
    int ch;
    NODE *head = NULL;

    printf("\n\t\tLINKED LIST IMPLEMENTION\n");
    while (1)
    {
        printf("\nMAIN MENU\n");
        printf("1.  INSERT IN BULK\n2.  INSERT BEFORE DATA\n3.  INSERT AFTER DATA\n");
        printf("4.  DELETE BEFORE DATA\n5.  DELETE AFTER DATA\n");
        printf("6.  SEARCH DATA\n7.  SWAP NODES'S DATA\n8.  REVERSE LL\n9.  DISPLAY\n10. MID\n11. EXIT\n");
        printf("enter your choice: ");
        scanf("%d", &ch);

        switch (ch)
        {
        case 1:
            head = insert_bulk(head);
            break;

        case 2:
            insert_before(head);
            break;

        case 3:
            insert_after(head);
            break;

        case 4:
            delete_before(head);
            break;

        case 5:
            delete_after(head);
            break;

        case 6:
            search(head);
            break;

        case 7:
            swap();
            break;

        case 8:
            head = reverse(head);
            break;

        case 9:
            display(head);
            break;

        case 10:
            mid(head);
            break;

        case 11:
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

NODE *get_node()
{
    NODE *temp = (NODE *)malloc(sizeof(NODE));
    temp->next = NULL;

    return temp;
}

NODE *insert_bulk(NODE *head)
{
    int n, i = 1;
    NODE *ptr = NULL;

    printf("\nenter the number of data you want to insert: ");
    scanf("%d", &n);

    while (i <= n)
    {
        ptr = get_node();
        printf("\nenter data: ");
        scanf("%d", &ptr->data);
        ptr->next = NULL;

        if (head == NULL)
        {
            head = last_node = ptr;
            printf("\nfirst node with data:%d created successfully !\n", ptr->data);
            display(head);
        }
        else
        {
            last_node->next = ptr;
            last_node = ptr;
            printf("\n%d appended successfully :)\n", ptr->data);
            display(head);
        }
        i++;
    }
    return head;
}

void insert_before(NODE *head)
{
    if (head == NULL)
        printf("\nLL IS EMPTY\n");
    else
    {
        int key, found = 0;
        NODE *temp = head;
        printf("\nbefore which element you want to insert: ");
        scanf("%d", &key);

        if (key == head->data)
            printf("\ncan't insert before head node :(\n");
        else
        {
            while (temp != NULL && !found)
            {
                if (temp->next->data == key)
                    found = 1;
                else
                    temp = temp->next;
            }
            if (!found)
                printf("\n%d not present anywhere in the linked list :(\n", key);
            else
            {
                NODE *ptr = get_node();
                printf("\nenter data: ");
                scanf("%d", &ptr->data);

                ptr->next = temp->next;
                temp->next = ptr;
                printf("\n%d inserted before %d !\n", ptr->data, key);
                display(head);
            }
        }
    }
}

void insert_after(NODE *head)
{
    if (head == NULL)
        printf("\nLL IS EMPTY :(\n");
    else
    {
        int key;
        printf("\nafter which element you want to insert data: ");
        scanf("%d", &key);

        if (key == last_node->data)
            printf("\ncan't insert after last_node :(\n");
        else
        {
            int found = 0;
            NODE *temp = head;
            while (temp != NULL && !found)
            {
                if (temp->data == key)
                    found = 1;
                else
                    temp = temp->next;
            }
            if (!found)
                printf("\n%d not present anywhere in linked list :(\n", key);
            else
            {
                NODE *ptr = get_node();
                printf("\nenter data: ");
                scanf("%d", &ptr->data);
                ptr->next = temp->next;
                temp->next = ptr;
                printf("\n%d inserted after %d successfully !\n", ptr->data, key);
                display(head);
            }
        }
    }
}

void delete_before(NODE *head)
{
    if (head == NULL)
        printf("\nLL IS EMPTY\n");
    else
    {
        int key, found = 0;
        NODE *temp = head;
        printf("\nbefore which element you want to delete: ");
        scanf("%d", &key);

        if (key == head->data || key == head->next->data)
            printf("\ncan't update head node :(\n");
        else
        {
            while (temp != NULL && !found)
            {
                if (temp->next->data == key)
                    found = 1;
                else
                    temp = temp->next;
            }
            if (!found)
                printf("\n%d not present anywhere in the linked list :(\n", key);
            else
            {
                NODE *p = temp->next;
                temp->next = p->next;
                p->next = NULL;
                free(p);
                printf("\nelement %d deleted successfully !\n", key);
                display(head);
            }
        }
    }
}

void delete_after(NODE *head)
{
    if (head == NULL)
        printf("\nLL IS EMPTY :(\n");
    else
    {
        int key;
        printf("\nafter which element you want to delete data: ");
        scanf("%d", &key);

        if (key == last_node->data)
            printf("\ncan't delete after last_node :(\n");
        else
        {
            int found = 0;
            NODE *temp = head;
            while (temp != NULL && !found)
            {
                if (temp->data == key)
                    found = 1;
                else
                    temp = temp->next;
            }
            if (!found)
                printf("\n%d not present anywhere in linked list :(\n", key);
            else
            {
                NODE *q = NULL;
                if (temp->next->data == last_node->data)
                {
                    q = temp->next;
                    temp->next = NULL;
                    last_node = temp;
                    free(q);
                    printf("\nlast_node deleted successfully !\n");
                    display(head);
                }
                else
                {
                    temp->next = q->next;
                    q->next = NULL;
                    free(q);
                    printf("\nelement after %d deleted successfully !\n", key);
                    display(head);
                }
            }
        }
    }
}

void search(NODE *head)
{
    if (head == NULL)
        printf("\nLL IS EMPTY :(\n");
    else
    {
        int key, found, count = 1;
        NODE *temp = head;

        printf("\nenter the element you want to search: ");
        scanf("%d", &key);

        while (temp != NULL && !found)
        {
            count++;
            if (temp->data == key)
                found = 1;
            temp = temp->next;
        }
        if (!found)
            printf("\n%d not preent in the linked list anywhere :(\n", key);
        else
            printf("\n%d present at node number:%d\n", key, count + 1);
    }
}

void swap()
{
    /* 
    current->next = nextnode->next; 
    nextnode->next = current;
    prev->next = current;
     */
}

NODE *reverse(NODE *head)
{
    if (head == NULL)
        printf("\nLL IS EMPTY :(\n");
    else
    {
        NODE *nextnode = head, *currnode = head, *prevnode = NULL;

        while (currnode != NULL)
        {
            nextnode = nextnode->next;
            currnode->next = prevnode;
            prevnode = currnode;
            currnode = nextnode;
        }
        head = prevnode;
        display(head);

        return head;
    }
}

void display(NODE *head)
{
    if (head == NULL)
        printf("\nLL IS EMPTY :(\n");
    else
    {
        NODE *temp = head;
        printf("\n");
        while (temp != NULL)
        {
            printf("%d -> ", temp->data);
            temp = temp->next;
        }
        printf("NULL\n");
    }
}

void mid(NODE *head)
{
    if (head == NULL)
        printf("\nLL IS EMPTY :(\n");
    else
    {
        NODE *fast = head, *slow = head;

        while (fast && fast->next) // fast != NULL && fast->next != NULL
        {
            slow = slow->next;
            fast = fast->next->next;
        }
        printf("\n%d is the middle element in the linked list :)\n", slow->data);
    }
}
/* 
Problem-29 :: Check whether the given Linked List length is even or odd?

Solution :: Use a 2x pointer. Take a pointer that moves at 2x [two nodes at a time]. At the end, if
the length is even, then the pointer will be NULL; otherwise it will point to the last node.
 */