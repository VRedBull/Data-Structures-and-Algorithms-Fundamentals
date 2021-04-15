#include<iostream>
#include<string.h>
using namespace std;

void con(char* c){          //function to print char arrays
    int i=0;
    while(*(c+i)!='\0')
    {
        cout<<c[i]<<flush;
        i++;
    }
    cout<<endl;
}

int main(){
    char c[6];
    c[0] = 'V';
    c[1] = 'I';
    c[2] = 'K';
    c[3] = 'A';
    c[4] = 'S';
    c[5] = '\0';    //Null character to point that it's last in the array

    cout<<c<<endl;
    cout<<"Size of char array = "<<strlen(c)<<endl;
    cout<<"Actual size of char array including the null char = "<<sizeof(c)/sizeof(char)<<endl;

    //Another ways of declaring and intializing a char array

    char c2[] = "Vivaan";               //Includes the null char automatically this way
    char c3[] = {'V','I','K','A','S',' ','P','R','\0'};     

    cout<<endl<<c2<<" Size of char array = "<<strlen(c2)<<endl<<"Actual size of array including the null char = "<<sizeof(c2)/sizeof(char)<<endl;

    cout<<endl<<c3<<" Size of char array = "<<strlen(c3)<<endl<<"Actual size of array including the null char = "<<sizeof(c3)/sizeof(char)<<endl;

    con(&c[0]);
    con(&c2[0]);
    con(&c3[0]);
}