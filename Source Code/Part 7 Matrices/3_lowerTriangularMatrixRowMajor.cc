#include<iostream>
using namespace std;

class LowerTriMatrix{
    private:
    int *A;
    int n;

    public:
    LowerTriMatrix(int n);
    void set_matrix_row_major(int i,int j, int ele);
    int get_matrix_row_major(int i, int j);
    void display_matrix();
    ~LowerTriMatrix(){delete []A;};
};

LowerTriMatrix::LowerTriMatrix(int n){
    this->n=n;
    A = new int[n*n];
}

void LowerTriMatrix::set_matrix_row_major(int i, int j, int ele){
    if(i>=j && i>0 && j>0){
        int pos = (i*i-i)/2+j-1;
        A[pos]=ele;
    }
}

int LowerTriMatrix::get_matrix_row_major(int i, int j){
    int pos = ((i*i-i)/2)+j-1;
    if(i>=j && i>0 && j>0){
        return A[pos];
    }else{
        return 0;
    }
}

void LowerTriMatrix::display_matrix(){
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cout<<get_matrix_row_major(i,j)<<"\t "<<flush;
        }cout<<endl;
    }cout<<endl;
}

int main(){
    LowerTriMatrix lmx(5);
    int temp=2;
    for(int i=1;i<=5;i++){
        for(int j=1;j<=5;j++){
            lmx.set_matrix_row_major(i,j,temp);
            temp*=(i+1);
        }
    }
    
    lmx.display_matrix();
}