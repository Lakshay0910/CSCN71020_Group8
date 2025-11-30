#include "pch.h"
#include "CppUnitTest.h"

// Include all necessary headers for both features
#include "../PolygonChecker/rectangle_solver.h" 
#include "../PolygonChecker/triangleSolver.h" 
#include "../PolygonChecker/main.h" 

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

// Shape type constants must match the definitions used in your C files
#define SHAPE_QUADRILATERAL 1
#define SHAPE_SQUARE        2
#define SHAPE_RECTANGLE     3
#define SHAPE_PARALLELOGRAM 4 

namespace PolygonCheckerTests
{
    // -----------------------------------------------------------------
    // 1. TRIANGLE VALIDITY AND TYPE TESTS (Project Requirement: Type of Triangle)
    // -----------------------------------------------------------------
    TEST_CLASS(IsTriangleTests)
    {
    public:
        // Test 1: Invalid side (Negative number)
        TEST_METHOD(NegativeSide)
        {
            // isTriangle should return 0 for negative side lengths
            Assert::AreEqual(0, isTriangle(-33, 23, 24));
        }

        // Test 2: Invalid (Zero side)
        TEST_METHOD(ZeroSide)
        {
            Assert::AreEqual(0, isTriangle(10, 34, 0));
        }

        // Test 3: Invalid (Flat line, fails Triangle Inequality)
        TEST_METHOD(FlatLine)
        {
            Assert::AreEqual(0, isTriangle(5, 5, 10));
        }

        // Test 4: Valid Isosceles
        TEST_METHOD(ValidIsosceles)
        {
            Assert::AreEqual(1, isTriangle(7, 7, 5));
        }

        // Test 5: Valid Equilateral
        TEST_METHOD(ValidEquilateral)
        {
            Assert::AreEqual(1, isTriangle(10, 10, 10));
        }
    };

    // -----------------------------------------------------------------
    // 2. TRIANGLE ANGLE TESTS (Project Requirement: Triangle Inside Angle)
    // -----------------------------------------------------------------
    TEST_CLASS(TriangleAngleTests)
    {
    public:
        // Test 1: Verify the Law of Cosines helper function for a 90-degree angle (1.570796 radians)
        TEST_METHOD(TestAngle_RightTriangle90Degrees)
        {
            // 3-4-5 triangle. We check the angle opposite the longest side (5).
            // Sides: a=5, b=3, c=4
            int side_a = 5;
            int side_b = 3;
            int side_c = 4;

            // 90 degrees = PI / 2 radians (approx 1.570796)
            double expectedAngle = 1.570796;

            // Call the helper function that implements Law of Cosines
            double actualAngle = angleInRadians(side_a, side_b, side_c);

            Assert::AreEqual(expectedAngle, actualAngle, 0.0001, L"Angle calculation failed for 90-degree angle.");
        }

        // Test 2: Verify angle calculation for an Equilateral Triangle (60 degrees = 1.047197 radians)
        TEST_METHOD(TestAngle_Equilateral60Degrees)
        {
            // Sides: 10, 10, 10
            int side_a = 10;
            int side_b = 10;
            int side_c = 10;

            // 60 degrees = PI / 3 radians (approx 1.047197)
            double expectedAngle = 1.047197;

            // Call the helper function
            double actualAngle = angleInRadians(side_a, side_b, side_c);

            Assert::AreEqual(expectedAngle, actualAngle, 0.0001, L"Angle calculation failed for 60-degree angle.");
        }
    };

    // -----------------------------------------------------------------
    // 3. FOUR POINTS (RECTANGLE) TESTS (Project Requirement: 4 points functionality)
    // -----------------------------------------------------------------
    TEST_CLASS(FourPointsTests)
    {
    public:

        // Test 1: Helper Test - Distance Calculation
        TEST_METHOD(TestDistance_Simple345)
        {
            Point p1 = { 0.0, 0.0 };
            Point p2 = { 3.0, 4.0 };
            double expected = 5.0;

            double actual = calculateDistance(p1, p2);

            Assert::AreEqual(expected, actual, 0.0001, L"Distance calculation failed.");
        }

        // Test 2: 6x4 rectangle should be detected as rectangle (value 3)
        TEST_METHOD(TestGetShapeType_IsRectangle)
        {
            Point p1 = { 0.0, 0.0 };
            Point p2 = { 6.0, 0.0 };
            Point p3 = { 6.0, 4.0 };
            Point p4 = { 0.0, 4.0 };
            Point points[4] = { p1, p2, p3, p4 };

            int actualShapeType = getShapeType(points);

            Assert::AreEqual(SHAPE_RECTANGLE, actualShapeType, L"Failed to identify 6x4 shape as a rectangle.");
        }

        // Test 3: 4x4 square should be detected as square (value 2)
        TEST_METHOD(TestGetShapeType_IsSquare)
        {
            Point p1 = { 0.0, 0.0 };
            Point p2 = { 4.0, 0.0 };
            Point p3 = { 4.0, 4.0 };
            Point p4 = { 0.0, 4.0 };
            Point points[4] = { p1, p2, p3, p4 };

            int actualShapeType = getShapeType(points);

            Assert::AreEqual(SHAPE_SQUARE, actualShapeType, L"Failed to identify 4x4 shape as a square.");
        }

        // Test 4: Parallelogram (Non-rectangle, expected value 4)
        TEST_METHOD(TestGetShapeType_IsParallelogram)
        {
            Point p1 = { 0.0, 0.0 };
            Point p2 = { 6.0, 0.0 };
            Point p3 = { 8.0, 4.0 };
            Point p4 = { 2.0, 4.0 };
            Point points[4] = { p1, p2, p3, p4 };

            int actualShapeType = getShapeType(points);

            Assert::AreEqual(SHAPE_PARALLELOGRAM, actualShapeType, L"Failed to classify slanted shape as a parallelogram.");
        }
    };
}