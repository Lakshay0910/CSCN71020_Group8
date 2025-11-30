#include "pch.h"
#include "CppUnitTest.h"
#include "../PolygonChecker/main.h"  

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace PolygonCheckerTest
{
    TEST_CLASS(IsTriangleTests)
    {
    public:

        TEST_METHOD(NegativeNumber)
        {
            Assert::AreEqual(0, isTriangle(-33, 23, 24));
        }

        TEST_METHOD(LargeTriangleImpossible)
        {
            Assert::AreEqual(0, isTriangle(9340403, 3994933, 4234243434));
        }

        TEST_METHOD(TwoLongOneShort)
        {
            Assert::AreEqual(1, isTriangle(99, 99, 1));
        }

        TEST_METHOD(ZeroSide)
        {
            Assert::AreEqual(0, isTriangle(10, 34, 0));
        }

        TEST_METHOD(ValidTriangle)
        {
            Assert::AreEqual(1, isTriangle(3, 4, 5));
        }

        TEST_METHOD(EquilateralTriangle)
        {
            Assert::AreEqual(1, isTriangle(10, 10, 10));
        }

        TEST_METHOD(IsoscelesTriangle)
        {
            Assert::AreEqual(1, isTriangle(7, 7, 5));
        }

        TEST_METHOD(FlatLine)
        {
            Assert::AreEqual(0, isTriangle(5, 5, 10)); 
        }
    };
}
