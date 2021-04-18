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
Arithmetic<T>::Arithmetic(T a, T b){        //We have to pass the template parameter in '<>' before using the class name
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
    Arithmetic<int> ar(10,5);   //We have pass the template parameter, that what type of data you'll pass to the class
    cout<<ar.add()<<endl;
    cout<<ar.sub()<<endl;

    Arithmetic<double> ar1(1.2,0.5);   //using the same generic class for int and double by just passing the template data type
    cout<<ar1.add()<<endl;
    cout<<ar1.sub()<<endl;
}