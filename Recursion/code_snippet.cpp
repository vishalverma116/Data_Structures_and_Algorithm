#include<bits/stdc++.h>

void func(int n){
    std::cout<<n<<", ";
    if(n>= 3)   return;
    func(n+1);
    func(n+2);
}

int main(){
    func(0);

    return 0;
}