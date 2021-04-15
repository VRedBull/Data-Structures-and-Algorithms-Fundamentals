#include<iostream>
using namespace std;

int main(){
    int a = 1025;
    int *p;
    p=&a;
    cout<<"int address = "<<p<<" "<<*(p)<<endl;
    cout<<"int address = "<<p+1<<" "<<*(p+1)<<endl;

    //void pointer
    void* v = (void*)p;
    cout<<"Address of void = "<<(v);
}