#include <bits/stdc++.h>
using namespace std;

int main(){
    // check if array is sorted and rotate
    int a,n;
    cout<<"Enter the size :"<<endl;
    cin>>n;
    vector <int> v;
    cout<<"Enter the array :"<<endl;
    for(int i=0;i<n;i++){
        cin>>a;
        v.push_back(a);
    }
    int count =0;
    for(int i=1;i<v.size();i++){
        if(v[i-1]>v[i])
        count++;
    }
    if(v[n-1]>v[0])
    count++;
    
    if(count<=1)
    cout<<"True "<<endl;
    else
    cout<<"False ";

}