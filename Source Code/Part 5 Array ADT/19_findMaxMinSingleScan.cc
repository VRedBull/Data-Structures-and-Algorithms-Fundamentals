#include<iostream>
using namespace std;

struct Array{
    int A[10];
    int length;
    int size;
};

void find_max_min(struct Array arr){
    int max = arr.A[0],min = arr.A[0];

    for(int i=0;i<arr.length;i++){
        if(arr.A[i]<min){
            min = arr.A[i];
        }else if(arr.A[i]>max){
            max = arr.A[i];
        }
    }

    cout<<"Max: "<<max<<", Min: "<<min<<endl;
}

int main(){
    struct Array arr = {{5,8,3,9,6,2,10,7,-1,4},10,10};
    find_max_min(arr);
}