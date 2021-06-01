#include<iostream>
using namespace std;

struct Array
{
    int A[10];
    int length;
    int size;
};
 
void display(struct Array arr){
    for(int i=0;i<arr.length;i++){
        cout<<arr.A[i]<<" "<<flush;
    }cout<<endl;
}

int get(struct Array arr, int index){
    if(index>=0 && index<= arr.length){
        return arr.A[index];
    }else{
        return (int)NULL;
    }
}

void set(struct Array *arr, int index, int ele){
    if(index>=0 && index<= arr->length){
        arr->A[index] = ele;
    }else{
        cout<<"Not a valid index"<<endl;
    }
}

int max(struct Array arr){
    int n=arr.A[0];
    for(int i=1;i<arr.length;i++){
        if(arr.A[i]>n){
            n=arr.A[i];
        }
    }
    return n;
}

int min(struct Array arr){
    int n=arr.A[0];
    for(int i=1;i<arr.length;i++){
        if(arr.A[i]<n){
            n=arr.A[i];
        }
    }
    return n;
}

int sum(struct Array arr){
    int total=0;
    for(int i=0;i<arr.length;i++){
        total += arr.A[i]; 
    }
    return total;
}

int rec_sum(int A[], int length){
    if(length<0){
        return 0;
    }else{
        return rec_sum(A,length-1)+A[length];
    }
}

int avg(struct Array arr){
    int total=0;
    for(int i=0;i<arr.length;i++){
        total+=arr.A[i];
    }
    return total/arr.length;
}

int main(){
    struct Array arr = {{110,20,301,40,50},5,10};
    cout<<"Getting 41 at index: "<<get(arr,41)<<endl;
    set(&arr,4,221);
    cout<<"After setting 221 at index 4: "<<flush;
    display(arr);
    cout<<"Maximum in the array: "<<max(arr)<<endl;
    cout<<"Minimum in the array: "<<min(arr)<<endl;
    cout<<"Sum of all array elements: "<<sum(arr)<<endl;
    cout<<"Finding sum recursively: "<<rec_sum(arr.A,arr.length)<<endl;
    cout<<"Average of all array elements: "<<avg(arr)<<endl;
}