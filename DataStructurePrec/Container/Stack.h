#pragma once
#include <string>

template <typename T, int size = 10>
class Stack {
	
public:
	Stack()
		: top(0)
	{
		
	}

	~Stack()
	{
		clear();
	}

	bool IsFull()
	{
		return top >= size;
	}

	bool IsEmpty()
	{
		return top == 0;
	}

	bool Push(T value)
	{
		if (IsFull())
		{
			return false;
		}
		data[top] = value;
		top++;

		return true;
	}

	T Pop()
	{
		if (IsEmpty())
		{
			return 0;
		}
		--top;
		return data[top];
	}

	int count()
	{
		return top;
	}

	void clear()
	{
		top = 0;
	}
	
	T DataPeek()
	{
		return data[top - 1];
	}
private:
	
	int top = 0;
	T data[size];

};