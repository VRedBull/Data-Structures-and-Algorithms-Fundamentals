#include<iostream>
using namespace std;

struct Array{
    int A[10];
    int length;
    int size;
};

void display(struct Array arr){
    for(int i:arr.A){
        cout<<i<<" "<<flush;
    }
    cout<<endl;
}

//using a auzillary array
void auxillary_reverse_array(int A[],int B[], int length){
    for(int i=length-1,j=0; i>=0; i--,j++){
        B[j] = A[i];
    }

    for(int i=0;i<length;i++){
        A[i] = B[i];
    }
}

void swap_reverse_array(int A[],int length){
    int i=0;
    int j=length-1;
    int temp=0;
    while(i<j){
        temp = A[j];
        A[j] = A[i];
        A[i] = temp;
        i++,j--;
    }

}

int main(){
    struct Array arr = {{10,20,30,40,50},5,10};
    struct Array brr = {{0},5,10};

    display(arr);
    // auxillary_reverse_array(arr.A, brr.A, arr.length);
    // display(arr);

    swap_reverse_array(arr.A,arr.length);
    display(arr);
}