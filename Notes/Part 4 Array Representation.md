# Array Representation

- Array is just storing a list of elements under one name.

- We can access different elements in the array using index number.

- Array memory is continuous.

- Array declaration

  ```c++
  int A[5];		//here we created a array of 5 elements in stack
  int B[n];	//where n=size of array given by the user, this can be only done in c++ and not in c
  ```

- Array initialization

  ```c++
  int A[4] = {2,1,5,2};	//Declared and assigned values to array
  int B[10] = {2,3};		//Declared and assigned only first 2 elements, rest will be initialized as 0
  int C[] = {48,11,29,73,3};  //When we directly initialize the elements in an array we don't need to specify 							//it's size in c++
  ```

- To access all the values of the array, we have to iterate it using a loop.

  ```c++
  int A[5] = {22,3,1,10,-2};
  for(int i=0;i<5;i++){
  	cout<<A[i]<<endl;
  }
  //can also do it using a for each loop
  for(int i:A){
      cout<<i<<endl;
  }
  ```

- Array size cannot be changed, since it's a occupies a continuous memory location we cannot predict if the next memory location is going to be free or not.

- But we might use **realloc()** from C to allocate a different memory location to the array and copy the elements from the previous location and paste it on the new memory location. We can also do this thing manually.

  To change the size of a array we can follow this code

  ```c
  int main()
  {
       int *p,*q;
       int i;
       p=(int *)malloc(5*sizeof(int));
       p[0]=3;p[1]=5;p[2]=7;p[3]=9;p[4]=11;
  
       q=(int *)malloc(10*sizeof(int));
  
       for(i=0;i<5;i++)
       	q[i]=p[i];
  
       free(p);
       p=q;
       q=NULL;
  
       for(i=0;i<5;i++)
       	printf("%d \n",p[i]);
  
       return 0;
  }
  ```

  

## Dynamic arrays

- Dynamic arrays are those arrays which are allocated memory in heap.

- Heap memory cannot be accessed directly, we have to use pointers to access heap.

- To access heap memory in C++, we need to use **new** operator and in C we need to use **malloc or calloc**.

  In C++,

  ```c++
  int *p;
  p = new int[5];
  //or
  int *q = new int[6];    
  p[1] = 4;
  *(q+2) = 6;		//q[2]
  ```

  In C,

  ```c++
  int *p = (int*)malloc(sizeof(int)*5);
  int *q = (int*)calloc(sizeof(int),5);		//this will initialize the whole array with 0
  ```

- After we use the dynamically created array, we must delete/free the allocated memory. 

  In C++

  ```c++
  delete []p;
  ```

  In C,

  ```c
  free(p);
  ```

  If we do not delete the unused allocated memory in heap it'll cause **memory leak.**



## 2D arrays

- 2D arrays are multidimensional arrays, which help us use it as a table with rows and columns.

- But the memory allocated to it is linear and not multidimensional.

- There are 4 different ways in which we can represent 2D-arrays.

  **Way 1** - Simplest array declaration, with memory inside stack.

  ```c++
  int A[3][4] = {			//this 2D array have 3 arrays with each length 4
  	{
  		1,2,3,4
  	},{
  		5,6,7,8
  	},{
  		9,10,11,12
  	}
  };		
  
  //We can print each element using a nested for loop
  for(int i=0;i<2;i++){
      for(int j:A[i])
          cout<<j<<" "<<flush;
      cout<<endl;
  }
  ```

  **Way 2** - Simplest way to create array in heap.

  ```c++
  int (*A)[3] = new int[2][3];    
      
      int x = 1;
      for(int i=0;i<2;i++){
          for(int j=0;j<3;j++){
              *(*(A+i)+j)=x;
              x++;
          }
      }
      for(int i=0;i<2;i++){
          for(int j=0;j<3;j++){
              cout<<*(*(A+i)+j)<<" "<<flush;
          }
          cout<<endl;
      }
  //output
  1 2 3 
  4 5 6
  ```

  **Way 3** - Creating an array of pointers in stack, and each of those pointers will create a dynamic array.

  ```c++
  	int *A[3];    //three pointers in array
      A[0] = new int[4];      //each pointer creating a array in heap
      A[1] = new int[4];
      A[2] = new int[4];
  
  //assinging values to those array elements
      int x=1;
      for(int i=0;i<3;i++){
          for(int j=0;j<4;j++){
              A[i][j] = x;
              x++;
          }
      }
  
  //printing out the values of the arrays
      for(int i=0;i<3;i++){
          for(int j=0;j<4;j++){
              cout<<A[i][j]<<" "<<flush;
          }
          cout<<endl;
      }
  ```

  This can be visualized here <img src="D:\Programming\Programming fundamentals\Data structures and algorithms fundamentals\Notes\2D arrays.JPG" style="zoom:70%;" />

  **Way 4** - Creating a double pointer in stack, which will point to array of pointers in heap those pointers in heap will create dynamic arrays.

  ```c++
   int **C;		//double pointer declaration
  
   C=(int **)malloc(3*sizeof(int *));
   C[0]=(int *)malloc(4*sizeof(int));
   C[1]=(int *)malloc(4*sizeof(int));
   C[2]=(int *)malloc(4*sizeof(int));
  
   for(i=0;i<3;i++)
   {
       for(j=0;j<4;j++)
       	printf("%d ",C[i][j]);
   printf("\n");
   }
  ```



## Array representation in compiler

### 1D array representation in compiler

