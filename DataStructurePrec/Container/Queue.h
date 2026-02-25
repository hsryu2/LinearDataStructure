#pragma once

#include "Stack.h"

template <typename T, int Size = 10>
class Queue
{
public:
	Queue()
		: front(0), rear(0), size(Size + 1)
	{

	}

	bool Enqueue(const T& value)
	{
		if (IsFull)
		{
			return false;
		}

		rear = (rear + 1) % size;
		data[rear] = value;
		stack.Push(value);
		return true
	}

	bool Dequeue(T& outValue)
	{
		if (IsEmpty)
		{
			return false;
		}
		front = (front + 1) % size;
		outValue = data[front];
		data[front] = T(); // √ ±‚»≠.
		return true;
	}

	bool IsEmpty()
	{
		return rear == front;
	}

	bool IsFull()
	{
		return (rear + 1) % size == front;
	}

	T Peek()
	{
		if (IsEmpty)
		{
			return false;
		}
		else
		{
			return data[(front + 1) % size];
		}
		
	}



private:
	int front;
	int rear;
	int size;
	Stack stack;
	T data[];

};