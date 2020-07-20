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

void insert(node *temp, int value)
{
    //cout << "\ninside the insert ";
    queue<node *> q;
    q.push(temp);

    while (!q.empty())
    {
        //cout << "\ninside the while loop";
        node *temp = q.front();
        q.pop();

        if (!temp->left)
        {
            temp->left = new node(value);
            break;
        }
        else
        {
            q.push(temp->left);
        }

        if (!temp->right)
        {
            temp->right = new node(value);
            break;
        }
        else
        {
            q.push(temp->right);
        }
    }
}

int main()
{
    //cout << "\ninsidde main";
    node *root = new node(10);
    root->left = new node(25);
    root->left->left = new node(13);

    root->right = new node(49);
    root->right->left = new node(34);
    root->right->right = new node(51);
    cout << "\ntree made";
    cout << "inorder traversal before : ";
    inorder(root);

        int value = 69;
    insert(root, value);
    cout << "\ninorder traversal after insertorion : ";
    inorder(root);

    return 0;
}