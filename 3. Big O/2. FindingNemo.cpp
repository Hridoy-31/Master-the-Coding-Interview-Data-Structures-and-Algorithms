#include <bits/stdc++.h>
using namespace std;

void findNemo(vector<string> arr)
{
    for (auto i : arr)
    {
        if (i == "Nemo")
        {
            cout << "Found Nemo !!!" << endl;
        }
    }
}

int main()
{
    vector<string> arr = {"Nemo"};
    findNemo(arr);
    return 0;
}