#include<iostream>
using namespace std;

class UpperMatrixRowMajor{
    private:
    int n;
    int *A;
    public:
    UpperMatrixRowMajor(int n);
    void setMatrix(int i, int j, int ele);
    int getMatrix(int i, int j);
    void display();
    ~UpperMatrixRowMajor(){delete []A;}
};

UpperMatrixRowMajor::UpperMatrixRowMajor(int n){
    this->n=n;
    A = new int[n*(n+1)/2];
}

void UpperMatrixRowMajor::setMatrix(int i, int j, int ele){
    int pos = n*(i-1) - (i-2)*(i-1)/2 + j-1;
    if(i<=j && i<=n && j<=n){
        A[pos] = ele;
    }else{
        A[pos] = 0;
    }
}

int UpperMatrixRowMajor::getMatrix(int i, int j){
    int pos = n*(i-1) - (i-2)*(i-1)/2 + j-1;
    if(i<=j && i<=n && j<=n){
        return A[pos];
    }else{
        return 0;
    }
}

void UpperMatrixRowMajor::display(){
    for(int i=0;i<n;i++){
        for(int j=0; j<n; j++){
            cout<<getMatrix(i,j)<<" \t"<<flush;
        }cout<<endl;
    }
}
int main(){
    UpperMatrixRowMajor upmr(5);
    int x=1;
    for(int i=0; i<5;i++){
        for(int j=0;j<5;j++){
            if(j>=i){
                upmr.setMatrix(i,j,x);
                x++;
            }
        }    
    }
    upmr.display();
}