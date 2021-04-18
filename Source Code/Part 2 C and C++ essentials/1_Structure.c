#include<stdio.h>

struct Rectangle
{
    /* data */
    int length;
    int breadth;
    char name[20];
};


int main(){
    struct Rectangle r = {10,20,"Rectangle 1"};       //can declare an object like this and initialize values like this   
    printf("length = %d, breadth = %d, name = %s\n",r.length,r.breadth,r.name);   //can also use the dot operator to assign or fetch values

    struct Rectangle D[10] = {             //And array of structure objects
        {1,2},{3,4},{5,6},{7,8}
    };

    for(int i=0;i<10;i++){
        printf("length = %d, breadth = %d\n",D[i].length,D[i].breadth);
    }
}