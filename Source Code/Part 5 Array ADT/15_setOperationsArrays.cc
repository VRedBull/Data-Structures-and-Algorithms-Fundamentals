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

void union_set_arrays(struct Array *arr1, struct Array *arr2, struct Array *arr3){

int temp_len =0;
if(arr1->length > arr2->length){
    temp_len = arr1->length;
}else{
    temp_len = arr2->length;
}

int flag=1;
for(int i=0;i<arr1->length; i++){
    for(int j=0;j<arr2->length; j++){
        if(arr1->A[i]!=arr2->A[j]){
            flag=1;
            continue;
        }else{
            flag=-1;
            break;
        }
    }
    if(flag==1){
        arr3->A[i] = arr1->A[i];
    }else{
        continue;
    }
}

int flag1=1;
for(int i=0;i<arr2->length; i++){
    for(int j=0;j<arr1->length; j++){
        if(arr2->A[i]!=arr1->A[j]){
            flag=1;
            continue;
        }else{
            flag=-1;
            break;
        }
    }
    static int arr3_index = 0;
    if(flag==1){
        arr3->A[arr3_index] = arr2->A[i];
        arr3_index++;
    }else{
        continue;
    }
}

}

int main(){
    struct Array arr1={{2,9,21,28,35},5,10};
    struct Array arr2={{2,3,9,18,28},5,10}; 
    struct Array arr3={{0},0,10}; 
    display(arr3);
    union_set_arrays(&arr1,&arr2,&arr3);
    display(arr3);

}
