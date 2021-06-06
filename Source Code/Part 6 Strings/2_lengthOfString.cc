#include<iostream>
using namespace std;

int length_of_string(char x[]){
    int i=0;
    while(x[i]!='\0'){
        i++;
    }
    return i;
}

int main(){
    char name[] = "Vikas Pradhan";
    cout<<"Length of name: "<<length_of_string(name);
}