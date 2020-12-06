#include<bits/stdc++.h>
using namespace std;



//naive method
/*void printPrime1(int n){
    for(int i=2;i*i<=n;i++){
        if(isPrime(i)){
            int x=i;
            while(n%x==0){
                print(i);
                x=x*i
            }
        }
    }
}
*/


//time complexity O(root n/6  * logn)
//logn for finding the number of factors present in the number however i can say it can never strict upper bound it is loose upper bound
void printPrime(int n){
    if(n==1){
        cout<<1<<endl;
        return;
    }
    else{
        if(n%2==0){
            int x=n;
            while(x%2==0){
                cout<<"2"<<endl;
                x=x/2;
            }
        }
        if(n%3==0){
            int x=n;
            while(x%3==0){
                cout<<"3"<<endl;
                x=x/3;
            }
        }
        {
            for(int i=5;i*i<=n;i=i+6){
                if(n%i==0){
                    int x=n;
                    while(x%i==0){
                        cout<<i<<endl;
                        x=x/i;
                    }
                }
                else if(n%(i+2)==0){
                    int x=n;
                    while(x%(i+2)==0){
                        cout<<i+2<<endl;
                        x=x/(i+2);
                    }
                }
            }
        }
    }

}

//best solution
/*for(int i=2;i*i<=n;i=i+6){
if(n%i==0){
    print(i);
    n=n/i;
    }
}
*/

int main(){
    printPrime(120);

return 0;
}
