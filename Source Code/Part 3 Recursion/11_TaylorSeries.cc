#include<iostream>
using namespace std;

double e(int x, int n){
    if(n>0){
        static double p = 1, f = 1;
        double r;
        r=e(x,n-1);
        p*=x;
        f*=n;
        return r+p/f;
    }
    return 1;
}

int main(){
    cout<<e(4,30);
}