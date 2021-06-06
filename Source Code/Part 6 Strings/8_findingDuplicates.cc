#include<iostream>
using namespace std;

int str_length(char str[]){
    int i;
    for(i=0;str[i]!='\0';i++){}
    return i;
}

void find_duplicate_comparing_elements(char str[]){
    int i,j;
    int str_l = str_length(str);
    for(i=0;i<(str_l-1);i++){
        int count=1;
        if(str[i]!='0'){
            for(j=i+1;j<str_l;j++){
                if(str[i]==str[j]){
                    count++;
                    str[j]='0';
                }else{
                    continue;
                }
            }
            if(count>1)
                cout<<str[i]<<" has occurred "<<count<<" times."<<endl;
        }
    }
}

//only for small letters
// void hash_string_duplicates(char str[]){
//     int hash[26]={0};

//     for(int i=0;str[i]!='\0';i++){
//         int x=str[i]-97;
//         hash[x]++;
//     }
    
//     for(int i=0;i<26;i++){
//         if(hash[i]>1){
//             printf("%c has occurred %d times\n",(i+97),hash[i]);
//         }
//     }
// }

//for small and capital letters
void hash_string_duplicates(char str[]){
    int hash[52]={0};

    for(int i=0;str[i]!='\0';i++){
        if(str[i]>='a' && str[i]<='z'){
            int x=str[i]-97;
            hash[x]++;
        }else if(str[i]>='A' && str[i]<='Z'){
            int x=str[i]-65+26;
            hash[x]++;
        }else{
            continue;
        }
    }
    
    for(int i=0;i<52;i++){
        if(hash[i]>1){
            if(i>=0 && i<=25){
                printf("%c has occurred %d times\n",(i+97),hash[i]);
            }else if(i>25 && i<=51){
                printf("%c has occurred %d times\n",(i+65-26),hash[i]);
            }
        }
    }
}



int main(){
    char str1[]="PananmaPAA";
    char str2[]="finding";
    find_duplicate_comparing_elements(str2);
    cout<<endl;
    hash_string_duplicates(str1);
}