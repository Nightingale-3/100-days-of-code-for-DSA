#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node* left;
    struct node* right;
};

struct node* createNode(int x)
{
    struct node* temp = (struct node*)malloc(sizeof(struct node));
    temp->data = x;
    temp->left = temp->right = NULL;
    return temp;
}

struct node* insert(struct node* root, int x)
{
    if(root == NULL)
        return createNode(x);

    if(x < root->data)
        root->left = insert(root->left, x);
    else if(x > root->data)
        root->right = insert(root->right, x);

    return root;
}

int search(struct node* root, int key)
{
    if(root == NULL)
        return 0;

    if(key == root->data)
        return 1;

    if(key < root->data)
        return search(root->left, key);
    else
        return search(root->right, key);
}

int main()
{
    int n, i, key;

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    struct node* root = NULL;

    printf("Enter elements: ");
    for(i = 0; i < n; i++)
    {
        int x;
        scanf("%d", &x);
        root = insert(root, x);
    }

    printf("Enter key to search: ");
    scanf("%d", &key);

    if(search(root, key))
        printf("Found");
    else
        printf("Not Found");
}