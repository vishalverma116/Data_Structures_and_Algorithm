#include<bits/stdc++.h>
using namespace std;

int subC(int *a,int n,int i,int SUM){
    if(SUM <0 || i==n) return 0;
    if(SUM == 0) return 1;

    int c1 = subC(a,n,i,SUM-a[i]);
    int c2 = subC(a,n,i+1,SUM);

    return c1+c2;
}

int main(){
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++) cin>>a[i];
    int SUM;
    cin>>SUM;
    int i=0;
    cout<<subC(a,n,i,SUM);
}