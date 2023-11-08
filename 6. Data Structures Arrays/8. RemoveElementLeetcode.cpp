#include <bits/stdc++.h>
using namespace std;

// Naive approach:
// Time complexity: O(n log(n))  ==> for sorting the array
// Space complexity: O(1)

int removeElementNative(vector<int>& nums, int val) {
    int count = 0;
    for (int i=0; i<nums.size(); i++) {
        if (nums[i] == val) {
            nums[i] = INT_MAX;
        }
        else {
            count++;
        }
    }
    sort(nums.begin(), nums.end());
    return count;
}

// Optimized approach:
// Time complexity: O(n)
// Space complexity: O(1)

int removeElementOptimized(vector<int>& nums, int val) {
    int index = 0;
    for (int i=0; i<nums.size(); i++) {
        if (nums[i] != val) {
            nums[index] = nums[i];
            index++;
        }
    }
    return index;
}


int main()
{
	vector <int> nums = {3,2,2,3};
	int val = 3;
	cout << removeElementNative(nums, val) << endl;
	return 0;
}
