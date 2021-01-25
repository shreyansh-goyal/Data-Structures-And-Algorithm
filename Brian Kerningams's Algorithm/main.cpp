#include <iostream>

using namespace std;

int table[256];
int lookupTableMethod(int n){
    int result =0;
    int x = 0xff;
    result += table[n&x];
    n=n>>8;
    result += table[n&x];
    n=n>>8;
    result += table[n&x];
    n=n>>8;
    result += table[n&x];
    return result;
}
int main()
{
    int n;
    cin>>n;
    table[0]=0;
    table[1]=1;
    for(int i=2;i<=255;i++){
        table[i] = (i%2) +  table[i/2];
    }
    cout<<lookupTableMethod(n)<<endl;
    if(lookupTableMethod(n)==1)cout<<"true";
    else cout<<"false";
    return 0;
}
