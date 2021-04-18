#include<iostream>
using namespace std;

struct Rectangle{
    int length;
    int breadth;

    int A[4];
};

//Call by Value
int area(Rectangle r){
    return (r.length)*(r.breadth);
}

//Call by address
int area(Rectangle *r){
    return (r->length)*((*r).breadth);
}

void changeLength(Rectangle *r,int length){
    r->length=length; 
}

//Call by Reference
// int area(Rectangle &r){
//     return (r.length)*(r.breadth);
// }

//pass by value
void accessArray(Rectangle r){      //here new object is created and values are copied to it.
    for(int i=0;i<4;i++)
        cout<<r.A[i]<<" "<<flush;
    cout<<endl;
}

int main(){
    Rectangle r = {10,5};
    changeLength(&r,11);
    cout<<area(r)<<endl;

    //Dynamic Object 
    Rectangle *r1 = new Rectangle();
    *r1={20,3};
    cout<<area(r1)<<endl;

    //when we pass an object of the struct we pass all the properties with it along with the arrays
    Rectangle r2 = {15,4,{1,2,3,4}};
    accessArray(r2);
    for(int i=0;i<4;i++)
        cout<<r2.A[i]<<" "<<flush;
}