#include<iostream>
using namespace std;

int main(){

    int A[2][3]={
        {2,3,5},
        {6,7,8}
    };

    int (*p)[3]=A;          //Standard Syntax for 2D arrays pointers initialization


    //Different ways to print addresses

    cout<<p<<endl;
    cout<<*p<<endl;
    
    cout<<A<<endl;
    cout<<*A<<endl;
    cout<<A[0]<<endl;
    cout<<&A[0]<<endl;
    cout<<&A[0][0]<<endl;

    cout<<p+1<<endl;
    cout<<*(p+1)<<endl;

    cout<<A+1<<endl;
    cout<<*(A+1)<<endl;
    cout<<A[1]<<endl;
    cout<<&A[1]<<endl;
    cout<<&A[1][0]<<endl;

    cout<<*(A+1)+1<<endl;
    cout<<*(p+1)+1<<endl;
    cout<<A[1]+1<<endl<<endl;

    //Differenet ways to get the values from array

    cout<<*(*p)<<endl;
    cout<<*(*A)<<endl;
    cout<<*(A[0])<<endl;
    cout<<*(*(&A[0]))<<endl;
    cout<<*(&A[0][0])<<endl;
    cout<<A[0][0]<<endl;

    cout<<*(*p+1)<<endl;

    cout<<*(*(p+1))<<endl;
    cout<<*(*(A+1))<<endl;
    cout<<*(A[1])<<endl;
    cout<<*(*(&A[1]))<<endl;
    cout<<*(&A[1][0])<<endl;
    cout<<A[1][0]<<endl;

    cout<<*(*(p+1)+1)<<endl;

}

/*
    int A[i][j] = {};
    int (*p)[j]=A;

    i=row, j=column

    for values
    A[i][j] = *(*(p+i)+j)  or  *(*(A+i)+j)  or *(A[i]+j)        

    for addresses
    &A[i][j] = *(p+i)+j  or  *(A+i)+j  or  A[i]+j
*/