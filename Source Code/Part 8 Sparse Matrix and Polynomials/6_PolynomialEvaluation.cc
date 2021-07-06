#include<iostream>
using namespace std;

struct Terms{
    int coeff;
    int exp;
};

struct Polynomial{
    int num;
    struct Terms *t;
    char var;
};

void create_polynomial(struct Polynomial *p){
    cout<<"Enter no. of non-zero :"<<flush;
    cin>>p->num;
    p->t = new Terms[p->num];
    cout<<"Enter the name of variable you want to use: "<<flush;
    cin>>p->var;
    for(int a=0;a<p->num;a++){
        cout<<"Enter coeff. of term "<<a<<" : "<<flush;
        cin>>p->t[a].coeff;
        cout<<"Enter exponent of term "<<a<<" : "<<flush;
        cin>>p->t[a].exp;
    }
}

void display_polynomial(struct Polynomial p){
    for(int a=0;a<p.num;a++){       
        cout<<p.t[a].coeff<<p.var<<"^"<<p.t[a].exp<<"+"<<flush;
    }cout<<endl;
}

int power(int a, int b){
    int sum=1;
    if(a==0){
        return 0;
    }else if(b==0){
        return 1;
    }else{
        for(int i=0;i<b;i++){
            sum*=a;
        }
        return sum;
    }
}

//When we get the value of the variable of the polynomial we can find out the value of the equation.
int solve_polynomial(int value,struct Polynomial p){
    int sum=0;
    for(int a=0;a<p.num;a++){
        int exp_value,term_value;
        exp_value=power(value, p.t[a].exp);
        term_value=(p.t[a].coeff)*exp_value;
        sum+=term_value;
    }
    return sum;
}

int main(){
    struct Polynomial p;
    create_polynomial(&p);
    display_polynomial(p);
    //passed the value of the variable as 2
    cout<<solve_polynomial(2,p);
}