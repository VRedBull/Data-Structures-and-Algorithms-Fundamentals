#include<iostream>
using namespace std;

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
        cout<<"Enter Row number: "<<flush;
        cin>>s->e[k].i;
        cout<<"Enter Col number: "<<flush;
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