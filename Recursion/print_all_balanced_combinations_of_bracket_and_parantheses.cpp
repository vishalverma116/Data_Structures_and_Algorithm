#include<bits/stdc++.h>
using namespace std;

stack<char> stak;

void pbp(string s,int n,int m,int l1,int r1,int l2,int r2){
    if(l1 == n && r1 == n && l2==m && r2==m){
        cout<<s<<"\n";
        return;
    }

    // ( or {
    if( l1<n && l1==r1 ){
        stak.push('(');
        pbp(s+'(',n,m,l1+1,r1,l2,r2);        
    }

    if (l2<m && l2==r2){
        stak.push('{');
        pbp(s+'{',n,m,l1,r1,l2+1,r2);
    }

    if(l1>r1 && l1==n && stak.top() == '(' ){
        stak.pop();
        pbp(s+')',n,m,l1,r1+1,l2,r2);
    }

    if(l2>r2 && l2==m && stak.top() == '{' ){
        stak.pop();
        pbp(s+'}',n,m,l1,r1,l2,r2+1);
    }

    if((l1>r1 && l1< n && l2>0) || (l2>r2 && l2<m && l1>0)){
        if(stak.top() == '('){
            stak.push('(');
            pbp(s+'(',n,m,l1+1,r1,l2,r2);
            pbp(s+')',n,m,l1,r1+1,l2,r2);
        }
    }

}

int main(){
    int n,m;
    cin>>n>>m;
    int l1=0,r1=0,l2=0,r2=0;
    string s= "";
    pbp(s,n,m,l1,r1,l2,r2);
}