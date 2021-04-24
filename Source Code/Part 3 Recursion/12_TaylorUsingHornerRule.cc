#include<iostream>
using namespace std;

//Taylor Series by horner rule using loop
double taylorHornerLoop(int x, int n){
    double s = 1;
    while(n>0){
        s = (1 + (x/n))*s;
        n--;
    }
    return s;
}

//Taylor Series by horner rule using recursion
// double taylorHornerRec(int x, int n){
//     static double s = 1;
//     if(n>0){
//         s = (1 + (x/n))*s;
//         taylorHornerRec(x,n-1);
//         return s;
//     }
//     return 1;
// }

//Just another method

double taylorHornerRec(int x, int n){
    static double s = 1;
    if(n==0){
        return s;
    }
    else{
        s = (1 + (x/n))*s;
        return taylorHornerRec(x,n-1);
    }
}

int main(){
    // cout<<taylorHornerLoop(4,30)<<endl;
    cout<<taylorHornerRec(4,30)<<endl; 
}