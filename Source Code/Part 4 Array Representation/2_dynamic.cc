#include<iostream>
using namespace std;



int main(){
    int *p;
    p = new int[5];
    free(p);
}