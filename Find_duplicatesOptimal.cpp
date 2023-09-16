#include <iostream>
#include <vector>
using namespace std;
int findDuplicate(vector<int> &arr)
{
    int ans = 0;

    // XOR ing all array elements
    for (int i = 0; i < arr.size(); i++)
    {
        ans = ans ^ arr[i];
    }

    // XOR [1, n-1]
    for (int i = 1; i < arr.size(); i++)
    {
        ans = ans ^ i;
    }
    return ans;
}
int main()
{
    int a, n;
    cout << "Enter the size :";
    cin >> n;
    vector<int> v;
    cout << "Enter the array :";
    for (int i = 0; i < n; i++)
    {
        cin >> a;
        v.push_back(a);
    }
    int res = findDuplicate(v);
    cout << "Repeated element :" << res;
}