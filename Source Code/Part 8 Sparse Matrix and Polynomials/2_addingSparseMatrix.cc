#include<iostream>
using namespace std;

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