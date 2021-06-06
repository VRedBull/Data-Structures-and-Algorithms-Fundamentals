#include<iostream>
using namespace std;

/*
Program where no speacial characters are not allowed like in a password and no spaces too
*/

int valid_string(char str[]){
    for(int i=0;str[i]!='\0';i++){
        if(!(str[i]>='A' && str[i]<='Z') && !(str[i]>='a' && str[i]<='z') && !(str[i]>=48 && str[i]<=57)){
            return 0;
        }
    }
    return 1;
}

int main(){
    char str1[] = "Vikas?Pradhan";
    char str2[] = "VivaanPradhan";

    if(valid_string(str1)){
        cout<<str1<<" is a Valid String"<<endl;
    }else{
        cout<<str1<<" is a Invalid String"<<endl;
    }

    if(valid_string(str2)){
        cout<<str2<<" is a Valid String"<<endl;
    }else{
        cout<<str2<<" is a Invalid String"<<endl;
    }
}   