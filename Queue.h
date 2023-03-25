#ifndef QUEUE_H
#define QUEUE_H
#define Max 1000
template <class T>
class Queue
{
private:
    int front;
    int rear;
    int counter;
    int size;
    T* q;
public:
    Queue ();//default constructor that sets array q to size MAX
    Queue (int);//constructor that sets array q to the parameter
    ~Queue () { delete[] q; };
    bool isEmpty ();
    bool isFull ();
    void push (T val);
    T top ();
    T pop ();

};
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
bool Queue<T>::isFull ()
{
    return !(counter < size);
}
template <class T>
bool Queue<T>::isEmpty ()
{
    return !counter;
}
template <class T>
void Queue<T>::push (T val)
{
    if (isFull ())
    {
        cout << "Error: queue overflow";
        exit(1);
    }
    else
    {
        rear = (rear + 1) % size;
        *(q + rear) = val;
        counter++;
    }
}
template <class T>
T Queue<T>::top ()
{
    if ( isEmpty ())
    {
        cout << "Error: Queue is empty" << endl;
        exit (1);
    }
    else {
        return *(q + front);
    }
}
template <class T>
T Queue<T>::pop ()
{
    if (isEmpty ())
    {
        cout << "Error: Queue underflow" << endl;
        exit (1);
    }
    else
    {
        T x = *(q + front);
        front = (front + 1) % size;
        counter--;
        return x;
    }
}
#endif //QUEUE_H