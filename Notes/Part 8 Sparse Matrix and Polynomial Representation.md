# Sparse Matrix

- Sparse Matrix are those matrices which have more zero than non-zero elements.
- So we need to only store the non-zero elements, to save space.
- We store sparse matrices in two ways.
  1. Coordinate List / 3 Column Representation
  2. Compressed sparse row

## Coordinate List / 3 Column Representation(table method)

This is represented in a table like structure containing rows and columns.

- This will contain 3 columns, to store the data of the non-zero element. 
- 1st column of row number of the non-zero element, 2nd column of column number and last column is the value.
- The very first row is reserved for number of rows, number of columns and number of non-zero elements respectively.

<img src="D:\Programming\Programming fundamentals\Data structures and algorithms fundamentals\Notes\sparse matrix table representation.JPG" style="zoom:60%;" />

## Compressed sparse Row

In this we will use array to store data of the non-zero elements.

- Here we will have 3 arrays.
- 1st array will have all the non-zero elements (order of storing it matters).
- 2nd array will have value of 0 at 0th index, then it'll store the number of non-zero elements till the 1st row, then no. of non-zero elements till the 2nd row, then no. of non-zero elements till the 3rd row. So, basically cumulative no. of non-zero elements.
- 3rd array will have the column number of the non-zero elements in the same order as it was stored in the 1st array.

<img src="D:\Programming\Programming fundamentals\Data structures and algorithms fundamentals\Notes\sparse matrix array representation.JPG" style="zoom:60%;" />

## Sparse Matrix Addition

- Spare Matrices can be added just like normal matrix addition (mathematically).<img src="D:\Programming\Programming fundamentals\Data structures and algorithms fundamentals\Notes\sparse matrix addition.JPG" style="zoom:55%;" />

  Here, A+B=C

- We add them using the table method (programmatically).<img src="D:\Programming\Programming fundamentals\Data structures and algorithms fundamentals\Notes\sparse matrix addtion table method.JPG" style="zoom:55%;" />



#### Creating and displaying a sparse matrix

Code in C: 

```c++
struct Elements{    //will make a array of this struct to make a table rep.
    int i;      //Row number
    int j;      //Col number
    int x;      //value
};

struct Sparse{      //properties of Sparse matrix are stored here and a pointer to the table rep. of elements
    int m;      //number of rows in matrix
    int n;      //number of Cols in matrix
    int num;    //no. of non-zero elements
    struct Elements *e;     //pointer to store the array of elements.
};

//create a sparse matrix
void create_sparse_matrix(struct Sparse *s){
    cout<<"Enter dimensions of Sparse Matrix: "<<endl;
    cout<<"Enter number of Rows: "<<flush;
    cin>>s->m;
    cout<<"Enter number of Cols: "<<flush;
    cin>>s->n;
    cout<<"Enter number of non-zero elements: "<<flush;
    cin>>s->num;
    cout<<endl;
    cout<<"Sparse matrix have rows = "<<s->m<<", cols = "<<s->n<<", non-zero elements = "<<s->num<<endl;
    //creating the table representation
    s->e = new Elements[s->num];
    cout<<"Enter the non-zero elements and it's rows and columns"<<endl;
    for(int k=0;k<s->num;k++){
        cout<<"Enter Col number: "<<flush;
        cin>>s->e[k].i;
        cout<<"Enter Row number: "<<flush;
        cin>>s->e[k].j;
        cout<<"Enter value: "<<flush;
        cin>>s->e[k].x;
    }
}

int get_sparse_Matrix(int i, int j, struct Sparse s){
    for(int k=0;k<s.num;k++){
        if(i==s.e[k].i && j==s.e[k].j)
        {
            return s.e[k].x;
        }else{
            continue;
        }
    }
    return 0;
}

void display_sparseMatrixTable(struct Sparse s){
    cout<<"Rows\tColumn\tNon-zero Elements"<<endl;
    cout<<s.m<<"\t"<<s.n<<"\t"<<s.num<<endl;
    for(int k=0;k<s.num;k++){
            cout<<s.e[k].i<<"\t"<<s.e[k].j<<"\t"<<s.e[k].x<<endl;
    }
}

void display_sparseMatrix(struct Sparse s){
    for(int a=0;a<s.m;a++){
        for(int b=0;b<s.n;b++){
            cout<<get_sparse_Matrix(a,b,s)<<" \t"<<flush;
        }cout<<endl;
    }
}

int main(){
    struct Sparse s;
    cout<<"Create a Sparse matrix."<<endl;
    create_sparse_matrix(&s);
    cout<<"Display Sparse Matrix Table Representation"<<endl;
    display_sparseMatrixTable(s);
    cout<<"Display the Sparse Matrix"<<endl;
    display_sparseMatrix(s);
}

//output
Create a Sparse matrix.
Enter dimensions of Sparse Matrix: 
Enter number of Rows: 4
Enter number of Cols: 5
Enter number of non-zero elements: 3

Sparse matrix have rows = 4, cols = 5, non-zero elements = 3
Enter the non-zero elements and it's rows and columns
Enter Col number: 2
Enter Row number: 3
Enter value: 12 
Enter Col number: 1
Enter Row number: 3
Enter value: 55
Enter Col number: 3
Enter Row number: 2
Enter value: 32 
Display Sparse Matrix Table Representation
Rows    Column  Non-zero Elements
4       5       3
2       3       12
1       3       55
3       2       32
Display the Sparse Matrix
0       0       0       0       0
0       0       0       55      0
0       0       0       12      0
0       0       32      0       0
```

