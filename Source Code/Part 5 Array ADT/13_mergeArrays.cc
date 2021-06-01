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
    }cout<<endl;
}

void merge_sorted_array(struct Array *arr, struct Array *brr, struct Array *crr){
    int i=0,j=0,k=0;

    while(i<arr->length && j<brr->length){
        if(arr->A[i] < brr->A[j]){
            crr->A[k] = arr->A[i];
            k++,i++;
        }else{
            crr->A[k] = brr->A[j];
            k++,j++;
        }
    }

    if(j<(brr->length)){
        for(int x=j; x<brr->length; x++){
            crr->A[k] = brr->A[x];
        }
    }else if(i<(arr->length)){
        for(int x=i; x<arr->length; x++){
            crr->A[k] = arr->A[x];
        }
    }

}

int main(){
    struct Array arr = {{2,4,6,8},4,10};
    struct Array brr = {{1,3,5,7,9},5,10};
    
    struct Array crr = {{0},10,10};

    display(crr);
    merge_sorted_array(&arr, &brr, &crr);
    display(crr);

}