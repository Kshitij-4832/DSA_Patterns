#include <bits/stdc++.h>
using namespace std;
int main()
{
    vector<int> arr = {1, 2, 3, 1, 7, 1, 1, 4, 2, 3};
    int k = 3, size = arr.size();
    int left = 0, right = 0, sum = 0, maxlen = 0;
    while (right < size)
    {
        sum = sum + arr[right];
        while (sum > k)
        {
            sum = sum - arr[left];
            left++;
        }
        if (sum == k)
        {
            maxlen = max(maxlen, right - left + 1);
        }
        if (sum <= k)
        {
            right++;
        }
    }
    cout << maxlen << endl;
    return 0;
}