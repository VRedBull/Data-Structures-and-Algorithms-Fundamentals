#include<iostream>
using namespace std;

void printHellW(){
    cout<<"Hello world!"<<endl;
}

int* Add(int *a, int *b){

    int *p;
    *p=(*a) + (*b);
    return p;
}

int main(){

    int a = 2, b = 3;

    int (*p) = Add(&a,&b);

    printHellW();
    
    cout<<*p<<endl;

}
