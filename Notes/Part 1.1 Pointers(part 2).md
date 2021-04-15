# Pointers (part 2)



## Pointer to Pointer

- Pointers are used to store the address of another variable and point to the value of that variable.

- Similarly, we store the address of another pointer in a double pointer (**p).

- **p this type of double pointer will store the address of the pointer it's pointing to and point to the value inside the pointer it's pointing to.

- Similarly, for triple pointer which will be used to point to double pointers.

- For eg.

  ```c++
  #include<iostream>
  using namespace std;
  
  int main(){
      int x = 10;
  
      int *p;
      p=&x;
      
      int **q;     //Double pointer is required to store the address of another pointer
      q=&p;
  
      int ***r;    /*triple pointer is required to store the address of a pointer which is also pointing to*/ 	r=&q;		//another pointer
      
  
      cout<<"Address stored in p = "<<p<< " Value pointed by p = "<<*p<<endl<<endl;     //Address of x and value 																				 //in x
      cout<<"Address stored in q = "<<q<< " Value pointed by q = "<<*q<<endl;     //Address of p and value in 																		//p(i.e.Address of x)
      cout<<"Accessing value pointed by p = "<<*(*q)<<endl<<endl;
  
      cout<<"Address stored in r = "<<r<< " Value pointed by r = "<<*r<<endl;     //Address of q and value in 																		//q(i.e.Address of p)
      cout<<"Accessing value pointed by q = "<<*(*r)<<endl;                       //Addess of x                
      cout<<"Accessing value pointed by p = "<<*(*(*r))<<endl;                    //Value of x
  	
      *(*q) = 12;
      cout<<"Changing value of x using double pointer = "<<x<<endl;
  
      *(*(*r)) = 14;
      cout<<"Changing value of x using triple pointer = "<<x<<endl;
  }
  
  //output
  Address stored in p = 0x61ff08 Value pointed by p = 10
  
  Address stored in q = 0x61ff04 Value pointed by q = 0x61ff08
  Accessing value pointed by p = 10
  
  Address stored in r = 0x61ff00 Value pointed by r = 0x61ff04
  Accessing value pointed by q = 0x61ff08
  Accessing value pointed by p = 10
  
  Changing value of x using double pointer = 12
  Changing value of x using triple pointer = 14
      
  
      //Explanation of above code
  /*
     Address          202         201        200           
     ***r[202]---> **q[201]---> *p[200]---> x[10]    
  
        p = 200
        *p = 10
  
        q = 201
        **q = 200                 We can say *(*q) or **q
  
        r = 202
        ***r = 201                We can say *(*(r)) or ***r
  */
  ```




## Pointers and arrays

- Pointers can also be used to do operations in arrays.
- Pointer Arithmetic makes sense in Arrays.
- When we increment or decrement the pointer to next location we actually point to the next / pre. element of the array.
- For eg. Different ways to use pointers on arrays are shown below

```c++
#include<iostream>
using namespace std;

int main(){
    int A[] = {2,4,8,5,1};

    int range = sizeof(A)/sizeof(int);
    
    int *p;
    p = &A[0];		//So, now p will point to 0th index of A array

    int *q = A;		//This will make q point to the 0th index of A array
	
    //Different ways of accessing the 1st index address
    cout<<&A<<endl;
    cout<<A<<endl;
    cout<<p<<endl;
    cout<<q<<endl<<endl;
	
    //Different ways of fetching the value at 0th index of the array
    cout<<A[0]<<endl;
    cout<<*A<<endl;
    cout<<*p<<endl;
    cout<<*q<<endl<<endl;
	
    //Ways of Accessing the next location of the array
    cout<<A[1]<<endl;
    cout<<*(A+1)<<endl;
    cout<<*(p+1)<<endl;
    cout<<*(q+1)<<endl<<endl;
	
    //Using for each loop to traverse through the whole array
    for(int x: A)
        cout<<x<<" "<<flush;
    
    cout<<endl<<endl;

    //For loop for accessing the whole array
    for(int i=0; i<range; i++){
        cout<<A[i]<<" "<<*(A+i)<<" "<<*(p+i)<<" "<<*(q+i)<<endl;
    }
}

//output
0x61fedc
0x61fedc
0x61fedc
0x61fedc

2
2
2
2

4
4
4
4

2 4 8 5 1 

2 2 2 2
4 4 4 4
8 8 8 8
5 5 5 5
1 1 1 1
```



## Arrays as function arguments

