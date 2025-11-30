#include "pch.h"
#include "CppUnitTest.h"
#include <string>

// include the header from PolygonChecker project
#include "../PolygonChecker/TriangleType.h"  

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace PolygonCheckerTests
{
    TEST_CLASS(TriangleTypeTests)
    {
    public:

        TEST_METHOD(Equilateral_333_ReturnsEquilateral)
        {
            Assert::AreEqual(std::string("Equilateral"), GetTriangleType(3, 3, 3));
        }

        TEST_METHOD(Isosceles_334_ReturnsIsosceles)
        {
            Assert::AreEqual(std::string("Isosceles"), GetTriangleType(3, 3, 4));
        }

        TEST_METHOD(Scalene_345_ReturnsScalene)
        {
            Assert::AreEqual(std::string("Scalene"), GetTriangleType(3, 4, 5));
        }

        TEST_METHOD(Boundary_123_NotTriangle)
        {
            Assert::AreEqual(std::string("Not a triangle"), GetTriangleType(1, 2, 3));
        }

        TEST_METHOD(ZeroOrNegative_NotTriangle)
        {
            Assert::AreEqual(std::string("Not a triangle"), GetTriangleType(0, 5, 5));
        }

        TEST_METHOD(Isosceles_5_7_7)
        {
            Assert::AreEqual(std::string("Isosceles"), GetTriangleType(5, 7, 7));
        }

        TEST_METHOD(Invalid_ZeroSide)
        {
            Assert::AreEqual(std::string("Not a triangle"), GetTriangleType(0, 5, 5));
        }

        TEST_METHOD(Invalid_NegativeSide)
        {
            Assert::AreEqual(std::string("Not a triangle"), GetTriangleType(-3, 4, 5));
        }

        TEST_METHOD(Invalid_Boundary_1_2_3)
        {
            Assert::AreEqual(std::string("Not a triangle"), GetTriangleType(1, 2, 3));
        }

        TEST_METHOD(Isosceles_LargeValues)
        {
            Assert::AreEqual(std::string("Isosceles"), GetTriangleType(1000, 1000, 1500));
        }
    };
}
