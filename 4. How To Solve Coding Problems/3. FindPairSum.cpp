// Given an array with values and a sum
// You have to find out a pair within the array that adds up
// equal to sum. If you find such pair, Print "YES". If you don't
// then print "NO".

// Example:
// [1, 2, 3, 9]    Sum = 8    No
// [1, 2, 4, 4]    Sum = 8    Yes

#include <bits/stdc++.h>
using namespace std;

// Naive approach:

// Time complexity: O(n^2)
// Space complexity: O(1)
void pairwithsum(vector<int> array1, int sum)
{
    for (int i = 0; i < array1.size() - 1; i++)
    {
        for (int j = i + 1; j < array1.size(); j++)
        {
            if (array1[i] + array1[j] == sum)
            {
                cout << "Yes" << endl;
                return;
            }
        }
    }
    cout << "No" << endl;
}

// Optimized approach:

// Time complexity: O(n)
// Space complexity: O(n)
void pairwithsumoptim(vector<int> array1, int sum)
{
    unordered_set<int> set;
    for (auto number : array1)
    {
        int complement = sum - number;
        if (set.find(complement) != set.end())
        {
            cout << "Yes" << endl;
            return;
        }
        set.insert(number);
    }
    cout << "No" << endl;
}

int main()
{
    vector<int> array1 = {1, 2, 3, 9};
    int sum = 8;
    pairwithsumoptim(array1, sum);
    return 0;
}