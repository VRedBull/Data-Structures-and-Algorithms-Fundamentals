#include<iostream>
using namespace std;


int main(){
    int a = 2, b = 3;
    
    // int (*p) = new int(2);
    // cout<<*p<<endl;
    // delete p;
    // *p=3;
    // cout<<*p<<endl;

    // int (*p1) = new int[10];
    // *(p1+1) = 21;
    // cout<<*(p1+1)<<endl;

    int (*p);

    p = new int;

    *p = 10;

    cout<<p<<endl;

    delete p;
    
    p = new int;
    *p=20;
    cout<<*p<<endl;

}