#include <bits/stdc++.h>
using namespace std;

struct node
{
    int data;
    node *left, *right;
    node(int value)
    {
        data = value;
        left = right = NULL;
    }
};

void inorder(node *temp)
{
    //cout << "\ninside the inroder";
    if (!temp)
        return;

    inorder(temp->left);
    cout << temp->data << " ";
    inorder(temp->right);
}

int height(node *root)
{
    node *temp = root;
    if (!temp)
    {
        return 0;
    }
    else
    {
        int lheight = height(temp->left);
        int rheight = height(temp->right);

        int maxheight = max(lheight, rheight) + 1;
        return maxheight;
    }
}

void printgivenlevel(node *temp, int level)
{
    if (!temp)
    {
        return;
    }
    if (level == 1)
    {
        cout << temp->data << " ";
    }
    else if (level > 1)
    {
        printgivenlevel(temp->left, level - 1);
        printgivenlevel(temp->right, level - 1);
    }
}

void levelorder(node *root)
{
    node *temp = root;
    int h = height(temp);
    for (int i = 1; i <= h; i++)
    {
        printgivenlevel(temp, i);
    }
}

void print_bfs(node *root)
{
    node *temp = root;
    queue<node *> q;

    if (!temp)
        return;

    q.push(temp);

    while (!q.empty())
    {
        temp = q.front();
        cout << temp->data << " ";
        q.pop();

        if (temp->left != NULL)
            q.push(temp->left);
        if (temp->right != NULL)
            q.push(temp->right);
    }
}

void postorder(node *root)
{
    node *temp = root;
    if (!temp)
        return;

    postorder(temp->left);
    postorder(temp->right);
    cout << temp->data << " ";
}

void preorder(node *root)
{
    node *temp = root;
    if (!temp)
        return;

    cout << temp->data << " ";
    preorder(temp->left);
    preorder(temp->right);
}

node *initialize_tree()
{
    node *root = new node(10);

    root->left = new node(20);
    root->left->left = new node(40);

    root->right = new node(30);
    root->right->left = new node(50);
    root->right->right = new node(60);
    root->right->right->right = new node(70);
    return root;
}