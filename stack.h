#include "circulararray.h"

template <typename T>
class StackArray : public StackArray<T>
    {
private:
    T *array;
    int capacity;
    int back, front;
    
public:
    StackArray();
    StackArray(int _capacity);
    virtual ~StackArray();
    void push_front(T data);  //Hecho
    T pop_front();  //Hecho
    bool is_full(); //Hecho
    bool is_empty(); //Hecho
    int size(); //Hecho
    void clear(); //Hecho

private:
    int next(int);
    int prev(int);
};

template <class T>
StackArray<T>::StackArray()
{
    StackArray(0);
}

template <class T>
StackArray<T>::StackArray(int _capacity)
{
    this->array = new T[_capacity];
    this->capacity = _capacity;
    this->front = this->back = 0;
}

template <class T>
StackArray<T>::~StackArray()
{
    delete[] array;
}

template <class T>
int StackArray<T>::prev(int index)
{
    if (index > 0) {index--;}
    else {cout<<"Stack is emppty, push some data"<<endl;}
    return index;
}

template <class T>
int StackArray<T>::next(int index)
{
    if (index <= capacity) {index++;}
    else{cout<<"Stak is full, pop some data"<<endl;}
    return index;
}

template<class T> 
void StackArray<T>::clear(){
    delete array;
    front = 0;
    back = 0;   
}

template<class T>
int StackArray<T>::size(){
    return (front +1);
}

template<class T>
void StackArray<T>::push_front(T data)
{
    if (is_full() == false){
        front=next(front);
        *(array+front) = data;
    }
    else {
        cout<<"Array is full can not push more data"<<endl;
    }
    return;
}

template<class T>
T StackArray<T>::pop_front()
{
    front=(front+capacity)%capacity;
    if (is_empty() == false){
        *(array+front) = 0;
        front=prev(front);
        }
    else{
        cout<<"Array is empty can not pop more data"<<endl;
        }
    return front;
}