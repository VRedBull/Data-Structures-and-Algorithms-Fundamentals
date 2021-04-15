#include<iostream>
using namespace std;

int main(){
    int A[] = {2,4,8,5,1};

    int range = sizeof(A)/sizeof(int);
    
    int *p;
    p = &A[0];

    int *q = A;

    cout<<&A<<endl;
    cout<<A<<endl;
    cout<<p<<endl;
    cout<<q<<endl<<endl;

    cout<<A[0]<<endl;
    cout<<*A<<endl;
    cout<<*p<<endl;
    cout<<*q<<endl<<endl;

    cout<<A[1]<<endl;
    cout<<*(A+1)<<endl;
    cout<<*(p+1)<<endl;
    cout<<*(q+1)<<endl<<endl;

    for(int x: A)
        cout<<x<<" "<<flush;
    
    cout<<endl<<endl;

    for(int i=0; i<range; i++){
        cout<<A[i]<<" "<<*(A+i)<<" "<<*(p+i)<<" "<<*(q+i)<<endl;
    }
}