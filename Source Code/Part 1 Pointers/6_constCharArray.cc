#include<iostream>
using namespace std;

void cons(const char* c){
    // *c = 'A';        //cannot change a value from the array as we are using a const pointer
    int i=0;
    while(*(c+i)!='\0'){
        cout<<*(c+i)<<flush;
        i++;
    }
    cout<<endl;
}

int main(){
    char c[] = "Hello";
    cons(c);
    
}