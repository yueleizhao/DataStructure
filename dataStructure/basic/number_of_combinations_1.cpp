#include<iostream>
const int MAX = 64;

/*
 * 组合数计算
 * ① C(n,m) = n!/(m!(n-m)!)
 * ② C(n,m) = C(n,n-m)
 * ③ C(n,0) = C(n,n)=1
 */

 //计算 C(n,m) = n!/(m!(n-m)!)

 //利用C(n,m) = C(n-1,m) + C(n-1,m-1)

long long res[MAX][MAX] = { 0 };//存放已经计算的数据，防止重复计算

 //方法一，时间复杂度和具体数值有关，但每次计算C(n.m)不会超过O(n^2)
//n = 67,m = 33时开始溢出
long long C1(long n, long m) {

	if (m == 0 || m == n)
		return 1;
	if (res[n][m] != 0)
		return res[n][m];
	return res[n][m] = C1(n - 1, m) + C1(n - 1, m - 1);

}

//方法二,计算所有C(n.m)的时间复杂度是O(n^2)
//n = 67,m = 33时开始溢出
long long C2(long n, long m) {
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
//方法三，时间复杂度O(m)
//利用 C(n,m)=(n-m-1)×(n-m-2×)……×(n-m+m)/(1×2×……×m)
//n = 62,m = 31时开始溢出
long long C3(long n, long m) {

	long long ans = 1;
	for (long long i = 1; i <= m; i++) {
		ans = ans * (n - m + i) / i;
	}
	return ans;
}


int main() {

	std::cout << C3(5, 2);

	return 0;
}
