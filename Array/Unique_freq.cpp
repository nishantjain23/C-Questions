#include <iostream>
#include <bits/stdc++.h>
// #include<set.h>
using namespace std;
int main()
{
    int n;
    cout<<"Enter the size of the array :"<<endl;
    cin >> n;
    int arr[100];
    int brr[100];
    cout<<"Enter the array :"<<endl;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    // instead of for we can also use while like
    // while(i<size)
    sort(arr, arr + n);
    int size = 0, i = 0, k = 0;
    while (i < n)
    {
        int count = 1;
        for (int j = i + 1; j < n; j++)
        {
            if (arr[i] == arr[j])
            {
                count++;
            }
        }
        brr[k] = count;
        k++;
        i += count;
        size++;
    }
    cout << "The size of element array is " << endl;
    cout << size << endl;
    cout << "The array containing freq. of element" << endl;
    for (i = 0; i < size; i++)
    {
        cout << brr[i] << " ";
    }
    cout << endl;
    int isunique = 0;
    for (i = 0; i < size - 1; i++)
    {
        if (brr[i] == brr[i + 1])
        {
            isunique = 1;
            break;
        }
    }
    if (isunique == 0)
        cout << "Unique occurences, True";
    else
        cout << "Not Unique occurence, False!";
}