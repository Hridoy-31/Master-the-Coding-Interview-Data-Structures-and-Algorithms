#include <bits/stdc++.h>
using namespace std;

/*
Use different variables for different inputs. Let us consider, the size
of arr1 is n and the size of arr2 is m. They are different vectors. So,
we should use different variables as their size.
So, the time complexity of the following function is O(n + m)
*/

void TwoBoxes(vector<int> arr1, vector<int> arr2)
{
    for (int i = 0; i < arr1.size(); i++)
    {
        cout << arr1[i] << endl;
    }

    for (int i = 0; i < arr2.size(); i++)
    {
        cout << arr2[i] << endl;
    }
}