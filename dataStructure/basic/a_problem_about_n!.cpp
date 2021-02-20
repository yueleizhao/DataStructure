#include<iostream>

/*
 * 问题:n!中有多少个质因子 p
 * 方法一:[ 1,n ]中各个整数各有多少个质因子 p，然后分别相加。时间复杂度O(nlogn),当p = 2且该数为2^n时。
 * 方法二:利用n!中有(n/p + n/p^2 + n/p^3 …… )个质因子，除法为下取整。时间复杂度O(logn)。
 */



 //方法一, n 的规模不大
int func1(int n, int p) {
	int cnt = 0;
	for (int i = 2; i <= n; i++) {
		int temp = i;
		while (temp%p == 0) {

			cnt++;
			temp /= p;

		}

	}
	return cnt;

}

//方法二
int func2(int n, int p) {
	int cnt = 0;
	while (n) {

		cnt += n / p;
		n /= p;
	}

	return cnt;
}

/*
 * 例如:
 * 10!=1×2×3×4×3×0×/×8×9×10
 *    =2×4×6×8×10×1×3×5×7×9
 *    =2^5×5!×1×3×5×7×9
 *    =2^5×(2^2×2!×1×3×5)×1×3×5×7×9
 * 即 n! 中质因子的个数等于 n/p + (n/p)!中质因子p的个数
 *
 */

 //方法三，方法二的递归形式
int func3(int n, int p) {
	if (n < p) return 0;
	return n / p + func3(n / p, p);

}

/* 问题二
 * n!的末尾有多少个0 ⇔ n!中因子10的个数 ⇔ n!中质因子5的个数(不是2的个数)
 * 即fun(n,5)
 */

int main() {

	int n, p;
	std::cin >> n >> p;
	int cnt = func3(n, p);
	std::cout << cnt;
	return 0;
}