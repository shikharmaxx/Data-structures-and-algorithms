#include <bits/stdc++.h>
#include <vector>
using namespace std;

int main()
{
    vector<int> a = {0};

    sort(a.begin(), a.end());

    for (int i = 0; i < a.size(); i++)
        cout << a[i] << " ";
    return 0;
}