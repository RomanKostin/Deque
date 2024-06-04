#include "pch.h"
#include "CppUnitTest.h"
#include "..\Solver\Deque.h"
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace Solvertest
{
	TEST_CLASS(DequeTest)
	{
	public:
		TEST_METHOD(EmptyDeque_Success)
		{
			rut::Deque deq;
			Assert::IsTrue(deq.IsEmpty());
		}
		TEST_METHOD(PushFrontOneTime_ValidData_Success)
		{
			rut::Deque deq;
			deq.push_front(1);
			Assert::AreEqual(deq.front(), 1);
		}
		TEST_METHOD(PushFrontFewTimes_ValidData_Success)
		{
			rut::Deque deq;
			deq.push_front(1);
			deq.push_front(2);
			Assert::AreEqual(deq.front(), 2);
		}
		TEST_METHOD(PushBackOneTime_ValidData_Success)
		{
			rut::Deque deq;
			deq.push_back(1);
			Assert::AreEqual(deq.back(), 1);
		}
		TEST_METHOD(PushBackFewTimes_ValidData_Success)
		{
			rut::Deque deq;
			deq.push_back(1);
			deq.push_back(2);
			Assert::AreEqual(deq.back(), 2);
		}
		TEST_METHOD(PushBackAndPushFront_ValidData_Success)
		{
			rut::Deque deq;
			deq.push_front(1);
			deq.push_back(4);
			Assert::AreEqual(deq.front(), 1);
			Assert::AreEqual(deq.back(), 4);
		}
		TEST_METHOD(PopFront_ValidData_Success)
		{
			rut::Deque deq{ 1,2,3 };
			deq.pop_front();
			Assert::AreEqual(deq.front(), 2);
			Assert::AreEqual(deq.back(), 3);
		}
		TEST_METHOD(PopBack_ValidData_Success)
		{
			rut::Deque deq{ 1,2,3 };
			deq.pop_back();
			Assert::AreEqual(deq.front(), 1);
			Assert::AreEqual(deq.back(), 2);
		}
		TEST_METHOD(EqualDequesConstruction_ValidData_Success)
		{
			rut::Deque deq1{ 1,2,3 }, deq2(deq1);
			Assert::AreEqual(deq1.front(), deq2.front());
			Assert::AreEqual(deq1.back(), deq2.back());
			deq1.pop_front();
			deq2.pop_front();
			Assert::AreEqual(deq1.front(),deq2.front());
		}
		TEST_METHOD(EqualDequesByOperator_ValidData_Success)
		{
			rut::Deque deq1{ 1,2,3 }, deq2 = deq1;
			Assert::AreEqual(deq1.front(), deq2.front());
			Assert::AreEqual(deq1.back(), deq2.back());
			deq1.pop_front();
			deq2.pop_front();
			Assert::AreEqual(deq1.front(), deq2.front());
		}
		TEST_METHOD(MoveConstructor_ValidData_Success)
		{
			rut::Deque deq1{ 1,2,3 }, deq2(std::move(deq1));
			Assert::AreEqual(deq2.front(), 1);
			deq2.pop_front();
			Assert::AreEqual(deq2.front(), 2);
			Assert::AreEqual(deq2.back(), 3);
		}
		TEST_METHOD(OperatorMove_ValidData_Success)
		{
			rut::Deque deq1{ 1,2,3 }, deq2=std::move(deq1);
			Assert::AreEqual(deq2.front(), 1);
			deq2.pop_front();
			Assert::AreEqual(deq2.front(), 2);
			Assert::AreEqual(deq2.back(), 3);
		}
	};
}
