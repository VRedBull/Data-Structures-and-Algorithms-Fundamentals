#include<iostream>
using namespace std;

void bubbleSort(int *A, int size){
    int temp;
    for(int i=0;i<size;i++){
        for(int j=0;j<size-1;j++){
            if( *(A+j) > *(A+j+1)){
                temp = *(A+j);
                *(A+j) = *(A+j+1);
                *(A+j+1) = temp;
            }else{
                continue;
            }
        }
    }
}

int main(){
    int A[] = {123,4,5,-5,67,56,-90};               
    int size = sizeof(A)/sizeof(int);
    bubbleSort(A,size);
    for(int x:A)
        cout<<x<<" "<<flush;
}

/*
Bubble sorting........

123,4,5,....
i=0,j=0
4,123,5....
i=0,j=1
4,5,123,-5,67....
i=0,j=2
4,5,-5,123,67....
i=0,j=
*/