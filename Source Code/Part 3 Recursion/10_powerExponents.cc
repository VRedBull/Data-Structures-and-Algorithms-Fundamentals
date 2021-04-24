#include<iostream>
using namespace std;

//Finding out exponents using recursion with a static integer
// int power(int m, int n){
//     static int total=1;
//     if(n>0){
//         total*=m;
//         power(m,n-1);
//         return total;
//     }
//     return 1;
// }

//without using a static integer
int power(int m, int n){
    if(n>0){
        return power(m,n-1)*m;
    }
    return 1;
}

//using a for loop
int powerLoop(int m, int n){
    int total=1;
    for(int i =0;i<n;i++){
        total*=m;
    }
    return total;
}

//dividing the power in half so that we need to make half the no. of functions calls

int halfPower(int m, int n){
    if(n>0){
        if(n%2==0){
            return halfPower(m*m,n/2);
        }else{
            return halfPower(m*m,(n-1)/2)*m;
        }
    }
    return 1;
}

int main(){
    cout<<power(2,6)<<endl;
    cout<<powerLoop(2,6)<<endl;
    cout<<halfPower(3,5)<<endl;
}