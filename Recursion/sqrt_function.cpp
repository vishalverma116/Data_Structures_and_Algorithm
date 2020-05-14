#include<bits/stdc++.h>
using namespace std;

int sqt(int n){
    int l=1;
    int h=n;
    int m,m2;

    while(l<=h){
        m = (l+h)/2;
        m2 = m*m;
        if(m2 ==n) return m;
        else if(m2>n) h = m-1;
        else l = m+1;
    }
    return min(l,h);
}

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        cout<<sqt(n)<<"\n";
    }
}

/*
BABYLONIAN METHOD
#include <iostream> 
using namespace std; 
class gfg { 
	Returns the square root of n. Note that the function 
public: 
	float squareRoot(float n) 
	{ 
		//We are using n itself as initial approximation 
		//This can definitely be improved 
		float x = n; 
		float y = 1; 
		float e = 0.000001; // e decides the accuracy level
		while (x - y > e) { 
			x = (x + y) / 2; 
			y = n / x; 
		} 
		return x; 
	} 
}; 

// Driver program to test above function
int main() 
{ 
	gfg g; 
	int n = 50; 
	cout << "Square root of " << n << " is " << g.squareRoot(n); 
	getchar(); 
} 

*/


