#include<iostream>
using namespace std;

//recursive function to add n natural number 
int fun(int n){

    static int sum=0;
    if(n>0){
        
        fun(n-1);
        sum+=n;
    }
    return sum;
}

//another function without using a static variable
int sum(int n){
    if(n>0){
        return sum(n-1)+n;
    }
    return 0;
}

int main(){
    cout<<sum(5);
}