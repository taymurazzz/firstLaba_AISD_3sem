#include "CppUnitTest.h"
#include "../firstLaba/Header.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;



TEST_CLASS(spisok)
{
public:
		
TEST_METHOD(push_back_test)
	{
		spisok obj;
		obj.push_back(11);

	}

};

