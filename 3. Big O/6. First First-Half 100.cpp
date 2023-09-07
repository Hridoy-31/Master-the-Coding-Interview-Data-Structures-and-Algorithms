#include <bits/stdc++.h>
using namespace std;

// Time complexity: O(n)
void firstFirsthalf100(vector<int> arr)
{
    cout << arr[0] << endl;

    int firsthalf = arr.size() / 2;
    int index = 0;

    while (index < firsthalf)
    {
        cout << arr[index] << endl;
        index++;
    }

    for (int i = 0; i < 100; i++)
    {
        cout << "Hi" << endl;
    }
}