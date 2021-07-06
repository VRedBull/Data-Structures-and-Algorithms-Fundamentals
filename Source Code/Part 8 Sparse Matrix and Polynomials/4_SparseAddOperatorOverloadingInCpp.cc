#include<iostream>
using namespace std;

class Elements{
    public:
    int i,j,x;
};

class Sparse{
    private:
    int m,n,num;
    Elements *ele;
    public:
    Sparse(int m,int n, int num);
    int get_Sparse_Matrix(int i, int j);
    ~Sparse(){delete []ele;}

    Sparse operator+(Sparse &s);        //watch the abdul bari video for implementation of this function
    friend istream & operator>>(istream &is, Sparse &s);
    friend ostream & operator<<(ostream &os, Sparse &s);
};

//sparse matrix operator overloading 

Sparse::Sparse(int m, int n, int num){
    this->m=m;
    this->n=n;
    this->num=num;
    ele = new Elements[num];
}

int Sparse::get_Sparse_Matrix(int i, int j){
    for(int a=0;a<num;a++){
        if(i==ele[a].i && j==ele[a].j){
            return ele[a].x;
        }
    }
    return 0;
}

istream & operator>>(istream &is, Sparse &s){
    for(int a=0;a<s.num;a++){
        cout<<"Enter Row: "<<flush;
        cin>>s.ele[a].i;
        cout<<"Enter Col: "<<flush;
        cin>>s.ele[a].j;
        cout<<"Enter Value: "<<flush;
        cin>>s.ele[a].x;
    }
    return is;
}

ostream & operator<<(ostream &os, Sparse &s){
    for(int a=0;a<s.m;a++){
        for(int b=0;b<s.n;b++){
            cout<<s.get_Sparse_Matrix(a,b)<<"\t"<<flush;
        }cout<<endl;
    }
    return os;
}

int main(){
    Sparse s1(4,4,3);
    cin>>s1;
    cout<<s1;
    // Sparse sum=s1+s2;    it's like sum=s1.add(s2)
    // cout<<sum;
}