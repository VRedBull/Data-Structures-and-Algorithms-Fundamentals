# Array ADT

Array ADT(abstract data type) - array is a type of data structure so, we can perform different types of operations on array.

Operations we can do on an array:

1. Display()
2. Add(x) / Append(x)
3. Insert(index x)
4. Delete(index)
5. Search(x)
6. Get(index)
7. Set(index, x)
8. Max() / Min()
9. Reverse()
10. Shift() / Rotate()



## Operations on array

### Display()

- For displaying an array we have to iterate through the array using a loop, and the print it.

- We can use a for loop or for each loop or even while loop.

- We will create a display(array, length) function which will take parameters as address of the first element of the array and the size/length of the array.

  ```c++
  struct Array{
      int *A;
      int size;
      int length;
  };
  
  void display_array(struct Array arr,int length){
      for(int i=0;i<length;i++){
          cout<<arr.A[i]<<" "<<flush;
      }
  }
  
  int main(){
      struct Array arr;
  
      cout<<"Enter the size of the array = "<<flush;
      cin>>arr.size;
  
      arr.A = new int[arr.size];
  
      cout<<"Enter the no. of numbers you want in the array(length) = "<<flush;
      cin>>arr.length;
  
      cout<<"Enter all the elements in the array = "<<flush;
  	for(int i=0;i<arr.length;i++){
          cin>>arr.A[i];
      }    
  
      cout<<"All elements of the array are = "<<endl;
      display_array(arr,arr.length);			//passing the object of Array struct
  }
  ```



### Add(x) / Append(x)

- We can append elements at the end of an array.

- We will write a function that will check if there is space available to append an element then, if there is space then it'll append and update the length of the array.

  Below code is written without append function

  ```c++
  #include<iostream>
  using namespace std;
  
  int main(){
      int size,length;
      size=10;
      int A[size] = {1,2,3,4,5};
  
      length = 5;
      int index=9;
      if(size>index){
          A[index] = 6;
          length++;
      }else{
          cout<<"We have run out of space in array"<<endl;
      }
  
      //display
      cout<<"New array is: "<<flush;
      for(int i:A)
          cout<<i<<" "<<flush;
  
  }
  ```

  Below code is having a append function separately

  ```c++
  #include<iostream>
  using namespace std;
  
  struct Array{
      int A[10];
      int size;
      int length;
  };
  
  void append(struct Array *arr, int ele){
      if((arr->length)<(arr->size)){
          arr->A[arr->length]=ele;
          arr->length+=1;
      }else{
          cout<<"Can't append since array ran out of size"<<endl;
      }
      arr=NULL;
  }
  
  void display(struct Array arr){
      for(int i=0;i<arr.size;i++){
          cout<<arr.A[i]<<" "<<flush;
      }
      cout<<endl;
  }
  
  int main(){
      struct Array arr = {{0,1,2,4,5,6,7,8,9},10,9};
      display(arr);
      
      insert(&arr,3,3);
      display(arr);
      
  }
  ```

- When we write a function for append we have to call the function by address and function parameter should have a pointer so that it can change the actual parameters passed to it.



### Insert(index,element)

- We can insert a element in an array at any index.

- When we insert a element the elements from the index value should be copied to the next index.

  A program to insert an element in an array

  ```c++
  #include<iostream>
  using namespace std;
  
  struct Array{
      int A[10];
      int size;
      int length;
  };
  
  void append(struct Array *arr, int ele){
      if((arr->length)<(arr->size)){
          arr->A[arr->length]=ele;
          arr->length+=1;
      }else{
          cout<<"Can't append since array ran out of size"<<endl;
      }
      arr=NULL;
  }
  
  void display(struct Array arr){
      for(int i=0;i<arr.size;i++){
          cout<<arr.A[i]<<" "<<flush;
      }
      cout<<endl;
  }
  
  void insert(struct Array *arr, int ele, int index){
      if(index<=(arr->length) && (arr->length)<(arr->size)){
  
          for(int i = arr->length; i>index;i--){
              arr->A[i] = arr->A[i-1];
          }
  
          arr->length+=1;
          arr->A[index]=ele;
      }else{
          cout<<"cannot insert element as array have run out of size"<<endl;
      }
  }
  
  int main(){
      struct Array arr = {{0,1,2,4,5,6,7,8,9},10,9};
      display(arr);
      
      insert(&arr,3,3);
      display(arr);
      insert(&arr,5,6);
  
  }
  
  //output
  0 1 2 4 5 6 7 8 9 0 
  0 1 2 3 4 5 6 7 8 9
  cannot insert element as array have run out of size
  ```

   We should use a pointer to change the value.

### Delete(index)

- We can also delete a element at a particular index in an array.

- We can write a function that'll take array and index as parameter and then remove the particular index from the array.

