#include<iostream>
using namespace std;

void count_vowels_consonants(char words[]){
    int vcount=0, ccount=0;
    for(int i=0; words[i]!=0;i++){
        if(words[i]=='a' || words[i]=='e' ||words[i]=='i' ||words[i]=='o' ||words[i]=='u' || words[i]=='A' ||words[i]=='E' ||words[i]=='I' ||words[i]=='O' ||words[i]=='U'){
            vcount++;
            continue;
        }else if ( (words[i]>='A' && words[i]<='Z') || (words[i]>='a' && words[i]<='z'))
        {
            ccount++;
        }
    }
    cout<<"Vowels: "<<vcount<<", Consonants: "<<ccount<<endl;
}

int number_of_words(char words[]){
    int word_count=0;
    for(int i=0;words[i]!=0;i++){
        if(words[i]==' ' && words[i-1]!=' ' && i!=0){
            word_count++;
        }
    }
    return word_count+1;        //+1 since there are 'n+1' words for 'n' no. of spaces
}

int main(){
    char words[] = " How are you   doing?";
    count_vowels_consonants(words);
    cout<<number_of_words(words)<<endl;
}