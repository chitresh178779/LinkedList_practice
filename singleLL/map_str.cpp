#include<iostream>
#include<map>
using namespace std;

bool isanagram(string s,string s1){
    map<int,char> yeah;
    for(int i=0;i<s.length();i++){
        yeah[s[i]]++;
    }
    int check_size= yeah.size();
    for (int i=0;i<s1.length();i++){
        yeah[s1[i]]++;
    }
    if(check_size!=yeah.size()){
        return false;
    }
    
    else{
        for(auto &ch:yeah){
            if((ch.second%2)!=0){
                return false;
            }
        }
    }
    return true;
}

int main(){
    string s;
    cin>>s;
    string s1;
    cin>>s1;
    bool validity= isanagram(s,s1);
    cout<<validity;
    return 0;
}