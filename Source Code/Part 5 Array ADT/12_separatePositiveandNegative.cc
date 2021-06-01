#include<iostream>
using namespace std;

struct Array{
    int A[15];
    int length;
    int size;
};

void display(struct Array arr){
    for(int i:arr.A){
        cout<<i<<" "<<flush;
    }cout<<endl;
}

void separate_pos_neg(struct Array *arr){
        int i=0;
        int j=(arr->length)-1;
        int temp=0;
        while(i<j){
            while(arr->A[i]<0){i++;};
            while(arr->A[j]>=0){j++;};
            if(i<j){
                temp=arr->A[i];
                arr->A[i] = arr->A[j];
                arr->A[j] = temp;
            }
        }
    }

int main(){
    struct Array arr = {{-6,3,-8,10,5,-7,-9,12,-4,2},10,15};
    display(arr);
    separate_pos_neg(&arr);
    display(arr);
}