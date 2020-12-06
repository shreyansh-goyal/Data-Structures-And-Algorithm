#include<bits/stdc++.h>
using namespace std;

int calculateFactorialIterative(int n){
    int fact=1;
    while(n>1){
        fact*=n;
        n--;
    }
    return fact;
}

int calculateFactorialRecursive(int n){
    if(n<=1) return 1;
    else return n*calculateFactorialRecursive(n-1);
}
int main(){

cout<<calculateFactorialRecursive(5)<<endl;
return 0;
}

