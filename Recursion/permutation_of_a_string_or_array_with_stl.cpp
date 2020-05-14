#include<bits/stdc++.h>
using namespace std;

void permutation(string s,string o){
    if(s.size() == 0){
        cout<<o<<"\n";
        return;
    }
    for(int i=0;i<s.size();i++){
        permutation(s.substr(1),o+s[0]);
        rotate(s.begin(),s.begin()+1,s.end());
    }
}

int main(){
    int n =3;
    //cin>>n;
    char a[n];
    a[3] = {'a','b','c'};
    //for(int i=0;i<n;i++) cin>>a[i];
    string s="";
    for(int i=0;i<n;i++) s += a[i];
    int i=0;
    string o="";
    permutation(s,o);
}