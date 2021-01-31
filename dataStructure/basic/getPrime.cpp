#include<iostream>
#include<cmath>
using namespace std;

/*
 * 以求小于等于100以内的素数为例
 */

const int MAX = 101;

bool isPrime(int n) {
	if (n <= 1) {

		return false;
	}
	int temp = (int)sqrt(1.0*n);
	for (int i = 2; i <= temp; i++) {
		if (n%i == 0) {
			return false;
		}

	}
	return true;
}

/*
 * 埃氏筛选
 * 若内部循环是j = 2*i,则复杂度O(nlogn);
 * 若内部循环是j = i+i,则复杂度O(nloglogn)
 */

bool p[MAX] = { 0 };//p[i] == 0,为素数，访问
void getPrime1(int *prime) {
	int num = 0;

	for (int i = 2; i < MAX; i++) {
		if ((p[i] == false) && (isPrime(i))) {
			prime[num++] = i;

			for (int j = i + i; j < MAX; j += i) {
				p[j] = true;//p[j]==true;不再访问

			}

		}

	}

}

/*
 * 欧拉筛选 O(n)
 */

void getPrime2(int *prime) {
	int num = 0;

	for (int i = 2; i < MAX; i++) {
		if ((p[i] == false) && (isPrime(i))) {
			prime[num++] = i;

			for (int j = 0; j < num&&i*prime[j] < MAX; j++) {
				p[i*prime[j]] = true;//不再访问
				if (i%prime[j] == 0) break;

			}

		}

	}

}


/*
 * n 在10^5以内
 */

void getPrime(int *prime) {
	int num = 0;
	for (int i = 2; i < MAX; i++) {
		if (isPrime(i) == true) {
			prime[num++] = i;
		}

	}

}

int main() {

	int prime[MAX] = { 0 };
	getPrime2(prime);
	for (int i = 0; prime[i] != 0; i++) {
		cout << prime[i] << ' ';
	}
	return 0;
}
