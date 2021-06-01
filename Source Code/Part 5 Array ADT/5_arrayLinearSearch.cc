#include<iostream>
using namespace std;

struct Array{
    int A[10];
    int size;
    int length;
};

int linear_search(struct Array arr, int ele){
    for(int i=0;i<arr.length;i++){
        if(ele == arr.A[i]){
            return i;
        }else{
            continue;
        }
    }
    return -1;
}

int main(){
    struct Array arr = {{0,1,2,3,4,5},10,6};
    cout<<linear_search(arr,3)<<endl;
    cout<<linear_search(arr,8)<<endl;
}