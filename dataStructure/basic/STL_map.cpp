#include<iostream>
#include<map>
#include<string>
using namespace std;
/*
 * ①可以将任何基本类型(包括STL容器)映射到任何基本类型(包括STL容器)。
 *   例如map(int,set<int> >,建立整数到集合的映射。
 * ②关键词可以理解为数组的下标，可以是任何类型;值可以理解为数组下标所对应内容，从而建立映射。
 * ③字符串映射到整数必须是 string 类型，而不能是char[]类型，即map<string,int>。
 * ④基于红黑树，所以关键词会自动实现从小到大排列。值不允许重复。
 */

int main() {
	/*
	 * 插入
	 */

	 //第一种插入方法
	map<int, string>m;
	m.insert(pair<int, string>(1, "hello"));
	m.insert(pair<int, string>(2, "world"));
	m.insert(pair<int, string>(3, "you"));
	for (map<int, string>::iterator it = m.begin(); it != m.end(); it++) {
		printf("%d %s", it->first, (it->second).c_str());
	}

	//第二种插入方法
	map<int, string>m;
	m.insert(map<int, string>::value_type(1, "hello"));
	m.insert(map<int, string>::value_type(1, "world"));
	m.insert(map<int, string>::value_type(1, "you"));
	for (map<int, string>::iterator it = m.begin(); it != m.end(); it++) {
		printf("%d %s", it->first, (it->second).c_str());
	}
	//输出结果:1 hello
	//第二、第三条insert语句没有发挥作用，因为insert向其中插入关键词——值的时候，关键词涉及到一个集合的不重复性


	//第三种插入方法，当关键词为整数时，利用数组方式插入
	map<int, string>m;
	m[1] = "hello";
	m[2] = "world";
	m[3] = "you";

	map<int, string>m;
	m[1] = "hello";
	m[1] = "world";
	//输出结果:1 world
	//关键词相同时，数组赋值的时候会直接覆盖。

	map<char, int> mp;
	mp['c'] = 20;
	mp['c'] = 30;//20 会被覆盖


	/*
	 * 容器的大小
	 */

	int a = m.size();

	/*
	 * 容器的清除，时间复杂度O(N),N 为map中元素的个数
	 */
	m.clear();

	/*
	 * 容器的遍历
	 */

	 //用前向迭代器进行遍历
	map<int, string> m;
	m[1] = "hello";
	m[2] = "world";
	m[3] = "you";
	for (map<int, string>::iterator it = m.begin(); it != m.end(); it++) {
		printf("%d %s", it->first, (it->second).c_str());
	}

	//用反向迭代器遍历
	map<int, string> m;
	m[1] = "hello";
	m[2] = "world";
	m[3] = "you";
	map<int, string>::reverse_iterator iter;
	for (iter = m.rbegin(); iter != m.rend(); iter++)
	{
		printf("%d %s", iter->first, (iter->second).c_str());
	}

	//数组遍历
	map<int, string> m;
	m[1] = "hello";
	m[2] = "world";
	m[3] = "you";

	for (int i = 1; i <= m.size(); i++)
	{
		printf("%s", (m[i]).c_str());
	}

	/*
	 * find(key),返回key关键词的迭代器，时间复杂度O(logN),N 为映射的个数
	 */

	map<int, string> m;
	m[1] = "hello";
	m[2] = "world";
	m[3] = "you";
	map<int, string >::iterator it = m.find(2);
	printf("%d,%s", it->first, (it->second).c_str());


	/*
	 * ①erase(it)，删除一个元素，it为迭代器，时间复杂度O(1)
	 * ②erase(key),删除一个元素，key为键，时间复杂度O(logN），N 为map中元素的个数
	 * ③erase(ita,itb),删除[ita,itb)之间的元素，时间复杂度O(itb-ita)
	 */
	map<int, string>::iterator it = m.find(2);//①
	m.erase(it);

	m.erase(3);//②

	map<int, string>::iterator it = m.find(2);//③
	m.erase(it, m.end());



	return 0;
}