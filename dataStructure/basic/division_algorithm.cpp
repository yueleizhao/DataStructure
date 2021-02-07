#include<iostream>

/*
 * 辗转相除法的递归算法
 */

int gcd1(int a, int b) {
	if (b == 0) {

		return a;

	}
	return gcd1(b, a%b);

}

/*
 * 辗转相除非递归
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
	std::cout << "输入 a b:";
	std::cin >> a >> b;
	std::cout << "辗转相除递归:" << gcd1(a, b) << "\n";
	std::cout << "辗转相除非递归:" << gcd2(a, b);
	return 0;

}
