//  program to implement doubly linked list
/* 
                                                    ALGO
        ALGORITHM FOR INSERTING A NODE
1. Input the DATA and POS
2. Initialize TEMP = START; i = 0
3. Repeat the step 4 if (i less than POS) and (TEMP is not equal to NULL)
4. TEMP = TEMP → RPoint; i = i +1
5. If (TEMP not equal to NULL) and (i equal to POS)
(a) Create a New Node
(b) NewNode → DATA = DATA
(c) NewNode → RPoint = TEMP → RPoint
(d) NewNode → LPoint = TEMP
(e) (TEMP → RPoint) → LPoint = NewNode
(f ) TEMP → RPoint = New Node
6. Else
(a) Display “Position NOT found”
7. Exit

        . ALGORITHM FOR DELETING A NODE
1. Input the POS
2. Initialize TEMP = START; i = 0
3. Repeat the step 4 if (i less than POS) and (TEMP is not equal to NULL)
4. TEMP = TEMP → RPoint; i = i +1
5. If (TEMP not equal to NULL) and (i equal to POS)
(a) Create a New Node
(b) NewNode → DATA = DATA
(c) NewNode → RPoint = TEMP → RPoint
(d) NewNode → LPoint = TEMP
(e) (TEMP → RPoint) → LPoint = NewNode
(f ) TEMP → RPoint = New Node
6. Else
(a) Display “Position NOT found”
7. Exit
 */

#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

struct node
{
    struct node *prev;
    int data;
    struct node *next;
} * head, *last_node;
typedef struct node NODE;

void insert_beg();
void insert_before();
void insert_after();
void insert_end();

void delete_beg();
void delete_before();
void delete_after();
void delete_at();
void delete_end();

void display();
void reverse();
NODE *get_node();

