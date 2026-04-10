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

struct node* buildTree(int arr[], int n)
{
    if(n == 0 || arr[0] == -1)
        return NULL;

    struct node* root = createNode(arr[0]);
    enqueue(root);

    int i = 1;

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

    return root;
}

struct node* LCA(struct node* root, int n1, int n2)
{
    if(root == NULL)
        return NULL;

    if(root->data == n1 || root->data == n2)
        return root;

    struct node* left = LCA(root->left, n1, n2);
    struct node* right = LCA(root->right, n1, n2);

    if(left != NULL && right != NULL)
        return root;

    if(left != NULL)
        return left;
    else
        return right;
}

int main()
{
    int n, i, n1, n2;

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    int arr[n];

    printf("Enter elements: ");
    for(i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    printf("Enter two nodes: ");
    scanf("%d %d", &n1, &n2);

    struct node* root = buildTree(arr, n);

    front = rear = NULL;

    struct node* ans = LCA(root, n1, n2);

    if(ans != NULL)
        printf("%d", ans->data);
}