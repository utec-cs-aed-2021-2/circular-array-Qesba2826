#include <iostream>
#include <stdlib.h>
#include <ctime>

using namespace std;

template <class T>
class CircularArray
{
private:
    T *array;
    int capacity;
    int back, front;
    
public:
    CircularArray();
    CircularArray(int _capacity);
    virtual ~CircularArray();
    void push_front(T data);  //Hecho
    void push_back(T data);  //Hecho
    void insert(T data, int pos);  //Hecho
    T pop_front();  //Hecho
    T pop_back();  //Hecho
    bool is_full(); //Hecho
    bool is_empty(); //Hecho
    int size(); //Hecho
    void clear(); //Hecho
    T &operator[](int);
    void sort();
    bool is_sorted();
    void reverse();
    string to_string(string sep=" ");

private:
    int next(int);
    int prev(int);
};

template <class T>
CircularArray<T>::CircularArray()
{
    CircularArray(0);
}

template <class T>
CircularArray<T>::CircularArray(int _capacity)
{
    this->array = new T[_capacity];
    this->capacity = _capacity;
    this->front = this->back = -1;
}

template <class T>
CircularArray<T>::~CircularArray()
{
    delete[] array;
}

template <class T>
int CircularArray<T>::prev(int index)
{
    return (index <= 0) ? capacity - 1 : index - 1;
}

template <class T>
int CircularArray<T>::next(int index)
{
    return  (index + 1) % capacity;
}

template <class T>
string CircularArray<T>::to_string(string sep)
{
    string result = ""; 
    for (int i = 0; i < size()+1; i++)
        result += std::to_string((*this)[i]) + sep;
    return result;    
}

template<class T>
bool CircularArray<T>::is_empty(){
    return (front == back);
}

template<class T>
bool CircularArray<T>::is_full(){
    return (size() == capacity);
}

template<class T>
void CircularArray<T>::push_front(T data)
{
    if (is_full() == false){
        front=next(front);
        *(array+front) = data;
    }
    else {
        cout<<"Array is full can not push more data"<<endl;
    }
    cout<<"front:"<<front<<" data:"<<data<<endl;
    cout<<*(array+front)<<endl;
    return;
}

template<class T>
void CircularArray<T>::push_back(T data)
{
    if (is_full() == false){
        back=prev(back);
        *(array+back)=data;
    }
    else {
        cout<<"Array is full can not push more data."<<endl;
    }
    cout<<"back:"<<back<<" data:"<<data<<endl;
    cout<<*(array+back)<<endl;
    return;
}

template<class T>
void CircularArray<T>::insert(T data, int pos)
{
    *(array+pos)=data;
    return;
}

template<class T>
T CircularArray<T>::pop_front()
{
    cout<<"frontorg"<<front<<endl;
    front=(front+capacity)%capacity;
    if (is_empty() == false){
        *(array+front) = 0;
        front=prev(front);
        cout<<"front:"<<front<<" valuein: "<<*(array+front)<<endl;
        }
    else{
        cout<<"Array is empty can not pop more data"<<endl;
        }
    cout<<"front:"<<front<<" value: "<<*(array+front)<<endl;
    return front;
}

template<class T>
T CircularArray<T>::pop_back(){
    if (is_empty() == false){
        *(array + back) = back*0;
        back=next(back);
        }
    else{
        cout<<"Array is empty can not pop more data."<<endl;
        }
    cout<<"back:"<<back<<" value: "<<*(array+back)<<endl;
    return back;
}

template<class T> 
void CircularArray<T>::clear(){
    delete array;
    front = -1;
    back = -1;   
}

template<class T>
int CircularArray<T>::size(){
    return (capacity + front - back)%capacity;
}

template<class T>
T &CircularArray<T>::operator[](int front){
    return array[front];
}