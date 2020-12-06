#include <bits/stdc++.h>

using namespace std;


int countDigit1(int n){
    //time complexity is log(n) base 10
    int count =0;
    while(n!=0){
        n=n/10;
        count++;
    }
    return count;
}
int countDigit2(int n){
    //time complexity is logn base 10
    //space complextity is logn base 10
    if(n==0) return 0;
    return 1+countDigit2(n/10);
}
int countDigit3(int n){
    //time complexity and space complexity is O(1) and O(1)
    return floor(log10(n)+1);
}

bool checkPalindrome(int n){
    int num=n;
    int rev=0;
    while(num!=0){
        rev = rev*10;
        rev+=num%10;
        num=num/10;
    }
    if(rev==n){
        return true;
    }
    else{
        return false;
    }
}


int main()
{
  cout<<checkPalindrome(1232);
    return 0;
}