- After removing that element we will have to shift all subsequent elements one index to the left.

  Here is a example

  ```c++
  struct Array{
      int A[10];
      int size;
      int length;
  };
  
  void display(struct Array arr){
      for(int i=0;i<arr.size;i++){
          cout<<arr.A[i]<<" "<<flush;
      }
      cout<<endl;
  }
  
  void del(struct Array *arr,int index){
      if(index>=0 && index<(arr->length)){
          cout<<"Deleteing "<<arr->A[index]<<endl;
          for(int i= index; i<arr->length;i++){
              arr->A[i]=arr->A[i+1];
          }
          arr->A[(arr->length)]=0;
          arr->length-=1;
  
      }else{
          cout<<"Invalid index"<<endl;
      }
  }
  
  int main(){
      struct Array arr = {{0,1,2,3,4,5},10,6};
      display(arr);
      del(&arr,1);
      display(arr);
      del(&arr,-1);
  }
  
  //output
  0 1 2 3 4 5 0 0 0 0 
  Deleteing 1
  0 2 3 4 5 0 0 0 0 0
  Invalid index
  ```



### Linear Search(element)

- In linear search, we find the element by iterating through the loop until we find the desired element or we stop when reach the end of the loop.

- An example program of linear search is given below.

  ```c++
  struct Array{
      int A[10];
      int size;
      int length;
  };
  
  int linear_search(struct Array arr, int ele){
      for(int i=0;i<arr.length;i++){
          if(ele == arr.A[i]){
              return i;
          }else{
              continue;
          }
      }
      return -1;			//returns -1 when we don't find the element in the array
  }
  
  int main(){
      struct Array arr = {{0,1,2,3,4,5},10,6};
      cout<<linear_search(arr,3)<<endl;
      cout<<linear_search(arr,8)<<endl;
  }
  
  //output
  3
  -1
  ```

#### Improved Linear Search

- We can also improve the linear search by two techniques.

  1. Transposition method
  2. Move to Front/Head

  **Transposition Method**

  - In this method when we find the element we are looking for by using linear search, then swap the element with element left to it (i.e. element at previous index).

  - By doing this, when we search for the same element next time, we will have to check it with one less element thereby reducing the time complexity.

    Here is code for Transposition method

    ```c++
    int transposition_linear_search(struct Array *arr, int ele){
        for(int i=1;i<=arr->length;i++){
            if(ele == arr->A[i]){
                int temp = arr->A[i-1];
                arr->A[i-1] = arr->A[i];
                arr->A[i] = temp;
                return i;
            }else{
                continue;
            }
        }
        return -1;
    }
    ```

  **Move to Front/Head**

  - In this method, after we have searched for the element swap it with the first element of the array.

  - So, when we want to find same element next time we will have reduced the time complexity from O(n) to O(1).

    Here's the code to that

    ```c++
    int head_linear_search(struct Array *arr, int ele){
        for(int i=1;i<=arr->length;i++){
            if(ele == arr->A[i]){
                int temp = arr->A[0];
                arr->A[0] = arr->A[i];
                arr->A[i] = temp;
                return 0;
            }else{
                continue;
            }
        }
        return -1;
    }
    ```

- Whole code for improved linear search

  ```c++
  #include<iostream>
  using namespace std;
  
  struct Array{
      int A[10];
      int size;
      int length;
  };
  
  void display(struct Array arr){
      for(int i:arr.A){
          cout<<i<<" "<<flush;
      }cout<<endl;
  }
  
  int transposition_linear_search(struct Array *arr, int ele){
      for(int i=1;i<=arr->length;i++){
          if(ele == arr->A[i]){
              int temp = arr->A[i-1];
              arr->A[i-1] = arr->A[i];
              arr->A[i] = temp;
              return i;
          }else{
              continue;
          }
      }
      return -1;
  }
  
  int head_linear_search(struct Array *arr, int ele){
      for(int i=1;i<=arr->length;i++){
          if(ele == arr->A[i]){
              int temp = arr->A[0];
              arr->A[0] = arr->A[i];
              arr->A[i] = temp;
              return 0;
          }else{
              continue;
          }
      }
      return -1;
  }
  
  int main(){
      struct Array arr = {{0,1,2,3,4,5},10,6};
      display(arr);
      cout<<"Doing transposition on element"<<endl;
      transposition_linear_search(&arr,3);
      display(arr);
      cout<<"Moving the element to very first after searching for it."<<endl;
      head_linear_search(&arr,4);
      display(arr);
  }
  
  //output
  0 1 2 3 4 5 0 0 0 0 
  Doing transposition on element
  0 1 3 2 4 5 0 0 0 0
  Moving the element to very first after searching for it.
  4 1 3 2 0 5 0 0 0 0
  ```



### Binary Search

- Binary Search is very efficient than using linear search.

- For, Binary Search we should have a sorted array.

- In Binary search, there's lower bound(1st element of array) and upper bound(last element of array) and mid of the array is found by dividing ( upper bound + lower bound )/ 2.

- Then it's checked whether mid > element or mid < element.

- If mid > element then we shift the upper bound to mid-1.

