#include "circulararray.h"

template <typename T>
class QueueArray : public QueueArray<T> 
    {
private:
    T *array;
    int capacity;
    int back, front;
    
public:
    QueueArray();
    QueueArray(int _capacity);
    virtual ~QueueArray();
    void push_front(T data);  //Hecho
    T pop_back();  //Hecho
    bool is_full(); //Hecho
    bool is_empty(); //Hecho
    int size(); //Hecho
    void clear(); //Hecho

private:
    int next(int);
    int prev(int);
};

template <class T>
QueueArray<T>::QueueArray()
{
    QueueArray(0);
}

template <class T>
QueueArray<T>::QueueArray(int _capacity)
{
    this->array = new T[_capacity];
    this->capacity = _capacity;
    this->front = this->back = 0;
}

template <class T>
QueueArray<T>::~QueueArray()
{
    delete[] array;
}

template <class T>
int QueueArray<T>::prev(int index)
{
    if (index > 0) {index--;}
    else {cout<<"Queue is emppty, push some data from the front"<<endl;}
    return index;
}

template <class T>
int QueueArray<T>::next(int index)
{
    if (index <= capacity) {index++;}
    else{cout<<"Stak is full, pop some data from the back"<<endl;}
    return index;
}

template<class T>
bool QueueArray<T>::is_empty(){
    return (front == 0 && back == 0);
}

template<class T>
bool QueueArray<T>::is_full(){
    return (front == capacity - 1);
}

template<class T> 
void QueueArray<T>::clear(){
    delete array;
    front = 0;
    back = 0;   
}

template<class T>
int QueueArray<T>::size(){
    return (front +1);
}


template<class T>
T QueueArray<T>::pop_back(){
    if (is_empty() == false){
        *(array + back) = back*0;
        back=next(back);
        }
    else{
        cout<<"Array is empty can not pop more data."<<endl;
        }
    return back;
}

template<class T>
void QueueArray<T>::push_front(T data)
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