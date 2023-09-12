#include <bits/stdc++.h>
using namespace std;

// Space complexity: O(1)
void numgen(int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << i << endl;
    }
}

// Space complexity: O(n)
void higen(int n)
{
    vector<string> v;
    for (int i = 0; i < n; i++)
    {
        v.push_back("Hi");
    }

    for (auto i : v)
    {
        cout << i;
    }
    cout << endl;
}