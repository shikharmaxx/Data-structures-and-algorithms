#include "treefunctions.cpp"
using namespace std;

void preorder(node *root)
{
    node *temp = root;
    if (!temp)
        return;

    cout << temp->data << " ";
    preorder(temp->left);
    preorder(temp->right);
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

int main()
{

    node *root = initialize_tree();
    inorder(root);
    cout << endl;
    preorder(root);
    cout << endl;
    postorder(root);
    return 0;
}
