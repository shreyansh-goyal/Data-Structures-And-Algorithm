#include <bits/stdc++.h>

using namespace std;

/**
In the naive solution what we are doing is to do a pass of the array and see if we are getting a majority element.we do this for all the element s.
Thus the time complexity becomes O(N^2)
*/
int naiveSolution(int arr[],int size){
    for(int oCounter=0;oCounter<size;oCounter++){
        int count=1;
        for(int iCounter=oCounter+1;iCounter<size;iCounter++){
            if(arr[iCounter]==arr[oCounter]){
                count++;
            }
        }
        if(count>(size/2)){
            return oCounter;
        }
    }
    return -1;
}
/**
Using the Moore voting algorithm we can do all of the above task in finding the majority element in the array we can do this task in O(N) time complexity
*/
int mooreVotingAlgorithm(int arr[],int size){
    int result=-1;
    int count=0;
    for(int counter=0;counter<size;counter++){
        if(result != -1&&arr[result] != arr[counter]){
            count--;
        }
        else if(result != -1){
            count++;
        }
        if(count==0){
            result=counter;
            count=1;
        }
    }
    count=0;
    for(int index=0;index<size;index++){
        if(arr[result]==arr[index]){
            count++;
        }
    }
    if(count>(size/2))return result;
    else return -1;
}
int main()
{
    int arr[]={3,2,3,3};
    cout<<naiveSolution(arr,4);
    cout<<mooreVotingAlgorithm(arr,4);
    return 0;
}

