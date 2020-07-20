#include "treefunctions.cpp"
#include <bits/stdc++.h>

using namespace std;

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

int main()
{
    node *root = new node(10);

    root->left = new node(20);
    root->left->left = new node(40);

    root->right = new node(30);
    root->right->left = new node(50);
    root->right->right = new node(60);
    root->right->right->right = new node(70);

    print_bfs(root);
    return 0;
}