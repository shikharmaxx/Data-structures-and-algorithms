#include <bits/stdc++.h>
using namespace std;

struct node
{
    int data;
    node *left, *right;

    node(int value)
    {
        data = value;
        right = left = NULL;
    }
};

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

int main()
{
    node *root = new node(10);
    root->left = new node(20);
    root->left->left = new node(30);

    root->right = new node(40);
    root->right->left = new node(50);
    root->right->right = new node(60);
    root->right->right->right = new node(70);

    cout << endl;
    cout << height(root) << endl;
    levelorder(root);

    return 0;
}