#include <bits/stdc++.h>

using namespace std;

/**
Kadane algorithm implementation
*/
int kadaneAlgorithm(int arr[],int size){

    int result =arr[0];
    int curr_result=arr[0];
    for(int i=1;i<size;i++){
        curr_result=max(curr_result+arr[i],arr[i]);
        result=max(result,curr_result);
    }
    return result;
}
/**
*This is the naiver solution for the maximum circular subarray sum
*/
int maximumCircularSubArraySum(int arr[],int size){

    int result=INT_MIN;
    for(int startingIndex=0;startingIndex<size;startingIndex++){
        int sum=0;
        for(int i=startingIndex;i<(size+startingIndex);i++){
            sum+=arr[i%size];
            result=max(sum,result);
            if(sum<0) sum=0;
        }
    }
    return result;
}
/**
This solution gives the maximumCircularSubArraySum in O(N) time complextiy
calculate the sum of all elements of the array and subtract the minimum sum subarray

*/

int maximumCircularSubArraySum_Efficient(int arr[],int n){
        int maximumSumSubarray=kadaneAlgorithm(arr,n);
        if(maximumSumSubarray<0)return maximumSumSubarray;
        int sum=0;
        for(int i=0;i<n;i++){
            sum+=arr[i];
            arr[i]*=-1;
        }
        int minSubarraySum=-1*kadaneAlgorithm(arr,n);
        int maxCircularSum=sum-minSubarraySum;
}
int main()
{
    int arr[]={8,-4,3,-5,4};
    cout<<maximumCircularSubArraySum_Efficient(arr,5);
    return 0;
}
