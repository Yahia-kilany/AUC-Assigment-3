#include "Queue.h"
#include <iostream>
#define Max 1000
using namespace std;
template <class T>
Queue<T>::Queue ()
{
    front = 0;
    rear = -1;
    counter = 0;
    size = Max;
    q = new T[Max];
}
template <class T>
Queue<T>::Queue (int n)
{
    front = 0;
    rear = -1;
    counter = 0;
    size = n;
    q = new T[size];
}
template <class T>
bool Queue<T>::isFull()
{
    return !(counter < size);
}
template <class T>
bool Queue<T>::isEmpty()
{
    return counter;
}
template <class T>
void Queue<T>::Enqueue (T val)
{
    if (isFull())
    {
        cout << "Error: queue overflow";
        return;
    }
    else
    {
        rear = (rear + 1) % size;
        *(q + rear) = val;
        counter++;
    }
}
template <class T>
T Queue<T>::Dequeue ()
{
    if (isEmpty ())
    {
        cout << "Error: Queue underflow" << endl;
        return;
    }
    else
    {
        T x = *(q + front);
        front = (front + 1) % size;
        counter--;
        return x;
    }
}


