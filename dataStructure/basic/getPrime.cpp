#include<iostream>
#include<string.h> 
using namespace std;

int main() {
	int a[3] = { 1 };
	for (int i = 0; i < 3; i++)
		cout << a[i];
	cout << '\n';
	memset(a, 1, sizeof(a));
	for (int j = 0; j < 3; j++)
		cout << a[j] << " ";


	return 0;
}