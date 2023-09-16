#include <vector>
#include <iostream>
using namespace std;
vector<int> findArrayIntersection(vector<int> &arr1, int n, vector<int> &arr2, int m)
{
    int i = 0, j = 0;
    vector<int> ans;
    while (i < n && j < m)
    {

        if (arr1[i] == arr2[j])
        {
            ans.push_back(arr1[i]);
            i++;
            j++;
        }
        else if (arr1[i] < arr2[j])
        {
            i++;
        }
        else
        {
            j++;
        }
    }
    return ans;
}
int main()
{
    int a, n;
    cout << "Enter the size :";
    cin >> n;
    vector<int> v1;
    cout << "Enter the array :";
    for (int i = 0; i < n; i++)
    {
        cin >> a;
        v1.push_back(a);
    }
    int b, m;
    cout << "Enter the size :";
    cin >> m;
    vector<int> v2;
    cout << "Enter the array :";
    for (int i = 0; i < n; i++)
    {
        cin >> b;
        v2.push_back(b);
    }
    vector<int> res = findArrayIntersection(v1, n, v2, m);
    for (auto i : res)
        cout << i << " ";
}