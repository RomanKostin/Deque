#pragma once
#include<iostream>
#include "Node.h"
#include <initializer_list>

namespace rut
{
	class Deque
	{
	private:

		Node* head;
		Node* tail;
		size_t size;

	public:

		Deque() : head{ nullptr }, tail{ nullptr }, size{ 0 } {}

		Deque(std::initializer_list<int> list);

		Deque(const Deque& other);

		Deque(Deque&& other) noexcept;

		~Deque();

		Deque& operator=(const Deque& other);

		Deque& operator = (Deque&& other) noexcept;

		friend std::ostream& operator << (std::ostream & output, const Deque & deque);

		void pop_front();

		void pop_back();

		void push_front(const int value);

		void push_back(const int value);

		int front();

		int back();
		
		bool IsEmpty();
	};
}
