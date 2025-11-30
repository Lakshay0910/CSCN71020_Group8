#include <stdio.h>
#include <stdbool.h>

#include "main.h"
#include "triangleSolver.h"
#include "rectangle_solver.h"


int side = 0;

int main() {
	bool continueProgram = true;
	while (continueProgram) {
		printWelcome();

		int shapeChoice = printShapeMenu();

		switch (shapeChoice)
		{
		case 1:
			printf_s("Triangle selected.\n");
			int triangleSides[3] = { 0, 0, 0 };
			int* triangleSidesPtr = getTriangleSides(triangleSides);
			//printf_s("! %d\n", triangleSidesPtr[0]);
			int is_triangle = isTriangle(triangleSidesPtr[0], triangleSidesPtr[1], triangleSidesPtr[2]);
			if (is_triangle == 1) {
				printf_s("%s \n", "These sides can form a triangle. ");
			}
			else if (is_triangle == 0) {
				printf_s("%s \n", "These sides can't form a triangle. ");
			}
			
			continueProgram = false;
			break;
		case 2:
			printf_s("Four - Point Rectangle Selected. \n");
			checkRectangleFeature();  
			break;
		case 0:
			continueProgram = false;
			break;
		default:
			printf_s("Invalid value entered.\n");
			break;
		}
	}
	return 0;
}

void printWelcome() {
	printf_s("\n");
	printf_s(" **********************\n");
	printf_s("**     Welcome to     **\n");
	printf_s("**   Polygon Checker  **\n");
	printf_s(" **********************\n");
}

int printShapeMenu() {
	printf_s("1. Triangle\n");
	printf_s("2. Four - Point Shape Rectangle Checker\n");
	printf_s("0. Exit\n");

	int shapeChoice;

	printf_s("Enter number: ");
	while (scanf_s("%d", &shapeChoice) != 1)
	{
		printf("Invalid input. Please enter a numeric value for shape choice: ");
		int c;
		while ((c = getchar()) != '\n' && c != EOF);
	}

	return shapeChoice;
}

int* getTriangleSides(int* triangleSides) {
	printf_s("Enter the three sides of the triangle: ");
	for (int i = 0; i < 3; i++)
	{
		// handles invalid input for triangle sides
		while (scanf_s("%d", &triangleSides[i]) != 1)
		{
			printf_s("Invalid input. Please enter a numeric value for side: ");

			// clear the bad input buffer
			int c;
			while ((c = getchar()) != '\n' && c != EOF);
			{

			}
		}
		
	}
	return triangleSides;
}


int isTriangle(int side1, int side2, int side3)
{
	if (side1 <= 0 || side2 <= 0 || side3 <= 0)
		return 0;

	if (side1 + side2 > side3 &&
		side1 + side3 > side2 &&
		side2 + side3 > side1)
		return 1;

	return 0;
}
