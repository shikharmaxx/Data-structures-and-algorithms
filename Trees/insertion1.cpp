#include "treefunctions.cpp"
using namespace std;

void insertion(node *root, int key)
{

    if (!root)
    {
        root = new node(key);
        return;
    }

    queue<node *> q;
    q.push(root);

    while (!q.empty())
    {
        node *temp = q.front();
        q.pop();

        if (temp->left == NULL)
        {
            temp->left = new node(key);
            return;
        }
        else if (temp->right == NULL)
        {
            temp->right = new node(key);
            return;
        }
        else
        {
            q.push(temp->left);
            q.push(temp->right);
        }
    }
}
int main()
{
    //node *root = initialize_tree();
    node *root = new node(10);
    inorder(root);
    cout << endl;
    insertion(root, 990);
    insertion(root, 600);
    cout << "after insertion";
    inorder(root);
    return 0;
}