- We can also pass arrays as actual parameters to functions.
- But when we pass an array, we actually just pass the address of the 0th index of the array.
- Because we now have a pointer to the array, we can now modify the values of the array from the function.

for eg.

```c++
#include<iostream>
using namespace std;

//two different ways of receiving array as parameter

int SumArrayA(int A[],int size){
    int sum=0;
    for(int x=0;x<size;x++)
        sum+=A[x];
    return sum;
}

int SumArrayB(int* B, int size){        //Same as formal parameter 'B[]'
    int sum=0;
    for(int x=0;x<size;x++)
        sum+=*(B+x);        //same as 'B[x]'
    return sum;
}

//changing the values of array from the function using pointers

void doubleArray(int* A, int size){         //Since these are pointers to the array
    for (int i=0;i<size;i++){               //we can also modify the values of array
        *(A+i)*=2;
    }
}

int main(){
    int A[]= {2,3,4,5,6,7};
    int sizeA = sizeof(A)/sizeof(int);
    int totalA = SumArrayA(A,sizeA);
    cout<<totalA<<endl;

    int B[] = {1,2,3,4,5};
    int sizeB = sizeof(B)/sizeof(int);
    int totalB = SumArrayB(&B[0],sizeB);       //Same as passing 'B'
    cout<<totalB<<endl;

    doubleArray(&B[0],sizeB);
    for(int x:B)
        cout<<x<<" ";
    
}

//output
27
15
2 4 6 8 10
```



## Character arrays and pointers

- Character arrays in C/C++ require a null char ( **'\0'** )at the end of the array.
- So when we want to make a char array of 5 elements, we actually create a array of 6 index and store the null char ( '\0' ) at the end of the array.
- The null char let's the compiler know where the array has to end.
- And as we already know when we pass a array to a function we actually pass the address of the 0th index of the array, so same is true for char array.

An example of char array

```c++
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

//output
VIKAS
Size of char array = 5
Actual size of char array including the null char = 6

Vivaan Size of char array = 6
Actual size of array including the null char = 7

VIKAS PR Size of char array = 8
Actual size of array including the null char = 9
VIKAS
Vivaan
VIKAS PR
```



### const  char pointer

- When we want something to not change we declare it constant.

- So, when we pass the char array to a function and we want that function to not change the values then we can use **const pointer**.

- The const won't allow to change the values of the array.

- Now will only read the char array and cannot modify it.

  for eg.

  ```c++
  #include<iostream>
  using namespace std;
  
  void cons(const char* c){
      // *c = 'A';        //cannot change a value from the array as we are using a const pointer
      int i=0;
      while(*(c+i)!='\0'){
          cout<<*(c+i)<<flush;
          i++;
      }
      cout<<endl;
  }
  
  int main(){
      char c[] = "Hello";
      cons(c);
  }
  
  //output
  Hello
  ```

  

## 2D array and pointers

- We can also use pointers for 2D arrays just like we use them for 1D arrays.

- If array is like

  ```c++
  int A[i][j] = {....};
  ```

- The pointer for 2D array is 

  ```c++
  int (*p)[j] = A;
  ```

- Here, the pointer points to Arrays of length j.

- For eg.

  ```c++
  #include<iostream>
  using namespace std;
  
  int main(){
  
      int A[2][3]={
          {2,3,5},
          {6,7,8}
      };
  
      int (*p)[3]=A;          //Standard Syntax for 2D arrays pointers initialization
  
  
      //Different ways to print addresses
  
      cout<<p<<endl;
      cout<<*p<<endl;
      
      cout<<A<<endl;
      cout<<*A<<endl;
      cout<<A[0]<<endl;
      cout<<&A[0]<<endl;
      cout<<&A[0][0]<<endl;
  
      cout<<p+1<<endl;
      cout<<*(p+1)<<endl;
  
      cout<<A+1<<endl;
      cout<<*(A+1)<<endl;
      cout<<A[1]<<endl;
      cout<<&A[1]<<endl;
      cout<<&A[1][0]<<endl;
  
      cout<<*(A+1)+1<<endl;
      cout<<*(p+1)+1<<endl;
      cout<<A[1]+1<<endl<<endl;
  
      //Differenet ways to get the values from array
  
      cout<<*(*p)<<endl;
      cout<<*(*A)<<endl;
      cout<<*(A[0])<<endl;
      cout<<*(*(&A[0]))<<endl;
      cout<<*(&A[0][0])<<endl;
      cout<<A[0][0]<<endl;
  
      cout<<*(*p+1)<<endl;
  
      cout<<*(*(p+1))<<endl;
      cout<<*(*(A+1))<<endl;
      cout<<*(A[1])<<endl;
      cout<<*(*(&A[1]))<<endl;
      cout<<*(&A[1][0])<<endl;
      cout<<A[1][0]<<endl;
  
      cout<<*(*(p+1)+1)<<endl;
  
  }
  
  //output
  0x61fef4
  0x61fef4
  0x61fef4
  0x61fef4
  0x61fef4
  0x61fef4
  0x61fef4
  0x61ff00
  0x61ff00
  0x61ff00
  0x61ff00
  0x61ff00
  0x61ff00
  0x61ff00
  0x61ff04
  0x61ff04
  0x61ff04
  
  2
  2
  2
  2
  2
  2
  3
  6
  6
  6
  6
  6
  6
  7
  ```

  

