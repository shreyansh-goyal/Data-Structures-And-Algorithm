#include <bits/stdc++.h>

using namespace std;

bool checkPalindrome(string s){
    if(s.length()==0||s.length()==1) return true;

    else {
        if(s[0]==s[s.length()-1]){
            return checkPalindrome(s.substr(1,s.length()-2));
        }
        else return false;
    }
}

int countDigitSum(int n){
    if(n/10==0){
        return n;
    }
    else{
        return (n%10)+countDigitSum(n/10);
    }
}

int countDigitImplementation2(int n){
    if(n==0){
        return 0;
    }
    else{
        int digit = (int)log10(n);
        int a=1;
        for(int i=0;i<digit;i++){
            a=a*10;
        }
        int x = n/a;
        int z=x*a;
        int y = n-z;
        cout<<n<<" ";
        cout<<x<<" "<<z<<" "<<y<<" "<<digit<<" "<<x*(pow(10,digit))<<" "<<a<<endl;

        return x + countDigitImplementation2((n-x*a));
    }
}
int k=-1;
void ropecuttingProblem(int n,int a ,int b,int c,int x)
{
    cout<<n<<endl;
    if(n==0){
        if(x>k) k=x;
        return;
    }else if(n<0){
        return;
    }

    else{
        if(n>=a)
        {
            ropecuttingProblem(n-a,a,b,c,x+1);
        }
        if(n>=b)
        {
            ropecuttingProblem(n-b,a,b,c,x+1);
        }
        if(n>=c)
        {
            ropecuttingProblem(n-c,a,b,c,x+1);
        }
        return;
    }
}
int maxPieces(int n ,int a ,int b, int c){
    if(n==0) return 0;
    else if(n<0) return -1;

    int res = max(maxPieces(n-a,a,b,c),max(maxPieces(n-b,a,b,c),maxPieces(n-c,a,b,c)));
    if(res==-1)return res;
    else return res+1;
}
void produceSubsequeceOfString(string str,vector<string> &vect,int index,string sub){
    if(index==str.length()){
        vect.push_back(sub);
        return;
    }
    else{

        sub+=str[index];
        produceSubsequeceOfString(str,vect,index+1,sub);
        sub=sub.substr(0,sub.length()-1);
        produceSubsequeceOfString(str,vect,index+1,sub);
    }
}
int joesphPractice(vector<int> vect,int k,int index){
    if(vect.size()==1) return vect[0];
    else{
        index=index+k-1;
        index=index%vect.size();
        vector<int>::iterator it;
        it = vect.begin()+index;
        vect.erase(it);
        return joesphPractice(vect,k,index);
    }
}
int josephProblem(int n,int k){
    vector<int> vect;
    for(int i=0;i<n;i++){
        vect.push_back(i);
    }
    return joesphPractice(vect,k,0);
}
int josephProblem2(int n,int k){
    if(n==1){
        return 0;
    }
    else {
        return (josephProblem2(n-1,k)+k)%n;
    }
}
int subsetSumProblem(int arr[],int n,int sum){
    int a=0;
    int b=0;
    if(sum==0){
        return 1;
    }
    if(n==0){
        return 0;
    }
    else{
        if(sum>=arr[0]){
            a = subsetSumProblem(arr+1,n-1,sum-arr[0]);
        }
            b = subsetSumProblem(arr+1,n-1,sum);
            return a+b;
    }

}
void permutation(string str,string sub){
    if(str.length()==0){
        cout<<sub<<endl;
        return;
    }
    else{
        for(int i=0;i<str.length();i++){
            sub = sub+str[i];
            string s = str;
            s.erase(i,1);
            permutation(s,sub);
            sub = sub.substr(0,sub.length()-1);
        }
    }
}
vector<string> keyCharacters(int n){

    if(n==2){
    vector<string> vect{"A","B","C"};
    return vect;
    }
    else if(n==3){
    vector<string> vect{"D","E","F"};
    return vect;
    }
    else if(n==4){
    vector<string> vect{"G","H","I"};
    return vect;
    }
    else if(n==5){
    vector<string> vect{"J","K","L"};
    return vect;
    }
    else if(n==6){
    vector<string> vect{"M","N","O"};
    return vect;
    }
    else if(n==7){
    vector<string> vect{"P","Q","R","S"};
    return vect;
    }
    else if(n==8){
    vector<string> vect{"T","U","V"};
    return vect;
    }
    else if(n==9){
    vector<string> vect{"W","X","Y","Z"};
    return vect;
    }
}
vector <string> possibleWords(int a[],int N)
{
    if(N==0){
        vector<string> vect;
        vect.push_back("");
        return vect;
    }
    else{
        vector<string> vect = possibleWords(a+1,N-1);
        int size = vect.size();
        vector<string> c= keyCharacters(a[0]);
        vector<string> retvect;
        for(int i=0;i<c.size();i++){
            for(int j=0;j<size;j++){
                string x = c[i]+vect[j];
                retvect.push_back(x);
            }
        }
        return retvect;
    }
}

int ThePowerSum(int X,int N,int n,int sum){
    float x=(float)1/N;
    int breach = pow(X,x);
    if(sum == X) return 1;
    if(n>breach) return 0;
    else{
        return ThePowerSum(X,N,n+1,sum+pow(n,N)) + ThePowerSum(X,N,n+1,sum);
    }
}

map<string,int> m;
int superDigit(string n) {
    if(m[n]){
        cout<<"it is happening "<<endl;
        return m[n];
    }
    if(n.length()==1) return stoi(n);
    else{
        int x=0;
            for(unsigned int i=0;i<n.length();i++){
                int digit = n[i];
                digit=digit-48;
                x+=digit;
        }
        cout<<x<<endl;
        if((x/10)>0){
            int res =  superDigit(to_string(x));
            m[to_string(x)]=res;
            cout<<m[to_string(x)];
            return res;
        }
        else
        {
            return x;
        }
    }
}

int main()
{
    int x;
    cout<<INT_MAX<<endl;
    return 0;
}
