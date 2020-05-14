#include<bits/stdc++.h>
//using namespace std;

// non - tailed recursion
int fact(int n){
    if( n<=1)   return 1;
    return n*fact(n-1);
}

//tailed recursion
int fact2(int n, unsigned int a){
    if(n<=0) return a;
    return fact2(n-1, n*a);
}

int main(){
    int n;
    unsigned int a = 1;
    std::cin>>n;
    std::cout<<fact(n)<<"\n";
    std::cout<<fact2(n,a);

    //return 0;
}