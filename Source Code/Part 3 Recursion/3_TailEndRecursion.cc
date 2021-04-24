#include<iostream>
using namespace std;

int fun1(int x){
    if(x>0){
        int n=0;
        n+=x;
        cout<<x<<" "<<n<<endl;
        fun1(x-1);              //Since this statement is at the very of the program it's a recursive function.
    }
    return 0;
}

//above tail recursive function converted to loop.

void loop(int x){
    while(x>0){
        int n=0;
        n+=x;
        cout<<x<<" "<<n<<endl;
        x--;
    }
}

int main(){
    fun1(3);
    cout<<endl;
    loop(3);
}