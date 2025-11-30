#include <stdio.h>
#include <stdbool.h>
#include <math.h>
#include <string.h>

#include "triangleSolver.h"

// Constants used for angle calculation
#define PI 3.14159265358979323846
#define EPSILON 0.0001 // Tolerance for double comparison

// Returns 1 if the 3 sides form a valid triangle, 0 otherwise (for validation)
int isTriangle(int side1, int side2, int side3)
{
    if (side1 <= 0 || side2 <= 0 || side3 <= 0)
        return 0;

    // Triangle Inequality Theorem
    if (side1 + side2 > side3 &&
        side1 + side3 > side2 &&
        side2 + side3 > side1)
        return 1;

    return 0;
}

// Determines the type of triangle
char* analyzeTriangle(int side1, int side2, int side3) {
    if (isTriangle(side1, side2, side3) == 0) {
        return "Not a valid triangle";
    }

    if (side1 == side2 && side1 == side3) {
        return "Equilateral triangle";
    }
    else if (side1 == side2 || side1 == side3 || side2 == side3) {
        return "Isosceles triangle";
    }
    else {
        return "Scalene triangle";
    }
}

// Helper function using Law of Cosines to calculate an angle in radians
double angleInRadians(int a, int b, int c) {
    // Law of Cosines: cos(A) = (b^2 + c^2 - a^2) / (2bc)
    double numerator = (double)b * b + (double)c * c - (double)a * a;
    double denominator = 2.0 * b * c;

    // Safety check for division by zero
    if (denominator == 0.0) {
        return 0.0;
    }

    double cosA = numerator / denominator;

    // Clamp to prevent domain errors for acos
    if (cosA > 1.0) cosA = 1.0;
    if (cosA < -1.0) cosA = -1.0;

    return acos(cosA);
}

// Main function to calculate and print angles (Project Requirement)
void calculateAngles(int side1, int side2, int side3) {
    if (isTriangle(side1, side2, side3) == 0) {
        printf("Cannot calculate angles: Sides do not form a valid triangle.\n");
        return;
    }

    // Calculate angles in radians
    double angleA_rad = angleInRadians(side1, side2, side3);
    double angleB_rad = angleInRadians(side2, side1, side3);
    double angleC_rad = angleInRadians(side3, side1, side2);

    // Convert to degrees and print
    double angleA_deg = angleA_rad * 180.0 / PI;
    double angleB_deg = angleB_rad * 180.0 / PI;
    double angleC_deg = angleC_rad * 180.0 / PI;

    printf("\nTriangle Inside Angles:\n");
    printf("  Angle opposite side %d: %.2f degrees\n", side1, angleA_deg);
    printf("  Angle opposite side %d: %.2f degrees\n", side2, angleB_deg);
    printf("  Angle opposite side %d: %.2f degrees\n", side3, angleC_deg);
}