Also Done this in C++ and using operator overloading(check source code folder).

#### Adding two Sparse Matrices

Code:

```c++
struct Elements{
    int i;
    int j;
    int x;
};

struct Sparse{
    int m;
    int n;
    int num;
    struct Elements *ele;
};



int get_sparse_Matrix(int i, int j, struct Sparse s){
    for(int k=0;k<s.num;k++){
        if(i==s.ele[k].i && j==s.ele[k].j){
            return s.ele[k].x;
        }
    }
    return 0;
}

void display_sparse_Matrix(struct Sparse s){
    cout<<"Displaying the Sparse Matrix"<<endl;
    for(int a=0;a<s.m;a++){
        for(int b=0;b<s.n;b++){
            cout<<get_sparse_Matrix(a,b,s)<<"\t"<<flush;
        }cout<<endl;
    }

    cout<<"Displaying the Sparse Matrix in Table form"<<endl;
    cout<<"Rows\tCols\tValue\t"<<endl;
    cout<<s.m<<"\t"<<s.n<<"\t"<<s.num<<endl;
    for(int a=0;a<s.num;a++){
            cout<<s.ele[a].i<<"\t"<<s.ele[a].j<<"\t"<<s.ele[a].x<<endl;
    }
}
void add_sparse_matrix(struct Sparse s1, struct Sparse s2){
    if(s1.m!=s2.m || s1.n!=s2.n){
        cout<<"Dimensions of Matrices to be added must be same!."<<endl;
        return;
    }
    struct Sparse *sum;
    sum = new Sparse();
    sum->num = s1.num+s2.num;
    sum->ele = new Elements[sum->num];
    sum->m=s1.m;
    sum->n=s2.n;
    int i=0,j=0,k=0;
    while(i<s1.num && j<s2.num){
        if(s1.ele[i].i<s2.ele[j].i){
            sum->ele[k++]=s1.ele[i++];
        }else if(s1.ele[i].i<s2.ele[j].i){
            sum->ele[k++]=s2.ele[j++];
        }else{
            if(s1.ele[i].j<s2.ele[j].j){
                sum->ele[k++]=s1.ele[i++];
            }else if(s1.ele[i].j>s2.ele[j].j){
                sum->ele[k++]=s2.ele[j++];
            }else{
                sum->ele[k]=s1.ele[i++];
                sum->ele[k++].x=s1.ele[j++].x+s2.ele[j++].x;
            }
        }
    }

    //if there are remaining elements of s1 and s2 after addition of matrices
    for(;i<s1.ele[k].i;i++)sum->ele[k++]=s1.ele[i];
    for(;j<s2.ele[k].j;j++)sum->ele[k++]=s2.ele[j];
    cout<<"Displayed Sparse Matrix after addition:"<<endl;
    display_sparse_Matrix(*sum);
}

void create_sparse_matrix(struct Sparse *s){
    cout<<"Rows: "<<flush;
    cin>>s->m;
    cout<<"Cols: "<<flush;
    cin>>s->n;
    cout<<"Number of non-zero elements: "<<flush;
    cin>>s->num;
    //
    s->ele = new Elements[s->num];
    cout<<"Enter rows and cols and values respectively: "<<endl;
    for(int k=0;k<s->num;k++){
        cout<<"Enter Row: "<<flush;
        cin>>s->ele[k].i;
        cout<<"Enter Cols: "<<flush;
        cin>>s->ele[k].j;
        cout<<"Enter Value: "<<flush;
        cin>>s->ele[k].x;
    }
}

int main(){
    struct Sparse s1,s2;
    cout<<"Create a SParse Matrix:"<<endl;
    create_sparse_matrix(&s1);
    cout<<"Display Sparse Matrix:"<<endl;
    display_sparse_Matrix(s1);
    cout<<"Create a SParse Matrix:"<<endl;
    create_sparse_matrix(&s2);
    cout<<"Display Sparse Matrix:"<<endl;
    display_sparse_Matrix(s2);
    cout<<"Add Sparse Matrix:"<<endl;
    add_sparse_matrix(s1,s2);
}

//output
Create a SParse Matrix:
Rows: 4
Cols: 4
Number of non-zero elements: 2
Enter rows and cols and values respectively: 
Enter Row: 1
Enter Cols: 2
Enter Value: 33
Enter Row: 0
Enter Cols: 3
Enter Value: 55
Display Sparse Matrix:      
Displaying the Sparse Matrix
0       0       0       55
0       0       33      0
0       0       0       0
0       0       0       0
Displaying the Sparse Matrix in Table form
Rows    Cols    Value
4       4       2
1       2       33
0       3       55
Create a SParse Matrix:
Rows: 4
Cols: 4
Number of non-zero elements: 3
Enter rows and cols and values respectively: 
Enter Row: 1
Enter Cols: 1
Enter Value: 22
Enter Row: 2
Enter Cols: 2
Enter Value: 33
Enter Row: 3
Enter Cols: 3
Enter Value: 66
Display Sparse Matrix:
Displaying the Sparse Matrix
0       0       0       0
0       22      0       0
0       0       33      0
0       0       0       66
Displaying the Sparse Matrix in Table form
Rows    Cols    Value
4       4       3
1       1       22
2       2       33
3       3       66
Add Sparse Matrix:
Displayed Sparse Matrix after addition:
Displaying the Sparse Matrix
0       0       0       55
0       22      33      0
0       0       0       0
0       0       0       0
Displaying the Sparse Matrix in Table form
Rows    Cols    Value
4       4       5
1       1       22
1       2       33
0       3       55
-832993759      268465389       4
1551068257      1920298835      1126196579
```



