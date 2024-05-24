#include "Deque.h"
#include<iostream>

rut::Deque::~Deque()
{
	while (!(this->size == 0))
	{
		pop_front();
	}
}

void rut::Deque::pop_front()
{
	if (this->size <= 0)
	{
		throw std::out_of_range("выход за пределы дэка");
	}
	Node* temp = this->head;
	if (this->head == this->tail)
	{
		this->head = this->tail = nullptr;
	}
	else
	{
		this->head->prev = nullptr;
	}
	delete temp;
	--this->size;
}

void rut::Deque::pop_back()
{
	if (this->size <= 0)
	{
		throw std::out_of_range("выход за пределы дэка");
	}
	Node* temp = this->tail;
	if (this->head == this->tail)
	{
		this->head = this->tail = nullptr;
	}
	else
	{
		this->tail->next = nullptr;
	}
	delete temp;
	--this->size;
}

void rut::Deque::push_front(const int value)
{
	Node* frontNode = new Node(value);
	if (this->size == 0)
	{
		this->head = this->tail = frontNode;
	}
	else
	{
		this->head->prev = frontNode;
		frontNode->next = this->head;
		this->head = frontNode;
	}
	++this->size;
}

void rut::Deque::push_back(const int value)
{
	Node* backNode = new Node(value);
	if (this->size == 0)
	{
		this->head = this->tail = backNode;
	}
	else
	{
		this->tail->next = backNode;
		backNode->prev = this->tail;
		this->tail = backNode;
	}
	++this->size;
}

int rut::Deque::front()
{
	if (this->size == 0)
	{
		throw std::out_of_range("выход за границы дэка");
	}
	return this->head->data;
}

int rut::Deque::back()
{
	if (this->size == 0)
	{
		throw std::out_of_range("выход за границы дэка");
	}
	return this->tail->data;
}
