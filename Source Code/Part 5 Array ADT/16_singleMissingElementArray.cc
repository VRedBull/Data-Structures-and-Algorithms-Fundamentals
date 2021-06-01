#include<iostream>
using namespace std;

struct Array{
    int A[10];
    int length;
    int size;
};

//missing elements in sorted array
void find_single_missing_element(struct Array arr){
    int l,h,n;
    n=arr.length;
    l=arr.A[0];
    h=arr.A[n-1];

    for(int i=0;i<n;i++){
        if(l != (arr.A[i])-i){
            cout<< i+l <<" is missing from index "<<i<<endl;
            break;
        }else{
            continue;
        }
    }  
}

//multiple missing elements in sorted array
void find_multi_missing_element(struct Array arr){
    int l,h,n;
    n=arr.length;
    l=arr.A[0];
    h=arr.A[n-1];

    static int diff = l;

    for(int i=0;i<n;i++){
        if(diff != (arr.A[i])-i){
                while(diff < (arr.A[i])-i){    //this loop here if there's multiple elements missing from that index i
                    cout<< i+diff <<" is missing "<<endl;
                    diff++;
            }
        }else{
            continue;
        }
    }  
}

int find_max(struct Array arr){
    int temp = arr.A[0];

    for(int i=0; i<arr.length; i++){
        if(temp < arr.A[i]){
            temp = arr.A[i];
        }else{
            continue;
        }
    }
    return temp;
}

//2nd method to find missing elements(works on unsorted arrays too) using hashing technique
void find_missing_hash_method(struct Array arr){
    int hash_len = find_max(arr);
    int *h = new int(hash_len);    //created a new array of size equal to the max. element in given array
    for(int i=0; i<hash_len; i++){
        h[i] = 0;
    }

    for(int i=0; i<arr.length; i++){
        h[arr.A[i]]+=1;
    }

    for(int i=0; i<hash_len; i++){
        if(h[i]==0){
            cout<<i<<" is missing"<<endl;
        }else{
            continue;
        }
    }

    delete []h;
}

int main(){
    struct Array arr1 = {{3,4,5,7,8,9,11,12,15,16},10,10};
    struct Array arr2 = {{3,7,4,9,12,6,1,11,2,10},10,10};
    // find_single_missing_element(arr1);
    // find_multi_missing_element(arr1);
    // cout<<find_max(arr2);

    find_missing_hash_method(arr2);
}