# Polynomials

## Polynomial Representation

Polynomial example = 2x^2 + 3x + 4

- Polynomials are made of terms.
- These terms consists of coefficient, power of the variable.

We can represent this in program like...

```c++
struct Terms{   //a polynomial is made up of terms
    int coeff;  //a term have two properties - coeff. and exponent
    int exp;    //the exponent
};

struct Polynomial{     //structure of polynomial 
    int num;    //no. of non-zero terms(non-zero coeff.) in the polynomial
    Terms *t;   //Pointer to make a array of terms in heap
    char var;   //the name of the variable to be used to make polynomial
};

void create_Polynomial(struct Polynomial *p){
    cout<<"Enter no. of non-zero terms in polynomial: "<<endl;
    cin>>p->num;
    p->t = new Terms[p->num];
    cout<<"Enter the variable name to be used in polynomial: "<<flush;
    cin>>p->var;
    for(int a=0;a<p->num;a++){
        cout<<"Enter coefficient of term "<<a<<" : "<<flush;
        cin>>p->t[a].coeff;
        cout<<"Enter exp of term "<<a<<" : "<<flush;
        cin>>p->t[a].exp;
    }
}

void display_Polynomial(struct Polynomial p){
    for(int a=0;a<p.num;a++){       //can also conditions for -ve coefficients and for exponent 0 and 
                                    //for last term of the polynomial
        cout<<p.t[a].coeff<<p.var<<"^"<<p.t[a].exp<<"+"<<flush;
    }cout<<endl;
}
int main(){
    struct Polynomial p;
    create_Polynomial(&p);
    display_Polynomial(p);
}
//output
Enter no. of non-zero terms in polynomial: 
4
Enter the variable name to be used in polynomial: x
Enter coefficient of term 0 : 8
Enter exp of term 0 : 3
Enter coefficient of term 1 : 4
Enter exp of term 1 : 2
Enter coefficient of term 2 : 7
Enter exp of term 2 : 1
Enter coefficient of term 3 : 2
Enter exp of term 3 : 0
8x^3+4x^2+7x^1+2x^0+
```



## Polynomial Evaluation

We can solve the polynomial if we get the value of the variable, then we can put the value in the variable and solve the polynomial.

