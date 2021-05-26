#include<iostream>
using namespace std;



int main(){
    int *arr = new int[10];
    *arr = {0};
    int arr1[10]={2,3};
    for(int x:arr1){
        cout<<x<<endl;
    }
}