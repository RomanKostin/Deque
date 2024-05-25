#include "Deque.h"

rut::Deque::Deque(std::initializer_list<int> list)
{
	for (int x : list)
	{
		push_back(x);
	}
}

rut::Deque::~Deque()
{
    while (!(IsEmpty())) 
    {
		pop_front();
    }
}

rut::Deque& rut::Deque::operator=(const Deque& other)
{
	Node* temp = other.head;
	while (!(IsEmpty()))
	{
		pop_front();
	}
	while (temp != nullptr)
	{
		push_back(temp->data);
		temp = temp->next;
	}
	return *this;
}

void rut::Deque::pop_front()
{
	if (IsEmpty())
	{
		throw std::out_of_range("выход за пределы дэка");
	}
	if (this->head == this->tail)
	{
		this->head = this->tail = nullptr;
	}
	else
	{
		this->head = this->head->next;
		this->head->prev = nullptr;
	}
	--this->size;
}

void rut::Deque::pop_back()
{
	if (IsEmpty())
	{
		throw std::out_of_range("выход за пределы дэка");
	}
	if (this->head == this->tail)
	{
		this->head = this->tail = nullptr;
	}
	else
	{
		this->tail = this->tail->prev;
		this->tail->next = nullptr;
	}
	--this->size;
}

void rut::Deque::push_front(const int value)
{
	Node* frontNode = new Node(value);
	if (IsEmpty())
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
	if (IsEmpty())
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
	if (IsEmpty())
	{
		throw std::out_of_range("выход за границы дэка");
	}
	return this->head->data;
}

int rut::Deque::back()
{
	if (IsEmpty())
	{
		throw std::out_of_range("выход за границы дэка");
	}
	return this->tail->data;
}

bool rut::Deque::IsEmpty()
{
	return this->size == 0;
}

std::ostream& rut::operator<<(std::ostream& output, const Deque& deque)
{
	Deque temp = deque;
	while (!(temp.IsEmpty()))
	{
		output << temp.front()<<std::endl;
		temp.pop_front();
	}
	return output;
}

std::istream& rut::operator>>(std::istream& input, Deque& deque)
{
	std::cout << "press ctrl z to stop" << std::endl;
	while (!(deque.IsEmpty()))
	{
		deque.pop_front();
	}
	int value;
	while (input>>value)
	{
		deque.push_back(value);
	}
	return input;
}
