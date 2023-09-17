#include <iostream>
#include <math.h>
using namespace std;
int main()
{
    int n;
    cout<<"Enter the number :"<<endl;
    cin >> n;
    float ans = 0;
    int i = 0;
    while (n != 0)
    {
        int bit = n & 1; //& is used as an and operator
        ans = (bit * pow(10, i)) + ans;
        n = n >> 1; //>> is used to shift the bit right side
        i++;
    }
    cout <<"After Binary conversion :"<< ans;
}