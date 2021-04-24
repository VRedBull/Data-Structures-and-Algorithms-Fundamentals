#include<iostream>
using namespace std;

int headRec(int n){
    if(n>0){
        headRec(n-1);       //Since this function call is at the start of the function, so it's a head recursion
        cout<<n<<endl;
    }
    return 0;
}

//Above function cannot be directly converted to loop, it'll require some changes
void loop(int n){
    int i=1;
    while(i<=n){    
        cout<<i<<endl;
        i++;
    }
}

int main(){
    headRec(3);
    cout<<endl;
    loop(3);
}