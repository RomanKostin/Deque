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
		*@brief ���� ������ ����
		*/
		Node* head;

		/*
		*@brief ���� ������ ����
		*/
		Node* tail;

		/*
		*@brief ������ ����
		*/
		size_t size;

	public:
		/*
		*@brief ����������� �� ���������
		*/
		Deque() : head{ nullptr }, tail{ nullptr }, size{ 0 } {}

		/*
		*@brief ����������� ��� ������
		*@param list - ������
		*/
		Deque(std::initializer_list<int> list);

		/*
		*@brief ����������� �����������
		*@param other - ������ ���
		*/
		Deque(const Deque& other);

		/*
		*@brief ����������� �����������
		*@param other - ������ ���
		*/
		Deque(Deque&& other) noexcept;

		/*
		*@brief ���������� ����
		*/
		~Deque();

		/*
		*@brief �������� ������������ ��� ����
		*@param other - ������ ���
		*@return ���������� ���, ������ other
		*/
		Deque& operator=(const Deque& other);

		/*
		*@brief �������� ������������ ������������ ��� ����
		*@param other - ������ ���
		*@return ���������� ���, ������ other
		*/
		Deque& operator = (Deque&& other) noexcept;

		/*
		*@brief �������� "<<" ��� ������ ���
		*/
		friend std::ostream& operator << (std::ostream & output, const Deque & deque);

		/*
		*@brief ������� �������� ��������� ���� ����
		*/
		void pop_front();

		/*
		*@brief ������� �������� ���������� ���� ����
		*/
		void pop_back();
		
		/*
		*@brief ������� ���������� ���� ������� ����
		*@param value - ��������, ������� ����� ��������� ����� ����
		*/
		void push_front(const int value);

		/*
		*@brief ������� ���������� ���� � ����� ����
		*@param value - ��������, ������� ����� ��������� ����� ����
		*/
		void push_back(const int value);

		/*
		*@brief ������� ��� ��������� �������� ��������� ���� ����
		*@return �������� ��������� ����
		*/
		int front();

		/*
		*@brief ������� ��� ��������� �������� ���������� ���� ����
		*@return �������� ���������� ����
		*/
		int back();
		
		/*
		*@brief ������� �������� �� ������� ����
		*@return true ���� ��� ������, ����� false
		*/
		bool IsEmpty();
	};
}
