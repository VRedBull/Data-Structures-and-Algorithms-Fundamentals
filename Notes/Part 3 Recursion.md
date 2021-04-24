# Recursion

- A function calling itself is called as Recursive function.

- When we call that function, there must be a base condition to terminate it. Otherwise, it'll run infinitely. 

- Example of Recursion, 

  ```c++
  #include<iostream>
  using namespace std;
  
  void fun1(int x){
      if(x>0){
          cout<<x<<endl;
          fun1(x-1);
      }
      // cout<<"End of fun "<<x<<endl;
  }
  
  void fun2(int x){
      if(x>0){
          fun2(x-1);
          cout<<x<<endl;
      }
  }
  
  int main(){
      fun1(3);
      cout<<endl;
      fun2(3);
  }
  //output
  3
  2
  1
  
  1
  2
  3
  ```

  In the above example, fun1() and fun2() were almost identical.

  Only difference, "cout" before calling itself in fun1() and in fun2() "cout" after calling itself.

- Space consumed by above program is O(n).

- Check the hand written notes of recursion in notebook of DSA for more detailed explanation.

- **Recursion can be divided into two phases, Ascending and Descending**

  **Ascending** this is time when the function calls are happening so the functions are being stacked up in the stack, so this can also be called as calling time. For eg. fun1() method in the above example.

  **Descending** time is when the lines of code at or after the function calls are being executed, this is when the allocated memory in stack to the functions are being deleted. This is also called returning time. For eg. fun2() method in the above example.



## Recurrence relation 

Learn it math.

## Static and Global variable in Recursion

- Static and global variable in a program remains for the lifetime of the program.

- These variable are stored in a separate section in memory called global/static section.

- So, they have only one copy of them created, whenever updated or changed anywhere in the program, it holds it's value for anywhere in the program.

- So when a static variable is used in recursion then, when we update it by each function call, the function which updated it last... that updated value will remain when the recursive function is returning calls.

  For eg

  ```c++
  #include<iostream>
  using namespace std;
  
  //This function have a local variable which have different value for each different function
  int fun1(int n){
      if(n>0){
          return fun1(n-1)+n;
      }
      return 0;
  }
  
  //This function have a static variable which will increment by 1 with each function call 
  //But after increment it'll become same for each function .... and also same goes for a global variable
  int fun2(int n){
      static int x=0;
      if(n>0){
          x++;
          return fun2(n-1)+x;
      }
      return 0;
  }
  
  int main(){
      cout<<"Local variable function = "<<fun1(5)<<endl;
      cout<<"Static/GLobal variable function = "<<fun2(5)<<endl;
  }
  
  /*
  Static/global variable function explanation
      0 - 0
      1 - fun(0)+5 = 5        x=5     //after x becomes 5 it's 5 only for all 
      2 - fun(1)+5 = 10       x=4     //previous functions too as there's only one copy of that x
      3 - fun(2)+5 = 15       x=3
      4 - fun(3)+5 = 20       x=2
      5 - fun(4)+5 = 25       x=1
  */
  
  /*
  local Variable function explanation
  stack   
      0 - 0               
      1 - fun(0)+1 = 1
      2 - fun(1)+2 = 3
      3 - fun(2)+3 = 6
      4 - fun(3)+4 = 10
      5 - fun(4)+5 = 15
  */
  
  //output
  Local variable function = 15
  Static/GLobal variable function = 25
  ```

  



## Types of Recursion

1. Tail Recursion
2. Head Recursion
3. Tree Recursion
4. Indirect Recursion
5. Nested Recursion

## 1. Tail Recursion

- This is the type of Recursion when the function call inside the recursive function is at the very end of the function.

  For eg.

  ```c++
  int fun1(int x){
      if(x>0){
          int n=0;
          n+=x;
          cout<<x<<" "<<n<<endl;
          fun1(x-1);              //Since this statement is at the very of the program it's a recursive function.
      }
      return 0;
  }
  
  int main(){
      fun1(3);
  }
  //output
  3 3
  2 2
  1 1
  ```

