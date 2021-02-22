#include<iostream>
#include<cmath>
using namespace std;
/*
 * 快速幂(二分幂)
 * 如果b是奇数,那么有ab = a * a^(b-1)。
 * 如果b是偶数,那么有ab = a^(b/2) * a^(b/2)。
 * 如果b是0，a^0 = 1
 *
 */

 //求解a^b % m
 //递归形式
long long binary_power1(long a, int long b, int long m) {

	if (b == 0) return 1;
	if (b % 2 == 1) return a * binary_power1(a, b - 1, m) % m;
	else {
		long long temp = binary_power1(a, b / 2, m);

		return temp * temp % m;

	}

}
//非递归形式
//例如 13=(1101)B,13 = 8+4+1 ,a^13 = a^(8+4+1)= a^8 * a^4 * a^1
long long binary_power2(long a, int long b, int long m) {
	long long ans = 1;
	while (b > 0) {
		if (b % 2 == 1) {
			ans = ans * a%m;

		}
		a = a * a%m;//a的平方的表示

		b /= 2;

	}
	return ans;
}

int main() {
	long long a, b, m;
	cin >> a >> b >> m;

	if (m == 1)//任何整数取模 1 都是0
		return 0;
	int ans;

	if (a >= m)//a >= m,提前取模
		ans = binary_power1(a%m, b, m);
	else ans = binary_power1(a, b, m);

	cout << ans << '\n';

	cout << binary_power2(a, b, m);
	return 0;
}