#include <bits/stdc++.h>
using namespace std;

// Naive approach:
// Time complexity: O(n^2)
// Space complexity: O(1)

vector<int> twoSum(vector<int> nums, int target)
{
    for (int i = 0; i < nums.size() - 1; i++)
    {
        for (int j = i + 1; j < nums.size(); j++)
        {
            if (nums[i] + nums[j] == target)
            {
                return {i, j};
                break;
            }
        }
    }

    return {};
}

// Optimized approach:
// Time complexity: O(n)
// Space complexity: O(n)

// We will give importance to optimize time complexity rather than space complexity. Because,
// increasing space is easy, but buying more time is impossible. In previous naive approach, time complexity
// was bad, but space complexity was optimal. But we have to give preference to optimize time. For this
// reason, time complexity in optimized approach is better than naive. On the other hand, space complexity
// not good compared to the previous one.

vector<int> twoSumopti(vector<int> &nums, int target)
{
    unordered_map<int, int> mapnum;

    for (int i = 0; i < nums.size(); i++)
    {
        int complement = target - nums[i];
        if (mapnum.count(complement))
        {
            return {mapnum[complement], i};
            break;
        }
        mapnum[nums[i]] = i;
    }

    return {};
}

int main()
{
    vector<int> nums = {2, 7, 11, 15};
    int target = 9;
    vector<int> result = twoSumopti(nums, target);
    for (auto element : result)
    {
        cout << element << " ";
    }
    cout << endl;

    return 0;
}