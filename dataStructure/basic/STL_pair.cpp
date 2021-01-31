#include<iostream>
#include<utility>
#include<string>
#include<map>
using namespace std;
/* 
 * pair可以看成是内部有两个元素的结构体，这两个元素的类型可以指定，如
 * 
 * struct pair｛
 * 
 * typeName1 first;
 * typeName2 second;
 * 
 * ｝;
 */



int main() {

	//pair<typeName1, typeName2> p;
	pair<string, int> pa("hello", 1);//初始化

	pair<string, int> p;
	p.first = "hello";
	p.second = 2;


	//临时构建一个pair
	//①
	p = make_pair("world", 3);
	//②
	p = pair<string, int>("you", 4);

//	printf("%s %d", (p.first).c_str(), p.second);

	/*
	 * 两个pair类型数据可以直接用==、！=、<=、>,先以first的大小作为标准，
	 * 只有first相等时才去判断second的大小
	 */
	pair<int, int> p1(5, 10);
	pair<int, int> p2(5, 5);
	pair<int, int> p3(10, 5);

//	if (p1 < p3)printf("p1<p3\n");
//	if (p1 > p2) printf("p1>p2");
	
	/*
	 * ①代替二元结构体及其构造函数
	 * ②作为map的键值进行插入
	 */

	map<string, int> mp;
	mp.insert(pa);
	mp.insert(make_pair("hello", 5));
	mp.insert(pair<string, int>("world", 6));
	for (map<string, int>::iterator it = mp.begin(); it != mp.end(); it++) {
		cout << it->first << " " << it->second;
	}

	return 0;
}