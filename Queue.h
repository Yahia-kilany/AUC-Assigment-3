#ifndef QUEUE_H
#define QUEUE_H
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
    Queue ();
    Queue (int);
    ~Queue (){delete[] q;};
    bool isEmpty();
    bool isFull ();
    void Enqueue (T val);
    T Dequeue ();

};
#endif //QUEUE_H