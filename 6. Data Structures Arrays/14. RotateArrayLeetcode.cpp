#include <bits/stdc++.h>
using namespace std;

// Naive Approach:
// Time complexity: O(n)
// Space complexity: O(n)

void rotateNaive(vector<int> &nums, int k)
{
    vector<int> rotated(nums.size());
    for (int i = 0; i < nums.size(); i++)
    {
        int rotindex = (i + k) % nums.size();
        rotated[rotindex] = nums[i];
    }
    for (int i = 0; i < nums.size(); i++)
    {
        nums[i] = rotated[i];
    }
}

// Optimized Approach:
// Time complexity: O(n) --> The time complexity of the reverse() function in O(n).
// Space complexity: O(1) --> The space complexity of the reverse() function is O(1).
//                            because, the function reverse elements "in-place". So,
//                            no extra space is required.

void rotateOptimized(vector<int> &nums, int k)
{
    k = k % nums.size();
    reverse(nums.begin(), nums.end());
    reverse(nums.begin(), nums.begin() + k);
    reverse(nums.begin() + k, nums.end());
}

int main()
{
    vector<int> nums = {1, 2, 3, 4, 5, 6, 7};
    int k = 3;
    // vector<int> nums = {-1, -100, 3, 99};
    // int k = 2;
    rotateOptimized(nums, k);
    for (auto element : nums)
    {
        cout << element << " ";
    }
    cout << endl;

    return 0;
}