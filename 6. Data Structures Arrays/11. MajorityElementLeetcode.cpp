#include <bits/stdc++.h>
using namespace std;

// Naive Approach: (Sorting)
// Time Complexity: O(n log (n))
// Space Complexity: O(1)

int majorityElementSorting(vector<int> &nums)
{
    sort(nums.begin(), nums.end());
    return nums[nums.size() / 2];
}

// Intermediate Approach: (Hash Map)
// Time Complexity: O(n)
// Space Complexity: O(n)

int majorityElementHashMap(vector<int> &nums)
{
    unordered_map<int, int> map;
    for (auto num : nums)
    {
        map[num]++;
    }

    for (auto element : map)
    {
        if (element.second > nums.size() / 2)
        {
            return element.first;
        }
    }
    return 0;
}

// Optimized Approach: (Moore's Voting Algorithm)
// Time Complexity: O(n)
// Space Complexity: O(1)

int majorityElementOptimized(vector<int> &nums)
{
    int count = 0, candidate = 0;
    for (auto num : nums)
    {
        if (count == 0)
        {
            candidate = num;
        }
        if (candidate == num)
        {
            count++;
        }
        else
        {
            count--;
        }
    }
    return candidate;
}

int main()
{
    // vector<int> nums = {3, 2, 3};
    vector<int> nums = {2, 2, 1, 1, 1, 2, 2};

    cout << majorityElementOptimized(nums) << endl;
    return 0;
}