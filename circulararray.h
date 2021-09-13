#include <iostream>
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
    int size();
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
    return (index == 0) ? capacity - 1 : index - 1;
}

template <class T>
int CircularArray<T>::next(int index)
{
    return (index + 1) % capacity;
}

/*template <class T>
string CircularArray<T>::to_string(string sep)
{
    string result = ""; 
    for (int i = 0; i < size(); i++)
        result += std::to_string((*this)[i]) + sep;
    return result;    
}*/


template<class T>
void CircularArray<T>::push_front(T data)
{
    array[next(front)] = data;
    front++;
    return;
}

template<class T>
void CircularArray<T>::push_back(T data)
{
    array[prev(back)] = data;
    back--;
    return;
}

/*template<class T>
void CircularArray<T>::insert(T data, int pos){
    array[pos]=data;
    return;
}*/

template<class T>
T CircularArray<T>::pop_front(){
    array[front] = 0;
    return front--;
}

template<class T>
T CircularArray<T>::pop_back(){
    array[back] = 0;
    return back++;
}

template<class T>
bool CircularArray<T>::is_empty(){
    return (front == -1 && back ==-1);
}

template<class T>
bool CircularArray<T>::is_full(){
    return (back = next(front));
}

template<class T> 
void CircularArray<T>::clear(){
    delete array;
    front = -1;
    back = -1;
}

template<class T>
int CircularArray<T>::size(){
    
}