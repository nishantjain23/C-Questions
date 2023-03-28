#include <bits/stdc++.h>
using namespace std;

int main(){
    int a,n;
    cout<<"Enter the size :"<<endl;
    cin>>n;
    vector <int> v;
    cout<<"Enter the array :"<<endl;
    for(int i=0;i<n;i++){
        cin>>a;
        v.push_back(a);
    }
    int k;
    cout<<"Enter number of places u wanted to shift: "<<endl;
    cin>>k;
    vector <int> ans(v.size());
    for(int i=0;i<v.size();i++){
        ans[(i+k)%v.size()]=v[i];
    }
    // v=ans;
    cout<<"Rotated array :"<<endl;
    for(auto i:ans){
        cout<<i<<" ";
    }
}