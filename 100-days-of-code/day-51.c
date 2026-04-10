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

int LCA(struct node* root, int n1, int n2)
{
    while(root != NULL)
    {
        if(n1 < root->data && n2 < root->data)
            root = root->left;
        else if(n1 > root->data && n2 > root->data)
            root = root->right;
        else
            return root->data;
    }
    return -1;
}

int main()
{
    int n, i, n1, n2;

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

    printf("Enter two nodes: ");
    scanf("%d %d", &n1, &n2);

    printf("%d", LCA(root, n1, n2));
}