- But, the Tail Recursion is **not very efficient to use**, better to use a equivalent loop.

  ```c++
  void loop(int x){
      while(x>0){
          int n=0;
          n+=x;
          cout<<x<<" "<<n<<endl;
          x--;
      }
  }
  
  int main(){
      loop(3);
  }
  //output
  3 3
  2 2
  1 1
  ```

  **Better to use this loop as it'll consume lesser space than the recursive function.**

  Space Complexity of loop() = O(1)

  Space Complexity of fun1() = O(n)

  But this is only the case for tail recursion, and doesn't apply to other types of recursion.

- Some compilers even convert the tail recursive functions to loop automatically in order to save space.

## 2. Head Recursion

- Head Recursion is the type of recursion where the function call is placed at the beginning of the recursive function.

- So the execution of function happens at returning time. While the stack frame of the functions are being deleted from the stack.

  Example of a recursive function

  ```c++
  int headRec(int n){
      if(n>0){
          headRec(n-1);       //Since this function call is at the start of the function, so it's a head 								  //recursion
          cout<<n<<endl;
      }
      return 0;
  }
  
  int main(){
      headRec(3);
  }
  
  //output
  1
  2
  3
  ```

  As we can see here the function call is first then the lines of code for execution.

  

  Head recursion cannot be directly converted to a loop, it'll require some changes...

  The above recursive function headRec() replacement to a loop

  ```c++
  //Above function cannot be directly converted to loop, it'll require some changes
  void loop(int n){
      int i=1;
      while(i<=n){    
          cout<<i<<endl;
          i++;
      }
  }
  
  int main()
  {
  loop(3);
  }
  
  //output
  1
  2
  3
  ```

   

## 3. Tree Recursion

Tree Recursion are those recursive function which make calls to themselves more than once.

For eg

```c++
// Recursive function
void fun(int n)
{
    if (n > 0) {
        printf("%d ", n);
 
        // Calling once
        fun(n - 1);
 
        // Calling twice
        fun(n - 1);
    }
}
 
// Driver code
int main()
{
    fun(3);
    return 0;
}
//output
3 2 1 1 2 1 1
```

This above code is visualized in the below image

Things on the left side (or left branch) are going to get executed first, then the things on the right.

<img src="D:\Programming\Programming fundamentals\Data structures and algorithms fundamentals\Notes\Recursion tree.jpg" style="zoom:80%;" />

for fun(n) no. of function calls are 2^(n+1)-1 

**Time Complexity** - Time complexity are measured by no. of function calls made, so it's **O(2^n)**.

**Space Complexity** - Space Complexity is measured by the maximum size of stack occupied during the lifetime of the program, but here the maximum size of the call stack grew to the height of the tree.(here the height of the tree is 4), so it **O(n)**



## 4. Indirect Recursion

Indirect Recursion is when funA() calls funB() and funB() calls funC() and funC() calls funA()... so it's kind like forming a cycle of function calls. <img src="D:\Programming\Programming fundamentals\Data structures and algorithms fundamentals\Notes\indirect Recursion example.jpg" style="zoom:50%;" />

- Example code of Indirect Recursion

  ```c++
  void funA(int n){
      if(n>0){
          cout<<n<<"  From A"<<endl;
          funB(n-1);
      }
  }
  
  void funB(int n){
      if(n>1){
          cout<<n<<"  From B"<<endl;
          funA(n/2);
      }
  }
  
  int main(){
      funA(20);
  }
  
  //output
  20  From A
  19  From B
  9  From A
  8  From B
  4  From A
  3  From B
  1  From A
  ```

  Tracing tree of the above Indirect recursion.

  Things on the left side (or left branch) are going to get executed first, then the things on the right.

  <img src="D:\Programming\Programming fundamentals\Data structures and algorithms fundamentals\Notes\indirect Recursion Tracing tree.jpg" style="zoom:65%;" />



## 5.Nested Recursion

In this recursion, a recursive function will pass the parameter as a recursive call. That means **“recursion inside recursion”.** 

For eg.

```c++
int fun(int n)
{
	if (n > 100)
		return n - 10;

	// A recursive function passing parameter
	// as a recursive call or recursion
	// inside the recursion
	return fun(fun(n + 11));
}

int main()
{
	cout<<fun(95);
}
//output
91
```

For any value less than 100 we pass in fun(x) then it'll return 91, as it get's to 101 it subtracts 10 from 101 then we get 91. 

And for any value above 100, it'll just directly subtract 10 and return.

To visualize this code, we make a tree to trace all the function calls.