- if mid < element then we shift the lower bound to mid+1.

  Here's the code.

  ```c++
  #include<iostream>
  using namespace std;
  
  struct Array{
      int A[10];
      int size;
      int length;
  };
  
  int binary_search(struct Array arr, int ele){
      int l,u,mid;
      l=0;
      u=arr.length-1;
  
      while(l<=u){
          mid = (l+u)/2;
          if(arr.A[mid]==ele){
              return mid;
          }else if(arr.A[mid] > ele){
              u=mid-1;
          }else{
              l=mid+1;
          }
      }
      return -1;    
  }
  
  int main(){
      struct Array arr = {{10,11,12,13,14,15},10,6};    //should have a sorted array for this search
      cout<<binary_search(arr,10)<<endl;
  }
  //output
  0
  ```

  We can also do binary search recursively

  ```c++
  int rec_bin_search(int A[], int l, int u, int ele){
      int mid;
      if(l<=u){    
          mid = (l+u)/2;
          if(A[mid]==ele){
              return mid;
          }else if(A[mid] > ele){
              return rec_bin_search(A,l,mid-1,ele);
          }else{
              return rec_bin_search(A,mid+1,u,ele);
          }   
      }
      return -1;
  }
  
  int main(){
      struct Array arr = {{10,11,12,13,14,15},10,6};    //should have a sorted array for this search
   
      cout<<rec_bin_search(arr.A,0,arr.length-1,15)<<endl;
  }
  //output
  5
  ```

  **Note** - Loop binary search is better that doing it recursively because recursive function uses stack, so it might use more memory that binary search.

- **Time Complexity**

  Best Case - O(1)

  Worst Case - O(log(n))	

  Average Case - O(log(n))

  Log(n) since it's diving the array into two part.



### Get() Set() Avg() Max() Min() Sum() 

We have to perform all these operations on an array.

Here's the program

```c++
#include<iostream>
using namespace std;

struct Array
{
    int A[10];
    int length;
    int size;
};
 
void display(struct Array arr){
    for(int i=0;i<arr.length;i++){
        cout<<arr.A[i]<<" "<<flush;
    }cout<<endl;
}

int get(struct Array arr, int index){
    if(index>=0 && index<= arr.length){
        return arr.A[index];
    }else{
        return (int)NULL;
    }
}

void set(struct Array *arr, int index, int ele){
    if(index>=0 && index<= arr->length){
        arr->A[index] = ele;
    }else{
        cout<<"Not a valid index"<<endl;
    }
}

int max(struct Array arr){
    int n=arr.A[0];
    for(int i=1;i<arr.length;i++){
        if(arr.A[i]>n){
            n=arr.A[i];
        }
    }
    return n;
}

int min(struct Array arr){
    int n=arr.A[0];
    for(int i=1;i<arr.length;i++){
        if(arr.A[i]<n){
            n=arr.A[i];
        }
    }
    return n;
}

int sum(struct Array arr){
    int total=0;
    for(int i=0;i<arr.length;i++){
        total += arr.A[i]; 
    }
    return total;
}

int rec_sum(int A[], int length){
    if(length<0){
        return 0;
    }else{
        return rec_sum(A,length-1)+A[length];
    }
}

int avg(struct Array arr){
    int total=0;
    for(int i=0;i<arr.length;i++){
        total+=arr.A[i];
    }
    return total/arr.length;
}

int main(){
    struct Array arr = {{110,20,301,40,50},5,10};
    cout<<"Getting 41 at index: "<<get(arr,41)<<endl;
    set(&arr,4,221);
    cout<<"After setting 221 at index 4: "<<flush;
    display(arr);
    cout<<"Maximum in the array: "<<max(arr)<<endl;
    cout<<"Minimum in the array: "<<min(arr)<<endl;
    cout<<"Sum of all array elements: "<<sum(arr)<<endl;
    cout<<"Finding sum recursively: "<<rec_sum(arr.A,arr.length)<<endl;
    cout<<"Average of all array elements: "<<avg(arr)<<endl;
}

//output
Getting 41 at index: 0
After setting 221 at index 4: 110 20 301 40 221
Maximum in the array: 301
Minimum in the array: 20
Sum of all array elements: 692
Finding sum recursively: 692
Average of all array elements: 138
```



### Reverse an array

- We can reverse the contents of an array.

