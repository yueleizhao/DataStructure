#include<iostream>

/*
 * շת������ĵݹ��㷨
 */

int gcd1(int a, int b) {
	if (b == 0) {

		return a;

	}
	return gcd1(b, a%b);

}

/*
 *շת����ǵݹ�
 */

int gcd2(int a, int b) {
	int temp;
	while (b) {
		temp = a % b;
		a = b;
		b = temp;

	}
	return a;

}

int main() {
	int a = 0;
	int b = 0;
	std::cout << "���� a b:";
	std::cin >> a >> b;
	std::cout << "շת����ݹ�:" << gcd1(a, b)<<"\n";
	std::cout << "շת����ǵݹ�:" << gcd2(a, b);
	return 0;

}