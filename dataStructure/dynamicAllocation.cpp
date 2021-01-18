
#include<iostream>
#include<stdlib.h>
#include<stdio.h> 
using namespace std;
/**
 * 动态内存分配
 */


int main() {
	int n = 0, m = 0;

	cin >> n >> m;

	int* arr1 = new int[n];
	for (int i = 0; i < n; i++) {
		arr1[i] = i;
		printf("%d", arr1[i]);
	}

	int* arr2 = NULL;
	arr2 = (int*)malloc(sizeof(int)*n);
	for (int i = 0; i < n; i++) {
		arr2[i] = i;
		printf("%d", arr2[i]);
	}

	int(*arr3)[n] = (int(*)[n])malloc(sizeof(int)*m*n);
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++) {

			arr3[i][j] = i + j;
			printf("%d", arr3[i][j]);
		}


	int **arr4 = (int**)malloc(sizeof(int*)*n);
	for (int i = 0; i < n; i++) {
		arr4[i] = (int*)malloc(sizeof(int)*m);
	}
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++) {

			arr4[i][j] = i + j;
			printf("%d", arr4[i][j]);

		}

	
	vector<vector<int> > arr5(n, vector<int>(m));
	//fun(vector<vector<int> > arr5,n) 函数形参 

	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++) {

			arr5[i][j] = i + j;
			printf("%d", arr5[i][j]);

		}


              return 0;
}
