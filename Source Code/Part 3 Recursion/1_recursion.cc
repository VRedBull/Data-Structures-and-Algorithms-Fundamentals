#include<iostream>
using namespace std;

void fun1(int x){
    if(x>0){
        cout<<x<<endl;
        fun1(x-1);
        cout<<x<<endl;
    }
    // cout<<"End of fun "<<x<<endl;
}

// void fun2(int x){
//     if(x>0){
//         fun2(x-1);
//         cout<<x<<endl;
//     }
// }

int main(){
    fun1(3);
    cout<<endl;
    // fun2(3);
}