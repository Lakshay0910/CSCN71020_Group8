#ifndef MAIN_H
#define MAIN_H

#ifdef __cplusplus
extern "C" {
#endif

	int isTriangle(int side1, int side2, int side3);
	int* getTriangleSides(int* triangleSides);
		int printShapeMenu();
		void printWelcome();
#ifdef __cplusplus
}
#endif

#endif
