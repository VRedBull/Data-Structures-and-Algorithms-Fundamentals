#include<iostream>
using namespace std;

int str_length(char str[]){     //length does not include the null char
    int i=0;
    while(str[i]!='\0'){
        i++;
    }
    return i;
}

void compare_check_anagram_string(char str1[],char str2[]){
    cout<<"Checking angram strings for: "<<str1 <<" and "<<str2<<endl;
    int str1_length = str_length(str1);
    int str2_length = str_length(str2);
    if(str1_length!= str2_length){
        cout<<"Strings are not having same number of characters."<<endl;
        return;
    }
    int flag=1;
    for(int i=0;str1[i]!='\0';i++){
        for(int j=0;str2[j]!='\0';j++){
            if(str1[i]==str2[j]){
            //    cout<<"Found "<<str1[i]<<endl;    can check what chars have we compared and found
               break; 
            }else if((j==str2_length-1) && (str2[j]!=str1[i])){
                cout<<"Strings are not anagram, since did not find "<<str1[i]<<endl;
                return;
            }
        }
    }

    cout<<"Strings are anagram"<<endl;
}

//in this we will only check for small alphabets
void hash_check_string_anagram(char str1[], char str2[]){
    cout<<"Checking angram strings for: "<<str1 <<" and "<<str2<<endl;
    int hash[26]={0};           

    if(str_length(str1)!= str_length(str2)){
        cout<<"Strings are not having same number of characters."<<endl;
        return;
    }

    for(int i=0;str1[i]!='\0';i++){
        int x=str1[i]-97;
        hash[x]++;
    }

    for(int i=0;str2[i]!='\0';i++){
        int x=str2[i]-97;
        if(hash[x]==0){
            cout<<str2[i]<<" is missing."<<endl;
            return;
        }else{
            continue;
        }
    }

    cout<<"Strings are anagram."<<endl;
}

int main(){
    char str1[]="decimal";
    char str2[]="medical";
    char str3[]="listen";
    char str4[]="silent";
    hash_check_string_anagram(str1,str2);
    cout<<endl;
    compare_check_anagram_string(str3,str4);
}