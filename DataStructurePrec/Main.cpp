#include <iostream>
#include "Container/Queue.h"



int main()
{
	Queue<int> queue;
	queue.Enqueue(10);
	queue.Enqueue(5);
	queue.Enqueue(6);
	queue.Enqueue(7);

	int value;
	value = queue.Dequeue(value);
	value = queue.Dequeue(value);
	value = queue.Dequeue(value);

	queue.Enqueue(6);
	queue.Enqueue(7);
	
	std::cout << "Undo 하기 전 출력 \n";
	queue.Print();

	queue.Undo();
	queue.Undo();

	std::cout << "Undo 후 출력 \n";
	queue.Print();


	queue.Enqueue(6);
	std::cout << "Redo 하기 전 출력 \n";
	queue.Print();

	queue.Redo();
	std::cout << "Redo 후 출력 \n";
	queue.Print();

	std::cin.get();

}