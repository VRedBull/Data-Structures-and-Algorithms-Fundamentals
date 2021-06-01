#include<iostream>
using namespace std;

struct Array{
    int A[10];
    int length;
    int size;
};

void pair_sum(struct Array arr, int sum){
    for(int i=0;i<arr.length;i++){
        for(int j=i+1;j<arr.length;j++){
            if(arr.A[i]+arr.A[j]==sum){
                cout<<arr.A[i]<<" + "<<arr.A[j]<<" = "<<sum<<endl;
            }else{
                continue;
            }
        }
    }
}

int find_max(struct Array arr){
    int temp = arr.A[0];
    for(int i=0;i<arr.length;i++){
        if(arr.A[i]>temp){
            temp=arr.A[i];
        }else{
            continue;
        }
    }
    return temp;
}

void hash_pair_sum(struct Array arr, int sum){
    int hash_len = find_max(arr);
    int *h = new int[hash_len];

    for(int i=0;i<hash_len;i++){
        h[i]=0;
    }

    for(int i=0; i<arr.length;i++){
        int pair_ele = sum - arr.A[i];
        if(h[pair_ele]!=0 && pair_ele>=0 && pair_ele<hash_len){
            cout<<arr.A[i]<<" + "<<pair_ele<<" = "<<sum<<endl;
        }
        h[arr.A[i]]++;
    }
}

void sorted_pair_sum(struct Array arr, int sum){
    int i=0,j=arr.length-1;
    while (i<j)
    {
        if(arr.A[i]+arr.A[j]==sum){
            cout<<arr.A[i]<<" + "<<arr.A[j]<<" = "<<sum<<endl;
            i++,j--;
        }else if( arr.A[i]+arr.A[j] < sum){
            i++;
        }else{
            j--;
        }
    }
    
}

int main(){
    struct Array arr1 = {{6,3,8,10,16,7,5,2,9,14},10,10};
    struct Array arr2 = {{1,3,4,5,6,8,9,10,12,14},10,10};
    int sum = 10;
    cout<<"Method 1 for finding the sum pair : "<<endl;
    pair_sum(arr1,sum);
    cout<<"Method 2 for finding the sum pair : "<<endl;
    hash_pair_sum(arr1,sum);
    cout<<"Method 3 for finding the sum pair : "<<endl;
    sorted_pair_sum(arr2,sum);
}