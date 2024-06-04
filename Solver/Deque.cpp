#include "Deque.h"
#include <utility>
rut::Deque::Deque(std::initializer_list<int> list)
{
	for (auto& x : list)
	{
		push_back(x);
	}
}

rut::Deque::Deque(const Deque& other) :Deque()
{
	Node* temp = other.head;
	while (temp != nullptr)
	{
		push_back(temp->data);
		temp = temp->next;
	}
}

rut::Deque::Deque(Deque&& other) noexcept : head{ other.head }, tail{ other.tail }, size{other.size}
{
	other.head = other.tail = nullptr;
	other.size = 0;
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
	if (this != &other)
	{
		Deque temp(other);
		std::swap(this->head, temp.head);
		std::swap(this->tail, temp.tail);
		std::swap(this->size, temp.size);
	}
	return *this;
}

rut::Deque& rut::Deque::operator=(Deque&& other) noexcept
{
	if (this != &other)
	{
		if (this == &other)
		{
			return *this;
		}
	}
	this->head = other.head;
	this->tail = other.tail;
	this->size = other.size;
	other.head = other.tail = nullptr;
	other.size = 0;
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