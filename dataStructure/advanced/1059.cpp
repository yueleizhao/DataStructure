#include<iostream>
#include<cmath>

/*
 * Prime Factors
 * 给出⼀个整数，按照从小到大的顺序输出其分解为质因数的乘法算式
 * 输入样例:
 * 97532468
 * 输出样例:
 * 97532468=2^2*11*17*101*1291
 */


 /*
  * 对于一个整数n，如果它存在[2,n]之前的质因子，这些质因子最多有一个大于sqrt(n),其余均小于等于sqrt(n)
  */

struct factor {
	int x = 0;//质因子 
	int cnt = 0;//个数 

}fac[10];//前10个素数的乘积已经大于整数的范围了，只需要开到10 


//是否是素数 
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

//获取 [1,sqrt(n)]内所有的质因子 ,素数表长至少为sqrt(n)+1 
void getPrime(int *prime, int m) {
	bool* p = new bool[m] {0};//p[i] == 0,为素数，访问
	int num = 0;

	for (int i = 2; i < m; i++) {
		if ((p[i] == false) && (isPrime(i))) {
			prime[num++] = i;

			for (int j = i + i; j < m; j += i) {
				p[j] = true;//p[j]==true;不再访问

			}

		}

	}
	delete[] p;
}

//求解质因子   
void prime_factors(int* prime, int n) {
	int num = 0;
	for (int i = 0; prime[i] != 0; i++) {
		if (n%prime[i] == 0) {
			fac[num].x = prime[i];
			fac[num].cnt = 0;
			while (n%prime[i] == 0) {
				fac[num].cnt++;
				n /= prime[i];
			}
			num++;
		}


	}

	//n不为1，则n有且仅有一个大于sqrt(n)的质因子(有可能是 n 本身) 
	if (n != 1) {
		fac[num].x = n;
		fac[num++].cnt = 1;
	}

}

int main() {
	int n;
	std::cin >> n;
	if (n == 1) {

		std::cout << n << "=" << n;
		return 0;
	}

	int  m = sqrt(n) + 1;//素数表长至少要比 sqrt(n)大 1 

	int* prime = new int[m] {0};


	getPrime(prime, m);

	prime_factor(prime, n);
	std::cout << n << "=";
	for (int i = 0; fac[i].cnt != 0; i++) {
		if (i > 0)std::cout << "*";

		if (fac[i].cnt > 1) {
			std::cout << fac[i].x << "^" << fac[i].cnt;
		}
		else if (fac[i].cnt == 1) {
			std::cout << fac[i].x;
		}


	}

	delete[] prime;


	return 0;
}