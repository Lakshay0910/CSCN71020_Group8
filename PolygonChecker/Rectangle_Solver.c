#include "rectangle_solver.h" 
#include <math.h>  
#include <stdio.h>
#include <stdbool.h>
#include <string.h> 

#define SHAPE_QUADRILATERAL 1
#define SHAPE_SQUARE        2
#define SHAPE_RECTANGLE     3
#define SHAPE_PARALLELOGRAM 4


double calculateDistance(Point p1, Point p2) {
	double dx;
	double dy;
	double result;

	// Distance Formula: d = sqrt((x2 - x1)^2 + (y2 - y1)^2)

	dx = p2.x - p1.x;
	dy = p2.y - p1.y;

	result = sqrt(dx * dx + dy * dy);

	return result;
}

bool getPointCoordinate(char* prompt, double* coordinate) {
	printf("%s", prompt);

	// Validate input 
	while (scanf("%lf", coordinate) != 1) {
		printf("Invalid input. Please enter a numeric value: ");

		// clear the input buffer
		int c;
		while ((c = getchar()) != '\n' && c != EOF);
	}
	return true;
}

int getShapeType(Point points[4])
{
	// NOTE: p0-p3 are redundant, but kept for consistency
	Point p0 = points[0];
	Point p1 = points[1];
	Point p2 = points[2];
	Point p3 = points[3];

	double Side1 = calculateDistance(points[0], points[1]);
	double Side2 = calculateDistance(points[1], points[2]);
	double Side3 = calculateDistance(points[2], points[3]);
	double Side4 = calculateDistance(points[3], points[0]);

	double D1 = calculateDistance(points[0], points[2]); // P1 to P3
	double D2 = calculateDistance(points[1], points[3]); // P2 to P4

	const double EPSILON = 0.0001;

	// FIX: DEGENERATE CASE CHECK 
	if (Side1 < EPSILON && Side2 < EPSILON && Side3 < EPSILON && Side4 < EPSILON) {
		return SHAPE_QUADRILATERAL;
	}

	// Check for Parallelogram 
	if (fabs(Side1 - Side3) < EPSILON && fabs(Side2 - Side4) < EPSILON) {

		// Check for Rectangle (Parallelogram + Equal Diagonals)
		if (fabs(D1 - D2) < EPSILON) {

			// Check for Square (Adjacent Sides Equal)
			if (fabs(Side1 - Side2) < EPSILON) {
				return SHAPE_SQUARE; // Returns 2 
			}
			return SHAPE_RECTANGLE; // Returns 3 
		}

		return SHAPE_PARALLELOGRAM; // Returns 4
	}

	return SHAPE_QUADRILATERAL; // Returns 1
}

void checkRectangleFeature(void) {
	// Need a static buffer for sprintf
	char buffer[256];

	Point points[4];

	sprintf(buffer, "\n Four Points / Rectangle Feature \n");
	printf_s("%s", buffer);

	// 1. Get the four points from the user
	for (int i = 0; i < 4; i++) {
		char promptX[50];
		char promptY[50];

		sprintf(promptX, "Enter x coordinate for Point %d: ", i + 1);
		sprintf(promptY, "Enter y coordinate for Point %d: ", i + 1);

		getPointCoordinate(promptX, &points[i].x);
		getPointCoordinate(promptY, &points[i].y);
	}

	// 2. Calculate the side lengths and the perimeter
	double side1 = calculateDistance(points[0], points[1]);
	double side2 = calculateDistance(points[1], points[2]);
	double side3 = calculateDistance(points[2], points[3]);
	double side4 = calculateDistance(points[3], points[0]);
	double perimeter = side1 + side2 + side3 + side4;

	// 3. Determine the shape type
	int resultShape = getShapeType(points);

	// 4. Determine Area and Output
	printf("\nResult: \n");

	switch (resultShape) {
	case SHAPE_QUADRILATERAL:
		printf("The points form a general Quadrilateral or a degenerate shape.\n");
		break;
	case SHAPE_PARALLELOGRAM:
		printf("The points form a Parallelogram.\n");
		break;
	case SHAPE_RECTANGLE:
	case SHAPE_SQUARE:
	{
		double area = side1 * side2;
		printf("The points form a %s.\n", (resultShape == SHAPE_SQUARE ? "Square" : "Rectangle"));
		printf("Area: %.2f\n", area);
	}
	break;
	default:
		printf("Shape type could not be determined.\n");
		break;
	}

	printf("Perimeter: %.2f\n", perimeter);

}