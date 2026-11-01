#include <bits/stdc++.h>
using namespace std;
bool F(vector<int> &arr, vector<int> &res, int index, int k, int sum)
{
    if (index >= arr.size())
    {
        if (sum == k)
        {
            for (int i : res)
            {
                cout << i << " ";
            }
            cout << endl;
            return true;
        }
        return false;
    }
    res.push_back(arr[index]);
    sum = sum + arr[index];
    if (F(arr, res, index + 1, k, sum))
    {
        return true;
    }
    res.pop_back();
    sum = sum - arr[index];
    if (F(arr, res, index + 1, k, sum))
    {
        return true;
    }
    return false;
}
int main()
{
    vector<int> arr = {1, 2, 1};
    vector<int> res;
    F(arr, res, 0, 2, 0);
    return 0;
}