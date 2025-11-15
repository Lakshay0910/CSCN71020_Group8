#include "pch.h"
#include "CppUnitTest.h"
#include ".../CSCN71020_Group8/main.h"
extern "C" char* isTriangle(int side1, int side2, int side3);
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace isTriangle
{
	TEST_CLASS(isTriangle)
	{
	public:
		
		TEST_METHOD(negativeNumbber)
		{
			char* result = isTriangle(-33, 23, 24);
			Assert::AreEqual(result, "These line can't form a triangle. ");
		}
		TEST_METHOD(largeTriangle)
		{
			char* result = isTriangle(9340403, 3994933, 4234243434);
			Assert::AreEqual(result, "These line can't form a triangle. ");
		}
		TEST_METHOD(twoLongOneShort)
		{
			char* result = isTriangle(99, 99, 1);
			Assert::AreEqual(result, "These line can't form a triangle. ");
		}
		TEST_METHOD(zero)
		{
			char* result = isTriangle(10, 34, 0);
			Assert::AreEqual(result, "These line can't form a triangle. ");
		}
	};
}
