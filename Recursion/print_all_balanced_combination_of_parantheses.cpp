#include<bits/stdc++.h>
using namespace std;

void pbp(string s,int n,int l,int r){
    if(n==l && n == r ){
        cout<<s<<"\n";
        return;
    }
    if(l<n && l==r){
        pbp(s+'(',n,l+1,r);
    }
    if(l>r && l<n ){
        pbp(s+'(',n,l+1,r);
        pbp(s+')',n,l,r+1);
    }
    if(l == n && l>r){
        pbp(s+')',n,l,r+1);
    }
}

int main(){
    int n;
    cin>>n;
    int l=0,r=0;
    string s="";
    pbp(s,n,l,r);
}