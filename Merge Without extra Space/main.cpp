#include <iostream>

using namespace std;

void quickSort(int* ,int* ,int n,int m);


int swapElements(int arr1[],int arr2[],int m,int n,int index1,int index2){
    if(index1<m&&index2<m){
        int temp = arr1[index1];
        arr1[index1]=arr1[index2];
        arr1[index2]=temp;
    }
    else if(index1<m&&index2>=m){
        int temp = arr1[index1];
        arr1[index1] = arr2[index2%m];
        arr2[index2%m] = temp;
    }
    else if(index1>=m&&index2>=m){
        int temp = arr2[index1%m];
        arr2[index1%m] = arr2[index2%m];
        arr2[index2%m] = temp;

    }
}
int partitionAlgorithm(int arr1[],int arr2[],int m,int n){
    int value = arr1[0];
    int i=0;
    for(int i=0;i<m;i++){
        cout<<arr1[i]<<" ";
    }
    for(int j=0;j<n;j++){
        cout<<arr2[j]<<" ";
    }
    for(int j=i+1;j<m+n;j++){
            cout<<i<<" "<<j<<" "<<value<<" ";
        if(j>=m){
            cout<<arr2[j%m]<<endl;
            if(arr2[j%m]<value){
                i++;
                swapElements(arr1,arr2,m,n,i,j);
            }
        }
        else{
            cout<<arr1[j]<<endl;
            if(arr1[j]<value){

                i++;
                int temp = arr1[i];
                arr1[i] = arr2[j];
                arr2[j]=temp;
            }
        }
    }
    swapElements(arr1,arr2,m,n,0,i);
    return i;
}
void quickSort(int arr1[],int arr2[],int m,int n){
    //Here x is the index
    cout<<"the value of m and n "<<m<<"  "<<n<<endl;
    cout<<"the value in the left array before partition"<<endl;
    for(int i=0;i<m;i++)cout<<arr1[i]<<endl;
    cout<<"the value in the right array before partition"<<endl;
    for(int i=0;i<n;i++)cout<<arr2[i]<<endl;
    if(m==0||n==0) return;
    int x = partitionAlgorithm(arr1,arr2,m,n);
    cout<<"this is the value of the x "<<x<<endl;
    cout<<"this is the sorted array"<<endl;
    for(int i=0;i<m;i++)cout<<arr1[i]<<endl;
    for(int j=0;j<n;j++)cout<<arr2[j]<<endl;
    cout<<endl<<endl<<endl;
    if(x>m){
        quickSort(arr1,arr2,m,(x-1)%m+1);
        quickSort(arr1,arr2+(x%m)+1,0,n-((x%m)+1));
    }
    else if(x%m==0){
        quickSort(arr1,arr2,m,0);
        quickSort(arr1,arr2+1,0,n-1);
    }
    else{
        quickSort(arr1,arr2,x,0);
        quickSort(arr1+x+1,arr2,m-x-1,n);
    }

}
void merge(int arr1[], int arr2[], int n, int m)
{
    quickSort(arr1,arr2, n, m);

}
int main()
{
    int arr1[]={4,5,10,11,15};
    int arr2[]={2,6,7,12,14};
    merge(arr1,arr2,5,5);
    for(int i=0;i<5;i++){
        cout<<arr1[i]<<endl;
    }
    for(int j=0;j<5;j++){
        cout<<arr2[j]<<endl;
    }
    return 0;
}