- There are two methods to reverse an array

  1. Using a auxiliary array
  2. Swapping corresponding end elements 

  #### Using a auxiliary array

  - We can use another array to store the elements of one array in reverse order.

  - Then copy and paste the array elements to the original array.

  - Now, the original array is in reverse order.

    Here's the code for it

    ```c++
    #include<iostream>
    using namespace std;
    
    struct Array{
        int A[10];
        int length;
        int size;
    };
    
    void display(struct Array arr){
        for(int i:arr.A){
            cout<<i<<" "<<flush;
        }
        cout<<endl;
    }
    
    void auxillary_reverse_array(int A[],int B[], int length){
        for(int i=length-1,j=0; i>=0; i--,j++){
            B[j] = A[i];
        }
    
        for(int i=0;i<length;i++){
            A[i] = B[i];
        }
    }
    
    int main(){
        struct Array arr = {{10,20,30,40,50},5,10};
        struct Array brr = {{0},5,10};
        
        display(arr);
        auxillary_reverse_array(arr.A, brr.A, arr.length);
        display(arr);
    }
    
    //output
    10 20 30 40 50 0 0 0 0 0 
    50 40 30 20 10 0 0 0 0 0
    ```

  #### Swapping corresponding end elements

  1. We can swap corresponding end elements until we reach the mid elements.

  2. We swap 1st with nth elements, 2nd with (n-1)th , 3rd with (n-2)th and so on...

     Here's the code

     ```c++
     #include<iostream>
     using namespace std;
     
     struct Array{
         int A[10];
         int length;
         int size;
     };
     
     void display(struct Array arr){
         for(int i:arr.A){
             cout<<i<<" "<<flush;
         }
         cout<<endl;
     }
     
     void swap_reverse_array(int A[],int length){
         int i=0;
         int j=length-1;
         int temp=0;
         while(i<j){
             temp = A[j];
             A[j] = A[i];
             A[i] = temp;
             i++,j--;
         }
     
     }
     
     int main(){
         struct Array arr = {{10,20,30,40,50},5,10};
         
         display(arr);
         swap_reverse_array(arr.A,arr.length);
         display(arr);
     }
     
     //output
     10 20 30 40 50 0 0 0 0 0 
     50 40 30 20 10 0 0 0 0 0
     ```



### Shift and Rotating an array

#### Left shift and Right shift

- We can shift elements of an array to either one index left or one index right.

- We just have to copy the elements to one index either left or right accordingly, and make the left most or right most element exclude from the array respectively, and also reduce the length of the array by one.

  Here's the code for **left shift**.

  ```c++
  #include<iostream>
  using namespace std;
  
  struct Array{
      int A[10];
      int length;
      int size;
  };
  
  void display(struct Array arr){
      for(int i:arr.A){
          cout<<i<<" "<<flush;
      }
      cout<<endl;
  }
  
  void left_shift(struct Array *arr){
      for(int i=1;i<arr->length;i++){
          arr->A[i-1] = arr->A[i];
      }
      arr->A[arr->length-1]=0;
      arr->length-=1;
  }
  
  int main(){
      struct Array arr = {{10,20,30,40,50,60,70,80,90,100},10,10};
      display(arr);
      left_shift(&arr);
      display(arr);
  }
  
  //output
  10 20 30 40 50 60 70 80 90 100 
  20 30 40 50 60 70 80 90 100 0
  ```

  Here's the code for **right shift**.

  ```
  #include<iostream>
  using namespace std;
  
  struct Array{
      int A[10];
      int length;
      int size;
  };
  
  void display(struct Array arr){
      for(int i:arr.A){
          cout<<i<<" "<<flush;
      }
      cout<<endl;
  }
  
  void right_shift(struct Array *arr){
      if(arr->length <= arr->size){
          for(int i=arr->length;i>0;i--){
              arr->A[i] = arr->A[i-1];
          }
          arr->A[0]=0;
          arr->length+=1;
      }
  }
  
  int main(){
      struct Array arr = {{10,20,30,40,50,60,70,80,90,100},10,10};
      display(arr);
      left_shift(&arr);
      display(arr);
  }
  
  //output
  10 20 30 40 50 60 70 80 90 100 
  0 10 20 30 40 50 60 70 80 90
  ```

#### Left rotate and right rotate

- Left rotate is just like left shift but here we don't lose the element, instead the first element becomes the last element in the left rotated array. 

- And it's the same for right rotation, but here the last element becomes the first element.

  Here's the code.

  ```c++
  struct Array{
      int A[10];
      int length;
      int size;
  };
  
  void display(struct Array arr){
      for(int i:arr.A){
          cout<<i<<" "<<flush;
      }
      cout<<endl;
  }
  
  void left_rotate(struct Array *arr){
      int temp = arr->A[0];
      for(int i=1;i<arr->length;i++){
          arr->A[i-1] = arr->A[i];
      }
      arr->A[arr->length-1]=temp;
      
  }
  
  void right_rotate(struct Array *arr){
      if(arr->length <= arr->size){
          int temp = arr->A[(arr->length-1)];
  
          for(int i=arr->length;i>0;i--){
              arr->A[i] = arr->A[i-1];
          }
          arr->A[0]=temp;
      }
  }
  
  int main(){
      struct Array arr = {{10,20,30,40,50,60,70,80,90,100},10,10};
      display(arr);
  
      left_rotate(&arr);
      display(arr);
  
      right_rotate(&arr);
      display(arr);
  }
  
  //output
  10 20 30 40 50 60 70 80 90 100 
  20 30 40 50 60 70 80 90 100 10			//after left rotation
  10 20 30 40 50 60 70 80 90 100			//after right rotation
  ```



### Check if Array is Sorted and Inserting in a Sorted array

#### Checking if Array is Sorted

