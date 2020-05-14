#include<bits/stdc++.h>
using namespace std;

void permutation(char *a,int n,int i){
    if(i == n){
        cout<<a<<"\n";
        return;
    }
    for(int j=i;j<n;j++){
        swap(a[i],a[j]);
        permutation(a,n,i+1);
        swap(a[i],a[j]);
    }
}

int main(){
    int n;
    cin>>n;
    char a[n];
    for(int i=0;i<n;i++) cin>>a[i];

    int i=0;
    permutation(a,n,i);
}