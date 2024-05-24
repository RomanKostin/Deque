#pragma once
#include "Node.h"
namespace rut
{
	class Deque
	{
	private:

		Node* head;
		Node* tail;
		size_t size;

	public:

		Deque() : head(nullptr), tail(nullptr), size(0) {}

		~Deque();

		void pop_front();

		void pop_back();

		void push_front(const int value);

		void push_back(const int value);

		int front();

		int back();
	};
}
