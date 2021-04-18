#include<iostream>
using namespace std;

int* fun(int n){
    int (*p) = (int*)(calloc(sizeof(int),n));
    return p;
    delete []p;
}

int main(){
    int (*a) = fun(5);
    for (int i=0;i<5;i++)
        cout<<*(a+i)<<" "<<flush;
}