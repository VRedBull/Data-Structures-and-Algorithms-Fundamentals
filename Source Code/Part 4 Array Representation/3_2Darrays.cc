#include<iostream>
using namespace std;

int main(){

    //way 1
    // int A[2][3] = {
    //     {
    //         1,2,3
    //     },{
    //         4,5,6
    //     }
    // };

    // for(int i=0;i<2;i++){
    //     for(int j:A[i])
    //         cout<<j<<" "<<flush;
    //     cout<<endl;
    // }

//__________________________________________________________________________________________________

    //way 2
    // int *A[3];    //three pointers in array
    // A[0] = new int[4];      //each pointer creating a array in heap
    // A[1] = new int[4];
    // A[2] = new int[4];

    // int x=1;
    // for(int i=0;i<3;i++){
    //     for(int j=0;j<4;j++){
    //         A[i][j] = x;
    //         x++;
    //     }
    // }

    // for(int i=0;i<3;i++){
    //     for(int j=0;j<4;j++){
    //         cout<<A[i][j]<<" "<<flush;
    //     }
    //     cout<<endl;
    // }

//__________________________________________________________________________________________________

    // way 3
    // int **A;
    // *A = new int[3];
    // A[0] = new int[4];
    // A[1] = new int[4];
    // A[2] = new int[4];
    
    // int a=1;
    // for(int i=0;i<3;i++){
    //     for(int j=0;j<4;j++){
    //         *(*(A+i)+j)=a;
    //         a++;
    //     }
    // }
    
    // for(int i=0;i<3;i++){
    //     for(int j=0;j<4;j++){
    //         cout<<A[i][j]<<" "<<flush;
    //     }
    //     cout<<endl;
    // }

//__________________________________________________________________________________________________

    // way 4 - simplest way to create array in heap
    int (*A)[3] = new int[2][3];    
    
    int x = 1;
    for(int i=0;i<2;i++){
        for(int j=0;j<3;j++){
            *(*(A+i)+j)=x;
            x++;
        }
    }
    for(int i=0;i<2;i++){
        for(int j=0;j<3;j++){
            cout<<*(*(A+i)+j)<<" "<<flush;
        }
        cout<<endl;
    }
}