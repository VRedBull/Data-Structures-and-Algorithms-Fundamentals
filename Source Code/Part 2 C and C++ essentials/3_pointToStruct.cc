#include<iostream>
using namespace std;

struct Rectangle
{
    /* data */
    int length;
    int breadth;
};


int main(){
    struct Rectangle r = {2,3};     
    struct Rectangle *p1 = &r;

    p1->length = 4;         //We can either use the arrow operator
    (*p1).breadth = 5;      //or use the dot operator but include the pointer in a bracket since the 
                            // dot operator have higher precedence than the asterisk 
    struct Rectangle *p2 = new Rectangle();

    Rectangle *p3 = new Rectangle();       //In C++ we treat Structure like classes and not have to 
                                            //mention struct everytime
}