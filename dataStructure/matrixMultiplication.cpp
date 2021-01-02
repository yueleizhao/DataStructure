#include<iostream>

/*
 *矩阵乘法
 */


int main() {
	int a[3][2] = { {1,2},{4,5},{7,8} };
	int b[2][4] = { {1,2},0 };
	int c[3][4] = { 0 };
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 4; j++) {
			for (int k = 0; k < 2; k++) {
				c[i][j] = c[i][j] + a[i][k] * b[k][j];

			}

		}

	}
	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 3; j++) {

			std::cout << c[i][j] << " ";

		}
	return  0;
}
