#include <bits/stdc++.h>
using namespace std;

// Naive approach:
// Time complexity: O(n^2)
// Space complexity: O(1)

int maxSubarraySumNaive(vector<int> &arr)
{
    int n = arr.size();
    int maxSum = INT_MIN;

    for (int i = 0; i < n; i++)
    {
        int currentSum = 0;
        for (int j = i; j < n; j++)
        {
            currentSum += arr[j];
            maxSum = max(maxSum, currentSum);
        }
    }

    return maxSum;
}

// Optimized approach:
// Time complexity: O(n)
// Space complexity: O(1)

int maxSubarraySumOptimized(vector<int> &arr)
{
    int currentSum = 0;
    int maxSum = INT_MIN;

    for (int i = 0; i < arr.size(); i++)
    {
        currentSum += arr[i];

        maxSum = max(maxSum, currentSum);

        if (currentSum < 0)
        {
            currentSum = 0;
        }
    }

    return maxSum;
}

// Divide and Conquer approach: [INTERVIEWER ASKED]
// Time complexity: O(n log(n)) [BETTER THAN NAIVE, BUT NOT GOOD AS OPTIMIZED]
// ==> For every recursion step, the array is being divided in half. So, O(log(n)) comes from here.
// ==> Inside of the recursion step, the adding sum operation is being executed in every single
// element in the divided subarray. So, ultimately the sum operation is being executed in all of
// the elements of the array whose size is n. So, n comes from here. That's why
// total time complexity is O(n log(n)).
// Space complexity: O(log n) [WORST THAN NAIVE AND OPTIMZED]
// ==> For every recursion step, the array is being divided in half and each half is acted like
// recursive function for the next steps. We know, each function assigns a default amount of space
// as a call stack for that function. As long as log(n) times the array is being divided, so,
// log(n) recursive functions are created with some call stack space assigned with them. So, the
// total space complexity is O(log(n)).

int maxCrossingSum(vector<int> &arr, int low, int mid, int high)
{
    int leftmax = INT_MIN;
    int sum = 0;
    for (int i = mid; i >= low; i--)
    {
        sum += arr[i];
        leftmax = max(leftmax, sum);
    }

    int rightmax = INT_MIN;
    sum = 0;
    for (int i = mid + 1; i <= high; i++)
    {
        sum += arr[i];
        rightmax = max(rightmax, sum);
    }

    return leftmax + rightmax;
}

int maxSubarraySumDivideConquer(vector<int> &arr, int low, int high)
{
    // Base case: If there is only one element in the subarray
    if (low == high)
    {
        return arr[low];
    }

    // Divide the array into two halves and find maximum subarray sum
    int mid = (low + high) / 2;
    int leftmax = maxSubarraySumDivideConquer(arr, low, mid);
    int rightmax = maxSubarraySumDivideConquer(arr, mid + 1, high);

    // Find the maximum subarray sum that crosses the midpoint
    int crossingsum = maxCrossingSum(arr, low, mid, high);

    // return the maximum of the three subarray sums (left max, crossing max, right max);
    return max(leftmax, max(crossingsum, rightmax));
}

int main()
{
    vector<int> arr = {5, 4, -1, 7, 8};

    int result = maxSubarraySumDivideConquer(arr, 0, arr.size() - 1);
    cout << "Maximum Subarray Sum: " << result << endl;

    return 0;
}
