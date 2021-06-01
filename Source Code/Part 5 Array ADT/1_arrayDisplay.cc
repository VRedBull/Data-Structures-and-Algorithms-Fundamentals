#include <iostream>
using namespace std;

struct Array{
    int *A;
    int size;
    int length;
};

void display_array(struct Array arr,int length){
    for(int i=0;i<length;i++){
        cout<<arr.A[i]<<" "<<flush;
    }
}

int main(){
    struct Array arr;

    cout<<"Enter the size of the array = "<<flush;
    cin>>arr.size;

    arr.A = new int[arr.size];

    cout<<"Enter the no. of numbers you want in the array(length) = "<<flush;
    cin>>arr.length;

    cout<<"Enter all the elements in the array = "<<flush;

    for(int i=0;i<arr.length;i++){
        cin>>arr.A[i];
    }    

    cout<<"All elements of the array are = "<<endl;
    display_array(arr,arr.length);
}