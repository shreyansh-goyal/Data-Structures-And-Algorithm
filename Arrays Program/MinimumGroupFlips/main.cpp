#include <bits/stdc++.h>

using namespace std;

void Efficient(int arr[],int size){
    bool from=true;
    for(int i=1;i<size;i++){
        if(arr[i-1]!=arr[i]){
            if(from){
                cout<<"from "<<i<<" :";
                from=!from;
            }
            else{
                cout<<"to "<<i-1<<endl;
                from=!from;
            }
        }
    }
}


int main()
{
    int arr[]={1,1,1,0,0,0,1,1,0,0,1};
    Efficient(arr,11);
    return 0;
}
