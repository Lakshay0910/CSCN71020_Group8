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
			return 4; // square
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
		
	}
