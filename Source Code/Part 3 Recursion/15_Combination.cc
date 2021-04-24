#include<iostream>
using namespace std;

int fact(int n){
    if(n>0){
        return fact(n-1)*n;
    }
    else{
        return 1;
    }
}

//nCr = n! / [ r!(n-r)! ]
int comb(int n, int r){
    int t1,t2,t3;
    t1=fact(n);
    t2=fact(r);
    t3=fact(n-r);

    return t1/(t2*t3);
}

int main(){
    cout<<comb(5,3);
}