#include<iostream>
#include<stdlib.h>
#include<stdio.h> 
#include<vector>
using namespace std;
/*
 * 动态内存分配
 * 建立一维、二维动态数组常用方法
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



	int **arr3 = (int**)malloc(sizeof(int*)*n);
	for (int i = 0; i < n; i++) {
		arr3[i] = (int*)malloc(sizeof(int)*m);
	}
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++) {

			arr3[i][j] = i + j;
			printf("%d", arr3[i][j]);

		}

	vector<vector<int> > arr4(n, vector<int>(m));
	//fun(vector<vector<int> > arr5，n) 函数形参 

	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++) {

			arr4[i][j] = i + j;
			printf("%d", arr4[i][j]);

		}



	return 0;
}