#include <bits/stdc++.h>
using namespace std;

// Naive Approach:
// Time Complexity: O(n log (n))
//                  The time complexity of each "insert" operation of a set is O(log (n)).
//                  Since, the set is inserting all the elements the vector "nums" have,
//                  whose size is n. So, the overall time complexity of this function is
//                  O(n log (n)).
// Space Complexity: O(n)
//                   The set "result" is keeping unique elements from the "nums" vector. In
//                   the worst case, if all the elements in the vector is unique, the set will
//                   contain all the elements, and it's size will become n. So, the overall space
//                   complexity of this function is O(n).

int removeDuplicatesNaive(vector<int> &nums)
{
    set<int> result;
    for (auto element : nums)
    {
        result.insert(element);
    }
    int index = 0;
    for (auto &set_element : result)
    {
        nums[index] = set_element;
        index++;
    }

    return result.size();
}

// Optimized Approach: [Two Pointer]
// Time Complexity: O(n)
// Space Complexity: O(1)

int removeDuplicatesOptimized(vector<int> &nums)
{
    int uniqueposindex = 1;
    for (int i = 1; i < nums.size(); i++)
    {
        if (nums[i] != nums[i - 1])
        {
            nums[uniqueposindex] = nums[i];
            uniqueposindex++;
        }
    }
    return uniqueposindex;
}

int main()
{
    vector<int> nums = {1, 1, 2};
    // vector<int> nums = {0, 0, 1, 1, 1, 2, 2, 3, 3, 4};

    // cout << removeDuplicatesNaive(nums) << endl;
    cout << removeDuplicatesOptimized(nums) << endl;

    return 0;
}