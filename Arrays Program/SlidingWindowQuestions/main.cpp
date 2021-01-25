#include <bits/stdc++.h>

using namespace std;
/**
Given an array of integer and a number k find the maximum sum of K consecutive elements
*/
int maxConsecutiveSumOfSubarrayOfKthElements(int arr[],int size,int k){
    int result=INT_MIN;
    int curr_sum=0;
    for(int i=0;i<k;i++){
        curr_sum+=arr[i];
    }
    result=max(result,curr_sum);
    for(int counter=k;counter<size;counter++){
        curr_sum=curr_sum+arr[counter]-arr[counter-k];
        result=max(result,curr_sum);
    }
    return result;

}
/**
Given an unsorted array of the non negative integers.Find if there is a subarray with the given sum
*/
string subarrayWithGivenSum(int arr[],int size,int sum){
    int curr_sum=arr[0];
    int leftIndex=0;
    int rightIndex=0;
    while(leftIndex<size&&rightIndex<size)
        {
        if(leftIndex>rightIndex){
            rightIndex=leftIndex;
            curr_sum=arr[rightIndex];
        }
        if(curr_sum>sum){
            curr_sum-=arr[leftIndex];
            leftIndex++;
        }
        else if(curr_sum<sum){
            rightIndex++;
            curr_sum+=arr[rightIndex];
        }
        else{
            return ""+to_string(leftIndex)+" : "+to_string(rightIndex);
        }
    }
    return "Not Found";
}


/**
Nth fibonacci function with the sliding window
*/
void NthFibonacci(int arr[],int size,int k){
    int curr_fibonnaci=0;
    for(int i=0;i<k-1;i++){
        arr[i]=0;
    }
    arr[k-1]=1;
    curr_fibonnaci=1;
    for(int i=k;i<size;i++){
        arr[i]=curr_fibonnaci;
        curr_fibonnaci+=arr[i]-arr[i-k];
    }
    cout<<arr[size-1];
    return;
}
int main()
{
    //int arr[]={1,8,30,-5,20,7};
    //cout<<maxConsecutiveSumOfSubarrayOfKthElements(arr,6,3);

    //int arr[]={2,4,20,3,10,5};
    //cout<<subarrayWithGivenSum(arr,6,23);

    int arr[8];
    NthFibonacci(arr,8,3);
    return 0;
}
