#include "pch.h"
#include "CppUnitTest.h"

#include "../PolygonChecker/rectangle_solver.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

// Shape type constants for tests
#define SHAPE_QUADRILATERAL 1
#define SHAPE_SQUARE        2
#define SHAPE_RECTANGLE     3

namespace PolygonCheckerTests
{
    TEST_CLASS(FourPointsTests)
    {
    public:

        // 3-4-5 triangle distance test
        TEST_METHOD(TestDistance_Simple345)
        {
            Point p1 = { 0.0, 0.0 };
            Point p2 = { 3.0, 4.0 };

            double actual = calculateDistance(p1, p2);
            double expected = 5.0;

            Assert::AreEqual(expected, actual, 0.0001, L"Distance calculation failed.");
        }

        // 6x4 rectangle should be detected as rectangle (value 3)
        TEST_METHOD(TestGetShapeType_IsRectangle)
        {
            Point p1 = { 0.0, 0.0 };
            Point p2 = { 6.0, 0.0 };
            Point p3 = { 6.0, 4.0 };
            Point p4 = { 0.0, 4.0 };
            Point points[4] = { p1, p2, p3, p4 };

            int actualShapeType = getShapeType(points);

            Assert::AreEqual(
                SHAPE_RECTANGLE,
                actualShapeType,
                L"Failed to identify 6x4 shape as a rectangle."
            );
        }

        // 4x4 square should be detected as square (value 2)
        TEST_METHOD(TestGetShapeType_IsSquare)
        {
            Point p1 = { 0.0, 0.0 };
            Point p2 = { 4.0, 0.0 };
            Point p3 = { 4.0, 4.0 };
            Point p4 = { 0.0, 4.0 };
            Point points[4] = { p1, p2, p3, p4 };

            int actualShapeType = getShapeType(points);

            Assert::AreEqual(
                SHAPE_SQUARE,
                actualShapeType,
                L"Failed to identify 4x4 shape as a square."
            );
        }
    };
}
