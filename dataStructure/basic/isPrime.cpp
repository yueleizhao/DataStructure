#include<iostream>
#include<cmath>
using namespace std;
/*
 * n 接近int型变量范围的上界
 */

bool isPrime_MAX(int n) {
	if (n <= 1) {

		return false;
	}
	int temp = (int)sqrt(1.0*n);//sqrt()要求参数为浮点型 
	for (int i = 2; i <= temp; i++) {
		if (n%i == 0) {
			return false;
		}

	}
	return true;
}

/*
 n 在10^9内都是安全的，否则将n定义为long long int
 */

bool isPrime_MIN(int n) {

	if (n <= 1) {
		return false;
	}
	for (int i = 2; i*i <= n; i++) {
		if (n%i == 0) {
			return false;
		}
	}
	return true;
}

//第三种方法

void isPrimeNumber(int value) {
	int i;
	for (i = 2; i < value; i++)
		if (value%i == 0) {
			std::cout << value << " is not prime number" << "\n";
			break;
			
		}
	
	if (i == value)std::cout << value << " is prime number" << "\n";

}

int main() {
	int n;
	cin >> n;

	if (n > 10 ^ 9) {
		cout << isPrime_MAX(n);

	}
	else if (n <= 10 ^ 9) {
		cout << isPrime_MIN(n);

	}
	
	isPrimeNumber(n);
	
	return 0;
}
