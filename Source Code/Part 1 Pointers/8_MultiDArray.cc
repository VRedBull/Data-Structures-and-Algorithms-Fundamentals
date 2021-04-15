#include<iostream>
using namespace std;

int main(){

    int A[3][2][2] = {
        {
            {2,3},
            {4,5}
            },
        {
            {6,71},
            {7,8}
            },
        {
            {9,0},
            {10,11}
            }
    };

    int (*p)[2][2] = A;              //Initializing an 3D array

    cout<<*(*(*(A+2)+1)+1)<<endl;           //Value at A[2][1][1]
    cout<<*(*(A[2]+1)+1)<<endl;             
    cout<<*(A[2][1]+1)<<endl;               
    cout<<A[2][1][1]<<endl;

    cout<<A[2][1]<<endl;                //Address of A[2][1][0]
    cout<<*(*(*(A+2)+1))<<endl;         //value of A[2][1][0]
    cout<<*(*(*A+1))<<endl;             //Value of A[0][1][0]
    cout<<*A+1<<endl;                   //Address of A[0][1][0]

    // int B[2][3] = {
    //     {1,2,3},
    //     {4,56,7}
    // };

    // int (*p2)[3] = B;

    // cout<<*(*B+1)<<endl;
    
}


// *(A+i) = A[i] = &A[i][0][0]
//*(*(A+i)+j) = A[i][j] = &A[i][j][0]
//*(*(*(A+i)+j)+k) = A[i][j][k]


/*
    int A[i][j][k] = {...};

    int (*p)[j][k] = A;

    for value
    A[i][j][k] = *(*(*(p+i)+j)+k)  or  *(*(*(A+i)+j)+k)  or  *(*(A[i]+j)+k)

    for address
    &A[i][j][k] = *(*(p+i)+j)+k  or *(*(A+i)+j)+k  or  *(A[i]+j)+k
*/