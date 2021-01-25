#include <iostream>

using namespace std;

int maxLengthEvenOddSubArray_Iteration(int arr[],int size){
    int result=0;
    int length=0;
    int nextToExpect=0;
    {
    if(size==0){
        return 0;
    }
    else result=1;
    }
    nextToExpect=(arr[0]+1)%2;
    length=1;
    for(int i=1;i<size;i++){
        if(arr[i]%2==nextToExpect){
            length++;
            result=max(result,length);
        }
        else{
            length=1;
        }
        nextToExpect=(arr[i]+1)%2;
    }
    return result;
}
int main()
{
    int arr[]={10,12,8,4};
    cout<<maxLengthEvenOddSubArray_Iteration(arr,5)<<endl;
    return 0;
}
