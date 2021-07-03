#include<iostream>
using namespace std;

void set_diagonal(int A[],int i,int j, int ele){
    if(i==j){
        A[i-1]=ele;
    }
}

int get_diagonal(int A[],int i, int j){
    if(i==j){
        return A[i-1];
    }else{
        return 0;
    }
}

void display(int A[]){
    for(int i=0;i<5;i++){
        for(int j=0;j<5;j++){
            if(i==j)
                cout<<i<<" "<<flush;
            else
                cout<<"0 "<<flush;
        }cout<<endl;
    }cout<<endl;
}

int main(){
    int A[5];
    int i,j,temp=1;

    for(i=1;i<=5;i++){
        for(j=1;j<=5;j++){
            if(i==j){
                temp++;
                set_diagonal(A,i,j,temp);
            }
        }
    }
    // cout<<get_diagonal(A,1,1)<<endl;
    display(A);
}   