#include<iostream>
#include<vector> 
using namespace std;
int main() {
	int n, m;
	cin >> n >> m;

	vector<int> a[100];

	vector<vector<int>> b(n, vector<int>(m));
	//fun(vector<vector<int> > &a，n) 函数形参

	//①二维数组第一种初始方式
	for (int i = 0; i < b.size(); i++) {
		b[i].resize(m);
	}
	for (int i = 0; i < b.size(); i++) {
		for (int j = 0; j < b[i].size(); j++) {
			b[i][j] = i + j;
			cout << b[i][j];
		}
	}
	//②二维数组第二种初始方式
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++) {

			b[i][j] = i + j;
			printf("%d", b[i][j]);

		}

	/*
	 * 迭代器，类似指针
	 */
	vector<int> v;

	/*
	 * push_back(i),追加元素，时间复杂度O(1)
	 * pop_back(i),删除尾元素,时间复杂度(1)
	 * v.clear(),清空所有元素,时间复杂度(N)
	 * v.insert(v.begin()+2,-1),将-1插入v[2],时间复杂度O(N)
	 */

	for (int i = 1; i <= 5; i++) {

		v.push_back(i);//追加元素
	}

	/*
	 * v.begin(),获取 v 的元素的首地址，即v[0];
	 * v.end()获取尾元素地址的下一个地址
	 */

	vector<int>::iterator it = v.begin();

	//输出形式:
	 //①
	for (int i = 0; i < 5; i++) {
		printf("%d", *(it + i));       //与v[i]、*(v.begin()+i)等价
	}

	//②
	for (vector<int>::iterator it = v.begin(); it != v.end(); it++) {
		printf("%d", *it);
	}

	//③
	for (int i = 0; i < v.size(); i++) {
		printf("%d", v[i]);
	}

	/*
	 * 二维数组追加元素,可以不是方阵
	 */
	vector<vector<int> > M;
	M.push_back(vector<int>());
	M.push_back(vector<int>());

	M[0].push_back(1);
	M[0].push_back(1);
	M[1].push_back(1);

	for (int i = 0; i < M.size(); i++) {
		for (int j = 0; j < M[i].size(); j++) {
			cout << M[i][j] << " ";
		}
	}
	/*
	 * erase()删除某个数据或者[a,b)区间中的数据，包括 a ,但是不包括 b
	 * 时间复杂度O(N)
	 */
	v.erase(v.begin() + 1);//删除v[1]
	v.erase(v.begin() + 1, v.begin() + 4);//删除v[1]、v[2]、v[3]
	v.erase(v.begin(), v.end());//删除所有元素


	return 0;
}