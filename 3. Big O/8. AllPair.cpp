#include <bits/stdc++.h>
using namespace std;

// Time Complexity: O(n^2)
void allpair(vector<int> arr1)
{
    for (int i = 0; i < arr1.size(); i++)
    {
        for (int j = 0; j < arr1.size(); j++)
        {
            cout << "[" << arr1[i] << ", " << arr1[j] << "]" << endl;
        }
    }
}

int main()
{
    vector<int> num = {1, 2, 3, 4, 5};
    allpair(num);
    return 0;
}