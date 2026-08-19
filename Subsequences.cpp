#include <bits/stdc++.h>
using namespace std;
void printSubsequences(vector<int> &arr, int index, vector<int> &sequences)
{
    if (index >= arr.size())
    {
        for (int ans : sequences)
        {
            cout << ans << " ";
        }
        cout << endl;
        return;
    }
    sequences.push_back(arr[index]);
    printSubsequences(arr, index + 1, sequences); // selecting the element
    sequences.pop_back();
    printSubsequences(arr, index + 1, sequences); // rejecting the element firstly
    // we can also reject the element first and then select it, but the output will be printed differently different
}
int main()
{
    vector<int> arr = {3, 1, 2};
    vector<int> sequences;
    printSubsequences(arr, 0, sequences);
    return 0;
}