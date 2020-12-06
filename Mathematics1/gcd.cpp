#include<bits/stdc++.h>
using namespace std;


int computeGCD(int a,int b){
    //naive method of computing the gcd
    int n=min(a,b);
    int i;
    for(i=n;i>=1;i--){
        if(a%i==0&&b%i==0){
            break;
        }
    }
    return i;
    //O(min(a,b))
}

int computeGcdEuclidean(int a,int b){
    cout<<a<<" "<<b<<endl;
    if(a==b) return a;
    int y=min(a,b);
    int x=max(a,b)-min(a,b);
    return computeGcdEuclidean(x,y);
}
int main(){
cout<<computeGcdEuclidean(7,20);
return 0;
}


/*
notes for the euclidiean algorithm
let a and b be the two number whom we have to compute the gcd between the two
let a = gx  b = gy
now a-b = g = g(x-y)
this means the gcd remained conserved and we are decreasing the number continuosly and after reaching to a proper output we get the desired the number
*/
