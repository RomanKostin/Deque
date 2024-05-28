#include <iostream>
#include "..\Solver\Deque.h"

int main()
{
	rut::Deque deq, list{ 1,2,3 };
	deq.push_front(7);
	deq.push_front(4);
	deq.push_front(44);
	rut::Deque copy=list;
	rut::Deque test(deq);
	std::cout << list;
	std::cout << test;
	rut::Deque stest(std::move(deq));
	deq = list;
	std::cout << std::endl << deq;
	return 0;
}
