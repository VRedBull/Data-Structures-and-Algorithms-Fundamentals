#include<iostream>
using namespace std;

struct Array{
    int A[10];
    int size;
    int length;
};

int binary_search(struct Array arr, int ele){
    int l,u,mid;
    l=0;
    u=arr.length-1;

    while(l<=u){
        mid = (l+u)/2;
        if(arr.A[mid]==ele){
            return mid;
        }else if(arr.A[mid] > ele){
            u=mid-1;
        }else{
            l=mid+1;
        }
    }
    return -1;    
}

int rec_bin_search(int A[], int l, int u, int ele){
    int mid;
    if(l<=u){    
        mid = (l+u)/2;
        if(A[mid]==ele){
            return mid;
        }else if(A[mid] > ele){
            return rec_bin_search(A,l,mid-1,ele);
        }else{
            return rec_bin_search(A,mid+1,u,ele);
        }   
    }
    return -1;
}

int main(){
    struct Array arr = {{10,11,12,13,14,15},10,6};    //should have a sorted array for this search
    cout<<binary_search(arr,10)<<endl;
    cout<<rec_bin_search(arr.A,0,arr.length-1,15)<<endl;
}