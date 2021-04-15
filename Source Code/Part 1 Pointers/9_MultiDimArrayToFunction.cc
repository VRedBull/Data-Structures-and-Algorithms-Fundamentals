#include<iostream>
using namespace std;

/*
for sugarcoating the compiler will accept the syntax as

void display(A[][]){
}
OR
void display(A[][][]){
}

But actually we pass the address of the 1st element of the array and in the formal parameter of the function 
we receive it in the pointer.
*/

void display(int (*p)[3], int size, int elements){

    for(int i=0; i<size; i++){
        for(int j=0; j<elements; j++){
            cout<<*(*(p+i)+j)<<" "<<flush;
        }
        cout<<endl;
    }
}

void display(int (*p)[2][3]){
    for(int i = 0; i<3; i++){
        for (int j = 0; j<2; j++){
            for(int k=0;k<3;k++){
                cout<<*(*(*(p+i)+j)+k)<<" "<<flush;
            }
            cout<<endl;
        }
        cout<<endl;
    }
}

int main(){
    int A[2][3] = {
        {1,2,3},
        {4,5,6}
    };

    int sizeArray = sizeof(A)/sizeof(A[2]);
    int elements = sizeof(A[2])/sizeof(int);
    display(A,sizeArray,elements);

    cout<<"-------------------------------"<<endl;
    int B[3][2][3] = {
        {
           {1,2,3},{4,5,6} 
        },
        {
            {7,8,9},{10,11,12}
        },
        {
            {13,14,15},{16,17,18}
        }
    };

    display(B);

}