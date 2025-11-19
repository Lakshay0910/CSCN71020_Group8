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
    };
}
