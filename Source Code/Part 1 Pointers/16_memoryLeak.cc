    #include <iostream>
    using namespace std;

    void functionHeap(){
        int (*A) = new int[5];
        for(int i = 0; i < 5 ; i++){
            *(A+i)=i+1;
        }
        cout<<"Address: "<<A<<endl;
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
        cout<<"Address: "<<A<<endl;
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