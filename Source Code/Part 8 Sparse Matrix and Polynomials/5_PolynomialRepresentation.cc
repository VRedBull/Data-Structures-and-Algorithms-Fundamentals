#include<iostream>
using namespace std;
struct Terms{   //a polynomial is made up of terms
    int coeff;  //a term have two properties - coeff. and exponent
    int exp;    //the exponent
};

struct Polynomial{     //structure of polynomial 
    int num;    //no. of non-zero terms(non-zero coeff.) in the polynomial
    Terms *t;   //Pointer to make a array of terms in heap
    char var;   //the name of the variable to be used to make polynomial
};

void create_Polynomial(struct Polynomial *p){
    cout<<"Enter no. of non-zero terms in polynomial: "<<endl;
    cin>>p->num;
    p->t = new Terms[p->num];
    cout<<"Enter the variable name to be used in polynomial: "<<flush;
    cin>>p->var;
    for(int a=0;a<p->num;a++){
        cout<<"Enter coefficient of term "<<a<<" : "<<flush;
        cin>>p->t[a].coeff;
        cout<<"Enter exp of term "<<a<<" : "<<flush;
        cin>>p->t[a].exp;
    }
}

void display_Polynomial(struct Polynomial p){
    for(int a=0;a<p.num;a++){       //can also conditions for -ve coefficients and for exponent 0 and 
                                    //for last term of the polynomial
        cout<<p.t[a].coeff<<p.var<<"^"<<p.t[a].exp<<"+"<<flush;
    }cout<<endl;
}
int main(){
    struct Polynomial p;
    create_Polynomial(&p);
    display_Polynomial(p);
}