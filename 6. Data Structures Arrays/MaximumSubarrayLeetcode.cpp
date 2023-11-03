#include <bits/stdc++.h>
using namespace std;

// Naive approach:
// Time complexity: O(n^2)
// Space complexity: O(1)

int maxSubarraySumNaive(vector<int>& arr) {
    int n = arr.size();
    int maxSum = INT_MIN;

    for (int i = 0; i < n; i++) {
        int currentSum = 0;
        for (int j = i; j < n; j++) {
            currentSum += arr[j];
            maxSum = max(maxSum, currentSum);
        }
    }

    return maxSum;
}

// Optimized approach:
// Time complexity: O(n)
// Space complexity: O(1)

int maxSubarraySumOptimized(vector<int>& arr) {
    int currentSum = 0;
    int maxSum = INT_MIN;

    for (int i=0; i<arr.size(); i++) {
        currentSum += arr[i];

        maxSum = max(maxSum, currentSum);

        if (currentSum < 0) {
            currentSum = 0;
        }
    }

    return maxSum;
}

int main() {
    vector<int> arr = {5,4,-1,7,8};

    int result = maxSubarraySumOptimized(arr);
    cout << "Maximum Subarray Sum (Naive): " << result << endl;

    return 0;
}
