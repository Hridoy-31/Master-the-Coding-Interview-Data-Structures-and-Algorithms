#include <bits/stdc++.h>
using namespace std;

// Given 2 arrays, create a function that let's a user know (true/false) whether these
// two arrays contain any common items

// For Example:
// const array1 = ['a', 'b', 'c', 'x'];
// const array2 = ['z', 'y', 'i'];
// should return false.

//-----------
// const array1 = ['a', 'b', 'c', 'x'];
// const array2 = ['z', 'y', 'x'];
// should return true.

// 2 parameters - arrays - no size limit
// return true or false

// Naive approach:

// Time complexity: O(n*m)
// Space complexity: O(1)
bool commonitems(vector<char> array1, vector<char> array2)
{
    for (int i = 0; i < array1.size(); i++)
    {
        for (int j = 0; j < array2.size(); j++)
        {
            if (array1[i] == array2[j])
            {
                return true;
            }
        }
    }
    return false;
}

// Optimized approach:

// Time complexity: O(n+m)
// Space complexity: O(n)   for storing n elements of array1 in the set.
bool commonitemsoptim(vector<char> array1, vector<char> array2)
{
    unordered_set<char> set;
    for (auto element : array1)
    {
        set.insert(element);
    }

    for (auto element : array2)
    {
        if (set.find(element) != set.end())
        {
            return true;
        }
    }

    return false;
}

int main()
{
    cout << boolalpha;
    vector<char> array1 = {'a', 'b', 'c', 'x'};
    vector<char> array2 = {'z', 'y', 'x'};

    cout << commonitemsoptim(array1, array2);
    return 0;
}
