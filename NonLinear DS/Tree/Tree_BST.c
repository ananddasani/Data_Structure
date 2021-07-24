// program to implement binary search tree
/* 
                                                ALGO

1. INSERTION ::
If node == NULL 
    return createNode(data)
if (data < node->data)
    node->left  = insert(node->left, data);
else if (data > node->data)
    node->right = insert(node->right, data);  
return node;


2. DELETION ::
There are three cases for deleting a node from a binary search tree.

Case I
In the first case, the node to be deleted is the leaf node. 
In such a case, simply delete the node from the tree.

Case II
In the second case, the node to be deleted lies has a single child node. In such a case follow the steps below:

1. Replace that node with its child node.
2. Remove the child node from its original position.

Case III
In the third case, the node to be deleted has two children. In such a case follow the steps below:

1. Get the inorder successor of that node.
2. Replace the node with the inorder successor.
3. Remove the inorder successor from its original position.


3. SEARCH  ::
If root == NULL 
    return NULL;
If number == root->data 
    return root->data;
If number < root->data 
    return search(root->left)
If number > root->data 
    return search(root->right)

            ::Time Complexity::
Operation	Best    	Average 	Worst 
Search	    O(log n)	O(log n)	O(n)
Insertion	O(log n)	O(log n)	O(n)
Deletion	O(log n)	O(log n)	O(n)

Here, n is the number of nodes in the tree.

        ::Space Complexity::
The space complexity for all the operations is O(n).

        ::Binary Search Tree Applications::
1. In multilevel indexing in the database
2. For dynamic sorting
3. For managing virtual memory areas in Unix kernel

 */
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

struct BST
{
    struct BST *right;
    int data;
    struct BST *left;
};
typedef struct BST NODE;

NODE *insert(NODE *, int);
NODE *delete (NODE *, int);

void preorder(NODE *);
void inorder(NODE *);
void postorder(NODE *);

int search(NODE *, int);
NODE *max(NODE *);
NODE *min(NODE *);

int main()
{
    NODE *root = 0, *MAX = 0, *MIN = 0;
    int ch, key, ele;
    printf("\n\t\tBST IMPLEMENT\n\n");
    while (1)
    {
        printf("\nMAIN MENU\n");
        printf("1. INSERT\n2. DELETE\n3. PREORDER TRAVERSAL\n4. INORDER TRAVERSAL\n5. POSTORDER TRAVERSAL\n6. SEARCH\n");
        printf("7. MAX VALUE\n8. MIN VALUE\n9. EXIT\n");
        printf("enter your choice :: ");
        scanf("%d", &ch);

        switch (ch)
        {
        case 1:
            printf("\nenter the element: ");
            scanf("%d", &ele);
            root = insert(root, ele);
            break;

        case 2:
            if (root == NULL)
                printf("\nBST IS EMPTY :(\n");
            else
            {
                printf("\nenter the element to be deleted: ");
                scanf("%d", &key);
                delete (root, key);
            }
            break;

        case 3:
            if (root == NULL)
                printf("\nBST IS EMPTY :(\n");
            else
            {
                printf("\nPREORDER :: ");
                preorder(root);
            }
            break;

        case 4:
            if (root == NULL)
                printf("\nBST IS EMPTY :(\n");
            else
            {
                printf("\nINORDER :: ");
                inorder(root);
            }
            break;

        case 5:
            if (root == NULL)
                printf("\nBST IS EMPTY :(\n");
            else
            {
                printf("\nPOSTORDER :: ");
                postorder(root);
            }
            break;

        case 6:
            if (root == NULL)
                printf("\nBST IS EMPTY :(\n");
            else
            {
                printf("\nenter the element you want to seach: ");
                scanf("%d", &key);

                if (search(root, key))
                    printf("\n%d is present in BST :)\n", key);
                else
                    printf("\n%d not present in BST :)\n", key);
            }
            break;

        case 7:
            if (root == NULL)
                printf("\nBST IS EMPTY :(\n");
            else
            {
                MAX = max(root);
                printf("\nMAX = %d\n", MAX->data);
            }
            break;

        case 8:
            if (root == NULL)
                printf("\nBST IS EMPTY :(\n");
            else
            {
                MIN = min(root);
                printf("\nMIN = %d\n", MIN->data);
            }
            break;

        case 9:
            printf("\nexiting...\n\n");
            exit(0);
            break;

        default:
            printf("\nINVALID CHOICE :(\n");
            break;
        }
    }
    return 0;
}

// function to create a new node to insert in the bst
NODE *newnode(int ele)
{
    NODE *temp = (NODE *)malloc(sizeof(NODE));
    temp->data = ele;
    temp->right = temp->left = NULL;
    printf("\n%d inserted successfully !\n", ele);

    return temp;
}

NODE *insert(NODE *root, int ele)
{
    // if (root->data == ele) // if the data is already exitsts then simply return
    // {
    //     printf("\n%d already present in the BST , so can't insert duplicate data :(\n");
    //     return;
    // }

    if (root == NULL) // if tree is empty return the newnode
        return newnode(ele);

    if (ele > root->data) // otherwise recurse down the tree
        root->right = insert(root->right, ele);

    else if (ele < root->data)
        root->left = insert(root->left, ele);

    return root; // return the unchanged node pointer (so that changes made here will reflect into the main function (insertion in this case))
}

NODE *delete (NODE *root, int key)
{
    // base case
    if (root == NULL)
        return root;

    if (key < root->data) // if key is smaller than root data then it lies in the left side of the tree
        root->left = delete (root->left, key);

    else if (key > root->data) // if key is greater than the root data then it lies in the right side of the tree
        root->right = delete (root->right, key);

    else // otherwise the element is to be deleted is equals to root data then
    {
        // node with only one child or no child
        if (root->left == NULL)
        {
            NODE *temp = root->right;
            free(root);
        }
        else if (root->right == NULL)
        {
            NODE *temp = root->left;
            free(root);
            return temp;
        }

        // if the node has 2 children then get the inorder successor (smallest in the right subtree)
        NODE *temp = min(root->right);

        root->data = temp->data; // copy the inorder successor to this node

        root->right = delete (root->right, temp->data); // delete that inorder successor
    }
    return root;
}

void preorder(NODE *root)
{ // root -> left -> right
    if (root)
    {
        printf("%d  ", root->data);
        preorder(root->left);
        preorder(root->right);
    }
}

void inorder(NODE *root)
{ // left -> root -> right
    if (root)
    {
        inorder(root->left);
        printf("%d  ", root->data);
        inorder(root->right);
    }
}

void postorder(NODE *root)
{ // root -> left -> right
    if (root)
    {
        postorder(root->left);
        postorder(root->right);
        printf("%d  ", root->data);
    }
}

int search(NODE *root, int key)
{
    if (root == NULL) // root ==  null means element is not present in the bst so simply return 0;
        return 0;

    else if (root->data == key) // if found then return 1;
        return 1;

    else if (key > root->data)
        return search(root->right, key);

    else //if (key < root->data)
        return search(root->left, key);
}

NODE *min(NODE *root)
{ // NOTE :- entire tree need not to be searched

    NODE *current = root;
    while (current && current->left != NULL) // loop down to find the left most element
        current = current->left;

    return current; // return the node that mimimum key value found in the tree
}

NODE *max(NODE *root)
{
    NODE *current = root;
    while (current && current->right != NULL)
        current = current->right;

    return current;
}
