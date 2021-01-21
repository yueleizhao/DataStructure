#include<iostream>
using namespace std;
/*
 * 非负整数进制转换
 */

int main() {
	int P, Q;
	int x, y = 0;
	cout << "将P进制数转化为Q进制数，输入进制P，Q;输入P进制数:"<<'\n';
	cin >> P >> Q >> x;

/*
 * 将P进制数x转化为十进制数y  ，但x是以十进制的形式输入的
 */
	int temp = 1;
	while (x) {

		y = y + (x % 10)*temp;
		x = x / 10;
		temp = temp * P;

	}

/*
 * 将十进制数y转化为Q进制数z
 */
	int z[20] = { 0 };
	int i = 0;

	while (y) {

		z[i++] = y % Q;
		y = y / Q;


	}
	for (; i > 0; i--) {
		cout << z[i - 1] << ' ';
	}

	return 0;
}