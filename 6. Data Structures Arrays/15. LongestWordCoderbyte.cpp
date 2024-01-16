#include <bits/stdc++.h>
using namespace std;

// First attempt: (I don't know it is optimized approach or not :| )
// Time complexity: O(n)
// Space complexity: O(maxi), where maxi is the size of the longest word.

string LongestWord(string sen)
{
    int maxi = 0;
    int curr = 0;
    string longest;

    for (int i = 0; i < sen.size(); i++)
    {
        if (isalnum(sen[i]))
        {
            curr++;
        }
        else
        {
            curr = 0;
        }
        maxi = max(maxi, curr);
    }
    curr = 0;
    for (int i = 0; i < sen.size(); i++)
    {
        if (isalnum(sen[i]))
        {
            curr++;
        }
        else
        {
            curr = 0;
            longest.clear();
        }
        if (curr <= maxi)
        {
            longest.push_back(sen[i]);
            if (curr == maxi)
            {
                return longest;
            }
        }
    }
}

int main(void)
{
    string s1 = "fun&!! time";
    string s2 = "I love dogs";
    string s3 = "123456789 987654321";
    string s4 = "hello world";
    cout << LongestWord(s1) << endl;
    cout << LongestWord(s2) << endl;
    cout << LongestWord(s3) << endl;
    cout << LongestWord(s4) << endl;
    return 0;
}