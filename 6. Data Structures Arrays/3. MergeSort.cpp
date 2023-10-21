#include <bits/stdc++.h>
using namespace std;

// Naive approach:
// Time complexity: O(p log p) ==> due to sort() function used, where p is the size of array3.
//                                 p = n + m, where n is the size of array1 and m is the size of
//                                 array2.
// Space complexity: O(p)      ==> for storing the elements of array1 and array2 in array3.

void mergesort(vector<int> array1, vector<int> array2)
{
    vector<int> array3;

    for (auto element : array1)
    {
        array3.push_back(element);
    }

    for (auto element : array2)
    {
        array3.push_back(element);
    }

    sort(array3.begin(), array3.end());

    for (auto element : array3)
    {
        cout << element << " ";
    }
    cout << endl;
}

// Optimized approach:
// Time complexity: O(p)  ==> where p is the size of array3. It is optimized than the previous one
//                            because there is no sort() used.
// Space complexity: O(p)

void mergesortopti(vector<int> array1, vector<int> array2)
{
    vector<int> array3;
    int i = 0, j = 0;

    while (i < array1.size() and j < array2.size())
    {
        if (array1[i] < array2[j])
        {
            array3.push_back(array1[i]);
            i++;
        }
        else
        {
            array3.push_back(array2[j]);
            j++;
        }
    }

    // if j finished traversing, then add the remaining elements of array1 to array3
    while (i < array1.size())
    {
        array3.push_back(array1[i]);
        i++;
    }

    // if i finished traversing, then add the remaining elements of array2 to array3
    while (j < array2.size())
    {
        array3.push_back(array2[j]);
        j++;
    }

    for (auto element : array3)
    {
        cout << element << " ";
    }
    cout << endl;
}

int main()
{
    vector<int> array1 = {0, 3, 4, 31};
    vector<int> array2 = {4, 6, 30};

    mergesortopti(array1, array2);

    return 0;
}