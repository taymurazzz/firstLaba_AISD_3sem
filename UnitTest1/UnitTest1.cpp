#include "pch.h"
#include "CppUnitTest.h"
#include "../firstLaba/Header.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(push_back_test)
		{
			spisok obj;
			obj.begin_of_work();
			obj.push_back(1);
			int data;
			data = obj.allHead->next->data;
			Assert::IsTrue(data == 1);
			obj.end_of_work();
		}

		TEST_METHOD(push_front_test)
		{
			spisok obj;
			obj.begin_of_work();
			obj.push_front(1);
			int data;
			data = obj.allHead->next->data;
			Assert::IsTrue(data == 1);
			obj.end_of_work();
		}
		TEST_METHOD(pop_back_test) {
			spisok obj;
			obj.begin_of_work();
			obj.push_back(1);
			obj.pop_back();
			Assert::IsTrue(obj.isEmpty() == 1);
			obj.end_of_work();
		}

		TEST_METHOD(pop_front_test) {
			spisok obj;
			obj.begin_of_work();
			obj.push_back(1);
			obj.pop_front();
			Assert::IsTrue(obj.isEmpty() == 1);
			obj.end_of_work();
		}

		TEST_METHOD(insert_test) {
			spisok obj;
			obj.begin_of_work();
			obj.push_back(0);
			obj.push_back(1);
			obj.push_back(3);
			obj.insert(2, 2);
			Assert::IsTrue(obj.allHead->next->next->next->data == 2);
			obj.end_of_work();
		}

		TEST_METHOD(at_test) {
			spisok obj;
			obj.begin_of_work();
			obj.push_back(0);
			obj.push_back(1);
			obj.push_back(2);
			Assert::IsTrue(obj.at(2) == 2);
			obj.end_of_work();
		}

		TEST_METHOD(remove_test) {
			spisok obj;
			obj.begin_of_work();
			obj.push_back(0);
			obj.push_back(1);
			obj.push_back(2);
			obj.remove(1);
			Assert::IsFalse(obj.allHead->next->next->data==1);
			obj.end_of_work();
		}

		TEST_METHOD(get_size_test) {
			spisok obj;
			obj.begin_of_work();
			obj.push_back(0);
			obj.push_back(1);
			obj.push_back(2);
			Assert::IsTrue(obj.get_size() == 3);
			obj.end_of_work();
		}

		TEST_METHOD(clear_test) {
			spisok obj;
			obj.begin_of_work();
			obj.push_back(1);
			obj.push_back(1);
			obj.push_back(1);
			obj.clear();
			Assert::IsTrue(obj.isEmpty() == 1);
			obj.end_of_work();
		}

		TEST_METHOD(set_test) {
			spisok obj;
			obj.begin_of_work();
			obj.push_back(1);
			obj.set(0,2);
			Assert::IsTrue(obj.allHead->next->data == 2);
			obj.end_of_work();
		}

		TEST_METHOD(isEmpty_test) {
			spisok obj;
			obj.begin_of_work();
			obj.push_back(1);
			Assert::IsTrue(obj.isEmpty() == 0);
			obj.clear();
			Assert::IsTrue(obj.isEmpty() == 1);
			obj.end_of_work();
		}
		TEST_METHOD(reverse_test) {
			spisok obj;
			obj.begin_of_work();
			obj.push_back(1);
			obj.push_back(2);
			obj.reverse();
			Assert::IsTrue(obj.allHead->next->data == 2);
			Assert::IsTrue(obj.allHead->next->next->data == 1);
			obj.end_of_work();
		}
	};
}
