#include <bits/stdc++.h>
using namespace std;
int F(vector<int> &arr, int index, int k, int sum, int L, int R)
{
    if (sum > k)//Works only if array contains positives
    {
        return 0;
    }
    if (index >= arr.size())
    {
        if (sum == k)
        {
            return 1;
        }
        return 0;
    }
    sum = sum + arr[index];
    L = F(arr, index + 1, k, sum, L, R);
    sum = sum - arr[index];
    R = F(arr, index + 1, k, sum, L, R);

    return L + R;
}
int main()
{
    vector<int> arr = {1, 2, 1};
    vector<int> res;
    cout << F(arr, 0, 2, 0, 0, 0);
    return 0;
}