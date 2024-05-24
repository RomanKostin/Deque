#include <iostream>
#include "..\Solver\Deque.h"

int main()
{
	rut::Deque deq;
	deq.push_front(1);
	std::cout << deq.front();
	return 0;
}
