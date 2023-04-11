#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int sum = 0;

typedef struct node
{
    int value;
    struct node *left;
    struct node *right;
} node;

node *insert(int value, node *tnode)
{
    /* add your code here */
    if (tnode == NULL)
    {
        node *new_node = (node *)malloc(sizeof(node));
        new_node->value = value;
        new_node->left = NULL;
        new_node->right = NULL;
        return new_node;
    }
    if (value <= tnode->value)
    {
        tnode->left = insert(value, tnode->left);
    }
    else if (value > tnode->value)
    {
        tnode->right = insert(value, tnode->right);
    }
    return tnode;
}

void dfs(node *root, int sum1)
{
    if (root == NULL)
    {
        return;
    }
    sum1 = sum1 + root->value;
    if (root->left == NULL && root->right == NULL)
    {
        sum = sum + sum1;
        printf("%d\n", sum1);
        return;
    }
    dfs(root->left, sum1);
    dfs(root->right, sum1);
}

int main()
{
    int i, num, value;
    node *root = NULL;
    scanf("%d", &num);
    for (i = 0; i < num; i++)
    {
        scanf("%d", &value);
        root = insert(value, root);
    }
    dfs(root, 0);
    printf("Sum of all paths: %d", sum);
    return 0;
}