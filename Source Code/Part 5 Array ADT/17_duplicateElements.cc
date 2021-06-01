#include<iostream>
using namespace std;

struct Array{
    int A[10];
    int length;
    int size;
};

void duplicate_sorted(struct Array arr){
    int lastDuplicate = 0;

    for(int i=0; i<arr.length-1; i++){
        if(arr.A[i]==arr.A[i+1] && arr.A[i]!=lastDuplicate){
            cout<<arr.A[i]<<" is a duplicate"<<endl;
            lastDuplicate=arr.A[i];
        }else{
            continue;
        }
    }
}

void duplicate_sorted_counter(struct Array arr){
    int lastDuplicate = 0;

    for(int i=0; i<arr.length-1; i++){
        int counter = 1;
        int j=i;
        while(arr.A[j]==arr.A[j+1]){     //this loop will increment the counter if there's a duplicate
            counter++,j++;
        }
        if(arr.A[i]==arr.A[i+1] && arr.A[i]!=lastDuplicate){
            cout<<arr.A[i]<<" occurs "<<counter<<" times"<<endl;
            lastDuplicate=arr.A[i];
        }else{
            continue;
        }
        i=j;        //here we skipped again checking the same elements
    }
}

int find_max(struct Array arr){
    int max=arr.A[0];
    for(int i=0;i<arr.length;i++){
        if(arr.A[i]>max){
            max=arr.A[i];
        }else{
            continue;
        }
    }
    return max;
}

//works for both sorted and unsorted array
void hash_duplicate_counter(struct Array arr){
    int hash_len=find_max(arr);
    int *h = new int[hash_len];
    for(int i=0; i<hash_len;i++){
        h[i]=0;
    }

    for(int i=0; i<arr.length; i++){
        h[arr.A[i]]++;
    }

    for(int i=0; i<hash_len; i++){
        if(h[i]>1){
            cout<<i<<" has occured "<<h[i]<<" times"<<endl;
        }else{
            continue;
        }
    }

    delete []h;
}

//this will also work for both sorted and unsorted
void duplicate_unsorted_counter(struct Array arr){
    for(int i=0; i<arr.length-1; i++){
        int counter = 1;
        if(arr.A[i]!=-1){
            for(int j=i+1;j<arr.length;j++){
                if(arr.A[i]==arr.A[j]){
                    arr.A[j]= -1;
                    counter++;
                }else{
                    continue;
                }
            }
            if(counter>1){
                cout<<arr.A[i]<<" occurred "<<counter<<" times"<<endl;
            }else{
                continue;
            }
        }
    }
}

int main(){
    struct Array arr1 = {{4,4,4,7,8,9,9,11,11,16},10,10};
    struct Array arr2 = {{2,1,6,9,12,6,1,1,2,10},10,10};

    // duplicate_sorted(arr1);
    // cout<<"Duplicate in the array with counter:"<<endl;
    // duplicate_sorted_counter(arr1);
    // cout<<find_max(arr1)<<endl;
    // cout<<endl;
    cout<<"Duplicates using hash for sorted array:"<<endl;
    hash_duplicate_counter(arr1);
    cout<<"Duplicates using hash for unsorted array:"<<endl;
    hash_duplicate_counter(arr2);
    cout<<"Duplicates using nested for loop:"<<endl;
    duplicate_unsorted_counter(arr2);
}