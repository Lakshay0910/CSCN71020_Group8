#pragma once

#include <stdbool.h> 

// 1. Data Structure
typedef struct Point {
	double x;
	double y;
} Point;

// EXTERN "C" BLOCK START 
#ifdef __cplusplus
extern "C" {
#endif

// 2. Function Declarations 
double calculateDistance(Point p1, Point p2);

bool getPointCoordinate(char* prompt, double* coordinate);

// Returns 3 for Rectangle, 2 for Parallelogram, 1 for Quadrilateral
int getShapeType(Point points[4]);

// The user-facing function that gathers input and prints the results
void checkRectangleFeature(void);

#ifdef __cplusplus
}
#endif
// EXTERN "C" BLOCK END
