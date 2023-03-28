#include <bits/stdc++.h>
using namespace std;
bool isPossible(vector<int> v, int n, int m, int mid)
{
    int studcnt = 1;
    int pagesum = 0;
    for (int i = 0; i < n; i++)
    {
        if (pagesum + v[i] <= mid)
        {
            pagesum += v[i];
        }
        else
        {
            studcnt++;
            if (studcnt > m || v[i] > mid)
            {
                return false;
            }
            pagesum = v[i];
        }
    }
    return true;
}
int main()
{
    // Book allocation problem
    int a, n, m;
    cout << "Enter number of studs: " << endl;
    cin >> m;
    cout << "Enter total no of books: " << endl;
    cin >> n;
    cout << "Enter each book pages: " << endl;
    vector<int> v;
    for (int i = 0; i < n; i++)
    {
        cin >> a;
        v.push_back(a);
    }
    int s = 0;
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += v[i];
    }
    int e = sum;
    int ans = -1;
    int mid = s + (e - s) / 2;
    while (s <= e)
    {
        if (isPossible(v, n, m, mid))
        {
            ans = mid;
            e = mid - 1;
        }
        else
        {
            s = mid + 1;
        }
        mid = s + (e - s) / 2;
    }
    cout << "The min of max pages alloted is: " << endl;
    cout << ans;
}