<img src="D:\Programming\Programming fundamentals\Data structures and algorithms fundamentals\Notes\nested Recursion.jpg" style="zoom:67%;" />



# Example Problems of Recursion

## 1. Adding 'n' natural numbers using recursion

In this Problem we have to add n natural number using n natural number.

Example 1. 

```c++
//recursive function to add n natural number 
int fun(int n){
    static int sum=0;
    if(n>0){
        sum+=n;        
        fun(n-1);
    }
    return sum;
}

int main(){
    cout<<fun(5);
}
//output
15
```

We can also do this without using a static variable

```c++
//another function without using a static variable
int sum(int n){
    if(n>0){
        return sum(n-1)+n;
    }
    return 0;
}

int main(){
    cout<<sum(5);
}
//output
15
```

Time complexity - O(n)

Space complexity - O(n)

For adding 'n' natural number we have a direct formula, sum = n(n+1) / 2

Also, we can use a loop to add 'n' natural numbers.

So, using recursion will have the same time complexity as a loop but, use more space on the stack than a loop.



## 2. Factorial

Factorial of a certain number using recursion.

f(n) = 1 * 2 * 3 * 4 ..... * (n-1) * n

**f(n) = f(n-1) * n**

So using this we can now write code for recursive function to generate factorial

```c++
int factorial(int n){
    if(n>0){
        return factorial(n-1)*n;
    }
    return 1;
}

int main(){
	cout<<factorial(6)<<endl;
}
//output
720
```

We can do the same using a loop

```c++
int factorialLoop(int n){
    int total=1;
    for(int i=1;i<=n;i++){
        total *=i; 
    }
    return total;
}

int main(){
    cout<<factorialLoop(5);
}
//output
120
```



## 3. Power / Exponents

Having a power to a number means to multiply the number with itself (power) no. of times.

For eg. If (m)^n = m * m * m * .....(n-1) times * m

then let's say (m)^n = power(m,n)

then **power(m,n) = power(m,n-1) * m**

Now by using this formula we can write our code based on this logic

```c++
int power(int m, int n){
    if(n>0){
        return power(m,n-1)*m;
    }
    return 1;
}

int main(){
	cout<<power(2,5);
}
//output
32
```

Another method to write the same function but using static integer

```c++
//Finding out exponents using recursion with a static integer
int power(int m, int n){
    static int total=1;
    if(n>0){
        total*=m;
        power(m,n-1);
        return total;
    }
    return 1;
}

int main(){
	cout<<power(2,6);
}
//output
64
```

using a for loop

```c++
//using a for loop
int powerLoop(int m, int n){
    int total=1;
    for(int i =0;i<n;i++){
        total*=m;
    }
    return total;
}
int main(){
    cout<<powerLoop(3,5);
}
//output
243
```

### Now we do the same above thing of exponents but just by half the no. of multiplications / calling the function half the number of times

For eg. (2)^16 can be written as (2*2)^8 ... so instead of multiplying 2 sixteen times, we just multiply 4 eight times.

Code for this...

```c++
//dividing the power in half so that we need to make half the no. of functions calls

int halfPower(int m, int n){
    if(n>0){
        if(n%2==0){
            return halfPower(m*m,n/2);
        }else{
            return halfPower(m*m,(n-1)/2)*m;
        }
    }
    return 1;
}

int main(){
    cout<<halfPower(3,5)<<endl;
}
//output
243
```

So now it's two times are more efficient as previous ones.



## 4. Taylor Series using recursion

The value of the Exponential function can be calculated using Taylor Series. 

Taylor series is ....
$$
e^x = 1 + x/1! + x^2/2! + x^3/3! + x^4/4!......
$$
To find its value using recursion, we will use static variables. For the power of x, we will use p and for factorials, we will use f as static variables. 

The function shown below is used to increase the power of x. 

```
p = p*x
```

The function below is used to find factorials. 

```
f = f*n
```

The function below is used to find factorials. 

```
r = e(x,n)	//where x = power of exponent and n is till how much power of x we want to calculate
r + p/f		//will be returning this value
```

Where r is the recursive call to the function.

Implementation  of the above idea...

