#include <bits/stdc++.h>

using namespace std;

/**
This is the maximum subarray sum using the recursion complexity is O(2^N)
*/
int maximumSubarraySum1(int arr[],int n,int sum,int index){
    if(index==n){
        return sum;
    }
    else{
        return (max(sum+arr[index],
                    max(maximumSubarraySum1(arr,n,sum+arr[index],index+1),maximumSubarraySum1(arr,n,0,index+1))));
    }

}
/**
This is the kadane's algorithm to calculate the maximum subarray sum the complexity of this algorithm is O(N)
*/
int maximumSubarraySum2(int arr[],int n){
int maxSubarraySum=arr[0];
int sum=0;
for(int i=0;i<n ;i++){
    sum+=arr[i];
    if(sum>maxSubarraySum)maxSubarraySum=sum;
    if(sum<0)sum=0;
    cout<<sum<<endl;
}
return maxSubarraySum;
}


int main()
{
     int arr[]={2,3,-8,7,-1,2,3};
     int maxSubarraySum=maximumSubarraySum1(arr,7,0,0);
     cout<<maxSubarraySum<<endl;
    return 0;
}
