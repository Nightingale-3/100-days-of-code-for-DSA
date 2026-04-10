#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node* left;
    struct node* right;
};

struct queue
{
    struct node* data;
    struct queue* next;
};

struct queue* front = NULL;
struct queue* rear = NULL;

void enqueue(struct node* x)
{
    struct queue* temp = (struct queue*)malloc(sizeof(struct queue));
    temp->data = x;
    temp->next = NULL;
    if(rear == NULL)
    {
        front = rear = temp;
        return;
    }
    rear->next = temp;
    rear = temp;
}

struct node* dequeue()
{
    if(front == NULL)
        return NULL;
    struct queue* temp = front;
    struct node* x = temp->data;
    front = front->next;
    if(front == NULL)
        rear = NULL;
    free(temp);
    return x;
}

struct node* createNode(int x)
{
    struct node* temp = (struct node*)malloc(sizeof(struct node));
    temp->data = x;
    temp->left = temp->right = NULL;
    return temp;
}

void inorder(struct node* root)
{
    if(root == NULL)
        return;
    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
}

void preorder(struct node* root)
{
    if(root == NULL)
        return;
    printf("%d ", root->data);
    preorder(root->left);
    preorder(root->right);
}

void postorder(struct node* root)
{
    if(root == NULL)
        return;
    postorder(root->left);
    postorder(root->right);
    printf("%d ", root->data);
}

int main()
{
    int n, i;
    printf("Enter number of nodes: ");
    scanf("%d", &n);

    int arr[n];
    printf("Enter elements: ");
    for(i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    if(n == 0 || arr[0] == -1)
        return 0;

    struct node* root = createNode(arr[0]);
    enqueue(root);

    i = 1;

    while(i < n)
    {
        struct node* current = dequeue();

        if(arr[i] != -1)
        {
            current->left = createNode(arr[i]);
            enqueue(current->left);
        }
        i++;

        if(i < n && arr[i] != -1)
        {
            current->right = createNode(arr[i]);
            enqueue(current->right);
        }
        i++;
    }

    inorder(root);
    printf("\n");
    preorder(root);
    printf("\n");
    postorder(root);
}