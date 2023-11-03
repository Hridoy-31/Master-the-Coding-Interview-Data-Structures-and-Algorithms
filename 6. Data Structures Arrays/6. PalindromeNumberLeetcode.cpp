#include <bits/stdc++.h>
using namespace std;

// Naive approach:
// Time complexity: O(n)  ==> for the reverse() funtion
// Space complexity: O(n) ==> for taking extra two strings in the function, where n is 
//                            number of digits in the integer x.

bool isPalindrome(int x) {
    string num = to_string(x);
    string rev = num;

    // Space complexity of the reverse() function is O(1). Because, it swaps elements within
    // the container itself. No extra container needed to store the swapped elements.
    reverse(rev.begin(), rev.end());

    return (num == rev);
}

// Optimized approach: (Without converting into a string)
// Time complexity: O(n)
// Space complexity: O(1)

bool isPalindromeOpti(int x) {
    if (x < 0) {
        return false;
    }
    else {
        long long int rev = 0;
        long long int given = x;

        while (x != 0) {
            rev = rev * 10 + x % 10;
            x = x / 10;
        }

        return (given == rev);
    }
}

int main()
{
    long long int x = -121;
    cout << boolalpha;
    cout << isPalindromeOpti(x) << endl;

    return 0;
}