- Machine code refers to address location and not by a variable name, and the address is given to it by compiler.

- Memory for variable is allocated during execution time, then how will the compiler know the address at compile time.

- This issue is what we will look into in the context of arrays.

- When we want to access a specific element in a array, say A[3]... then this line of code will be converted to machine code (compiler converts it to machine code) and reffered to it by address... and address is allocated at run-time and not during compile time.

- Compiler will not know the address before hand so it can convert it to machine code.

- **So the compiler will use a generalized formula** to obtain that address.

- Suppose the base address of array (address of 1st element) = Lb, 

  index = i,

  sizeof(data_type) = w

  Then using these we can formulate, given an array A...we need to access the 'i'th element, then the formula used by compiler

  **address(A[ i ]) = base_address + (index * sizeof(data_type) )**

  **address(A[ i ]) = Lb + ( i * w)**

  **Note** - this formula is valid for only those programming languages whose array indexes starts from 0, if array index stated from 1 or any other number then we have to subtract / change the index 'i'. Some old programming lang. had index starting from 1.

### 2D array representation in compiler

- We think of 2D array as a table with rows and columns.

- But the memory allocation is linear in memory.

- So similar to the 1D array 2D array also have a generalized formula for compilers to use to obtain address at compile time.

- The formula used by compiler can be divided into 2 parts **Row Major and Column Major**

- **Row Major** 

  In this the linear memory is divided between rows as per array size

  this can be visualized here<img src="D:\Programming\Programming fundamentals\Data structures and algorithms fundamentals\Notes\Row major.JPG" style="zoom:70%;" />

  - Suppose a array with m*n elements (m=rows, n=columns), A [ m ] [ n ]

    and from this array we want to access element A [ i ] [ j ], then the formula will be

    **address(A [ i ] [ j ]) = base_address + ( i * n + j ) * sizeof(data_type)** 

    **address(A [ i ] [ j ]) = Lb + ( i * n + j ) * w**

- **Column Major**

  For Column Major the elements of the 2D array are mapped on a 1D linear memory column-by-column.

  This can be visualized here<img src="D:\Programming\Programming fundamentals\Data structures and algorithms fundamentals\Notes\Column major.JPG" style="zoom:70%;" />

  - Suppose a array with m*n elements (m=rows, n=columns), A [ m ] [ n ]

    and from this array we want to access element A [ i ] [ j ], then the formula will be

    **address(A [ i ] [ j ]) = base_address + ( j * m + i ) * sizeof(data_type)** 

    **address(A [ i ] [ j ]) = Lb + ( j * m + i ) * w**

- Here we can see that same number of operations are done in both row major or column major, so both of them are equally efficient.

  So, a compiler may choose follow from any of them.



### nD array representation in compiler

- Just like we have a general formula for 2D arrays we can have a formula for 4D arrays or nD arrays.

- First, we will consider the general formula for 4D arrays.

- **Row Major of 4D**

  Consider an array A [ d1 ] [ d2 ] [ d3 ] [ d4 ]

  the formula is 

  **address(A [ i1 ] [ i2 ] [ i3 ] [ i4 ]) = base_address + [ (i1 * d2 * d3 * d4) + (i2 * d3 * d4) + (i3 * d4) + (i4) ] * sizeof(data_type)**
  
  **Note** - In row major formulae we go from left to right ( i1 -> i4 ) and then multiply from the next dimension (like for i1 multiply from d2 to d4, then for i2 multiply from d3 to d4 and so on).
  
  We can generalize the above formula for nd arrays using mathematical symbols
  
  <img src="D:\Programming\Programming fundamentals\Data structures and algorithms fundamentals\Notes\nd arrays row major.JPG" style="zoom:60%;" />
  
- **Column Major of 4D**

  Consider an array A [ d1 ] [ d2 ] [ d3 ] [ d4 ]

  the formula is 

  **address(A [ i1 ] [ i2 ] [ i3 ] [ i4 ]) = base_address + [ ( i4 * d1 * d2 * d3 ) + (i3 * d1 * d2) + (i2 * d1) + (i1) ] * sizeof(data_type)**

  **Note** - In Column major formulae we go from right to left ( i4 -> i1 ) and then multiply from the first dimension and leave from the last dimension of 'i' number (like for i4 multiply from d1 to d3 and leave d4, then for i3 multiply from d1 to d2 and leave from d3 so on).

### Horner's Rule 

But this multiplication will give us O(n^2) time complexity which is very time consuming.

We can reduce this time consuming process by using **Horner's Rule**.

In Horner's rule we just take common multiplications outside in a bracket thereby reducing the number of multiplications...like this

Consider all the multiplications in Row major of 4D arrays... there are total 6 multiplication operation by using horner's rule we reduce it to only 3 multiplication <img src="D:\Programming\Programming fundamentals\Data structures and algorithms fundamentals\Notes\horner rule row major 4d.JPG" style="zoom:50%;" />

Now the time complexity is only O(n).



### 3D arrays row major and column major

<img src="D:\Programming\Programming fundamentals\Data structures and algorithms fundamentals\Notes\3D row major and column major.JPG" style="zoom:67%;" />

- **row major**

  **address(A [ i ] [ j ] [ k])= base_address + [ ( i * m * n ) + ( j * n ) + ( k ) ] * sizeof(data_type)**

  **column major**

  **address(A [ i ] [ j ] [ k]) = base_address + [ ( k * l * m ) + ( j * l ) + ( i ) ] * sizeof(data_type)**