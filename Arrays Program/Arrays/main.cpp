#include <bits/stdc++.h>
using namespace std;

void DeleteElement(int* arr,int n,int index){
    for(int i=index;i<n;i++){
        arr[i]=arr[i+1];
    }
}
int secondLargestElement(int arr[],int n){
    if(n<2)return -1;
    int index1=0;
    for(int i=0;i<n;i++){
        if(arr[index1]<arr[i])index1=i;
    }
    int index2=0;
    while(index2<n&&arr[index2]==arr[index1]){
        index2++;
    }
    if(index2==n)return -1;
    for(int j=index2;j<n;j++){
            if(arr[j]>arr[index2]){
                index2=j;
            }
    }
    return index2;
}
bool checksorted(int arr[],int n){
    if(n<2)return true;
    for(int i=1;i<n;i++){
        if(arr[i]<arr[i-1]){
            return false;
        }
    }
    return true;
}
void swapArrayElements(int *arr,int i,int j){
    int temp = arr[i];
    arr[i]=arr[j];
    arr[j]=temp;
}
void reverseArray(int arr[],int n){
    if(n==0) return;
    for(int i=0;i<(n/2);i++){
        swapArrayElements(arr,i,n-1-i);
    }
}
int removeDuplicateElements(int arr[],int n){
    if(n==1)return 1;
    for(int i=1;i<n;i++){
        if(arr[i]==arr[i-1]){
            DeleteElement(arr,n,i-1);
            n=n-1;
            i--;
        }
    }
    return n;
}
int* moveZeroesToTheEnd(int arr[],int n){
    int arr2[n];
    int index=0;
    for(int i=0;i<n;i++){
        if(arr[i]>0){
            arr2[index]=arr[i];
            index++;
        }
    }
    for(int i=index;i<n;i++){
        arr2[i]=0;
    }
    return arr2;
}
void moveZeroesToTheEndPart2(int arr[],int n){
    int coun=0;
    for(int i=0;i<n;i++){
        if(arr[i]!=0){
            int temp = arr[i];
            arr[i] = arr[coun];
            arr[coun] =  temp;
            coun++;
        }
    }

    for(int i=0;i<n;i++){
        cout<<arr[i]<<" "<<endl;
    }

}
void leftRotateArrayByOne(int arr[],int n){
    if(n<=1)return;
    else{
        int temp = arr[0];
        for(int i=0;i<n-1;i++){
            arr[i]=arr[i+1];
        }
        arr[n-1]=temp;
    }
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
}
void generalizedRotationOfArray(int arr[],int n,int k){
    if(n<=k){
        return generalizedRotationOfArray(arr,n,k%n);
    }
    else{
         int arr1[k];
        for(int i=0;i<k;i++){
            arr1[i]=arr[i];
        }
        for(int i=0;i<n-k;i++){
             int temp = arr[i];
             arr[i] = arr[i+k];
             arr[i+k] = temp;
        }
        for(int i=n-k;i<n;i++){
            arr[i]=arr1[i-n+k];
        }
    }
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}
void generalizedRotation2(int arr[],int n,int k){
//int k is used for the fact that we have to perform that number of the rotation
//n means the number of elements in the array and arr means the array
    if(k/n){
        return generalizedRotation2(arr,n,k%n);
    }
    else{
        //reverse the array from the index 0 to the index k-1
        //left part
        int mid=(k-1)/2;
        for(int i=0;i<mid;i++){
            int temp= arr[i];
            arr[i] = arr[k-1-i];
            arr[k-1-i] = temp;
        }
        cout<<"After reversing for the first time"<<endl;
        for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
        }
        //reversing the array from the index k to the index n-1
        //right part
        mid = (k+n-1)/2;
        int mid2 = (n-k)/2;
        for(int i=k;i<mid2+k;i++){
            int temp= arr[i];
            arr[i] = arr[n-1-i+k];
            arr[n-1-i+k] = temp;
        }
        cout<<"After reversing for the second time"<<endl;
        for(int i=0;i<n;i++){
            cout<<arr[i]<<" ";
        }
        cout<<endl;
        //reverse the full array
        mid = (n)/2;
        for(int i=0;i<mid;i++){
            int temp = arr[i];
            arr[i] = arr[n-1-i];
            arr[n-1-i] = temp;
        }

        cout<<"After reversing for the third time"<<endl;
        for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
        }
        cout<<endl;

    }
}
void leader(int arr[],int n){
    long long int maxm = LONG_MIN;
    stack<int> s;
    for(int i=n-1;i>=0;i--){
        if(arr[i]>maxm){
            maxm=arr[i];
            s.push(arr[i]);
            cout<<"check"<<endl;
        }
    }
    while(!s.empty()){
        cout<<s.top()<<" ";
        s.pop();
    }

}

