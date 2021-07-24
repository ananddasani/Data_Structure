// program to implement circular linked list
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
} * last_node;
typedef struct node NODE;

NODE *get_node();
void display(NODE *);

NODE *insert_beg(NODE *);
NODE *insert_before(NODE *);
void insert_end(NODE *);

NODE *delete_beg(NODE *);
void delete_after(NODE *);
void delete_end(NODE *);
NODE *reverse(NODE *);

int main()
{
    NODE *head = NULL;
    int ch;
    printf("\n\t\tCIRCULAR LINKED LIST IMPLEMENTION\n");
    while (1)
    {
        printf("\nMAIN MENU\n");
        printf("1. INSERT BEGINING\n2. INSERT BEFORE DATA\n3. INSERT AT END\n");
        printf("4. DELETE AT BEGINING\n5. DELETE AFTER DATA\n6. DELETE END\n");
        printf("7. DISPLAY\n8. REVERSE\n9. EXIT\n");
        printf("enter your choice: ");
        scanf("%d", &ch);

        switch (ch)
        {
        case 1:
            head = insert_beg(head);
            // printf("\nHEAD = %p  && %d\nl_node = %p && %d\n", head->next, head->data, head->next, head->data);
            break;

        case 2:
            head = insert_before(head);
            // printf("\nHEAD = %p  && %d\nl_node = %p && %d\n", head->next, head->data, head->next, head->data);
            break;

        case 3:
            insert_end(head);
            // printf("\nHEAD = %p  && %d\nl_node = %p && %d\n", head->next, head->data, head->next, head->data);
            break;

        case 4:
            head = delete_beg(head);
            // printf("\nHEAD = %p  && %d\nl_node = %p && %d\n", head->next, head->data, head->next, head->data);
            break;

        case 5:
            delete_after(head);
            // printf("\nHEAD = %p  && %d\nl_node = %p && %d\n", head->next, head->data, head->next, head->data);
            break;

        case 6:
            delete_end(head);
            // printf("\nHEAD = %p  && %d\nl_node = %p && %d\n", head->next, head->data, head->next, head->data);
            break;

        case 7:
            display(head);
            // printf("\nHEAD = %p  && %d\nl_node = %p && %d\n", head->next, head->data, head->next, head->data);
            break;

        case 8:
            head = reverse(head);
            display(head);
            break;

        case 9:
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

NODE *insert_beg(NODE *head)
{

    NODE *ptr = get_node();
    ptr->next = NULL;

    printf("\nenter data: ");
    scanf("%d", &ptr->data);

    if (head == NULL)
    {
        head = last_node = ptr;
        last_node->next = head;
        printf("\nfirst node with data:%d created successfully !\n", ptr->data);
    }
    else
    {
        ptr->next = head;
        head = ptr;
        last_node->next = head;
        printf("\n%d inserted at the begining of CLL successfull !\n", ptr->data);
    }
    return head;
}

NODE *insert_before(NODE *head)
{

    if (head == NULL)
    {
        printf("\nCLL IS EMPTY, BY DEFAULT FIRST NODE WILL CREATED\n");
        head = insert_beg(head);
    }
    else
    {
        int key;
        NODE *ptr = get_node();
        NODE *temp = head;
        ptr->next = NULL;

        printf("\nenter element before which you want to insert data: ");
        scanf("%d", &key);

        if (key == head->data)
            head = insert_beg(head);
        else
        {
            int found = 0;
            while (temp != NULL && !found)
            {
                if (key == temp->next->data)
                    found = 1;
                else
                    temp = temp->next;
            }
            if (!found)
                printf("\n%d is not present in the circular linked list\n");
            else
            {
                printf("\nenter data: ");
                scanf("%d", &ptr->data);

                ptr->next = temp->next;
                temp->next = ptr;
                printf("\n%d inserted before %d successfully !\n", ptr->data, key);
            }
        }
    }
    return head;
}

void insert_end(NODE *head)
{
    if (head == NULL)
        printf("\nCLL IS EMPTY , CAN'T INSERT AT THE END\n");
    else
    {
        NODE *ptr = get_node();
        ptr->next = NULL;

        printf("\nenter data: ");
        scanf("%d", &ptr->data);

        last_node->next = ptr;
        last_node = ptr;
        last_node->next = head;
        printf("\n%d appended at the end of CLL successfully !\n", ptr->data);
    }
}

NODE *delete_beg(NODE *head)
{
    if (head == NULL)
        printf("\nCLL IS EMPTY\n");
    else if (head->next == NULL)
    {
        free(head);
        head = last_node = NULL;
        printf("\nthe only node deleted successfully , now CLL is empty\n");
    }
    else
    {
        NODE *temp = head;
        head = head->next;
        last_node->next = head;
        temp->next = NULL;
        free(temp);
        printf("\nfirst node deleted successfully !\n");
    }
    return head;
}

void delete_after(NODE *head)
{
    if (head == NULL)
        printf("\nCLL IS EMPTY\n");
    else
    {
        int key;
        printf("\nenter element after you want deletion: ");
        scanf("%d", &key);

        if (key == last_node->data)
            printf("\ncan't delete anything after last node :(\n");
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
                printf("\n%d not present in the CLL anywhere :(\n", key);
            else
            {
                if (temp->next == last_node)
                    delete_end(head);
                else
                {
                    NODE *q = temp->next;
                    temp->next = q->next;
                    q->next = NULL;
                    free(q);
                    printf("\ndata after %d is deleted successfully !\n", key);
                }
            }
        }
    }
}

void delete_end(NODE *head)
{
    if (head == NULL)
        printf("\nCLL IS EMPTY\n");
    else
    {
        if (head->next == NULL)
        {
            free(head);
            head = last_node = NULL;
            printf("\nthe only node deleted successfully , now CLL is empty\n");
        }
        else
        {
            NODE *temp = head;
            while (temp->next->data != last_node->data)
                temp = temp->next;
            temp->next = head;
            free(last_node);
            last_node = temp;
            printf("\nlast node deleted successfully !\n");
        }
    }
}

void display(NODE *head)
{
    if (head == NULL || last_node == NULL)
        printf("\nCLL IS EMPTY\n");
    else
    {
        NODE *temp = head;
        printf("\nHEAD :: ");
        do
        {
            printf("%d -> ", temp->data);
            temp = temp->next;
        } while (temp != head);
        printf("NULL\n");
    }
}

NODE *reverse(NODE *head)
{
    if (head == NULL)
        printf("\nCLL IS EMPTY :(\n");
    else if (head->next == head)
        printf("\ncan't reverse , only one node is present :(\n");
    else
    {
        NODE *currnode = last_node->next, *prevnode = NULL, *nextnode;

        while (currnode != last_node)
        {
            prevnode = currnode;
            nextnode = currnode->next;
            currnode->next = prevnode;
        }
        nextnode->next = last_node;
        last_node = nextnode;

        return head;
    }
}