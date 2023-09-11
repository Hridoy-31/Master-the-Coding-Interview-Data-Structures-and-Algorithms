#include <bits/stdc++.h>
using namespace std;

// Time Complexity: O(n^2)
void allpairsum(vector<int> arr)
{
    cout << "The Numbers are: " << endl;
    for (auto i : arr)
    {
        cout << i << endl;
    }

    cout << "The sums of each pair: " << endl;
    for (int i = 0; i < arr.size(); i++)
    {
        for (int j = 0; j < arr.size(); j++)
        {
            cout << arr[i] + arr[j] << endl;
        }
    }
}

int main()
{
    vector<int> nums = {1, 2, 3, 4, 5};
    allpairsum(nums);
    return 0;
}