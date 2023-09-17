#include <bits/stdc++.h>
using namespace std;

void Adding(vector<int> v1, vector<int> v2, int n, int m)
{
    int i = n - 1;
    int j = m - 1;
    int carry = 0;
    vector<int> v3;
    while (i >= 0 && j >= 0)
    {
        int val1 = v1[i];
        int val2 = v2[j];
        int sum = val1 + val2 + carry;
        carry = sum / 10;
        sum = sum % 10;
        v3.push_back(sum);
        i--;
        j--;
    }
    // first case
    while (i >= 0)
    {
        int sum = v1[i] + carry;
        carry = sum / 10;
        sum = sum % 10;
        v3.push_back(sum);
        i--;
    }
    // second case
    while (j >= 0)
    {
        int sum = v2[j] + carry;
        carry = sum / 10;
        sum = sum % 10;
        v3.push_back(sum);
        j--;
    }
    // Third case
    while (carry != 0)
    {
        int sum = carry;
        carry = sum / 10;
        sum = sum % 10;
        v3.push_back(sum);
    }
    int s = 0;
    int e = v3.size() - 1;
    while (s < e)
    {
        swap(v3[s], v3[e]);
        s++;
        e--;
    }
    // Printing
    cout << "The sum of the given number is: " << endl;
    for (auto k : v3)
    {
        cout << k << " ";
    }
}
int main()
{
    // adding two array
    int a, n;
    cout << endl
         << "Enter the number of digit of first number: " << endl;
    cin >> n;
    vector<int> v1;
    cout << "Enter First Number: " << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> a;
        v1.push_back(a);
    }
    int b, m;
    cout << "Enter the number of digit of second number: " << endl;
    cin >> m;
    vector<int> v2;
    cout << "Enter Second Number: " << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> b;
        v2.push_back(b);
    }
    Adding(v1, v2, n, m);
}