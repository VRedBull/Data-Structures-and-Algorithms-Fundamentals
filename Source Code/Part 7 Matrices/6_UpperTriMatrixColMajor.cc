#include<iostream>
using namespace std;

class UpperTriMatrixColMajor{
    private:
    int n;
    int *A;
    public:
    UpperTriMatrixColMajor(int n);
    void setMatrix(int i, int j, int ele);
    int getMatrix( int i, int j);
    void display();
    ~UpperTriMatrixColMajor(){delete []A;}
};

UpperTriMatrixColMajor::UpperTriMatrixColMajor(int n){
    this->n=n;
    A = new int[n*(n+1)/2];
}

void UpperTriMatrixColMajor::setMatrix(int i, int j, int ele){
    int pos = j*(j-1)/2 + i-1;
    if(j>=i && i<=n && j<=n){
        A[pos] = ele;
    }else{
        A[pos] = 0;
    }
}

int UpperTriMatrixColMajor::getMatrix(int i, int j){
    int pos = j*(j-1)/2 + i-1;
    if(j>=i && i<=n && j<=n){
        return A[pos];
    }else{
        return 0;
    }
}

void UpperTriMatrixColMajor::display(){
    for(int i=0;i<n;i++){
        for(int j=0;j<n; j++){
            cout<<getMatrix(i,j)<<" \t"<<flush;
        }cout<<endl;
    }
}
int main(){
    UpperTriMatrixColMajor utmc(5);
    int x=1;
    for(int i=0;i<5;i++){
        for(int j=0;j<5;j++){
        if(j>=i){
            utmc.setMatrix(i,j,x);
            x++;
        }
        }
    }
    utmc.display();
}