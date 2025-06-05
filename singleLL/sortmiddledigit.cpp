#include<iostream>
#include<map>
using namespace std;
int main(){
    int n;
    cout<<"enter the number of elements: ";
    cin>>n;
    cout<<"enter only 3 digit numbers :";
    int arr[n];
    for(int i=0;i<n;i++){
        cout<<"enter the element "<<i<<" : ";
        cin>>arr[i];
    }
    map<int,int>mp;
    for(int i=0;i<n;i++){
        int key=arr[i];
        int midele=(arr[i]/10)%10;
        mp[midele]=key;
    }
    for(auto val:mp){
        cout<<val.second<<" ";
    }
    return 0;
}