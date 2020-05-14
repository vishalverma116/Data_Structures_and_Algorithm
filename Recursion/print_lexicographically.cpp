#include<bits/stdc++.h>

int cnt=0;

void pl(char *a,int n,std::string s){
    if(s.size() > 3 || cnt >= 15)    
        return;

    if(s.size() > 0){
        std::cout<<s<<"\n";
        cnt += 1;
    }
    for(int i=0;i<n;i++){
        pl(a,n,s+a[i]);
    }
}

int main(){
    int n;
    std::string s = "";
    std::cin>>n;
    char a[n];
    for(int i=0;i<n;i++)
        std::cin>>a[i];

    //int cnt=0;
    pl(a,n,s);
}