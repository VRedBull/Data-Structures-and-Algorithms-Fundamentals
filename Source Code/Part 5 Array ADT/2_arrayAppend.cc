#include<iostream>
using namespace std;



int main(){
    int size,length;
    size=10;
    int A[size] = {1,2,3,4,5};

    length = 5;
    int index=9;
    if(size>index){
        A[index] = 6;
        length++;
    }else{
        cout<<"We have run out of space in array"<<endl;
    }

    //display
    cout<<"New array is: "<<flush;
    for(int i:A)
        cout<<i<<" "<<flush;

}