#include <iostream>
#include "Container/Queue.h"



int main()
{
	std::string str; 
	Queue<std::string> queue;
	std::string value;

	std::cout << "문자 입력시 큐에 삽입.\n";
	std::cout << "de 입력시 dequeue.\n";
	std::cout << "undo, redo 입력 가능. \n";
	std::cout << "q 입력시 프로그램 종료 \n";

	while (str != "q")
	{
		
		std::cout << "입력해주세요 : ";
		std::cin >> str;

		if (str == "undo")
		{
			queue.Undo();
		}
		else if (str == "redo")
		{
			queue.Redo();
		}

		else if (str == "show")
		{
			std::cout << "undo, Redo 스택 목록\n";
			queue.strStack.show();
			queue.stringStack.show();
		}
		else if (str == "de")
		{
			queue.Dequeue(value);
		}
		else if (str == "print")
		{
			queue.Print();
		}
		else
		{
			queue.Enqueue(str);
		}
	}

}