But Some standard Ways to get values and addresses using pointers are

```c++
    int A[i][j] = {};
    int (*p)[j]=A;

   	//here consider, i=row, j=column

    //for values
    A[i][j] = *(*(p+i)+j)  or  *(*(A+i)+j)  or *(A[i]+j)        

    //for addresses
    &A[i][j] = *(p+i)+j  or  *(A+i)+j  or  A[i]+j

```

**Note** - Just remember the standard notations above.



## Pointers and multidimensional arrays

- As we can use pointers on 2D arrays, similarly we can use pointers on 3D or multi-dimensional arrays.

- If array is like...

  ```c++
  int A[i][j][k] = {{{},{}}{{},{}}};
  ```

- The we have to initialize the pointer like this...

  ```c++
  int (*p)[j][k] = A;
  ```

- We can also use some of these below give standard formulae to get access values and addresses form the arrays

  ```c++
   int A[i][j][k] = {...};
  
      int (*p)[j][k] = A;
  
      for value
      A[i][j][k] = *(*(*(p+i)+j)+k)  or  *(*(*(A+i)+j)+k)  or  *(*(A[i]+j)+k)
  
      for address
      &A[i][j][k] = *(*(p+i)+j)+k  or *(*(A+i)+j)+k  or  *(A[i]+j)+k
  ```

- Some examples are given below.

  ```c++
  #include<iostream>
  using namespace std;
  
  int main(){
  
      int A[3][2][2] = {
          {
              {2,3},
              {4,5}
              },
          {
              {6,71},
              {7,8}
              },
          {
              {9,0},
              {10,11}
              }
      };
  
      int (*p)[2][2] = A;              //Initializing an 3D array
  
      cout<<*(*(*(A+2)+1)+1)<<endl;           //Value at A[2][1][1]
      cout<<*(*(A[2]+1)+1)<<endl;             
      cout<<*(A[2][1]+1)<<endl;               
      cout<<A[2][1][1]<<endl;
  
      cout<<A[2][1]<<endl;                //Address of A[2][1][0]
      cout<<*(*(*(A+2)+1))<<endl;         //value of A[2][1][0]
      cout<<*(*(*A+1))<<endl;             //Value of A[0][1][0]
      cout<<*A+1<<endl;                   //Address of A[0][1][0]
  }
  
  //output
  11
  11
  11
  11
  0x61ff04
  10
  4
  0x61fee4
  ```

  

## Passing Multi-Dimensional Arrays as parameters to functions

- Just like we pass can an 1D array to a function, similarly we can pass a 2D or 3D array to a function.

- When we pass an Array to a function, we can pass it like this....

  ```c++
  void fun(int A[][]){
  };
  
  int main(){
  	int A[][] = {...};
  	fun(A);
  }
  ```

- But the above is just a sugar coated syntax, we never actually pass the whole array to the function.

- We actually just pass a address as actual parameter to the pointer in the formal parameter of the function. like this...

  ```c++
  void fun(int (*p)[j]){
  };
  
  int main(){
  	int A[i][j] = {...};
  	fun(A);
  }
  ```

