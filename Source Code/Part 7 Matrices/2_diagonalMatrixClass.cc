#include<iostream>
using namespace std;

class Matrix{
    private:
    int *A;
    int n;

    public:
    Matrix(int n);
    void set_Matrix(int i,int j,int ele);
    int get_Matrix(int i, int j);
    void display_Matrix();
    ~Matrix(){delete []A;};
};

Matrix::Matrix(int n){
    this->n = n;
    A = new int[n];
}

void Matrix::set_Matrix(int i, int j, int ele){
    if(i==j){
        A[i-1]=ele;
    }
}

int Matrix::get_Matrix(int i, int j){
    if(i==j){
        return A[i-1];
    }else{
        return 0;
    }
}

void Matrix::display_Matrix(){
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
               cout<<get_Matrix(i,j)<<" "<<flush; 
        }cout<<endl;
    }cout<<endl;
}

int main(){
    
    Matrix mx(5);
    
    int temp=10;
    for(int i=1;i<=5;i++){
        mx.set_Matrix(i,i,temp);
        temp*=(i+1);
    }
    
    mx.display_Matrix();
}
