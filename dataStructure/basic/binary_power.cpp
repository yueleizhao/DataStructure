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

long long binary_power(long a, int long b, int long m) {

	if (b == 0) return 1;
	if (b % 2 == 1) return a * binary_power(a, b - 1, m) % m;
	else {
		long long temp = binary_power(a, b / 2, m);

		return temp * temp % m;

	}

}

int main() {
	long long a, b, m;
	cin >> a >> b >> m;

	if (m == 1)//任何整数取模 1 都是0
		return 0;
	int ans;
	if (a >= m)//a >= m,提前取模 
		ans = binary_power(a%m, b, m);
	else ans = binary_power(a, b, m);

	cout << ans;
	return 0;
}