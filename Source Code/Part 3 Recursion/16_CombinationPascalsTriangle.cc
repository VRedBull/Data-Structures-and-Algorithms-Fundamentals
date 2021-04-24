#include<iostream>
using namespace std;

//We can use the formula obtained from Pascal's triangle
// nCr = (n-1)Cr + (n-1)C(r-1)
//also when r=0 or n=r then always nCr = 1

int combPascalTri(int n, int r){
    if(r==0 || n==r){
        return 1;
    }
    else{
        return combPascalTri(n-1, r) + combPascalTri( n-1, r-1);
    }
}

int main(){
    cout<<combPascalTri(4,2);
}