- Some examples of passing 2D and 3D arrays are...

  ```c++
  //Program to display the 2D and 3D arrays using functions and pointers
  
  #include<iostream>
  using namespace std;
  
  /*
  for sugarcoating the compiler will accept the syntax as
  
  void display(A[][]){
  }
  OR
  void display(A[][][]){
  }
  
  But actually we pass the address of the 1st element of the array and in the formal parameter of the function 
  we receive it in the pointer.
  */
  
  void display(int (*p)[3], int size, int elements){
  
      for(int i=0; i<size; i++){
          for(int j=0; j<elements; j++){
              cout<<*(*(p+i)+j)<<" "<<flush;
          }
          cout<<endl;
      }
  }
  
  void display(int (*p)[2][3]){
      for(int i = 0; i<3; i++){
          for (int j = 0; j<2; j++){
              for(int k=0;k<3;k++){
                  cout<<*(*(*(p+i)+j)+k)<<" "<<flush;
              }
              cout<<endl;
          }
          cout<<endl;
      }
  }
  
  int main(){
      int A[2][3] = {
          {1,2,3},
          {4,5,6}
      };
  
      int sizeArray = sizeof(A)/sizeof(A[2]);
      int elements = sizeof(A[2])/sizeof(int);
      display(A,sizeArray,elements);
  
      cout<<"-------------------------------"<<endl;
      int B[3][2][3] = {
          {
             {1,2,3},{4,5,6} 
          },
          {
              {7,8,9},{10,11,12}
          },
          {
              {13,14,15},{16,17,18}
          }
      };
  
      display(B);
  
  }
  
  //output
  1 2 3 
  4 5 6
  -------------------------------
  1 2 3
  4 5 6
  
  7 8 9
  10 11 12
  
  13 14 15
  16 17 18
  ```

  



# Dynamic Memory in C/C++

**Memory Structure in computer**

<img src="D:\Programming\Programming fundamentals\Data structures and algorithms fundamentals\Notes\Computer memory structure.JPG" style="zoom:70%;" />

When we talk about computer's memory we generally talk about the RAM.

So the memory is divided into typically 4 sections. Namely,

1. Heap
2. Stack
3. Static/global
4. Code(Text)

1. **Code (Text)** - The code section basically will have the machine code instructions to be executed in it.

2. **Static/Global** - This section will generally comprise of the Global or static variables which will remain throughout the life-time of the program.

3. **Stack** - Stack section is where all the function calls and Local variables are stored.... **Call stack is stored here.** 

   - **Call stack** is basically all the functions calls.

   - The function which is at the top of the stack are currently being executed.

   - Once the function ends all the memory of that function is automatically deallocated from the stack, including the local variables of the function.

   - Each block of memory allocated for the function is stack-frame of that particular function.

   - After that the function below it starts it's execution.

   - For eg.

     <img src="D:\Programming\Programming fundamentals\Data structures and algorithms fundamentals\Notes\Call stack.JPG" style="zoom:50%;" />

   - From the picture above we can see that currently **square()** method is executing.

   - After the execution of **square()** method the memory is deallocated from stack.

   - And stack looks something like this.

      <img src="D:\Programming\Programming fundamentals\Data structures and algorithms fundamentals\Notes\Call stack 2.JPG" style="zoom:40%;" />

   - So, this process of allocation and deallocation is repeated until program is over.
   - The global section is cleared after the program is over.
   - When our call stack grows beyond the reserved memory for the stack, then this is called **StackOverflow**.
   - StackOverflow causes programs to crash. One eg. of StackOverflow is bad recursive function, and program goes to infinity.

   

4. **Heap** - Unlike other types of memory heap can vary in size during the life-time of the program. 

   - And also unlike stack there are no set rules for allocation and deallocation in heap.

   - The programmer have to manually allocate and deallocate the memory in heap.

   - Heap memory is virtually unlimited memory for a programmer's perspective.

   - Heap is also called dynamic memory, and using heap is referred to as dynamic memory allocation. 

   - We use **new** and **delete** to operate in heap memory using C++.

   - We can only access the heap using pointers.

   - When we create pointer, memory for pointer is allocated in stack, then using pointer we point to free up a certain size of heap memory. like this...

     ```c++
     int (*p);		//pointer p is now on stack
     p = new int;	//pointer have created space for an integer(4 bytes)
     *p = 10;		//the heap now have this value of 10
     ```

     A pictorial representation

     <img src="D:\Programming\Programming fundamentals\Data structures and algorithms fundamentals\Notes\Heap memory 1.JPG" style="zoom:50%;" />

   - Now if continue our program and assign the pointer variable a new int space in heap, without deleting the previous one which will look something like this....

     ```c++
     	int (*p);
         p = new int;
         *p = 10;
     
         p = new int;		//without deleting the last memory of heap created a new one
         *p=20;
     ```

     A pictorial representation <img src="D:\Programming\Programming fundamentals\Data structures and algorithms fundamentals\Notes\Heap memory 2.JPG" style="zoom:50%;" />

   - Now this is a waste a memory, so to avoid this we should always delete the memory allocated to it then re-use it again, like this...

     ```c++
     	int (*p);
         p = new int;
         *p = 10;
     	
     	delete p;		//this will free up the allocated space in heap 
     	
         p = new int;		
         *p=20;
     ```

   - A pictorial representation of heap memory after deleting p <img src="D:\Programming\Programming fundamentals\Data structures and algorithms fundamentals\Notes\Heap memory 3.JPG" style="zoom:50%;" />

   

   **Arrays in Heap memory**

   - Arrays can also be created in heap memory.

   - We can pass the no. of elements we want in the array.

   - So that accordingly the compiler will allocate the specific size as a continuous block of memory in heap for array. And the pointer will point to the starting address (base address) of the array.

   - We can do it like this...

     ```c++
     int (*p);
     p = new int[20];	//now we have allocated 20 int size of continous block of memory in heap for an array
     
     //Now we allocate values like this...
     *(p+0) = 1;
     *(p+1) = 2;
     p[2] = 3;
     p[3] = 4;
     
     //after we are done with the array... we delete it 
     delete []p;
     ```

     A pictorial representation of memory <img src="D:\Programming\Programming fundamentals\Data structures and algorithms fundamentals\Notes\Heap memory 4 arrays.JPG" style="zoom:50%;" />

