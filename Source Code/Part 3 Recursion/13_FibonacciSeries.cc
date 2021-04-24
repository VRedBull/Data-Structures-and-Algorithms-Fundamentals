#include<iostream>
using namespace std;

//Fibonacci series using recursion
int fibonacci(int n){
    if(n==0){
        return 0;
    }
    else if(n==1 || n==2){
        return 1;
    }else{
        return fibonacci(n-1)+fibonacci(n-2);
    }
}

//Fibonacci series using loop
int fibLoop(int n){
    int t0=0,t1=1,temp;
    for(int i=0;i<n;i++){
        temp=t0+t1;
        t0=t1;
        t1=temp;
    }
    return temp;
}

int main(){
    for(int i =0;i<9;i++)
        cout<<fibLoop(i)<<endl;
    cout<<fibonacci(7)<<endl;
}

