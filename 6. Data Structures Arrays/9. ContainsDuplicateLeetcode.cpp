#include <bits/stdc++.h>
using namespace std;

// Naive Approach
// Time Complexity: O(n^2)
// Space Complexity: O(1)

bool containsDuplicateNaive(vector<int> &nums)
{
    for (int i = 0; i < nums.size(); i++)
    {
        for (int j = i + 1; j < nums.size(); j++)
        {
            if (nums[i] == nums[j])
            {
                return true;
            }
        }
    }
    return false;
}

// Sorting Approach
// Time Complexity: O(n log (n))
// Space Complexity: O(1)

bool containsDuplicateSorting(vector<int> &nums)
{
    sort(nums.begin(), nums.end());
    for (int i = 0; i < nums.size() - 1; i++)
    {
        if (nums[i] == nums[i + 1])
        {
            return true;
        }
    }
    return false;
}

// Hash Set Approach: [Optimized 1]
// Time Complexity: O(n)
// Space Complexity: O(n)  ==> If there is no duplicate, then the hash set will contain
//                             all the elements of nums. So, in the worst case, the size of
//                             the hash set will be n.

bool containsDuplicateHashSet(vector<int> &nums)
{
    unordered_set<int> seen;
    for (auto num : nums)
    {
        if (seen.count(num) > 0)
        {
            return true;
        }
        seen.insert(num);
    }
    return false;
}

// Hash Map Approach [Optimized 2]
// Time Complexity: O(n)
// Space Complexity: O(n)

bool containsDuplicateHashMap(vector<int> &nums)
{
    unordered_map<int, int> seen;
    for (auto num : nums)
    {
        if (seen[num] >= 1)
        {
            return true;
        }
        seen[num]++;
    }
    return false;
}

int main()
{
    cout << boolalpha;
    vector<int> v1 = {1, 2, 3, 1};
    vector<int> v2 = {1, 2, 3, 4};
    vector<int> v3 = {1, 1, 1, 3, 3, 4, 3, 2, 4, 2};
    cout << containsDuplicateHashMap(v1) << endl;
    cout << containsDuplicateHashMap(v2) << endl;
    cout << containsDuplicateHashMap(v3) << endl;
    return 0;
}