- We write code to check whether an array is sorted or not. (i.e. whether array elements are in increasing order or not).

  Here's the code 

  ```c++
  void display(struct Array arr){
      for(int i:arr.A){
          cout<<i<<" "<<flush;
      }cout<<endl;
  }
  
  int if_sorted(struct Array arr){
      for(int i=1;i<arr.length;i++){
          if(arr.A[i-1] <= arr.A[i]){
              continue;
          }else{
              return -1;
          }
      }
      return 1;
  }
  
  int main(){
      struct Array arr = {{4,8,13,16,20,25,28,33},8,10};
      cout<<if_sorted(arr)<<endl;
      display(arr);
  }
  
  //output
  1					//if returned 1 then array is sorted
  ```

#### Inserting an element in a sorted array

- After checking if the array is sorted, we insert an element in the sorted array.

- Now, the when we insert an element in the sorted array we need to insert it at right location in the sorted array so as to keep the array sorted.

- Before inserting we need to shift the elements one index to the right, so that it makes space for the new element.

  Here's the code

  ```c++
  struct Array{
      int A[10];
      int length;
      int size;
  };
  
  void display(struct Array arr){
      for(int i:arr.A){
          cout<<i<<" "<<flush;
      }cout<<endl;
  }
  
  int if_sorted(struct Array arr){
      for(int i=1;i<arr.length;i++){
          if(arr.A[i-1] <= arr.A[i]){
              continue;
          }else{
              return -1;
          }
      }
      return 1;
  }
  
  //Inserts the element at right place and shifts the elements right to it, to one index higher
  void insert_at(struct Array **arr, int ele, int index){
      if((*(arr))->length < (*(arr))->size){    
          for(int i = (*(arr))->length; i>index; i--){
              (*(arr))->A[i] = (*(arr))->A[i-1];
          }
          (*(arr))->A[index] = ele;
          (*(arr))->length+=1;
      }else{
          cout<<"Array ran out of space"<<endl;
      }
  }
  
  void insert_sorted(struct Array *arr, int ele){
      if(if_sorted(*arr)){
  
          for(int i=0; i<arr->length; i++){
  
              if(arr->A[i]<=ele && arr->A[i+1] >= ele){
                  insert_at(&arr, ele,i);
                  break;
              }else{
                  continue;
              }
  
          }
      }else{
          cout<<"Not a sorted array"<<endl;
      }
  }
  
  int main(){
      struct Array arr = {{4,8,13,16,20,25,28,33},8,10};
      
      cout<<if_sorted(arr)<<endl;
      
      display(arr);
      insert_sorted(&arr,21);
      display(arr);
      
      insert_sorted(&arr,31);
      display(arr);
      
      insert_sorted(&arr,15);
      display(arr);
  }     
  
  //output
  1
  4 8 13 16 20 25 28 33 0 0
  4 8 13 16 21 20 25 28 33 0
  4 8 13 16 21 20 25 31 28 33
  Array ran out of space
  4 8 13 16 21 20 25 31 28 33
  ```

    

### Merging Arrays (Binary Operation)

There are many types of Binary operations in arrays we can perform. Binary operations require at least two arrays to be performed on.

1. Append - where one array's elements are copied to another array from the end.
2. Concatenation - Appending updates the original array, but in concatenation we will require a new array where both array elements will be copied one after the other.
3. Compare - Comparing elements of both arrays.
4. Copy - Copying elements of one array to another empty/non-empty array.
5. Merging - Two sorted arrays are merged to create a new sorted array.

Here, we will discuss Merger operation

- In merging, we will require atleast three arrays,  two of them sorted and one empty.

- We will check each element of both array and compare them one by one, if one is smaller than the other then we copy it to the new array.

- After comparing both the arrays, if one array is larger than the other then we will just copy the remaining elements of that array to the new array.

  Here's how to do it. (My way)

  ```c++
  struct Array{
      int A[10];
      int length;
      int size;
  };
  
  void display(struct Array arr){
      for(int i:arr.A){
          cout<<i<<" "<<flush;
      }cout<<endl;
  }
  
  void merge_sorted_array(struct Array *arr, struct Array *brr, struct Array *crr){
      int i=0,j=0,k=0;
  
      while(i<arr->length && j<brr->length){
          if(arr->A[i] < brr->A[j]){
              crr->A[k] = arr->A[i];
              k++,i++;
          }else{
              crr->A[k] = brr->A[j];
              k++,j++;
          }
      }
  
      if(j<(brr->length)){
          for(int x=j; x<brr->length; x++){
              crr->A[k] = brr->A[x];
          }
      }else if(i<(arr->length)){
          for(int x=i; x<arr->length; x++){
              crr->A[k] = arr->A[x];
          }
      }
  
  }
  
  int main(){
      struct Array arr = {{2,4,6,8},4,10};
      struct Array brr = {{1,3,5,7,9},5,10};
      
      struct Array crr = {{0},10,10};
  
      display(crr);
      merge_sorted_array(&arr, &brr, &crr);
      display(crr);
  
  }
  
  //output
  0 0 0 0 0 0 0 0 0 0 
  1 2 3 4 5 6 7 8 9 0
  ```

  Abdul bari way(using dynamic array)

  ```c++
  #include<iostream>
  using namespace std;
  
  struct Array
  {
   int A[10];
   int size;
   int length;
  };
  
  void Display(struct Array arr)
  {
      int i;
      printf("\nElements are\n");
      for(i=0;i<arr.length;i++)
      printf("%d ",arr.A[i]);
  }
  
  struct Array* Merge(struct Array *arr1,struct Array *arr2)
  {
      int i,j,k;
      i=j=k=0;
  
      struct Array *arr3=(struct Array *)malloc(sizeof(struct Array));
  
      while(i<arr1->length && j<arr2->length)
      {
          if(arr1->A[i]<arr2->A[j])
              arr3->A[k++]=arr1->A[i++];
          else
              arr3->A[k++]=arr2->A[j++];
          }
  
          for(;i<arr1->length;i++)
              arr3->A[k++]=arr1->A[i];
  
          for(;j<arr2->length;j++)
              arr3->A[k++]=arr2->A[j];
  
          arr3->length=arr1->length+arr2->length;
          arr3->size=10;
  
          return arr3;
  }
  int main()
  {
      struct Array arr1={{2,9,21,28,35},10,5};
      struct Array arr2={{2,3,16,18,28},10,5};
      struct Array *arr3; 
      arr3=Merge(&arr1,&arr2);
      Display(*arr3);
  
      return 0;
  }
  
  //output
  Elements are
  2 2 3 9 16 18 21 28 28 35
  ```



