#include<iostream>
using namespace std;

void printHW(){
    cout<<"Hello world!"<<endl;
}

int add(int a, int b){
    return a+b;
}

int main(){

    int (*p)(int, int);
    p = &add;
    cout<<(*p)(2,3)<<endl;

    void (*q)();
    q = printHW;
    q();
}