/*#include<bits/stdc++.h>
using namespace std;
int main(){
string str;
cin>>str;
int powSize = pow(2,str.length());
for(int i=0;i<powSize;i++){
    for(int j=0;j<str.length();j++){
        //cout<<"value of count "<<i<<"value of index "<<j<<"  "<<"value of index and with count"<<(i&(1<<j))<<endl;
        if((i&(1<<j))!=0) cout<<str[j];
    }
    cout<<" ";
}
return 0;
}
*/
