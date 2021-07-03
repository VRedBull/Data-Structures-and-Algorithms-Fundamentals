#  Matrices

## Diagonal matrix

- Diagonal matrix are those matrix which have non-zero diagonal elements and the rest of the matrix element are zero.

- To store all the elements of a matrix we need a 2D array.

- But why waste memory storing value 'zero'. 

- We can store only non-zero diagonal elements in a single dimensional array.

  Here's the C code

  ```c++
  void set_diagonal(int A[],int i,int j, int ele){
      if(i==j){
          A[i-1]=ele;
      }
  }
  
  int get_diagonal(int A[],int i, int j){
      if(i==j){
          return A[i-1];
      }else{
          return 0;
      }
  }
  
  void display(int A[]){
      for(int i=0;i<5;i++){
          for(int j=0;j<5;j++){
              if(i==j)
                  cout<<i<<" "<<flush;
              else
                  cout<<"0 "<<flush;
          }cout<<endl;
      }cout<<endl;
  }
  
  int main(){
      int A[5];
      int i,j,temp=1;
  
      for(i=1;i<=5;i++){
          for(j=1;j<=5;j++){
              if(i==j){
                  temp++;
                  set_diagonal(A,i,j,temp);
              }
          }
      }
      // cout<<get_diagonal(A,1,1)<<endl;
      display(A);
  }   
  
  //output
  0 0 0 0 0
  0 1 0 0 0
  0 0 2 0 0
  0 0 0 3 0
  0 0 0 0 4
  ```

  Here's the C++ code for diagonal matrix.
  
  ```c++
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
  
  //output
  10 0 0 0 0 
  0 20 0 0 0
  0 0 60 0 0
  0 0 0 240 0
  0 0 0 0 1200
  ```
  



## Triangular Matrices

### Lower Triangular Matrix

- Lower Triangular Matrix are those matrix which have all their elements non-zero below the diagonal of the matrix, and the diagonal elements are also non-zero. And all the elements above the diagonal must be zero.

  <img src="D:\Programming\Programming fundamentals\Data structures and algorithms fundamentals\Notes\Lower Triangular Matrix Row Major.JPG" style="zoom:65%;" />

- Since, all there are many elements which are zero in the matrix. So, why waste space by storing all of them in a 2D array.

- We will store all the elements in a 1D array.

- We will need an 1D array of size n(n+1)/2, since no. of elements in row 1 is 1 then row 2 is 2 and so on... then it adds up as 1+2+3+....+n = n(n+1)/2.

- Now there are two ways of storing elements from a triangular matrix to a 1D array.

  1. **Row-Major**
  2. **Column-Major** 

  ### Row-Major

  In Row-Major we will store all the elements row-wise in the 1D array from the matrix.<img src="D:\Programming\Programming fundamentals\Data structures and algorithms fundamentals\Notes\Row Major Mapping.JPG" style="zoom:60%;" />

  For Mapping elements in the appropriate position in the 1D array from the Matrix(like a 2D array), we will need a formula for position the elements.

  This formula can be derived like this...<img src="D:\Programming\Programming fundamentals\Data structures and algorithms fundamentals\Notes\Lower Triangular Matrix Row Major position formula.JPG" style="zoom:60%;" />

  Here's the Code(C++)

  ```c++
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
  
  //output gives a little error, refer the c++ code by abdul bari pdf
  ```

  ### Column-Major

  In column Major we'll just go through the Matrix Column-wise and fill all the non-zero elements in the 1D array.<img src="D:\Programming\Programming fundamentals\Data structures and algorithms fundamentals\Notes\Column Major Mapping.JPG" style="zoom:60%;" />

  Position formula for Column Major is<img src="D:\Programming\Programming fundamentals\Data structures and algorithms fundamentals\Notes\Lower Triangular Matrix Column Major position formula.JPG" style="zoom:67%;" />

  Now The code

  ```c++
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
  
  //output
  5
  1       0       0       0       0
  2       3       0       0       0
  4       5       6       0       0
  7       8       9       10      0
  11      12      13      14      15
  ```



### Upper Triangular Matrix

- As the name suggests, the upper triangular Matrix have non-zero elements above the diagonal. Also the diagonal elements are non-zero.<img src="D:\Programming\Programming fundamentals\Data structures and algorithms fundamentals\Notes\Upper Triangular Matrix.JPG" style="zoom:60%;" />

  The size of the 1D array in which we are going to store the non-zero elements = n(n+1)/2.

  Similarly here also there's Row major and Column Major.

  ### Row-Major

  Row Major mapping in 1D array is <img src="D:\Programming\Programming fundamentals\Data structures and algorithms fundamentals\Notes\Upper Triangular Row Major Mapping.JPG" style="zoom:60%;" />

  Position formula <img src="D:\Programming\Programming fundamentals\Data structures and algorithms fundamentals\Notes\Upper Triangular Row Major Position Formula.JPG" style="zoom:60%;" />

  Here's the code

  ```c++
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
  
  //output
  1       2       3       4       5 
  0       6       7       8       9
  0       0       10      11      12
  0       0       0       13      14
  0       0       0       0       15
  ```

  ### Column-Major

  1D array mapping <img src="D:\Programming\Programming fundamentals\Data structures and algorithms fundamentals\Notes\Upper Triangular Column Major Mapping.JPG" style="zoom:60%;" />

  Position formula <img src="D:\Programming\Programming fundamentals\Data structures and algorithms fundamentals\Notes\Upper Triangular Column Major Position Formula.JPG" style="zoom:60%;" />

  Here's the code

  ```c++
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
  
  //output
  2       2       6       10      13 
  0       6       7       8       9
  0       0       10      11      12
  0       0       0       13      14 
  0       0       0       0       15
  ```



### Tri Diagonal Matrix

Tri-Diagonal Matrix is a Matrix with 3 diagonals. (2 diagonal around the main diagonal on both sides).

<img src="D:\Programming\Programming fundamentals\Data structures and algorithms fundamentals\Notes\Tri-diagonal Matrix.JPG" style="zoom:60%;" />

We'll store the non-zero elements in a 1D array.

Length of the array = 3n-2	.... since main diagonal size = n, other 2 diagonals size = n-1

Mapping of the Matrix on 1D array is done Diagonal by diagonal... <img src="D:\Programming\Programming fundamentals\Data structures and algorithms fundamentals\Notes\Tri-diagonal Matrix mapping.JPG" style="zoom:55%;" />



This time there is not one single formula for the position of a element of matrix on the 1D array, but three different cases since there are three different diagonals.

The cases and position formula is ...<img src="D:\Programming\Programming fundamentals\Data structures and algorithms fundamentals\Notes\Tri-diagonal Matrix position formula.JPG" style="zoom:60%;" />

Here's the code

```c++
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

//output
12      2       0       0       0 
3       4       5       0       0
0       6       7       8       0
0       0       9       10      11
0       0       0       12      13
```



### Toeplitz Matrix

In this matrix all the diagonal elements are same.<img src="D:\Programming\Programming fundamentals\Data structures and algorithms fundamentals\Notes\Toeplitz Matrix.JPG" style="zoom:60%;" />

We will store only the original elements (i.e. elements in the 1st row and 1st column)

Position formula<img src="D:\Programming\Programming fundamentals\Data structures and algorithms fundamentals\Notes\Toeplitz Matrix position formula.JPG" style="zoom:60%;" />

Here's the code

```c++
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

//output
1       2       3       4       5 
6       1       2       3       4
7       6       1       2       3
8       7       6       1       2
9       8       7       6       1 
```

