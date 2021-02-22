#include<iostream>
using namespace std;

//递归形式，假设arr[ ]严格递增
int binarysearch1(int arr[], int l, int r, int x)
{
	if (r >= l)
	{
		int mid = l + (r - l) / 2;//避免(l+r)/2发生溢出

		if (arr[mid] == x)  return mid;

		if (arr[mid] > x) return binarysearch1(arr, l, mid - 1, x);//递减序列，arr[mid]<x

		return binarysearch1(arr, mid + 1, r, x);
	}

	return -1;
}

//非递归形式
int binarysearch2(int arr[], int l, int r, int x)
{

	int mid;
	while (l <= r) {
		mid = l + (r - l) / 2;
		if (arr[mid] == x) return mid;
		else if (arr[mid] > x) {
			r = mid - 1;
		}
		else l = mid + 1;

	}

	return -1;
}


//问题一:求序列中第一个大于等于 x 元素的位置

//二分上下界为左闭右闭的[left, right],传入的初值为[0,n]
int lower_bound(int A[], int left, int right, int x) {
	int mid;
	while (left < right) {//对[1eft,right]来说,left==right意味着找到唯一位置

		mid = (left + right) / 2;
		if (A[mid] >= x) {
			right = mid;

		}
		else
			left = mid + 1;

	}
	return left;

}

/*
 * 如果想要寻找最后一个满足“条件C”的元素的位置，则可以先求第一个满足“条件!C”的元素的位置，
 * 然后将该位置减1即可
 *
 * 解决“寻找有序序列第一个满足某条件的元素的位置”问题,只需将A[mid] > x 变成条件
 */

 //问题二:求序列中第一个大于 x 元素的位置

 //二分上下界为左闭右闭的[left, right],传入的初值为[0,n]
int upper_bound(int A[], int left, int right, int x) {
	int mid;
	while (left < right) {

		mid = (left + right) / 2;
		if (A[mid] > x) {//

			right = mid;

		}
		else
			left = mid + 1;

	}
	return left;

}

int main() {


	int arr[] = { 2, 3, 4,10, 40 };

	int n = sizeof(arr) / sizeof(arr[0]);

	int x = 42;

	int result = binarysearch2(arr, 0, n - 1, x);

	(result == -1) ? printf("Element is not in the array\n")
		: printf("Element is present at index %d\n", result);


	cout << lower_bound(arr, 0, n, x) << '\n';//传入 n ，是因为若该元素比所有元素都大，则它应该是在 n 这个位置
	cout << upper_bound(arr, 0, n, x);
	return 0;
}