## Dynamic memory allocation in C

Similar to C++ we can do dynamic memory allocation using 4 keywords in C.

1. **malloc**
2. **calloc**
3. **realloc**
4. **free**

We can also these same keywords in C++, as C++ have backwards compatibility.

1. **malloc** - is used to assign space in heap, we can do it like this...

   ```c++
   int (*p) = (int*)malloc(sizeof(int));		//here we assigned free space in heap to pointer
   *p = 5;				//can assign like this
   ```

   Since, originally **malloc is void pointer**, **we have to typecast it** to the type of data we want to assign.

   We can also make arrays using mallocs 

   ```c++
   int *p = (int*)malloc(10*sizeof(int));      //just multiply sizeof(int) to the no. of elements we want in array
   
   // Can assign the values like this
   *p = 1;
   *(p+1) = 2;
   p[2] = 3;
   ```

2. **calloc** - calloc function is quite similar to malloc but it takes 2 arguments instead of one.

   - It takes no. of elements and the size of each element.
   - Also, calloc **initializes all the values with 0**, malloc does not initialize values so they have garbage values in them.

   We can use calloc like this

   ```c++
   int (*p) = (int*)calloc(2, sizeof(int));	
   
     // *p = 2;    if we do not initialize it then it's going to be 0
     *(p+1) = 3;
     *(p+2) = 4;//since these are just pointers we can also access the next address beyond the array specific size
     p[3] = 5;
   
       for(int x=0;x<4;x++)
           cout<<*(p+x)<<" "<<flush;
   
   //output
   0 2 4 5
   ```

3. **realloc** - realloc as the name suggests is just basically changing the size of memory that already allocated, and assigning it to a new pointer.

   - We may increase/decrease the size of a array.

   - It may create a whole new space for the array and copy and paste the elements into the new space. Or it will just extend or decrement the memory of that same space. These things will vary for different machines and compilers.

   - Here's an example where we extend the array, while the base address remains the same.

     ```c++
     //Dynamically created a array
     int (*p) = (int*)calloc(4, sizeof(int));
     
         *p = 2;
         *(p+1) = 3;
         *(p+2) = 4;
         p[3] = 5;
     
         for(int x=0;x<4;x++)
             cout<<*(p+x)<<" "<<flush;
         cout<<endl;
         
         cout<<"Base Address of the array =  "<<p<<endl;
     
     //-------------------------------------------------------------------------------------
     //Exented the dynamic memory of that array using realloc
     
         int (*q) = (int*)realloc(p,7*sizeof(int));
         
     	cout<<"Base Address of the array =  "<<p<<endl;
     
         for(int x=0;x<7;x++)
             cout<<*(p+x)<<" "<<flush;
     
     //output
     2 3 4 5 
     Base Address of the array =  0x727a48
     Base Address of the array =  0x727a48
     2 3 4 5 167772170 21787 7502120
     ```

     Since the base address of remained same after reallocation, it shows that we did not assigned a whole new memory space but it just extended the existing memory space.

   - Now, here's a example where we decrease the no. of elements in the array in heap.

     ```c++
     int (*p) = (int*)calloc(4, sizeof(int));
     
         *p = 2;
         *(p+1) = 3;
         *(p+2) = 4;
         p[3] = 5;
     
         for(int x=0;x<4;x++)
             cout<<*(p+x)<<" "<<flush;
         cout<<endl;
         
         cout<<"Base Address of the array =  "<<p<<endl;
         
         //--------------------------------------------------------
     
         int (*r) = (int*)realloc(p,2*sizeof(int));
         cout<<"Base Address of the array =  "<<p<<endl;
     
         for(int x=0;x<2;x++)
             cout<<*(p+x)<<" "<<flush;
     
     //output
     2 3 4 5 
     Base Address of the array =  0xf27a48
     Base Address of the array =  0xf27a48
     2 3
     ```

     Here also base address of the array remained the same and we just cut the array size.

