#include<bits/stdc++.h>
using namespace std;

int trailingZeros(int n){
    int itr=5;
    int res=0;
    while(itr<=n){
        res+=floor(n/itr);
        itr*=5;
    }
    return res;
    //complexity log base5 n ;
    //thus the complexity of the problem is the O(logn)

}
int main(){
cout<<trailingZeros(120)<<endl;
return 0;
}
