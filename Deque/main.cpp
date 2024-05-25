#include <iostream>
#include "..\Solver\Deque.h"

int main()
{
	rut::Deque deq, list{ 1,2,3 };
	deq.push_front(7);
	deq.push_front(4);
	rut::Deque copy=list;
	std::cout << list;
	std::cout << copy;
	std::cin >> deq;
	std::cout << std::endl << deq;
	return 0;
}
