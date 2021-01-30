#include<iostream>
#include<string>
#include<cstring> 
using namespace std;

/*
 * 字符串的操作
 */


int main() {
	string str1 = "helloWorld";
	string str2 = "hello";

	str1.append(str2);			//将 Str2 添加 str1 字符串尾
	str1.assign(str2);			//将 str2 赋值给 str1 
	str1.compare(str2);			//str1 < str2,返回负数;相等时返回 0 ; 否则返回正数 
	str1.insert(0, str2);	    //将 str2 插入到str1 0 位置之前 
	str1.swap(str2);            //交换两个字符串的值
	str1.find("World");         // 查找字符串 World 在 str1 中第一次出现的位置 
	str1.substr(0, 5);          //取子字符串,返回 str1 0 位置开始的 5 个字符返回 
	str1.length();              //返回字符串 str1 的长度 

	string t1 = str1 + str2;    //字符串连接 
	str1 = str2;                //str2赋值给str1 
	bool a = (str1 == str2);    //是否相等,!= 是否不等 
	bool b = (str1 < str2);     //是否小于 
	
	cout << str1[2];            //访问 str1 中位置为 2 的字符 

	char s[] = "C++";
	cout << (str1 = s);          //用字符数组初始化字符串,即字符数组转化为字符串 

	char c[20] = {};
	strcpy(c, str1.c_str());     //include<cstring>,将字符串 str1 转化为字符数组,但 str1.c_str() 函数并不安全


	return 0;
}