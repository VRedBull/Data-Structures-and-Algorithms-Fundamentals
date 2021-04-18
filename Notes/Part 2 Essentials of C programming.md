# Structure in C/C++

- A structure is a user defined data type in C/C++. Just like classes, but in structure all members are public by default.

- But unlike classes we can declare an array of objects for Structure.

- for eg.

  ```c
  #include<stdio.h>
  
  struct Rectangle
  {
      /* data */
      int length;
      int breadth;
      char name[20];
  };
  
  
  int main(){
      struct Rectangle r = {10,20,"Rectangle 1"};       //can declare an object like this and initialize values 													//like this   
      printf("length = %d, breadth = %d, name = %s\n",r.length,r.breadth,r.name);   //can also use the dot 																	//operator to assign or fetch values
  
      struct Rectangle D[10] = {             //And array of structure objects
          {1,2},{3,4},{5,6},{7,8}
      };
  
      for(int i=0;i<10;i++){
          printf("length = %d, breadth = %d\n",D[i].length,D[i].breadth);
      }
  }
  
  //output
  length = 10, breadth = 20, name = Rectangle 1
  length = 1, breadth = 2
  length = 3, breadth = 4
  length = 5, breadth = 6
  length = 7, breadth = 8
  length = 0, breadth = 0
  length = 0, breadth = 0
  length = 0, breadth = 0
  length = 0, breadth = 0
  length = 0, breadth = 0
  length = 0, breadth = 0
  ```



## Pointer to Structure

- We can also have pointers to objects of Structure. 

- So, there the pointers pointing to that object must be also the Structure data type.

- And then using pointers we can access the properties of Structure using the arrow operator.

- We can also create objects of Structures Dynamically. We have to use pointers for this.

- For eg.

  ```c++
  #include<iostream>
  using namespace std;
  
  struct Rectangle
  {
      /* data */
      int length;
      int breadth;
  };
  
  
  int main(){
      struct Rectangle r = {2,3};     
      struct Rectangle *p1 = &r;
  
      p1->length = 4;         //We can either use the arrow operator
      (*p1).breadth = 5;      //or use the dot operator but include the pointer in a bracket since the 
                              // dot operator have higher precedence than the asterisk 
      struct Rectangle *p2 = new Rectangle();		//Or use malloc/calloc
  
      Rectangle *p3 = new Rectangle();       //In C++ we treat Structure like classes and not have to 
                                              //mention struct everytime
  }
  ```

  

## Returning an array from a function

We can also return an array from a function.

For eg. 

```c++
#include<iostream>
using namespace std;

int* fun(int n){
    int (*p) = (int*)(calloc(sizeof(int),n));
    return p;
    delete []p;
}

int main(){
    int (*a) = fun(5);
    for (int i=0;i<5;i++)
        cout<<*(a+i)<<" "<<flush;
}
//output
0 0 0 0 0		//0 are the value of the elements since calloc initializes the array elements with 0
```



## Structure as Parameter

- We can also pass objects of Structure to an function.

- When the function is call by value then the structure's new object is created in that function, an all the values of passed objects are copied to object of function.

- Even if the Structure have an array, the whole array is also passed by value. 

- But when it's a Pass by address then it's just a pointer to that passed object, and we can access the properties of that object by arrow function.

  For eg.

  ```c++
  #include<iostream>
  using namespace std;
  
  struct Rectangle{
      int length;
      int breadth;
  
      int A[4];
  };
  
  //Call by Value
  int area(Rectangle r){
      return (r.length)*(r.breadth);
  }
  
  //Call by address
  int area(Rectangle *r){
      return (r->length)*((*r).breadth);
  }
  
  void changeLength(Rectangle *r,int length){
      r->length=length;
  }
  
  //Call by Reference
  // int area(Rectangle &r){
  //     return (r.length)*(r.breadth);
  // }
  
  //pass by value
  void accessArray(Rectangle r){      //here new object is created and values are copied to it.
      for(int i=0;i<4;i++)
          cout<<r.A[i]<<" "<<flush;
      cout<<endl;
  }
  
  int main(){
      Rectangle r = {10,5};
      changeLength(&r,11);
      cout<<area(r)<<endl;
  
      //Dynamic Object 
      Rectangle *r1 = new Rectangle();
      *r1={20,3};
      cout<<area(r1)<<endl;
  
      //when we pass an object of the struct we pass all the properties with it along with the arrays
      Rectangle r2 = {15,4,{1,2,3,4}};
      accessArray(r2);
      for(int i=0;i<4;i++)
          cout<<r2.A[i]<<" "<<flush;
  }
  //output
  55
  60
  1 2 3 4
  1 2 3 4
  ```



Grouping of Data is Structure, and grouping of instructions is function.



# Template in C++

- Template are used for generic data type. (i.e. when we want to use int,float or any other data type).

- For eg. If we created a class for addition and subtraction of 2 integer numbers, but now we want to do the same for double or float data type then we will have make a separate class for float or double.

- Here we can make the class as generic by using template, and use any type of data.

- For eg. here is a simple class for addition and subtraction  of integers only.

  ```c++
  #include<iostream>
  using namespace std;
  
  class Arithmetic{
      private:
      int a,b;
  
      public:
      Arithmetic(int a,int b);
      int add();
      int sub();
  };
  
  Arithmetic::Arithmetic(int a, int b){
      this->a=a;
      (*this).b=b;
  }
  
  int Arithmetic::add(){
      return a+b;
  }
  
  int Arithmetic::sub(){
      return a-b;
  }
  
  int main(){
      Arithmetic ar(10,5);
      cout<<ar.add()<<endl;
      cout<<ar.sub()<<endl;
  }
  //output
  15
  5
  ```

- But now to make it generic(i.e. make it template class), we have to do some changes like...

  ```c++
  #include<iostream>
  using namespace std;
  
  template<class T>     //This class T is only valid for the class block of code
  class Arithmetic{      //after the class bracket ends we have to define the template again for fucntion's body
      private:
      T a,b;
  
      public:
      Arithmetic(T a,T b);
      T add();
      T sub();
  };
  
  template<typename T>        //we can either use keyword 'class' or 'typename'
  Arithmetic<T>::Arithmetic(T a, T b){        //We have to pass the template parameter in '<>' before using the 											//class name
      this->a=a;
      (*this).b=b;
  }
  
  template<class T>
  T Arithmetic<T>::add(){
      return a+b;
  }
  
  template<typename T>
  T Arithmetic<T>::sub(){
      return a-b;
  }
  
  int main(){
      Arithmetic<int> ar(10,5);   //We have pass the template parameter, that what type of data you'll pass to 								//the class
      cout<<ar.add()<<endl;
      cout<<ar.sub()<<endl;
  
      Arithmetic<double> ar1(1.2,0.5);   //using the same generic class for int and double by just passing the 									//template data type
      cout<<ar1.add()<<endl;
      cout<<ar1.sub()<<endl;
  }
  //output
  15
  5
  1.7
  0.7
  ```

  

