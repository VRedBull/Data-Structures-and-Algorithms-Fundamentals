# Strings

Read introduction/basics to strings and char arrays in Pointers part 2 module, Or in DSA hand written notes.



## Operations on Strings

### Length of a String

- We can count the length of a string by using a loop.

- We use a while loop, start from the 0th index and increment the counter until reaching '\0')

  Here's the Code

  ```c++
  int length_of_string(char x[]){
      int i=0;
      while(x[i]!='\0'){
          i++;
      }
      return i;
  }
  
  int main(){
      char name[] = "Vikas Pradhan";
      cout<<"Length of name: "<<length_of_string(name);
  }
  //output
  Length of name: 13
  ```




### Changing Cases in a String

- We can make a string change it's case.

- If it's lower case we'll make it Uppercase and vice-versa.

- To do this we have to use ASCII code (or their equivalent characters).

- We can iterate through the whole string and use a if else statement for each character and use condition if it's between lowercase characters then decrease it by 32 and if it's between uppercase characters then increase it by 32.

  Here's the code

  ```c++
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
  
  //output
  vIKaS pRAdHAn
  ```

  Observe that all the lowercase are converted to uppercase and vice-versa.



### Counting words and vowels in a string

- This is Just a basic operation, we write condition if it's a vowel update the vowel counter same goes for consonants.

- And since no. of spaces + 1 = no. of words, we can count the no. of spaces and add one to it. We also have to skip count if there are multiple space between words.

  Here's the code

  ```c++
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
  
  //output
  Vowels: 7, Consonants: 7
  4
  ```



### Checking a Username/password have a valid string or not

- We can check whether a password given by user is valid or not, by checking for special characters and spaces in between if they contain those special characters then they're invalid otherwise valid.

  Here's the code

  ```c++
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
  
  //output
  Vikas?Pradhan is a Invalid String	//since the string contains a '?' which is a special char
  VivaanPradhan is a Valid String
  ```



### Reversing an string

- Reversing an string is pretty much like reversing a array, since it's just an array of characters.

- We have two methods for reversing.

  1. **Reverse using two arrays** - This will involve copying elements of given array to another array in reverse order and then it back in straight order, so this will reverse the order.
  2. **Reversing the array by swaping elements** - This will swap the first and last element, then the 2nd and 2nd-last element and so on.

  Here's the code for both methods

  ```c++
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
  
  //output
  desreveR
  Reversed
  ```



### Comparing Strings and palindrome

- We can compare strings for if they are equal, or if one comes after another in dictionary using ASCII codes.

- Then we can we can check if a string is a palindrome. 

- A string is palindrome is when we reverse the string the string remain the same.

- We can do this by Copying the elements from a given string and pasting it on another string in reverse order, then checking if the elements are same in both the strings. If they're same then they are palindrome, otherwise not palindrome.

  Here's the code

  ```c++
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
  
  //output
  Painting is greater than Painter
  Reversed string: MadaM
  MadaM: String is palindrome
  Painting is not a palindrome string
  ```



### Finding duplicates in a string

- We can find duplicates in a string similar to how we found duplicates in integer arrays.

  We have three methods here

  1. Comparing with other letters
  2. Using a hash table as a count
  3. Using bits

- **Comparing with other letters** - In this method we compare each letter with every other element of the string, if we have once compared it with one element we make it as '0' char.

- **Using a hash table as a count** - We can use a hash table as a count and update the index in hash array whenever we encounter a char of same ASCII code as the hash index.

  Here's the code

  ```c++
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
  
  //output
  i has occurred 2 times.
  n has occurred 2 times.
  
  a has occurred 3 times
  n has occurred 2 times
  A has occurred 2 times
  P has occurred 2 times
  ```

- **Using Bits** - Watch Abdul bari video for this. He have use bit masking and merging for checking duplicates.



### Checking if strings are anagram

Two strings are anagram when all alphabet of both strings are same, just they're in different orders.

- We can check if two strings are anagram or not, by comparing each element of 1st string to every element of 2nd string until we reach the last element. 

  If we found all elements of 1st string are present in 2nd string then the strings are anagram. 

  But, if we don't find the char of 1st string in 2nd string before reaching the end of 2nd string then the strings are not Anagram.

- 2nd method, is by using hash array. We can create a hash array and increment every respective hash array by one for the corresponding element of the given 1st string (by reducing 97 since we are only doing for small numbers). Just like we updated while finding duplicates in string.

  Then after updating all the elements in hash array, we can check if all elements of 2nd string are present or not in the corresponding index of hash array(reduced by 97).

  Here's the code for both

  ```c++
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
  
  //output
  Checking angram strings for: decimal and medical
  Strings are anagram.
  
  Checking angram strings for: listen and silent
  Strings are anagram
  ```

  

Permutation of string (using backtracking, recursion, brute-force) - watch the abdul bari video for this.