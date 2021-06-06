#include<iostream>
using namespace std;

void changeCase(char name[]){
    
    for(int i=0; name[i]!='\0'; i++){
        if(name[i]>='A' && name[i]<='Z'){
            name[i]+=32;
        }else if(name[i]>='a' && name[i]<='z'){
            name[i]-=32;
        }
    }
}


int main(){
    char name1[] = "VikAs PraDhaN";
    changeCase(name1);
    printf("%s",name1);
}