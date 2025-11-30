#pragma once

#ifdef __cplusplus
extern "C" {
#endif

	// Returns a text description of the triangle type
	char* analyzeTriangle(int side1, int side2, int side3);

	// Function to calculate and print the three interior angles
	void calculateAngles(int side1, int side2, int side3);

	// Returns 1 if the 3 sides form a valid triangle, 0 otherwise
	int isTriangle(int side1, int side2, int side3);

	double angleInRadians(int a, int b, int c);

#ifdef __cplusplus
}
#endif