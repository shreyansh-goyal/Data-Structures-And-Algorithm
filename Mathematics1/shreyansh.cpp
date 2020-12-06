#include<bits/stdc++.h>
using namespace std;

bool checkPalindrome(int number){
    int rev=0;
    int n=number;
    while(n!=0){
        rev*=10;
        rev= rev+(n%10);
        n=n/10;
    }
    cout<<rev<<endl;
    if(rev == number) return true;
    else return false;
}

int main(){

cout<<checkPalindrome(123421);
return 0;
}