### Set Operations on array

There are four different types of operations in set

1. Union of sets.
2. Intersection of sets.
3. Difference between sets.
4. Set membership (just checks whether a element is there or not, just like searching).

Watch abdul bari videos again to understand the code implementation.



## <u>Student exercises</u>

### Finding missing elements from an array

#### From a sorted array

1. **Single missing element (first missing element in the array)**

   - If we have a sorted 1st 'n' natural number array, then the difference between the index and it's index value should remain constant throughout the array.

   - If the difference is not the same at some particular index, then element of that index is missing.

   - We can add the index value and the difference to get the missing element.

   - And then we should either return or print the missing element.

   - After that we can break from the loop.

     Here's the Code

     ```c++
     struct Array{
         int A[10];
         int length;
         int size;
     };
     
     //missing elements in sorted array
     void find_single_missing_element(struct Array arr){
         int l,h,n;
         n=arr.length;
         l=arr.A[0];
         h=arr.A[n-1];
     
         for(int i=0;i<n;i++){
             if(l != (arr.A[i])-i){		//we can use the first element is difference
                 cout<< i+l <<" is missing from index "<<i<<endl;
                 break;
             }else{
                 continue;
             }
         }  
     }
     
     int main(){
         struct Array arr1 = {{3,4,5,7,8,9,11,12,13,14},10,10};
         find_single_missing_element(arr1);
     }
     
     //output
     6 is missing from index 3
     ```

