#include<iostream>
using namespace std;

/*
 * 组合数计算,计算 C(n, m) % p(p是正整数)
 * ① C(n,m) = n!/(m!(n-m)!)
 * ② C(n,m) = C(n,n-m)
 * ③ C(n,0) = C(n,n)=1
 */


const int MAX = 101;
long long res[MAX][MAX] = { 0 };//存放已经计算的数据，防止重复计算
int prime[MAX] = { 0 };//存放素数


//方法一①,m<<n<<10^4,p<=10^9
long long C1(long n, long m, int p) {

	if (m == 0 || m == n)
		return 1;
	if (res[n][m] != 0)
		return res[n][m];
	return res[n][m] = (C1(n - 1, m, p) + C1(n - 1, m - 1, p)) % p;

}

//方法一②,m<<n<<10^4,p<=10^9
long long C2(long n, long m, int p) {
	//初始化边界
	for (int i = 0; i <= MAX; i++) {
		res[i][0] = res[i][i] = 1;
	}

	for (int i = 2; i <= MAX; i++) {
		for (int j = 0; j <= i / 2; j++) {
			res[i][j] = (res[i - 1][j] + res[i - 1][j - 1]) % p;//递推计算C(i,j)
			res[i][i - j] = res[i][j];//C(i,i-j) = C(i,j)
		}
	}

	return res[n][m];
}

//方法二，利用质因数分解
// m << n << 10 ^ 6, p <= 10 ^ 9
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

bool p[MAX] = { 0 };//p[i] == 0,为素数，访问
void getPrime(int *prime) {
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
//n!中有多少质因子 p 
int cal(int n, int p) {
	int cnt = 0;
	while (n) {

		cnt += n / p;
		n /= p;
	}

	return cnt;
}
//快速幂
long long binary_power(long a, int long b, int long m) {

	if (b == 0) return 1;
	if (b % 2 == 1) return a * binary_power(a, b - 1, m) % m;
	else {
		long long temp = binary_power(a, b / 2, m);

		return temp * temp % m;

	}

}
long long C3(int n, int m, int p) {

	long long ans = 1;

	for (int i = 0; i <= n; i++) {

		long long temp = cal(n, prime[i]) - cal(m, prime[i]) - cal(n - m, prime[i]);
		//快速幂计算
		ans = ans * binary_power(prime[i], temp, p) % p;
	}
	return ans;
}

//方法四,Lucas算法
// m << n << 10 ^ 18, p <= 10 ^ 5,且 p 是素数

int cal(int n, int m,int p) {
	//初始化边界
	for (int i = 0; i <= MAX; i++) {
		res[i][0] = res[i][i] = 1;
	}

	for (int i = 2; i <= MAX; i++) {
		for (int j = 0; j <= i / 2; j++) {
			res[i][j] = res[i - 1][j] + res[i - 1][j - 1];//递推计算C(i,j)
			res[i][i - j] = res[i][j];//C(i,i-j) = C(i,j)
		}
	}

	return res[n][m];
}



int Lucas(int n, int m, int p) {
	if (m == 0)return 1;

	return cal(n%p, m%p, p) * Lucas(n / p, m / p, p) % p;
}


int main() {

	cout << C1(5, 2, 3) << '\n';//方法一

	getPrime(prime);//获取素数
	cout << C3(5, 2, 3)<<'\n';

	cout << Lucas(8, 3, 5);
	return 0;
}