```c++
struct Terms{
    int coeff;
    int exp;
};

struct Polynomial{
    int num;
    struct Terms *t;
    char var;
};

void create_polynomial(struct Polynomial *p){
    cout<<"Enter no. of non-zero :"<<flush;
    cin>>p->num;
    p->t = new Terms[p->num];
    cout<<"Enter the name of variable you want to use: "<<flush;
    cin>>p->var;
    for(int a=0;a<p->num;a++){
        cout<<"Enter coeff. of term "<<a<<" : "<<flush;
        cin>>p->t[a].coeff;
        cout<<"Enter exponent of term "<<a<<" : "<<flush;
        cin>>p->t[a].exp;
    }
}

void display_polynomial(struct Polynomial p){
    for(int a=0;a<p.num;a++){       
        cout<<p.t[a].coeff<<p.var<<"^"<<p.t[a].exp<<"+"<<flush;
    }cout<<endl;
}

int power(int a, int b){
    int sum=1;
    if(a==0){
        return 0;
    }else if(b==0){
        return 1;
    }else{
        for(int i=0;i<b;i++){
            sum*=a;
        }
        return sum;
    }
}

//When we get the value of the variable of the polynomial we can find out the value of the equation.
int solve_polynomial(int value,struct Polynomial p){
    int sum=0;
    for(int a=0;a<p.num;a++){
        int exp_value,term_value;
        exp_value=power(value, p.t[a].exp);
        term_value=(p.t[a].coeff)*exp_value;
        sum+=term_value;
    }
    return sum;
}

int main(){
    struct Polynomial p;
    create_polynomial(&p);
    display_polynomial(p);
    //passed the value of the variable as 2
    cout<<solve_polynomial(2,p);
}

//output
Enter no. of non-zero :4
Enter the name of variable you want to use: y
Enter coeff. of term 0 : 7
Enter exponent of term 0 : 3
Enter coeff. of term 1 : 6
Enter exponent of term 1 : 2
Enter coeff. of term 2 : 8
Enter exponent of term 2 : 1
Enter coeff. of term 3 : 9
Enter exponent of term 3 : 0
7y^3+6y^2+8y^1+9y^0+
105
```



## Polynomial Addition

Here we take two polynomials and just add them together in another polynomial and display the result.

Code:

```c++
struct Terms{
    int coeff;
    int exp;
};

struct Polynomial{
    int num;
    struct Terms *t;
    char var;
};

void create(struct Polynomial *p){
    cout<<"No. of non-zero terms: "<<flush;
    cin>>p->num;
    p->t = new Terms[p->num];
    cout<<"Enter the name of variable of polynomial: "<<flush;
    cin>>p->var;
    for(int a=0;a<p->num;a++){
        cout<<"Enter coeff. of term "<<a+1<<": "<<flush;
        cin>>p->t[a].coeff;
        cout<<"Enter exp. of term "<<a+1<<": "<<flush;
        cin>>p->t[a].exp;
    }
}

void display(struct Polynomial p){
    for(int a=0;a<p.num;a++){
        cout<<p.t[a].coeff<<p.var<<"^"<<p.t[a].exp<<" + "<<flush;
    }cout<<endl;
}

void add_polynomial(struct Polynomial p1, struct Polynomial p2){
    struct Polynomial sum;
    sum.num=p1.num+p2.num;
    sum.t = new Terms[sum.num];
    sum.var=p1.var;
    int a=0,b=0,x=0;
    while(a<p1.num && b<p2.num){
        if(p1.t[a].exp==p2.t[b].exp){
            sum.t[x].coeff = p1.t[a].coeff + p2.t[b].coeff;
            sum.t[x].exp=p1.t[a].exp;
            x++,a++,b++;
        }else if(p1.t[a].exp<p2.t[b].exp){
            sum.t[x].coeff = p1.t[a].coeff;
            sum.t[x].exp = p1.t[a].exp;
            x++,b++;
        }else{
            sum.t[x].coeff = p2.t[b].coeff;
            sum.t[x].exp = p2.t[b].exp;
            x++,b++;
        }
    }

    for(;a<p1.num;a++){
        sum.t[x++]=p1.t[a];;
    }
    for(;b<p2.num;b++){
        sum.t[x++]=p2.t[b];
    }

    sum.num=x;

    display(sum);
}

int main(){
    struct Polynomial p1,p2;
    create(&p1);
    display(p1);
    create(&p2);
    display(p2);
    add_polynomial(p1,p2);
}   

//output
No. of non-zero terms: 3
Enter the name of variable of polynomial: y
Enter coeff. of term 1: 7
Enter exp. of term 1: 2
Enter coeff. of term 2: 9
Enter exp. of term 2: 4
Enter coeff. of term 3: 8
Enter exp. of term 3: 1
No. of non-zero terms: 3
Enter the name of variable of polynomial: y
Enter coeff. of term 1: 6
Enter exp. of term 1: 2
Enter coeff. of term 2: 9
Enter exp. of term 2: 3
Enter coeff. of term 3: 1
Enter exp. of term 3: 2
6y^2 + 9y^3 + 1y^2 +
13y^2 + 9y^3 + 1y^2 + 9y^4 + 8y^1 +
```

