/*#include <bits/stdc++.h>

using namespace std;

int main()
{
    string s;
    cin>>s;
    for(int i=1;i<(pow(2,s.length()));i++){
        string output="";
        int counter=i,j=s.length()-1;
        while(counter){
            if(counter%2!=0){
                output=s[j]+output;
            }
            counter=counter/2;
            j--;
        }
        cout<<output<<endl;
    }
    return 0;
}
*/
