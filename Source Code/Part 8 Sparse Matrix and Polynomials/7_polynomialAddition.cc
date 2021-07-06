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

void create(struct Polynomial *p){
    cout<<"No. of non-zero terms: "<<flush;
    cin>>p->num;
    p->t = new Terms[p->num];
    cout<<"Enter the name of variable of polynomial: "<<flush;
    cin>>p->var;
    for(int a=0;a<p->num;a++){
        cout<<"Enter coeff. of term "<<a+1<<": "<<flush;
        cin>>p->t[a].coeff;
        cout<<"Enter exp. of term "<<a+1<<": "<<flush;
        cin>>p->t[a].exp;
    }
}

void display(struct Polynomial p){
    for(int a=0;a<p.num;a++){
        cout<<p.t[a].coeff<<p.var<<"^"<<p.t[a].exp<<" + "<<flush;
    }cout<<endl;
}

void add_polynomial(struct Polynomial p1, struct Polynomial p2){
    struct Polynomial sum;
    sum.num=p1.num+p2.num;
    sum.t = new Terms[sum.num];
    sum.var=p1.var;
    int a=0,b=0,x=0;
    while(a<p1.num && b<p2.num){
        if(p1.t[a].exp==p2.t[b].exp){
            sum.t[x].coeff = p1.t[a].coeff + p2.t[b].coeff;
            sum.t[x].exp=p1.t[a].exp;
            x++,a++,b++;
        }else if(p1.t[a].exp<p2.t[b].exp){
            sum.t[x].coeff = p1.t[a].coeff;
            sum.t[x].exp = p1.t[a].exp;
            x++,b++;
        }else{
            sum.t[x].coeff = p2.t[b].coeff;
            sum.t[x].exp = p2.t[b].exp;
            x++,b++;
        }
    }

    for(;a<p1.num;a++){
        sum.t[x++]=p1.t[a];;
    }
    for(;b<p2.num;b++){
        sum.t[x++]=p2.t[b];
    }

    sum.num=x;

    display(sum);
}

int main(){
    struct Polynomial p1,p2;
    create(&p1);
    display(p1);
    create(&p2);
    display(p2);
    add_polynomial(p1,p2);
}   