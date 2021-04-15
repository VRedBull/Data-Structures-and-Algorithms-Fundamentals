#include<iostream>
using namespace std;

int main(){
    int x = 10;

    int *p;
    p=&x;
    
    int **q;     //Double pointer is required to store the address of another pointer
    q=&p;

    int ***r;    //triple pointer is required to store the address of a pointer which is also pointing to another pointer
    r=&q;

    cout<<"Address stored in p = "<<p<< " Value pointed by p = "<<*p<<endl<<endl;     //Address of x and value in x

    cout<<"Address stored in q = "<<q<< " Value pointed by q = "<<*q<<endl;     //Address of p and value in p(i.e.Address of x)
    cout<<"Accessing value pointed by p = "<<*(*q)<<endl<<endl;

    cout<<"Address stored in r = "<<r<< " Value pointed by r = "<<*r<<endl;     //Address of q and value in q(i.e.Address of p)
    cout<<"Accessing value pointed by q = "<<*(*r)<<endl;                       //Addess of x                
    cout<<"Accessing value pointed by p = "<<*(*(*r))<<endl<<endl;                    //Value of x

    *(*q) = 12;
    cout<<"Changing value of x using double pointer = "<<x<<endl;

    *(*(*r)) = 14;
    cout<<"Changing value of x using triple pointer = "<<x<<endl;

}

/*
   Address          202         201        200           
   ***r[202]---> **q[201]---> *p[200]---> x[10]    

      p = 200
      *p = 10

      q = 201
      **q = 200                 We can say *(*q) or **q

      r = 202
      ***r = 201                We can say *(*(r)) or ***r
*/