int main()
{
    int ch;
    printf("\n\t\tDOUBLY LINKED LIST IMPLEMENT \n\n");
    while (1)
    {
        printf("\nMAIN MENU\n");
        printf("1. INSERT BEGINNING\n2. INSERT BEFORE ELEMENT\n3. INSERT AFTER ELEMENT\n4. INSERT AT END\n");
        printf("5. DELETE BEGINNING\n6. DELETE BEFORE ELEMENT\n7. DELETE AFTER ELEMENT\n8. DELETE AT END\n");
        printf("9. DISPLAY\n10. REVERSE DLL\n11. DELETE AT \n12. EXIT\n");
        printf("enter your choice: ");
        scanf("%d", &ch);

        switch (ch)
        {
        case 1:
            insert_beg();
            display();
            break;

        case 2:
            insert_before();
            display();
            break;

        case 3:
            insert_after();
            display();
            break;

        case 4:
            insert_end();
            display();
            break;

        case 5:
            delete_beg();
            display();
            break;

        case 6:
            delete_before();
            display();
            break;

        case 7:
            delete_after();
            display();
            break;

        case 8:
            delete_end();
            display();
            break;

        case 9:
            display();
            break;

        case 10:
            reverse();
            break;

        case 11:
            delete_at();
            break;

        case 12:
            printf("\nexiting...\n");
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
    temp->prev = temp->next = NULL;

    return temp;
}

void insert_beg()
{
    NODE *ptr = get_node();
    ptr->next = ptr->prev = NULL;

    printf("\nenter data: ");
    scanf("%d", &ptr->data);

    if (head == NULL)
    {
        head = last_node = ptr;
        printf("\nfirst node with data %d created successfully !\n", ptr->data);
    }
    else
    {
        ptr->next = head;
        head->prev = ptr;
        head = ptr;
        printf("\nnode with data %d added at the biginning successfully !\n", ptr->data);
    }
}

void insert_before()
{
    int key;
    printf("\nenter element before which you want insertion: ");
    scanf("%d", &key);

    if (head == NULL)
        insert_beg();
    else
    {
        if (key == head->data)
            insert_beg();
        else
        {
            NODE *temp = head;
            int found = 0;
            while (temp != NULL && !found)
            {
                if (temp->data == key)
                    found = 1;
                else
                    temp = temp->next;
            }
            if (!found)
                printf("\n%d not present anywhere in the DLL :(\n", key);
            else
            {
                NODE *ptr = get_node();
                ptr->next = ptr->prev = NULL;

                printf("\nenter data: ");
                scanf("%d", &ptr->data);

                temp->prev->next = ptr;
                ptr->prev = temp->prev;
                ptr->next = temp;
                temp->prev = ptr;

                printf("\n%d inserted before %d successfully !\n", ptr->data, key);
            }
        }
    }
}
void insert_after()
{
    int key;
    printf("\nenter element after which you want insertion: ");
    scanf("%d", &key);

    if (head == NULL)
        insert_beg();
    else
    {
        if (key == last_node->data)
            insert_end();
        else
        {
            NODE *temp = head;
            int found = 0;
            while (temp != NULL && !found)
            {
                if (temp->data == key)
                    found = 1;
                else
                    temp = temp->next;
            }
            if (!found)
                printf("\n%d not present anywhere in the DLL :(\n", key);
            else
            {
                NODE *ptr = get_node();
                ptr->next = ptr->prev = NULL;

                printf("\nenter data: ");
                scanf("%d", &ptr->data);

                ptr->next = temp->next;
                temp->next->prev = ptr;
                temp->next = ptr;
                ptr->prev = temp;

                printf("\n%d inserted after %d successfully !\n", ptr->data, key);
            }
        }
    }
}

void insert_end()
{
    NODE *ptr = get_node();
    ptr->next = ptr->prev = NULL;

    printf("\nenter data: ");
    scanf("%d", &ptr->data);

    if (head == NULL)
    {
        head = last_node = ptr;
        printf("\nfirst node with data %d created successfully !\n", ptr->data);
    }
    else
    {
        last_node->next = ptr;
        ptr->prev = last_node;
        last_node = ptr;
        printf("\nnode with data %d appended successfully !\n", ptr->data);
    }
}

void delete_beg()
{
    if (head == NULL)
        printf("\nDLL is empty :(\n");
    else if (head->next == NULL)
    {
        head = last_node = NULL;
        free(head);
        free(last_node);
        printf("\nthe only node is deleted\n");
    }
    else
    {
        NODE *temp = head;
        head = head->next;
        temp->next = NULL;
        free(temp);

        printf("\nfirst node deleted successfully !\n");
    }
}

void delete_before()
{
    if (head == NULL)
        printf("\nDLL is empty :(\n");
    else
    {
        int key;
        printf("\nenter element before which you want deletion: ");
        scanf("%d", &key);
        if (key == head->data)
            printf("\ncan't delete anything before head node :(\n");
        else if (key == head->next->data)
            delete_beg();
        else
        {
            NODE *temp = head;
            int found = 0;
            while (temp != NULL && !found)
            {
                if (key == temp->next->data)
                    found = 1;
                else
                    temp = temp->next;
            }
            if (!found)
                printf("\n%d not present anywhere in the DLL :(\n", key);
            else
            {
                temp->prev->next = temp->next;
                temp->next->prev = temp->prev;
                temp->prev = temp->next = NULL;
                free(temp);
                printf("\ndata before %d deleted successfully !\n", key);
            }
        }
    }
}

void delete_at()
{
    if (head == NULL)
        printf("\nDLL is empty :(\n");
    else
    {
        int key;
        printf("\nenter element which you want delete: ");
        scanf("%d", &key);

        int found = 0;
        NODE *temp = head;
        while (temp != NULL && !found)
        {
            if (key == temp->data)
                found = 1;
            else
                temp = temp->next;
        }
        if (!found)
            printf("\n%d not present anywhere in the DLL :(\n", key);
        else
        {
            temp->prev->next = temp->next;
            temp->next->prev = temp->prev;
            temp->next = NULL;
            temp->prev = NULL;
            display();
            // printf("\ndata at %d deleted successfully !\n", key);
        }
    }
}

void delete_after()
{
    if (head == NULL)
        printf("\nDLL is empty :(\n");
    else
    {
        int key;
        printf("\nenter element after which you want deletion: ");
        scanf("%d", &key);

        if (key == last_node->data)
            printf("\ncan't delete anything after last node :(\n");
        else if (key == last_node->prev->data)
            delete_end();
        else
        {
            int found = 0;
            NODE *temp = head;
            while (temp != NULL && !found)
            {
                if (key == temp->next->data)
                    found = 1;
                else
                    temp = temp->next;
            }
            if (!found)
                printf("\n%d not present anywhere in the DLL :(\n", key);
            else
            {
                temp->prev = temp->next;
                temp->next->prev = temp->prev;
                temp->prev = temp->next = NULL;
                free(temp);
                printf("\ndata before %d deleted successfully !\n", key);
            }
        }
    }
}

void delete_end()
{
    if (head == NULL)
        printf("\nDLL is empty :(\n");
    else if (head->next == NULL)
    {
        head = last_node = NULL;
        free(head);
        free(last_node);
        printf("\nthe only node is deleted\n");
    }
    else
    {
        NODE *temp = last_node;
        last_node = last_node->prev;
        last_node->next = NULL;
        free(temp);
        printf("\nlast node deleted successfully !\n");
    }
}

void display()
{
    if (head == NULL)
        printf("\nDLL is empty :(\n");
    else
    {
        NODE *temp = head;
        printf("\nHEAD :: ");
        while (temp != NULL)
        {
            printf("%d -> ", temp->data);
            temp = temp->next;
        }
        printf("NULL\n");
    }
}

void reverse()
{
    if (head == NULL)
        printf("\nDLL IS EMPTY\n");
    else
    {
        NODE *currnode = head, *nextnode = NULL;

        while (currnode != NULL)
        {
            nextnode = currnode->next;
            currnode->next = currnode->prev;
            currnode->prev = nextnode;
            currnode = nextnode;
        }
        currnode = head;
        head = last_node;
        last_node = currnode;

        display();
    }
}