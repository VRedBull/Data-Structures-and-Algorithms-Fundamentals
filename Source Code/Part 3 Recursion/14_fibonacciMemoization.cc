#include<iostream>
using namespace std;

int fibMemoization(int n){
    static int (*m) = new int[n+1];
    for(int i=0;i<=n;i++){
        m[i]=-1;
    }
    if(m[n]!=-1){
        return m[n];
    }
    else if(n==0){
        m[n] = 0;
        return m[n];
    }
    else if(n==1){
        m[n] = 1;
        return m[n];
    }
    else{
        m[n] = fibMemoization(n-2)+fibMemoization(n-1);
        return m[n];
    }
    delete []m;
}

int main(){
    cout<<fibMemoization(8)<<endl;
}