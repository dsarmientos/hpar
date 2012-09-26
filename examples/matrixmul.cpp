#include <iostream>

using namespace std;

void MatrixMultiplication(float*, float*, float*, int);
void PrintMatrix(float*, int);


int main() {
	float A[3][3] = { { 1, 1, 1 }, { 1, 0, 1 }, { 1, 1, 5 } };
	float B[3][3] = { { 1, 1, 1 }, { 1, 2, 1 }, { 1, 1, 1 } };
	float C[3][3] = { { 0, 0, 0 }, { 0, 0, 0 }, { 0, 0, 0 } };
	float *a = A[0];
	float *b = B[0];
	float *c = C[0];
	MatrixMultiplication(a, b, c, 3);
	PrintMatrix(c, 3);
}


void MatrixMultiplication(float* M, float* N, float* P, int width) {
	for (int i = 0; i < width; ++i) {
		for (int j = 0; j < width; ++j) {
			float sum = 0;
			for (int k  = 0; k < width; ++k) {
				float a = M[i * width + k];
				float b = N[k * width + j];
				 sum += a * b;
			}
		        P[i * width + j] = sum;
		}
	}
}


void PrintMatrix(float* M, int width) {
	for (int i = 0; i < width; ++i) {
		for (int j = 0; j < width; ++j) {
		        float v = M[i * width + j];
			cout << v << '\t';
		}
		cout << endl;
	}
}


