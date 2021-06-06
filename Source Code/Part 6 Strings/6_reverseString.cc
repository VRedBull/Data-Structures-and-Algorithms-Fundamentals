#include<iostream>
using namespace std;

int length_str(char str[]);

void reverse_using_two_array(char str[]){
    int arr_len=length_str(str);
    char str2[arr_len];
    int i=arr_len-1,j=0;
    while(i>=0){
        str2[j]=str[i];
        i--,j++;
    }
    str2[j]='\0';

    for(int x=0;str2[x]!='\0';x++){
        str[x] = str2[x];
    }
}

void reverse_using_swap_array(char str[]){
    int i=0,j=length_str(str)-1;
    char temp;
    while(i<j){
        temp = str[i];
        str[i] = str[j];
        str[j] = temp;
        i++,j--;
    }
}

int length_str(char str[]){
    int i=0;
    for(i=0;str[i]!='\0';i++)
        i++;
    return i;
}
int main(){
    char str1[] = "Reversed";
    reverse_using_two_array(str1);
    cout<<str1<<endl;   
    reverse_using_swap_array(str1); 
    cout<<str1<<endl;   
}