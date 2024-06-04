#pragma once
#include<iostream>
#include "Node.h"
#include <initializer_list>

namespace rut
{
	class Deque
	{
	private:
		/*
		*@brief узел головы дэка
		*/
		Node* head;

		/*
		*@brief узел хвоста дэка
		*/
		Node* tail;

		/*
		*@brief размер дэка
		*/
		size_t size;

	public:
		/*
		*@brief конструктор по умолчанию
		*/
		Deque() : head{ nullptr }, tail{ nullptr }, size{ 0 } {}

		/*
		*@brief конструктор для списка
		*@param list - список
		*/
		Deque(std::initializer_list<int> list);

		/*
		*@brief конструктор копирования
		*@param other - другой дэк
		*/
		Deque(const Deque& other);

		/*
		*@brief конструктор перемещения
		*@param other - другой дэк
		*/
		Deque(Deque&& other) noexcept;

		/*
		*@brief деструктор дэка
		*/
		~Deque();

		/*
		*@brief оператор присваивания для дэка
		*@param other - другой дэк
		*@return возвращает дэк, равный other
		*/
		Deque& operator=(const Deque& other);

		/*
		*@brief оператор присваивания перемещением для дэка
		*@param other - другой дэк
		*@return возвращает дэк, равный other
		*/
		Deque& operator = (Deque&& other) noexcept;

		/*
		*@brief оператор "<<" для класса дэк
		*/
		friend std::ostream& operator << (std::ostream & output, const Deque & deque);

		/*
		*@brief функция удаления переднего узла дэка
		*/
		void pop_front();

		/*
		*@brief функция удаления последнего узла дэка
		*/
		void pop_back();
		
		/*
		*@brief функция добавления узла спереди дэка
		*@param value - значение, которое будет принимать новый узел
		*/
		void push_front(const int value);

		/*
		*@brief функция добавления узла в конце дэка
		*@param value - значение, которое будет принимать новый узел
		*/
		void push_back(const int value);

		/*
		*@brief функция для получения значения переднего узла дэка
		*@return значение переднего узла
		*/
		int front();

		/*
		*@brief функция для получения значения последнего узла дэка
		*@return значение последнего узла
		*/
		int back();
		
		/*
		*@brief функция проверки на пустоту дэка
		*@return true если дэк пустой, иначе false
		*/
		bool IsEmpty();
	};
}
