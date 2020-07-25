#include "treefunctions.cpp"
using namespace std;

void deepest_node_delete(node *root, node *deepnode)
{
    queue<node *> q;
    node *temp = root;

    q.push(temp);

    while (!q.empty())
    {
        temp = q.front();
        q.pop();

        if (temp->left)
        {
            if (temp->left == deepnode)
            {
                temp->left = NULL;
                delete deepnode;
                return;
            }
            else
                q.push(temp->left);
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
                q.push(temp->right);
        }
    }
}

node *deletion(node *root, int key)
{

    if (root == NULL)
    {
        cout << "nothing in tree";
        return NULL;
    }

    if (root->left == NULL && root->right == NULL)
    {
        if (root->data == key)
        {
            cout << "root is deleted";
            return NULL;
        }
        else
        {
            cout << "value not found";
            return root;
        }
    }

    node *temp = root;
    node *keynode = NULL;
    queue<node *> q;

    q.push(temp);

    while (!q.empty())
    {
        temp = q.front();
        q.pop();

        if (temp->data == key)
            keynode = temp; // key value found
        if (temp->left)
            q.push(temp->left);
        if (temp->right)
            q.push(temp->right);
    }

    if (keynode != NULL)
    {
        int x = temp->data; // this is the deepest node
        deepest_node_delete(root, temp);
        cout << "value succesfully deleted";
        keynode->data = x; // keyvalue replaced with deep value
    }
    else

        cout << "value not found";

    return root;
}
int main()
{
    node *root = initialize_tree();
    inorder(root);
    cout << endl;
    root = deletion(root, 40);
    cout << "\n";
    inorder(root);
    return 0;
}