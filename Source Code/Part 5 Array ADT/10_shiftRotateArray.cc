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

void left_shift(struct Array *arr){
    for(int i=1;i<arr->length;i++){
        arr->A[i-1] = arr->A[i];
    }
    arr->A[arr->length-1]=0;
    arr->length-=1;
}

void left_rotate(struct Array *arr){
    int temp = arr->A[0];
    for(int i=1;i<arr->length;i++){
        arr->A[i-1] = arr->A[i];
    }
    arr->A[arr->length-1]=temp;
    
}

void right_shift(struct Array *arr){
    if(arr->length <= arr->size){
        for(int i=arr->length;i>0;i--){
            arr->A[i] = arr->A[i-1];
        }
        arr->A[0]=0;
        arr->length+=1;
    }
}

void right_rotate(struct Array *arr){
    if(arr->length <= arr->size){
        int temp = arr->A[(arr->length-1)];

        for(int i=arr->length;i>0;i--){
            arr->A[i] = arr->A[i-1];
        }
        arr->A[0]=temp;
    }
}

int main(){
    struct Array arr = {{10,20,30,40,50,60,70,80,90,100},10,10};
    display(arr);
    // left_shift(&arr);
    // display(arr);
    
    left_rotate(&arr);
    display(arr);

    // right_shift(&arr);
    // display(arr);

    right_rotate(&arr);
    display(arr);
}