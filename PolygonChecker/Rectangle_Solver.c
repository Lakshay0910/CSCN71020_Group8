#include "rectangle_solver.h" 
#include <math.h>  
#include <stdio.h>
#include <stdbool.h>

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
	Point p0 = points[0];
	Point p1 = points[1];
	Point p2 = points[2];
	Point p3 = points[3];

	double width = fabs(p1.x - p0.x);
	double height = fabs(p3.y - p0.y);

	if ((p0.y == p1.y) && // the bottom is horizontal 
		(p1.x == p2.x) && // the right side is vertical
		(p2.y == p3.y) && // the top is horizontal
		(p3.x == p0.x))   // the left side is vertical 
	{

		if (width == height)
		{
			return 2; // square
		}
		else
		{
			return 3; // Rectangular
		}
	}
	else 
	{
		return 1; // Quadrilateral
	}
}


void checkRectangleFeature(void) 
{
	Point points[4];

	// 1. Get the four points from the user
	for (int i = 0; i < 4; i++)
	{
		char promptX[50];
		char promptY[50];

		sprintf(promptX, "Enter x coordinate for Point %d: ", i + 1);
		getPointCoordinate(promptX, &points[i].x);

		sprintf(promptY, "Enter y coordinate for Point %d: ", i + 1);
		getPointCoordinate(promptY, &points[i].y);
	}
	
	// 2. Determine the shape type
	int resultShape = getShapeType(points);

	switch (resultShape) {
		case 1:
			printf("The shape is a Quadrilateral.\n");
			break;
		case 2:
			printf("The shape is a Square.\n");
			break;
		case 3:
			printf("The shape is a Rectangle.\n");
			break;

	}

	// 3. Calculate the side lengths and the perimeter 
	double side1 = calculateDistance(points[0], points[1]);
	double side2 = calculateDistance(points[1], points[2]);
	double side3 = calculateDistance(points[2], points[3]);
	double side4 = calculateDistance(points[3], points[0]);

	double perimeter = side1 + side2 + side3 + side4;
	printf("Perimeter of the Shape : %.2f\n", perimeter);

	// 4. Calculate the area for square and rectangle
	if (resultShape == 2 || resultShape == 3) {
		double area = side1 * side2;  // length * width || side * side for square
		printf("Area of the Shape : %.2f\n", area);
	}
	
}
