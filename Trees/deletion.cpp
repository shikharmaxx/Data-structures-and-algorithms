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
    {
        return;
    }

    inorder(temp->left);
    cout << temp->data << " ";
    inorder(temp->right);
}

void delete_deepest(struct node *root, struct node *deepnode)
{
    queue<node *> q;
    q.push(root);

    node *temp;
    while (!q.empty())
    {
        temp = q.front();
        q.pop();
        if (temp == deepnode)
        {
            temp = NULL;
            delete deepnode;
            return;
        }
        if (temp->right)
        {
            if (temp->right == deepnode)
            {
                temp->right = NULL;
                delete deepnode;
                return;
            }
            else
            {
                q.push(temp->right);
            }
        }
        if (temp->left)
        {
            if (temp->left == deepnode)
            {
                temp->left = NULL;
                delete deepnode;
                return;
            }
            else
            {
                q.push(temp->left);
            }
        }
    }
}

node *deletion(node *root, int value)
{

    if (root == NULL)
        return NULL;

    if (root->left == NULL && root->right == NULL)
    {
        if (root->data == value)
            return NULL;
        else
            return root;
    }
    queue<node *> q;
    q.push(root);
    struct node *temp;
    struct node *keynode = NULL;

    while (!q.empty())
    {
        temp = q.front();
        q.pop();

        if (temp->data == value)
            keynode = temp;

        if (temp->left)
            q.push(temp->left);

        if (temp->right)
            q.push(temp->right);
    }

    if (keynode != NULL)
    {
        int x = temp->data;
        delete_deepest(root, temp);
        keynode->data = x;
    }
    return root;
}

int main()
{
    cout << "\ninsidde main";
    node *root = new node(10);
    root->left = new node(25);
    root->left->left = new node(13);

    root->right = new node(49);
    root->right->left = new node(34);
    root->right->right = new node(51);
    cout << "\ntree made";
    cout << "inorder traversal before : ";
    inorder(root);
    int value = 49;
    deletion(root, value);
    cout << "\ninorder traversal after insertorion : ";
    inorder(root);

    return 0;
}