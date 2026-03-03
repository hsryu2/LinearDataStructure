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

		if (!IsUndo)
		{
			rear = (rear + 1) % size;
			data[rear] = value;
			strStack.Push(value);
			stringStack.Push("Enqueue");
		}
		else
		{
			// (이전 실행이 Dequeue) undo 실행시
			// 이전에 있던 데이터를 현재 front에 넣고
			// front를 하나 이전 시점으로 옮겨줘야한다.
			data[front] = value; // 초기화.
			front = ((front - 1) % size);
			IsUndo = false;
		}

		return true;
	}

	bool Dequeue(T& outValue)
	{
		if (IsEmpty())
		{
			return false;
		}

		if (!IsUndo)
		{
			front = (front + 1) % size;
			outValue = data[front];
			data[front] = T(); // 초기화.
			strStack.Push(outValue);
			stringStack.Push("Dequeue");
		}
		else
		{
			// (이전 실행이 Enqueue) undo 실행시
			// 이전에 있던 데이터를 초기화 시켜주고, 
			// front를 하나 이전 시점으로 옮겨줘야한다.
			data[rear] = value;
			rear = ((rear - 1) % size);
			IsUndo = false;

		}
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
		IsUndo = true;
		if (stringStack.DataPeek() == "Enqueue")
		{
			stringStack.Pop();
			strStack.Pop();
			Dequeue(value);
		}
		else if (stringStack.DataPeek() == "Dequeue")
		{
			stringStack.Pop();
			T tmp = strStack.Pop();
			Enqueue(tmp);
		}
		return true;
	}
	
	bool Redo()
	{
		if (stringStack.count() == 0)
		{
			return false;
		}

		if (stringStack.DataPeek() == "Enqueue")
		{
			T tmp = strStack.DataPeek();
			Enqueue(tmp);
		}
		else if (stringStack.DataPeek() == "Dequeue")
		{
			strStack.DataPeek();
			T tmp;
			Dequeue(tmp);
		}
		return true;
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
public:
	// 데이터 정보를 넣을 strStack
	// enqueue, dequeue를 구분 할 stringStack
	Stack<std::string> strStack;
	Stack<std::string> stringStack;
private:
	int front = 0;
	int rear = 0;

	// 초기화 전용 값.
	T value = " ";

	// undo를 호출했을때 구분지을 변수.
	bool IsUndo = false;

	T data[size + 1] = { };

};