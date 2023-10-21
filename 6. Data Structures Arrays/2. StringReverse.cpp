#include <bits/stdc++.h>
using namespace std;

// Naive approach
// Time complexity: O(n)
// Space complexity: O(n)

string revstr(string s)
{
    string reversestr;
    for (int i = s.size() - 1; i >= 0; i--)
    {
        reversestr.push_back(s[i]);
    }

    return reversestr;
}

// Optimized approach
// Time complexity: O(n)
// Space complexity: O(1) ==> No extra space required. Because "reverse" function is
//                            reversing the string in-place.

string revstropti(string s)
{
    reverse(s.begin(), s.end());
    return s;
}

int main()
{
    string s = "Hridoy";
    cout << revstropti(s) << endl;
    return 0;
}