#include<iostream>
using namespace std;

//This function have a local variable which have different value for each different function
int fun1(int n){
    if(n>0){
        return fun1(n-1)+n;
    }
    return 0;
}

//This function have a static variable which will increment by 1 with each function call 
//But after increment it'll become same for each function .... and also same goes for a global variable
// int x=0;        //global variable
int fun2(int n){
    static int x=0;
    if(n>0){
        x++;
        return fun2(n-1)+x;
    }
    return 0;
}

int main(){
    cout<<"Local variable function = "<<fun1(5)<<endl;
    cout<<"Static/GLobal variable function = "<<fun2(5)<<endl;
}

/*
Static/global variable function
    0 - 0
    1 - fun(0)+5 = 5        x=5     //after x becomes 5 it's 5 only for all 
    2 - fun(1)+5 = 10       x=4     //previous functions too as there's only one copy of that x
    3 - fun(2)+5 = 15       x=3
    4 - fun(3)+5 = 20       x=2
    5 - fun(4)+5 = 25       x=1
*/

/*
local Variable function explanation
stack   
    0 - 0               
    1 - fun(0)+1 = 1
    2 - fun(1)+2 = 3
    3 - fun(2)+3 = 6
    4 - fun(3)+4 = 10
    5 - fun(4)+5 = 15
*/