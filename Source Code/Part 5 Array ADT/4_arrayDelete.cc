#include<iostream>
using namespace std;

struct Array{
    int A[10];
    int size;
    int length;
};

void display(struct Array arr){
    for(int i=0;i<arr.size;i++){
        cout<<arr.A[i]<<" "<<flush;
    }
    cout<<endl;
}

void del(struct Array *arr,int index){
    if(index>=0 && index<(arr->length)){
        cout<<"Deleteing "<<arr->A[index]<<endl;
        for(int i= index; i<arr->length;i++){
            arr->A[i]=arr->A[i+1];
        }
        arr->A[(arr->length)]=0;
        arr->length-=1;

    }else{
        cout<<"Invalid index"<<endl;
    }
}

int main(){
    struct Array arr = {{0,1,2,3,4,5},10,6};
    display(arr);
    del(&arr,1);
    display(arr);
    del(&arr,-1);
    
}