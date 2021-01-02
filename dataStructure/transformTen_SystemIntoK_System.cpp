#include<iostream>
/*
 *将十进制数转化为K进制数
 */
int main() {
	int i;
	int value;
	int k;
	std::cin >> value >> k;
	int a[20] = { 0 };
	for (i = 0; value != 0; i++) {
		a[i] = value % k;
		value = value / k;
	}
	for (; i > 0; i--) {
		printf("%d", a[i - 1]);
	}


	return 0;
}