4. **free** - this free() function is used to deallocate the allocated memory in heap. We can use it like **delete** in C++.

   We use it like this.

   ```c++
   int *p = (int*)malloc(3*sizeof(int));
   
   free(p);		//this will free up that memory
   ```

   It is very important to free up the memory after use, otherwise it'll remain in heap for life-time of the program and it's a waste of resources.



## Pointer as function returns

We can definitely return pointers, but we should not and here's why...

-  For eg.

  ```c++
  void printHellW(){
      cout<<"Hello world!"<<endl;
  }
  
  int* Add(int *a, int *b){
  
      int *p;
      *p=(*a) + (*b);
      return p;
  }
  
  int main(){
  
      int a = 2, b = 3;
  
      int (*p) = Add(&a,&b);	//after this line in call stack the of that function is cleared.
  						//now even though the *p have the address of that integer which was returned
  						//but there is no data in the address, since it was cleared by stack
      printHellW();
      
      cout<<*p<<endl;			//there's only garbage value in that address
  
  }
  
  //output
  Hello world!
  4199728
  ```

  For more clarity on this topic view - https://www.youtube.com/watch?v=E8Yh4dw6Diw&list=PL2_aWCzGMAwLZp6LMUKI3cc7pgGsasm2_&index=16&ab_channel=mycodeschool



## Calling function using pointers

We can call a function using a pointer. 

- Function in a stack occupies some memory, as function gets a continuous block of memory.

- The base address / entry point address of the function is where the pointer will point to.

- We can assign and call like this...

  ```c++
  #include<iostream>
  using namespace std;
  
  void printHW(){
      cout<<"Hello world!"<<endl;
  }
  
  int add(int a, int b){
      return a+b;
  }
  
  int main(){
  
      int (*p)(int, int);
      p = &add;
      cout<<(*p)(2,3)<<endl;
  
      //2nd way of assigning and calling the function
      void (*q)();
      q = printHW;
      q();
  }
  
  //output
  5
  Hello world!
  ```

  

## 

## Memory leak 

Memory leak is caused when an memory is allocated in heap but is not deleted after use.

for eg.

```c++
#include <iostream>
using namespace std;

void functionHeap(){
    int (*A) = new int[5];
    for(int i = 0; i < 5 ; i++){
        *(A+i)=i+1;
    }
    cout<<"Address: "<<A<<endl;		//in heap it will give out different address each time
    for(int i = 0; i<5; i++){
        cout<<*(A+i)<<" "<<flush;
    }
    cout<<endl;

    delete []A;         //If we do delete the array of integers in heap then it'll cause memory leakage
}

void functionStack(){   
    int A[5];               //Since this array is created in stack it'll be deleted as soon as 
                            //function goes out of scope
    for(int i = 0; i < 5 ; i++){    
        *(A+i)=i+1;
    }
    cout<<"Address: "<<A<<endl;		//it may give the same address each time
    for(int i = 0; i<5; i++){
        cout<<*(A+i)<<" "<<flush;
    }
    cout<<endl;
}

int main(){
    string c;
    int x=0;

    while(x<10000){
        cout<<x<<endl;
        x++;
        functionHeap();
    }
    
}
```

As we can see if we do not add the line **delete []A** at the end of the **functionHeap()** then the integers of array will keep getting allocated but get not deallocated in heap and the memory taken by our program will keep on increasing with every **functionHeap()** call and it is what's called **memory leak**. 

But in **functionStack()** we create a array of integers in stack itself so, when the **functionStack()** goes out of scope the whole functions along with all it's variables are deallocated from the stack automatically.

**NOTE** - We can also try and run each function separately and observe the memory taken by our C++ program in the task manager. 