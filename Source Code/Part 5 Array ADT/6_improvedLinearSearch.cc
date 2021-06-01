#include<iostream>
using namespace std;

struct Array{
    int A[10];
    int size;
    int length;
};

void display(struct Array arr){
    for(int i:arr.A){
        cout<<i<<" "<<flush;
    }cout<<endl;
}

int transposition_linear_search(struct Array *arr, int ele){
    for(int i=1;i<=arr->length;i++){
        if(ele == arr->A[i]){
            int temp = arr->A[i-1];
            arr->A[i-1] = arr->A[i];
            arr->A[i] = temp;
            return i;
        }else{
            continue;
        }
    }
    return -1;
}

int head_linear_search(struct Array *arr, int ele){
    for(int i=1;i<=arr->length;i++){
        if(ele == arr->A[i]){
            int temp = arr->A[0];
            arr->A[0] = arr->A[i];
            arr->A[i] = temp;
            return 0;
        }else{
            continue;
        }
    }
    return -1;
}

int main(){
    struct Array arr = {{0,1,2,3,4,5},10,6};
    display(arr);
    cout<<"Doing transposition on element"<<endl;
    transposition_linear_search(&arr,3);
    display(arr);
    cout<<"Moving the element to very first after searching for it."<<endl;
    head_linear_search(&arr,4);
    display(arr);
}