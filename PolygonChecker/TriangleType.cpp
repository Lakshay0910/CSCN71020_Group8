#include "TriangleType.h"

static bool isTriangle(int a, int b, int c)
{
    if (a <= 0 || b <= 0 || c <= 0)
        return false;

    if (a + b <= c) return false;
    if (a + c <= b) return false;
    if (b + c <= a) return false;

    return true;
}

std::string GetTriangleType(int a, int b, int c)
{
    if (!isTriangle(a, b, c))
        return "Not a triangle";

    if (a == b && b == c)
        return "Equilateral";

    if (a == b || b == c || a == c)
        return "Isosceles";

    return "Scalene";
}
