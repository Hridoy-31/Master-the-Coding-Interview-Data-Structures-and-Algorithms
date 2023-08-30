#include <bits/stdc++.h>
using namespace std;

void findNemo(vector<string> arr)
{
    auto start = chrono::high_resolution_clock::now();
    for (auto i : arr)
    {
        if (i == "nemo")
        {
            cout << "Found Nemo !!!" << endl;
        }
    }
    auto end = chrono::high_resolution_clock::now();
    auto duration = chrono::duration_cast<chrono::milliseconds>(end - start);
    cout << "Time taken: " << duration.count() << " milliseconds." << endl;
}

int main()
{
    vector<string> arr = {"nemo"};

    vector<string> arr2 = {"dory", "bruce", "marlin", "nemo"};

    vector<string> everyone = {"dory", "bruce", "marlin", "nemo", "gill", "bloat",
                               "nigel", "squirt", "darla", "hank"};

    vector<string> arr3(10);
    fill(arr3.begin(), arr3.end(), "nemo");

    findNemo(arr3);

    return 0;
}