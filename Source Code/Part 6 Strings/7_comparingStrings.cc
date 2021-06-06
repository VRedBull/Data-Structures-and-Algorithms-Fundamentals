#include<iostream>
using namespace std;

int str_length(char str[]){
    int i;
    for(i=0;str[i]!=0;i++){}
    return i;
}

void compare_str(char str1[], char str2[]){
    int i,j;

    for(i=0,j=0; str1[i]!='\0'|| str2[j]!='\0';i++,j++){
        if(str1[i]!=str2[j]){
            break;
        }
    }
    if(str1[i]>str2[j]){
        cout<<str1<<" is greater than "<<str2<<endl;
    }else{
        cout<<str2<<" is greater than "<<str1<<endl;
    }
}

void check_palindrome_using_two_arrays(char str[]){ //note that it's case sensitive
    int str_l=str_length(str);               //we can also convert all letters to one particular case first
    char str2[str_l];

    int i,j;
    for(i=0,j=str_l-1;j>=0;i++,j--){
        str2[i]=str[j];
    }
    str2[i]='\0';
    cout<<"Reversed string: "<<str2<<endl;           //prints the reversed string

    for(int x=0;str[x]!='\0' || str2[x]!='\0';x++){
        if(str[x]!=str2[x]){
            cout<<str<<": string not palindrome"<<endl;
            return;
        }
    }
    cout<<str<<": String is palindrome"<<endl;

}

void check_palindrome_using_swap(char str[]){
    int i,j;
    for(i=0,j=str_length(str)-1;i<j;i++,j--){
        if(str[i]!=str[j]){
            cout<<str<<" is not a palindrome string"<<endl;
            return;
        }
    }
    cout<<str<<" is palindrome"<<endl;
}

int main(){
    char str1[] = "Painter";
    char str2[] = "Painting";
    char str3[] = "MadaM";    
    compare_str(str1,str2);
    check_palindrome_using_two_arrays(str3);
    check_palindrome_using_swap(str2);
}