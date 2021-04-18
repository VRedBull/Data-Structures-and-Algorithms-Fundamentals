#include<iostream>
using namespace std;

int main(){
    int a =10;
    int (*p0) = &a;

    int (*p3) = new int[10];
    p3[0]=10;
    *(p3+1)=20;

    free(p3);
    delete []p3;

    int A[] = {2,12,3,4,5,6,62,7,71};

    int (*p)=A;

    int A1[2][3]={
        {1,2,3},{4,5,6}
    };
    int (*p1)[3]=A1;
    cout<<*(*(p1+1)+2)<<endl;


    int A2[3][4][2] = {
        {
            {1,2},{3,4},{5,6},{7,8}
        },{
            {9,10},{11,12},{13,14},{15,16}
        },{
            {91,110},{111,112},{113,114},{315,156}
        }
    };

    int (*p2)[4][2]=A2;

    cout<<*(*(*(p2+1)+2)+1)<<endl;

    int (*p4)[3] = new int[2][3];       //multi D array in heap

    *(*(p4+0)+0)=1;
    p4[0][1]=2;


}