```c++
// C++ implementation of the approach
#include <stdio.h>

// Recursive Function with static
// variables p and f
double e(int x, int n)
{
	static double p = 1, f = 1;
	double r;

	// Termination condition
	if (n == 0)
		return 1;

	// Recursive call
	r = e(x, n - 1);

	// Update the power of x
	p = p * x;

	// Factorial
	f = f * n;

	return (r + p / f);
}

// Driver code
int main()
{
    cout<<e(4,15);
}
//output
54.59
```



## 5. Taylor Series using Horner's Rule (less number of multiplications)

Taylor series is ....
$$
e^x = 1 + x/1! + x^2/2! + x^3/3! + x^4/4!......
$$
Now consider the 

- 1st term i.e. 1 - No multiplications here
- 2nd term i.e. x/1!  -  No multiplications here too
- 3rd term i.e. x^2/2!  -  Two multiplications here   (x*x / 1 * 2)
- 4th term i.e. x^3/3!  -   four multiplications here   (x * x * x / 1 * 2 * 3)
- 5th term i.e. x^4/4!  -   six multiplications here   (x * x * x * x / 1 * 2 * 3 * 4)

So, if we go till 4th power of x in Taylor series we have to do 2+4+6 = 12 multiplications.

To this number of multiplications it'll take us O(n^2).

But we can reduce the no. of multiplications by using the Horner's rule.

Horner's Rule is just to take common variables and constants so to reduce the power the inside the bracket.

We can convert the Taylor series to 
$$
e^x = 1 + x/1! + x^2/2! + x^3/3! + x^4/4!......
e^x = 1 + x/1 ( 1 + x/2 + x^2/2*3 + x^3/2*3*4).........
e^x = 1 + x/1 (1 + x/2 (1 + x/3 + x^2 / 3*4) ).....
e^x = 1 + x/1 (1 + x/2 (1 + x/3 ( 1 + x/4 ) ) ).....
$$
<img src="D:\Programming\Programming fundamentals\Data structures and algorithms fundamentals\Notes\Taylor Series using Horner's Rule.JPG" style="zoom:80%;" />

So, now the total number of multiplications is reduced to just 4 from 12.

So, this will give us O(n) time complexity.

Now, we can convert this into a program using a for loop

```c
double taylorHornerLoop(int x, int n){
    double s = 1;
    while(n>0){
        s = (1 + (x/n))*s;
        n--;
    }
    return s;
}

int main(){
    cout<<taylorHornerLoop(4,30)<<endl;
}

//output
60
```

We can also do this by using recursion

```c++
//Taylor Series by horner rule using recursion
double taylorHornerRec(int x, int n){
    static double s = 1;
    if(n>0){
        s = (1 + (x/n))*s;
        taylorHornerRec(x,n-1);
        return s;
    }
    return 1;
}

//Just another method to do the same above thing

// double taylorHornerRec(int x, int n){
//     static double s = 1;
//     if(n==0){
//         return s;
//     }
//     else{
//         s = (1 + (x/n))*s;
//         return taylorHornerRec(x,n-1);
//     }
// }

int main(){
    cout<<taylorHornerRec(5,30)<<endl; 
}
//output
144
```



## 6. Fibonacci Series

Fibonacci Series is just     0,1,1,2,3,5,8,13,21

It's the addition of last two number to get the next number.

So, to obtain a term at nth position in Fibonacci series. We can either use recursion or Loops

Here's a example to do in loops

```c++
//Fibonacci series using loop
int fibLoop(int n){
    int t0=0,t1=1,temp;
    for(int i=0;i<n;i++){
        temp=t0+t1;
        t0=t1;
        t1=temp;
    }
    return temp;
}

int main(){
    for(int i =0;i<9;i++)			//We will get the first 9 values of a fibonacci series
        cout<<fibLoop(i)<<endl;
}
```

Here's how to do the same thing using recursion

```c++
//Fibonacci series using recursion
int fibonacci(int n){
    if(n==0){
        return 0;
    }
    else if(n==1 || n==2){
        return 1;
    }else{
        return fibonacci(n-1)+fibonacci(n-2);
    }
}

int main(){
    fibonacci(7);
}

//output
13
```

Time complexity of the recursion function is **O(2^n)**.



## 7. Fibonacci Series using memoization

When we make the tracing tree of the above code we don't store any values, so we have to make the calls again and again, and do the calculations again. 

We can avoid this repetition of calling function by storing it in a array. So, this a example of memoization and is used in dynamic programming.

