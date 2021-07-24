// program to implement tree
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *Lchild;
    struct node *Rchild;
};
typedef struct node NODE;

NODE *creat();
void preorder(NODE *);
void inorder(NODE *);
void postorder(NODE *);

int main()
{
    NODE *root = 0;
    int ch, key;
    printf("\n\tTREE IMPLEMENT\n\n");
    while (1)
    {
        printf("\nMAIN MENU\n");
        printf("1. INSERTION\n2. PREORDER TRAVERSAL\n3. INORDER TRAVERSAL\n4. POSTORDER TRAVERSAL\n5. EXIT\n");
        printf("enter your choice :: ");
        scanf("%d", &ch);

        switch (ch)
        {
        case 1:
            root = creat();
            break;

        case 2:
            if (root == NULL)
                printf("\nBST IS EMPTY :(\n");
            else
            {
                printf("\nPREORDER :: ");
                preorder(root);
            }
            break;

        case 3:
            if (root == NULL)
                printf("\nBST IS EMPTY :(\n");
            else
            {
                printf("\nINORDER :: ");
                inorder(root);
            }
            break;

        case 4:
            if (root == NULL)
                printf("\nBST IS EMPTY :(\n");
            else
            {
                printf("\nPOSTORDER :: ");
                postorder(root);
            }
            break;

        case 5:
            printf("\nexiting...\n");
            exit(0);
            break;

        default:
            printf("\nINVALID CHOICE\n");
            break;
        }
    }
    return 0;
}

NODE *creat()
{
    NODE *new_node = (NODE *)malloc(sizeof(NODE)); // creating the root node
    new_node->Lchild = new_node->Rchild = NULL;

    int ele;
    printf("\nenter data (-1 for NULL) :: ");
    scanf("%d", &ele);

    if (ele == -1) // base contition for terminating the recursion
        return 0;

    new_node->data = ele; // inserting the element in the root node

    // creating the left child recursively
    printf("\tenter the Left child for %d :: ", ele);
    new_node->Lchild = creat();

    // creating the right child recursively
    printf("\tenter the Right child for %d :: ", ele);
    new_node->Rchild = creat();

    return new_node; // returning the root to the main function
}

void preorder(NODE *root)
{ // root -> left -> right
    if (root)
    {
        printf("%d  ", root->data);
        preorder(root->Lchild);
        preorder(root->Rchild);
    }
}

void inorder(NODE *root)
{ // left -> root ->right
    if (root)
    {
        inorder(root->Lchild);
        printf("%d  ", root->data);
        inorder(root->Rchild);
    }
}

void postorder(NODE *root)
{ // left -> right -> root
    if (root)
    {
        postorder(root->Lchild);
        postorder(root->Rchild);
        printf("%d  ", root->data);
    }
}