void maxDifferenceNaive(int arr[],int n){
    int difference=INT_MIN;
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            if(arr[j]-arr[i]>difference)difference=arr[j]-arr[i];
        }
    }
    cout<<difference<<endl;
}


void maxDifferencePart2(int arr[],int n){
    int minm = min(arr[0],arr[1]);
    int difference = arr[1]-arr[0];
    for(int i=2;i<n;i++){
        if(arr[i]-minm>difference){
            difference=arr[i]-minm;
        }
        minm=min(arr[i],minm);
    }
    cout<<difference<<endl;
}
void frequency(int arr[],int n){
    int coun=0;
    for(int i=0;i<n;i++){
        if(i+1<n){
            if(arr[i+1]==arr[i]){
                coun++;
            }
            else{
                coun++;
                cout<<arr[i]<<"  "<<coun<<endl;
                coun=0;
            }
        }
        else{
            coun++;
            cout<<arr[i]<<"  "<<coun<<endl;
        }
    }
}
int stockBuyAndSell(int arr[],int n,int s,int e){
    cout<<s<<"  "<<e<<endl;
    if(s>=e)return 0;
    int profit=0;
    for(int i=s;i<e;i++){
        for(int j=i+1;j<=e;j++){
            if(arr[j]-arr[i]>0){
                int curr_profit = arr[j]-arr[i]+stockBuyAndSell(arr,n,s,i-1)+stockBuyAndSell(arr,n,j+1,e);
                profit = max(profit,curr_profit);
            }
        }
    }
    return profit;
}
int stockButAndSellPart2(int arr[],int n){
    int profit=0;
    for(int i=1;i<n;i++){
        if(arr[i]>arr[i-1]){
            profit+=arr[i]-arr[i-1];
        }
    }
    return profit;
}
int calculateTrappedWater(int arr,int s,int e,int minm){

}
int trappingRainWater(int arr[],int n){
    int total =0;
    for(int i=1;i<n-1;i++){//O(N)
        int lh=arr[i];
        int rh=arr[i];
        for(int j=0;j<i;j++){//O(N)
            if(lh<arr[j])lh=arr[j];
        }
        for(int j=i+1;j<n;j++){//O(N)
            if(rh<arr[j])rh=arr[j];
        }
        int minm=min(lh,rh);
        total+=minm-arr[i];
    }
    return total;
}
int trappingWaterPart2(int arr[],int n){
    int lh[n];
    int rh[n];
    lh[0]=arr[0];
    rh[0] = arr[n-1];
    int total=0;
    for(int i=1;i<n;i++){
        if(arr[i]>lh[i-1])lh[i]=arr[i];
        else lh[i] = lh[i-1];
    }
    for(int i = n-2;i>=0;i--){
        if(arr[i]>rh[i+1])rh[i] = arr[i];
        else rh[i] = rh[i+1];
    }
    for(int i=1;i<n-1;i++){
        total += min(lh[i],rh[i])-arr[i];
    }
    return total;
}
int maximumConsicutiveSum(int arr[],int n){
    int res=0;
    int curr_res=0;
    for(int i=0;i<n;i++){
        if(arr[i]==1){
            curr_res++;
            res = max(curr_res,res);
        }
        else{
            curr_res=0;
        }
    }
    return res;
}
int maximumSubarraySum(int arr[],int n){
    int res=INT_MIN;
    int curr_res=0;
    for(int i=0;i<n;i++){
        curr_res+=arr[i];
        if(curr_res>res)res=curr_res;
        if(curr_res<0)curr_res=0;
    }
    return res;
}
int main()
{
    int arr[100];
    int n;
    cout<<"enter how many values you want to enter in the array"<<endl;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    cout<<"the maximum subarray sum can be considered as "<<maximumSubarraySum(arr,n)<<endl;
    return 0;
}
