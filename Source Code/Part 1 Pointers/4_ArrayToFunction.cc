#include<iostream>
using namespace std;

int SumArrayA(int A[],int size){
    int sum=0;
    for(int x=0;x<size;x++)
        sum+=A[x];
    return sum;
}

int SumArrayB(int* B, int size){        //Same as formal parameter 'B[]'
    int sum=0;
    for(int x=0;x<size;x++)
        sum+=*(B+x);        //same as 'B[x]'
    return sum;
}

void doubleArray(int* A, int size){         //Since these are pointers to the array
    for (int i=0;i<size;i++){               //we can also modify the values of array
        *(A+i)*=2;
    }
}

int main(){
    int A[]= {2,3,4,5,6,7};
    int sizeA = sizeof(A)/sizeof(int);
    int totalA = SumArrayA(A,sizeA);
    cout<<totalA<<endl;

    int B[] = {1,2,3,4,5};
    int sizeB = sizeof(B)/sizeof(int);
    int totalB = SumArrayB(&B[0],sizeB);       //Same as passing 'B'
    cout<<totalB<<endl;

    doubleArray(&B[0],sizeB);
    for(int x:B)
        cout<<x<<" ";
    

}