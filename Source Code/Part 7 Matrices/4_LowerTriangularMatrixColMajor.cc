#include<iostream>
using namespace std;

class LowerTriMatrixCol{
    private:
    int *A;
    int n;
    
    public:
    LowerTriMatrixCol(int n);
    void setMatrix(int i, int j, int ele);
    void display();
    int getMatrix(int i, int j);
    ~LowerTriMatrixCol(){
        delete []A;
    }
};

LowerTriMatrixCol::LowerTriMatrixCol(int n){
    this->n=n;
    A = new int[n*(n+1)/2];
}

void LowerTriMatrixCol::setMatrix(int i, int j, int ele){
    int pos = (n*j-n) - ((j-2)*(j-1)/2) + (i-j);
    if(i>=j && i<=n && j<=n){
        A[pos] = ele;
    }else{
        A[pos] = 0;
    }
}

int LowerTriMatrixCol::getMatrix(int i, int j){
    int pos = (n*j-n) - ((j-2)*(j-1)/2) + (i-j);
    if(i>=j && i<=n && j<=n){
        return A[pos];
    }else{
        return 0;
    }
}

void LowerTriMatrixCol::display(){
    for(int i=0;i<n;i++){
        for(int j=0; j<n; j++){
            cout<<getMatrix(i,j)<<" \t"<<flush;
        }
        cout<<endl;
    }cout<<endl;
}

int main(){
    LowerTriMatrixCol ltmc(5);
    int x=1;
    for(int i=0;i<5;i++){
        for(int j=0;j<5;j++){
            if(i>=j){
                ltmc.setMatrix(i,j,x);
                x++;
            }
        }
    }
    cout<<ltmc.getMatrix(2,1)<<endl;
    ltmc.display();
}   