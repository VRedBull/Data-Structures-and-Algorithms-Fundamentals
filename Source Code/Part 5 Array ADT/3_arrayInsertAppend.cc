#include<iostream>
using namespace std;

struct Array{
    int A[10];
    int size;
    int length;
};

void append(struct Array *arr, int ele){
    if((arr->length)<(arr->size)){
        arr->A[arr->length]=ele;
        arr->length+=1;
    }else{
        cout<<"Can't append since array ran out of size"<<endl;
    }
    arr=NULL;
}

void display(struct Array arr){
    for(int i=0;i<arr.size;i++){
        cout<<arr.A[i]<<" "<<flush;
    }
    cout<<endl;
}

void insert(struct Array *arr, int ele, int index){
    if(index<=(arr->length) && (arr->length)<(arr->size)){

        for(int i = arr->length; i>index;i--){
            arr->A[i] = arr->A[i-1];
        }

        arr->length+=1;
        arr->A[index]=ele;
    }else{
        cout<<"cannot insert element as array have run out of size"<<endl;
    }
}

int main(){
    struct Array arr = {{0,1,2,4,5,6,7,8,9},10,9};
    display(arr);
    
    insert(&arr,3,3);
    display(arr);
    insert(&arr,5,6);
}