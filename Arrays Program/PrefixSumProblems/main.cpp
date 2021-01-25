#include <iostream>

using namespace std;

/**
Handle the prefix queries
*/
int handleThePrefixQueries(int arr[],int size,int startingPoint,int endingPoint){
    int sumArr[size];
    sumArr[0]=arr[0];

    for(int index=1;index<size;index++){
        sumArr[index]=sumArr[index-1]+arr[index];
    }
    if(startingPoint==0)
    return arr[endingPoint];
    else
        return sumArr[endingPoint]-sumArr[startingPoint-1];
}
/**
Finding the Equillibrium point with the prefix method but with the O(N) extra space
*/
int findTheEquillibriumPoint(int arr[],int size){
    int sumFromLeft[size];
    int sumFromRight[size];
    sumFromLeft[0]=arr[0];
    sumFromRight[size-1]=arr[size-1];
    for(int index=1;index<size;index++){
        sumFromLeft[index]=sumFromLeft[index-1]+arr[index];
    }
    for(int index=size-2;index>=0;index--){
        sumFromRight[index]=sumFromRight[index+1]+arr[index];
    }

    for(int index=0;index<size;index++){
        cout<<sumFromLeft[index]<<" ";
    }
    cout<<endl;
    for(int index=0;index<size;index++){
        cout<<sumFromRight[index]<<" ";
    }
    cout<<endl;
    for(int index=0;index<size;index++){
        if(index-1<0){
            if(sumFromRight[index+1]==0)
                return index;
        }
        else if(index+1>size-1){
            if(sumFromLeft[index-1]==0){
                return index;
            }
        }
        else{
            if(sumFromLeft[index-1]==sumFromRight[index+1]){
                return index;
            }
        }
    }
    return -1;
}
/**
Finding the equillibrium point with the prefix method using the O(1) space.
*/
int findEquillibriumEfficientMethod(int arr[],int size){
    int total=0;
    for(int index=0;index<size;index++){
        total += arr[index];
    }
    int curr_sum=arr[0];
    if(0==(total-arr[0])){
        return 0;
    }
    else{
        for(int index=1;index<size;index++){
            if(curr_sum==(total-curr_sum-arr[index])){
                return index;
            }
            else{
                curr_sum+=arr[index];
            }
        }
    }
    return -1;
}
/**
find if array can be divided in three part having the same sum
*/
void ThreePartedArray(int arr[],int size){
    int sum[size];
    sum[0]=arr[0];
    cout<<sum[0]<<endl;
    for(int i=1;i<size;i++){
        sum[i]=sum[i-1]+arr[i];
    }
    for(int i=0;i<size;i++){
        for(int j=0;j<size;j++){
            if(i==0||j==0)continue;

            int sum1=sum[i-1];
            int sum2=sum[j]-sum[i-1];
            int sum3=sum[size-1]-sum[j-1];
            if((sum1==sum2)&&(sum2==sum3)){
                cout<<"from 0 to "<<i-1<<" from "<<i<<" to "<<j<<"from "<<j+1<<" to "<<size-1;
            }
        }
    }
}
int main()
{
    int arr[]={1, 3, 4, 0, 4};
    ThreePartedArray(arr,5);
    return 0;
}
