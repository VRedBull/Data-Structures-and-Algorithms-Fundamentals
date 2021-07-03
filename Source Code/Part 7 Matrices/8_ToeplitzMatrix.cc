#include<iostream>
using namespace std;

class ToeplitzMatrix{
    private:
    int n;
    int *A;
    public:
    ToeplitzMatrix(int n);
    void setMatrix(int i, int j, int ele);
    int getMatrix(int i, int j);
    void display();
    ~ToeplitzMatrix(){delete []A;}
};

ToeplitzMatrix::ToeplitzMatrix(int n){
    this->n=n;
    A = new int[2*n-1];
}

void ToeplitzMatrix::setMatrix(int i, int j, int ele){
    if(i<=j){
        A[j-i]=ele;
    }else{
        A[n+i-j-1]=ele;
    }
}

int ToeplitzMatrix::getMatrix(int i, int j){
    if(i<=j){
        return A[j-i];
    }else{
        return A[n+i-j-1];
    }
}

void ToeplitzMatrix::display(){
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout<<getMatrix(i,j)<<" \t"<<flush;
        }cout<<endl;
    }
}

int main(){
    ToeplitzMatrix tm(5);
    int x=1;
    for(int j=1;j<=5;j++){
        tm.setMatrix(1,j,x);
        x++;
    }
    for(int j=2;j<=5;j++){
        tm.setMatrix(j,1,x);
        x++;
    }

    
    tm.display();
}