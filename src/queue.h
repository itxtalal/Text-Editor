#include<iostream>
#include<string>
using namespace std;
template<typename T>

// Defining Class of Queue
class queue
{
	int front;
	int rear;
	T *q;
	int size;
	public:
		queue();
		queue(T);
		void enqueue(T);
		T dequeue();
};

// Constructors
template<class T>
queue<T>::queue()
{
	front=-1;
	rear=-1;
	size=10;
	q=new T[size]();
}
template<class T>
queue<T>::queue(T n)
{
	front=-1;
	rear=-1;
	size=n;
	q=new T[size]();
}

// Enqueue() method
template<class T>
void queue<T>::enqueue(T d)
{
	if(rear==size)
	cout<<"queue is full";
	else
	{
		rear++;
		q[rear]=d;
	}
}

// Dequeue() method
template<class T>
T queue<T>::dequeue()
{
	T element;
	if(rear==front)
	cout<<"queue is empty";
	else
	{
		front++;
		element=q[front];
	}
	return element;
}
