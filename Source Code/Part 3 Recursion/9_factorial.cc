#include<iostream>
using namespace std;

int factorial(int n){
    if(n>0){
        return factorial(n-1)*n;
    }
    return 1;
}

int factorialLoop(int n){
    int total=1;
    for(int i=1;i<=n;i++){
        total *=i; 
    }
    return total;
}

int main(){
    cout<<factorial(6)<<endl;
    cout<<factorialLoop(6);
}