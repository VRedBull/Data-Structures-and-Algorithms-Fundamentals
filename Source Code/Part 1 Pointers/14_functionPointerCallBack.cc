#include<iostream>
using namespace std;

void fun1(){
    cout<<"Fun1 function called"<<endl;
}

void fun2(void (*p)()){
    p();
}
int main(){
    void (*p)() = fun1;

    (*p)();

    fun2(p);

    fun2(&fun1);     //just doing this directly wihtout using pointers can also be done as we are only passing
                    //the address of the function fun1
}