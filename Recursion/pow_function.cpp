#include<bits/stdc++.h>
using namespace std;

/*
// this method runs in logn time not enough for large values of n
double myPow(double x, int n) {
	if(n==0)
	    return 1;
	if(n == 1 )
	    return x;
	if( n == -1)
	    return double(1/x);
	        
	if(n%2==0)
	    return myPow(x,n/2)*myPow(x,n/2);
	else if(n%2 == 1)
	    return x*myPow(x,n/2)*myPow(x,n/2);
	else
	    return 1/double(x)*myPow(x,n/2)*myPow(x,n/2);
}
*/
/*
double binaryExponentiation(double x,int n){
        if(x==0){
            return 0;
        }
        if(n==0){
            return 1;
        }
        double ans = binaryExponentiation(x,n/2);
        if(n%2==0){
            return ans*ans;
        }
        if(n<0){
            return (1/x)*ans*ans;
        }
        return x*ans*ans;
    }
    
    double myPow(double x, int n) {
        return binaryExponentiation(x,n);
    }
*/
// this method runs in log(log(n)) time
double calculate(double x, long n){
    if(n==0) 
        return 1;
    return calculate(x*x, n/2) * (n%2 ?x:1);
}

double myPow(double x,int n){
    if(x == 1.0)
        return x;
    if(n==0)
    	return 1;
    if(n>0)
        return calculate(x,n);
    else 
        return 1/calculate(x, -long(n));
}

int main(){
	int x = 2.0000, n = 10;
	cout<<myPow(x,n);
}


