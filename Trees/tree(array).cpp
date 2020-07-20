#include <bits/stdc++.h>
using namespace std;
char tree[10];

int root(char key)
{
    if (tree[0] != '\0')
        cout << "tree already had root";
    else
        tree[0] = key;
    return 0;
}

int set_left(char key, int parent)
{
    if (tree[parent] == '\0')
}

int main()
{
}