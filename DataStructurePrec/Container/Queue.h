#pragma once

#include "Stack.h"
#include <string>

template <typename T, int size = 10>
class Queue
{
public:
	Queue()
	{

	}

	bool Enqueue(const T& value)
	{
		if (IsFull())
		{
			return false;
		}

		rear = (rear + 1) % size;
		data[rear] = value;
		intStack.Push(value);
		stringStack.Push("Enqueue");
		return true;
	}

	bool Dequeue(T& outValue)
	{
		if (IsEmpty())
		{
			return false;
		}
		front = (front + 1) % size;
		outValue = data[front];
		data[front] = T(); // 초기화.
		intStack.Push(outValue);
		stringStack.Push("Dequeue");
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
		if (IsEmpty())
		{
			return false;
		}
		else
		{
			return data[(front + 1) % size];
		}
		
	}

	// 현재 상태에서 되돌리기.
	// ex) 이전 입력 : 큐에 "A" enqueue
	// A를 다시 빼내야함.

	// ex) 이전 입력 : 큐에 "A" dequeue
	// A를 다시 넣어야함.

	bool Undo()
	{
		// 스택에 top이 0이면 Undo 불가.
		if (stringStack.count() == 0)
		{
			return false;
		}

		if (stringStack.DataPeek() == "Enqueue")
		{
			stringStack.Pop();
			intStack.Pop();
			Dequeue(value);
		}
		else if (stringStack.DataPeek() == "Dequeue")
		{
			stringStack.Pop();
			T tmp = intStack.Pop();
			Enqueue(tmp);
		}

	}

	void Print()
	{
		std::cout << "큐 내용 출력: ";

		// 출력.
		const int max = (front < rear) ?
			rear : (rear + (size + 1));
		for (int ix = front + 1; ix <= max; ++ix)
		{
			std::cout << " " << data[ix % (size + 1)];
		}

		// 마무리.
		std::cout << "\n";
	}
private:
	int front = 0;
	int rear = 0;
	int value = 0;
	Stack<int> intStack;
	Stack<std::string> stringStack;
	T data[size + 1] = { };

};