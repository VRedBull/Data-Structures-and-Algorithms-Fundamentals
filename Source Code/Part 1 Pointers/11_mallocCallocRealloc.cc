#include<iostream>
using namespace std;

int main(){

    // int (*p) = (int*)malloc(sizeof(int));

    // *p = 5;

    // free(p);

    // int *p = (int*)malloc(10*sizeof(int));      //just multiply sizeof(int) to the no. of elements we want in array

    // // Can assign the values like this
    // *p = 1;
    // *(p+1) = 2;
    // p[2] = 3;

    // Calloc -----------------------------------------------------------------

    // int (*p) = (int*)calloc(4, sizeof(int));

    // *p = 2;
    // *(p+1) = 3;
    // *(p+2) = 4;
    // p[3] = 5;

    // for(int x=0;x<4;x++)
    //     cout<<*(p+x)<<" "<<flush;
    // cout<<endl;
    
    // cout<<"Base Address of the array =  "<<p<<endl;

    // int (*q) = (int*)realloc(p,7*sizeof(int));

    // cout<<"Base Address of the array =  "<<p<<endl;

    // for(int x=0;x<7;x++)
    //     cout<<*(p+x)<<" "<<flush;

//--------------------------------------------------------
    // free(p);
    // // int (*r) = (int*)realloc(p,2*sizeof(int));
    // // cout<<"Base Address of the array =  "<<p<<endl;

    // for(int x=0;x<4;x++)
    //     cout<<*(p+x)<<" "<<flush;

    int (*p) = new int[6];

    for(int i=0;i<6;i++)
        *(p+i)=i+1;
    
    for(int i=0;i<6;i++)
        cout<<*(p+i)<<endl;
    
    delete p;

    for(int i=0;i<6;i++)
        cout<<*(p+i)<<endl;
    
}