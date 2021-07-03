#include<iostream>
using namespace std;
class TriDiagonalMatrix{
    private:
    int n;
    int *A;
    public:
    TriDiagonalMatrix(int n);
    void setMatrix(int i, int j, int ele);
    int getMatrix(int i, int j);
    void display();
    ~TriDiagonalMatrix(){delete []A;}
};

TriDiagonalMatrix::TriDiagonalMatrix(int n){
    this->n=n;
    A = new int[3*n-2];
}

void TriDiagonalMatrix::setMatrix(int i, int j, int ele){
    if(i-j==1){
        A[i-1]=ele;
    }else if(i-j==0){
        A[n+i-2]=ele;
    }else if(i-j==-1){
        A[2*n+i-2]=ele;
    }
}

int TriDiagonalMatrix::getMatrix(int i, int j){
    if(i-j==1){
        return A[i-1];
    }else if(i-j==0){
        return A[n+i-2];
    }else if(i-j==-1){
        return A[2*n+i-2];
    }else{
        return 0;
    }
}

void TriDiagonalMatrix::display(){
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout<<getMatrix(i,j)<<" \t"<<flush;
        }cout<<endl;
    }
}

int main(){
    TriDiagonalMatrix tdm(5);
    int x=1;
    for(int i=0;i<5;i++){
        for(int j=0;j<5;j++){
            if((i-j)==0 || (i-j)==1 || (i-j)==-1){
                tdm.setMatrix(i,j,x);   
                x++;
            }
        }
    }
    tdm.display();
}