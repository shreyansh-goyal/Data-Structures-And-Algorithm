#include<bits/stdc++.h>
using namespace std;

int countSetBits(int n)
{
    if(n==0) return 0;
    int power=0;
    int m = n;
    while(m){
        power++;
        m=m>>1;
    }
    int x = pow(2,power);
    return (x/4)*(power-1)+(n-x/2 + 1) + countSetBits(n-x/2);
}

int main(){
    int x=42;
    cout<<~42<<endl;
return 0;
}