2. **Multiple missing elements in a sorted array**

   - We will do the same here as we did for the single missing element function.

   - But, here we will keep a static integer for difference.

   - After we find the 1st difference we should update the difference by one (update by one until we reach the next element difference with it's index).

   - Since there might be multiple elements missing after a single index, we used that while loop.

     Here's the code

     ```c++
     struct Array{
         int A[10];
         int length;
         int size;
     };
     
     //multiple missing elements in sorted array
     void find_multi_missing_element(struct Array arr){
         int l,h,n;
         n=arr.length;
         l=arr.A[0];
         h=arr.A[n-1];
     
         static int diff = l;
     
         for(int i=0;i<n;i++){
             if(diff != (arr.A[i])-i){
                     while(diff < (arr.A[i])-i){    //this loop here if there's multiple elements missing from that index i
                         cout<< i+diff <<" is missing "<<endl;
                         diff++;
                 }
             }else{
                 continue;
             }
         }  
     }
     
     
     int main(){
         struct Array arr1 = {{3,4,5,7,8,9,11,12,15,16},10,10};
         find_multi_missing_element(arr1);
     }
     
     //output
     6 is missing 
     10 is missing
     13 is missing
     14 is missing
     ```



#### From a unsorted array

- We can find missing elements from an unsorted array, by using hashing technique.

- This will reduce the time complexity but might increase the space complexity(since we need to create a array of size equal to the maximum value element in the given unsorted array).

- But nowadays we do not worry much about space, because memory is abundant in today's computer's.

- So, in this hashing technique we create a array of size equal to the maximum value element in the given unsorted array, let's call this array 'h'.

- Then initialize the array elements of array 'h' as 0.

- Now, we will iterate through our given unsorted array.

- While iterating through the array, we will increment the index of array 'h'  by one if we find an equivalent element (equivalent to the index of array 'h') in the given unsorted array.

- After that, we'll iterate through the array 'h' if we find an element equal to zero that means that the index has not been updated then we will print that element as missing. 

- Therefore all elements which are equal to zero in array 'h' their indexes are missing in the given unsorted array. (i.e. if in array 'h' index 4 == 0 then element 4 is missing in the given unsorted array).

  Here's the code

  ```c++
  struct Array{
      int A[10];
      int length;
      int size;
  };
  
  //2nd method to find missing elements(works on unsorted arrays too) using hashing technique
  void find_missing_hash_method(struct Array arr){
      int hash_len = find_max(arr);
      int *h = new int(hash_len);    //created a new array of size equal to the max. element in given array
      for(int i=0; i<hash_len; i++){
          h[i] = 0;
      }
  
      for(int i=0; i<arr.length; i++){
          h[arr.A[i]]+=1;
      }
  
      for(int i=0; i<hash_len; i++){
          if(h[i]==0){
              cout<<i<<" is missing"<<endl;
          }else{
              continue;
          }
      }
  
      delete []h;
  }
  
  int main(){
  
      struct Array arr2 = {{3,7,4,9,12,6,1,11,2,10},10,10};
  
      find_missing_hash_method(arr2);
  }
  
  //output
  0 is missing
  5 is missing
  8 is missing
  ```



### Duplicates in a Array

#### Duplicates in a sorted array and counting the duplicates

- We can find the duplicate elements just by comparing the consecutive elements.

- We can also keep a count of how many time a element is occurring, by using another loop inside the initial loop(loop which helps to iterate the whole array).

  Here's the code 

  ```c++
  struct Array{
      int A[10];
      int length;
      int size;
  };
  
  void duplicate_sorted(struct Array arr){
      int lastDuplicate = 0;
  
      for(int i=0; i<arr.length-1; i++){
          if(arr.A[i]==arr.A[i+1] && arr.A[i]!=lastDuplicate){
              cout<<arr.A[i]<<" is a duplicate"<<endl;
              lastDuplicate=arr.A[i];
          }else{
              continue;
          }
      }
  }
  
  void duplicate_sorted_counter(struct Array arr){
      int lastDuplicate = 0;
  
      for(int i=0; i<arr.length-1; i++){
          int counter = 1;
          int j=i;
          while(arr.A[j]==arr.A[j+1]){     //this loop will increment the counter if there's a duplicate
              counter++,j++;
          }
          if(arr.A[i]==arr.A[i+1] && arr.A[i]!=lastDuplicate){
              cout<<arr.A[i]<<" occurs "<<counter<<" times"<<endl;
              lastDuplicate=arr.A[i];
          }else{
              continue;
          }
          i=j;        //here we skipped again checking the same elements
      }
  }
  
  int main(){
      struct Array arr1 = {{4,4,4,7,8,9,9,11,11,16},10,10};
      duplicate_sorted(arr1);
      cout<<"Duplicate in the array with counter:"<<endl;
      duplicate_sorted_counter(arr1);
  }
  
  //output
  4 is a duplicate
  9 is a duplicate
  11 is a duplicate
  Duplicate in the array with counter:
  4 occurs 3 times
  9 occurs 2 times
  11 occurs 2 times
  ```

#### Duplicates in a unsorted array and counting duplicates

- We can count the no. of elements using a hash array(like we did for finding missing elements), where we will  keep incrementing the index value in hash array duplicates occur. 

- If hash array has value more than 1 then, it's a duplicate element and has occurred equal to the hash array index value.

- Another method is to compare each element with every other element in the array and check if duplicates occurs and maintain a counter to count it.

- Once, we have encountered a duplicate element we can change the value to -1, so as to indicate that we have already counted this element.

  Here's the code for both methods

  ```c++
  struct Array{
      int A[10];
      int length;
      int size;
  };
  
  int find_max(struct Array arr){
      int max=arr.A[0];
      for(int i=0;i<arr.length;i++){
          if(arr.A[i]>max){
              max=arr.A[i];
          }else{
              continue;
          }
      }
      return max;
  }
  
  //works for both sorted and unsorted array
  void hash_duplicate_counter(struct Array arr){
      int hash_len=find_max(arr);
      int *h = new int[hash_len];
      for(int i=0; i<hash_len;i++){
          h[i]=0;
      }
  
      for(int i=0; i<arr.length; i++){
          h[arr.A[i]]++;
      }
  
      for(int i=0; i<hash_len; i++){
          if(h[i]>1){
              cout<<i<<" has occured "<<h[i]<<" times"<<endl;
          }else{
              continue;
          }
      }
  
      delete []h;
  }
  
  //this will also work for both sorted and unsorted
  void duplicate_unsorted_counter(struct Array arr){
      for(int i=0; i<arr.length-1; i++){
          int counter = 1;
          if(arr.A[i]!=-1){
              for(int j=i+1;j<arr.length;j++){
                  if(arr.A[i]==arr.A[j]){
                      arr.A[j]= -1;
                      counter++;
                  }else{
                      continue;
                  }
              }
              if(counter>1){
                  cout<<arr.A[i]<<" occurred "<<counter<<" times"<<endl;
              }else{
                  continue;
              }
          }
      }
  }
  
  int main(){
      struct Array arr1 = {{4,4,4,7,8,9,9,11,11,16},10,10};
      struct Array arr2 = {{2,1,6,9,12,6,1,1,2,10},10,10};
  
      cout<<"Duplicates using hash for sorted array:"<<endl;
      hash_duplicate_counter(arr1);
      cout<<"Duplicates using hash for unsorted array:"<<endl;
      hash_duplicate_counter(arr2);
      cout<<"Duplicates using nested for loop:"<<endl;
      duplicate_unsorted_counter(arr2);
  }
  
  //output
  Duplicates using hash for sorted array:
  4 has occured 3 times
  9 has occured 2 times
  11 has occured 2 times
  Duplicates using hash for unsorted array:
  1 has occured 3 times
  2 has occured 2 times
  6 has occured 2 times
  Duplicates using nested for loop:
  2 occurred 2 times
  1 occurred 3 times
  6 occurred 2 times
  ```



### Finding pair of elements in a array for a sum k

- We can find element pairs which will make a given.

- **Method 1**

- We can take one element and then add it with every other element on the array and compare if it comes as equal to the given sum, if it does come equal then we will print both the elements.

- We can do this for every element in the array.

- **Method 2**

- Another method is to use a hash array, to understand this either read code or watch the abdul bari video ( in Array ADT module video no. - 34)

- **Method 3**

- These above methods will work for both sorted and unsorted array, but if it's a unsorted there's more efficient method.

- If there's a sorted array, then for finding a given sum we can place i at index 0 and j at the last index. Now, if we get the addition of the values at i and j indexes then, we print both the elements and we do i++ and j--.

  If A[i] + A[j] < sum then:

  ​	i++

  if A[i] + A[j] > sum then:

  ​	j--;

- Here's the code for all the above methods

  ```c++
  struct Array{
      int A[10];
      int length;
      int size;
  };
  
  void pair_sum(struct Array arr, int sum){
      for(int i=0;i<arr.length;i++){
          for(int j=i+1;j<arr.length;j++){
              if(arr.A[i]+arr.A[j]==sum){
                  cout<<arr.A[i]<<" + "<<arr.A[j]<<" = "<<sum<<endl;
              }else{
                  continue;
              }
          }
      }
  }
  
  int find_max(struct Array arr){
      int temp = arr.A[0];
      for(int i=0;i<arr.length;i++){
          if(arr.A[i]>temp){
              temp=arr.A[i];
          }else{
              continue;
          }
      }
      return temp;
  }
  
  void hash_pair_sum(struct Array arr, int sum){
      int hash_len = find_max(arr);
      int *h = new int[hash_len];
  
      for(int i=0;i<hash_len;i++){
          h[i]=0;
      }
  
      for(int i=0; i<arr.length;i++){
          int pair_ele = sum - arr.A[i];
          if(h[pair_ele]!=0 && pair_ele>=0 && pair_ele<hash_len){
              cout<<arr.A[i]<<" + "<<pair_ele<<" = "<<sum<<endl;
          }
          h[arr.A[i]]++;
      }
  }
  
  void sorted_pair_sum(struct Array arr, int sum){
      int i=0,j=arr.length-1;
      while (i<j)
      {
          if(arr.A[i]+arr.A[j]==sum){
              cout<<arr.A[i]<<" + "<<arr.A[j]<<" = "<<sum<<endl;
              i++,j--;
          }else if( arr.A[i]+arr.A[j] < sum){
              i++;
          }else{
              j--;
          }
      }
      
  }
  
  int main(){
      struct Array arr1 = {{6,3,8,10,16,7,5,2,9,14},10,10};
      struct Array arr2 = {{1,3,4,5,6,8,9,10,12,14},10,10};
      int sum = 10;
      cout<<"Method 1 for finding the sum pair : "<<endl;
      pair_sum(arr1,sum);
      cout<<"Method 2 for finding the sum pair : "<<endl;
      hash_pair_sum(arr1,sum);
      cout<<"Method 3 for finding the sum pair : "<<endl;
      sorted_pair_sum(arr2,sum);
  }
  
  //output
  Method 1 for finding the sum pair : 
  3 + 7 = 10
  8 + 2 = 10
  Method 2 for finding the sum pair :
  7 + 3 = 10
  2 + 8 = 10
  Method 3 for finding the sum pair :
  1 + 9 = 10
  4 + 6 = 10
  ```

  



### Finding maximum and minimum in a single scan

- We can find max and min in a array in a single iteration using two temporary variables and two conditions.

  Here's the code

  ```c++
  #include<iostream>
  using namespace std;
  
  struct Array{
      int A[10];
      int length;
      int size;
  };
  
  void find_max_min(struct Array arr){
      int max = arr.A[0],min = arr.A[0];
  
      for(int i=0;i<arr.length;i++){
          if(arr.A[i]<min){
              min = arr.A[i];
          }else if(arr.A[i]>max){
              max = arr.A[i];
          }
      }
  
      cout<<"Max: "<<max<<", Min: "<<min<<endl;
  }
  
  int main(){
      struct Array arr = {{5,8,3,9,6,2,10,7,-1,4},10,10};
      find_max_min(arr);
  }
  
  //output
  Max: 10, Min: -1
  ```

  