To understand this clearly, watch the abdul bari video or https://www.youtube.com/watch?v=vYquumk4nWw

So the rough algorithm is...

1. Make a array and initialize it with -1
2. When making a call check if that value already we have it or not in the array.
3. If yes, return the value.
4. If no, then do make the call and store the value in the appropriate position before returning the value.

The code for Fibonacci using memoization.

```c++
int fibMemoization(int n){
    static int (*m) = new int[n+1];		//creating a array dynamically
    for(int i=0;i<=n;i++){
        m[i]=-1;					//initializing the array with -1
    }
    if(m[n]!=-1){
        return m[n];				//checking if the value already exists in the array
    }
    else if(n==0){					// first and the 2nd value are 0 and 1
        m[n] = 0;
        return m[n];
    }
    else if(n==1){
        m[n] = 1;
        return m[n];
    }
    else{							//then storing the value of the nth term in array before returning it
        m[n] = fibMemoization(n-2)+fibMemoization(n-1);
        return m[n];
    }
    delete []m;						//deleting the dynamic array is very important
}

int main(){
    cout<<fibMemoization(8)<<endl;
}

//output
21
```

This code will take O(n) time. So, it's better than O(n^2) that was for a simple recursive Fibonacci function.



## 8. Combinations ( nCr )

- If we are given a set of objects then in how many ways we can select the subset of those objects are called Combinations.

- In simpler terms, when we are given 'n' number of objects, then in how many ways we can select 'r' number of object from them.
- We have a direct formula for it 

$$
nCr = n! / r!(n-r)! 
$$

- here n = total number of objects, r = no. of objects we can select at once

- Then nCr will give us total number of combinations possible.

- For eg. When we are given {A,B,C,D} then if we are allowed to select 3 objects from it then no. of combinations possible are

- {A,B,C}, {A,C,D}, {B,C,D}, {A,B,D} 	here n = 4, r = 3

- So putting n and r in the nCr formula will give us 4, and we found 4 combinations. Since, 4C3 = 4.

Remeber if there's {A,B,C} then {B,C,A} or {C,B,A} are not allowed, since we are only finding out the combinations and not have to arrange the combinations. Those combinations and then arranging them comes under Permutations.

So, after having known all this we can now write the code for combinations

```c++
int fact(int n){
    if(n>0){
        return fact(n-1)*n;
    }
    else{
        return 1;
    }
}

//nCr = n! / [ r!(n-r)! ]
int comb(int n, int r){
    int t1,t2,t3;
    t1=fact(n);
    t2=fact(r);
    t3=fact(n-r);

    return t1/(t2*t3);
}

int main(){
    cout<<comb(5,3);
}
//output
10
```

So, this is a pretty simple program where we just find the factorials and put it in formula.

- Now, we have to use recursion to find the Combinations.

- There's Pascal Triangle which can directly give us the value for combinations

  **Pascal's Triangle and combinations**

  <img src="D:\Programming\Programming fundamentals\Data structures and algorithms fundamentals\Notes\Pascals Triangle.JPG" style="zoom:67%;" />

As we can see that 3C1 + 3C2 = 4C2, 

We can generalize this and form a formula 
$$
nCr = (n-1)Cr + (n-1)C(r-1)
$$
Also, when r = 0  or n=r then value of nCr = 1.

So, using the above values and formula we can convert this into a recursive function.

```c++
//We can use the formula obtained from Pascal's triangle
// nCr = (n-1)Cr + (n-1)C(r-1)
//also when r=0 or n=r then always nCr = 1

int combPascalTri(int n, int r){
    if(r==0 || n==r){
        return 1;
    }
    else{
        return combPascalTri(n-1, r) + combPascalTri( n-1, r-1);
    }
}

int main(){
    cout<<combPascalTri(4,2);
}
//output
6
```





## 9. Tower of Hanoi problem.

So in this problem we try to move a certain number of dics from one pole to another pole, using recursion

Watch the abdul bari video to understand this problem more

Code of the program

```c++
int TOH(int n, int A, int B, int C){
    if(n>0){
        TOH(n-1,A,C,B);
        cout<<A<<" to "<<C<<endl;
        TOH(n-1,B,A,C);
    }
}

int main(){
    TOH(3,1,2,3);
}
//output
1 to 3
1 to 2
3 to 2
1 to 3
2 to 1
2 to 3
1 to 3
```

