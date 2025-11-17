#include "rectangle_solver.h" 
#include <math.h>  
#include <stdio.h>
#include <stdbool.h>

double calculateDistance(Point p1, Point p2) {
// Distance Formula: d = sqrt((x2 - x1)^2 + (y2 - y1)^2)

	double dx = p2.x - p1.x;
	double dy = p2.y - p1.y;

	return sqrt(dx * dx + dy * dy);
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
		
	(void)points;
	return 1;
}

void checkRectangleFeature(void)
	{
		
	}
