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
    void create_sparse();
    int get_sparse(int i, int j);
    void display_sparse();
    ~Sparse(){delete []ele;}
};

Sparse::Sparse(int m, int n, int num){
    this->m=m;
    this->n=n;
    this->num=num;
    ele = new Elements[this->num];
}

void Sparse::create_sparse(){
    for(int a=0;a<num;a++){
        cout<<"Row no.: "<<flush;
        cin>>ele[a].i;
        cout<<"Col no.: "<<flush;
        cin>>ele[a].j;
        cout<<"Value: "<<flush;
        cin>>ele[a].x;
    }
}

int Sparse::get_sparse(int i, int j){
    for(int a=0;a<num;a++){
        if(i==ele[a].i && j==ele[a].j){
            return ele[a].x;
        }
    }
    return 0;
}

void Sparse::display_sparse(){
    for(int a=0;a<m;a++){
        for(int b=0;b<n;b++){
            cout<<get_sparse(a,b)<<"\t"<<flush;
        }cout<<endl;
    }
}
int main(){
    Sparse s(4,4,3);
    s.create_sparse();
    s.display_sparse();
}