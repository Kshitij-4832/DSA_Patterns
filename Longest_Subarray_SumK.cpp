#include <bits/stdc++.h>
using namespace std;
int main()
{
    vector<int> arr = {1, 2, 3, 1, 1, 1, 1, 4, 2, 3};
    int size = arr.size(), k = 3, maxlen = 0;
    unordered_map<int, int> mpp;
    int prefixsum = 0;
    for (int i = 0; i < size; i++)
    {
        prefixsum += arr[i];
        if (prefixsum == k)
        {
            maxlen = max(maxlen, i + 1);
        }
        int rem = prefixsum - arr[i];
        if (mpp.find(rem) != mpp.end())
        {
            maxlen = max(maxlen, i - mpp[rem]);
        }
        if (mpp.find(prefixsum) == mpp.end())
        {
            mpp[prefixsum] = i;
        }
    }
    cout << maxlen << endl;
    return 0;
}
// If the array contains non positive numbers then this is the most optimised solution