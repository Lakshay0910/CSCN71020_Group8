#include "pch.h"
#include "CppUnitTest.h"

#include "../PolygonChecker/rectangle_solver.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

#define SHAPE_QUADRILATERAL 1
#define SHAPE_PARALLELOGRAM 2
#define SHAPE_RECTANGLE     3
#define SHAPE_SQUARE        4

namespace PolygonCheckerTests
{
    TEST_CLASS(FourPointsTests)
    {
    public:

        TEST_METHOD(TestDistance_Simple354)
        {
            Point p1 = { 0.0, 0.0 };
            Point p2 = { 3.0, 4.0 };

            double actual = calculateDistance(p1, p2);
            double expected = 5.0;

            Assert::AreEqual(expected, actual, 0.0001, L"Distance calculation failed.");
        }

        TEST_METHOD(TestGetShapeType_IsRectangle)
        {
            Point p1 = { 0.0, 0.0 };
            Point p2 = { 6.0, 0.0 };
            Point p3 = { 6.0, 4.0 };
            Point p4 = { 0.0, 4.0 };
            Point points[4] = { p1, p2, p3, p4 };

            int actualShapeType = getShapeType(points);

            Assert::AreEqual(SHAPE_RECTANGLE, actualShapeType,
                L"Failed to identify 6x4 shape as a rectangle.");
        }

        TEST_METHOD(TestGetShapeType_IsSquare)
        {
            // A 4x4 square
            Point p1 = { 0.0, 0.0 };
            Point p2 = { 4.0, 0.0 };
            Point p3 = { 4.0, 4.0 };
            Point p4 = { 0.0, 4.0 };
            Point points[4] = { p1, p2, p3, p4 };

            int actualShapeType = getShapeType(points);

            Assert::AreEqual(SHAPE_SQUARE, actualShapeType,
                L"Failed to identify 4x4 shape as a square.");
        }

    };
}
