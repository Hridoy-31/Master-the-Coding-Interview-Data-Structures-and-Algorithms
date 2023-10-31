#include <bits/stdc++.h>
using namespace std;

// Initial approach:
// Time complexity: O(n)
// Space complexity: O(n)

int romanToInt(string s)
{
    unordered_map<char, int> roman;
    // mapping
    roman['I'] = 1;
    roman['V'] = 5;
    roman['X'] = 10;
    roman['L'] = 50;
    roman['C'] = 100;
    roman['D'] = 500;
    roman['M'] = 1000;

    long long int sum = 0;

    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == 'I' and (s[i + 1] == 'V' or s[i + 1] == 'X'))
        {
            sum += roman[s[i + 1]] - roman[s[i]];
            i++;
        }
        else if (s[i] == 'X' and (s[i + 1] == 'L' or s[i + 1] == 'C'))
        {
            sum += roman[s[i + 1]] - roman[s[i]];
            i++;
        }
        else if (s[i] == 'C' and (s[i + 1] == 'D' or s[i + 1] == 'M'))
        {
            sum += roman[s[i + 1]] - roman[s[i]];
            i++;
        }
        else
        {
            sum += roman[s[i]];
        }
    }
    return sum;
}

// Cleaner approach:

int romanToIntClean(string s)
{
    unordered_map<char, int> roman;

    // mapping
    roman['I'] = 1;
    roman['V'] = 5;
    roman['X'] = 10;
    roman['L'] = 50;
    roman['C'] = 100;
    roman['D'] = 500;
    roman['M'] = 1000;

    long long int answer = 0;

    for (int i = 0; i < s.size(); i++)
    {
        if (roman[s[i]] < roman[s[i + 1]])
        {
            answer -= roman[s[i]];
        }
        else
        {
            answer += roman[s[i]];
        }
    }

    return answer;
}

int main()
{
    string s = "MCMXCIV";
    long long int result = romanToIntClean(s);
    cout << result << endl;
    return 0;
}