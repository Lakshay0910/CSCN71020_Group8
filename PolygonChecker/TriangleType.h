#pragma once
#include <string>

inline bool isTriangle(int a, int b, int c)
{
    if (a <= 0 || b <= 0 || c <= 0)
        return false;

    // Triangle inequality
    if (a + b <= c) return false;
    if (a + c <= b) return false;
    if (b + c <= a) return false;

    return true;
}

inline std::string GetTriangleType(int a, int b, int c)
{
    if (!isTriangle(a, b, c))
        return "Not a triangle";

    if (a == b && b == c)
        return "Equilateral";

    if (a == b || b == c || a == c)
        return "Isosceles";

    return "Scalene";
}

