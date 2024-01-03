#include <bits/stdc++.h>
using namespace std;

// Naive Approach:
// Time Complexity: O(n)
// Space Complexity: O(n)

void moveZeroesNaive(vector<int> &nums)
{
    vector<int> nonzeronums;
    for (auto element : nums)
    {
        if (element != 0)
        {
            nonzeronums.push_back(element);
        }
    }

    for (int i = 0; i < nonzeronums.size(); i++)
    {
        nums[i] = nonzeronums[i];
    }

    for (int i = nonzeronums.size(); i < nums.size(); i++)
    {
        nums[i] = 0;
    }
}

// Optimized Approach: [Two Pointer Approach]
// Time Complexity: O(n)
// Space Complexity: O(1)

void moveZeroesOptimized(vector<int> &nums)
{
    int nonzeroind = 0;
    for (int i = 0; i < nums.size(); i++)
    {
        if (nums[i] != 0)
        {
            swap(nums[i], nums[nonzeroind]);
            nonzeroind++;
        }
    }
}

int main()
{
    vector<int> nums = {0, 1, 0, 3, 12};
    // vector<int> nums = {0};

    // moveZeroesNaive(nums);
    moveZeroesOptimized(nums);

    for (auto element : nums)
    {
        cout << element << " ";
    }
    cout << endl;
}