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

int if_sorted(struct Array arr){
    for(int i=1;i<arr.length;i++){
        if(arr.A[i-1] <= arr.A[i]){
            continue;
        }else{
            return -1;
        }
    }
    return 1;
}

void insert_at(struct Array **arr, int ele, int index){
    if((*(arr))->length < (*(arr))->size){    
        for(int i = (*(arr))->length; i>index; i--){
            (*(arr))->A[i] = (*(arr))->A[i-1];
        }
        (*(arr))->A[index] = ele;
        (*(arr))->length+=1;
    }else{
        cout<<"Array ran out of space"<<endl;
    }
}

void insert_sorted(struct Array *arr, int ele){
    if(if_sorted(*arr)){

        for(int i=0; i<arr->length; i++){

            if(arr->A[i]<=ele && arr->A[i+1] >= ele){
                insert_at(&arr, ele,i);
                break;
            }else{
                continue;
            }

        }
    }else{
        cout<<"Not a sorted array"<<endl;
    }
}

int main(){
    struct Array arr = {{4,8,13,16,20,25,28,33},8,10};
    cout<<if_sorted(arr)<<endl;
    display(arr);
    insert_sorted(&arr,21);
    display(arr);
    insert_sorted(&arr,31);
    display(arr);
    insert_sorted(&arr,15);
    display(arr);
}     