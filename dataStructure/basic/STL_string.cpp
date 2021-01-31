#include<iostream>
#include<string>
using namespace std;
int main() {
	string str = "abcd";

	//第①种输出形式:
	for (int i = 0; i < str.length(); i++) {
		printf("%c", str[i]);
	}
	//第②种输出形式:
	printf("%s", str.c_str());

	//第③种输出形式:
	cout << str;

	//第④种输出形式: 
	//string和vector都支持对迭代器进行加减
	for (string::iterator it = str.begin(); it != str.end(); it++) {
		printf("%c", *it);
	}


	/*
	 * 插入
	 * ①insert(pos,string).在pos位置上插入string，时间复杂度O(N)
	 * ②insert(it,it2,it3),在原字符的 it 位置上，插入另一个字符的 it2 到 it3 位置上的字符
	 */
	string str2 = "efd";
	str.insert(1, str2);
	str.insert(str.begin() + 1, str2.begin(), str2.end());

	/*
	 * 删除，时间复杂度均为O(N)
	 * ①删除单个元素
	 * ②删除一个区间中所有元素
	 * ③str.erase(pos,length),删除从 pos 位置开始的 length 长度的字符，包括pos位置上的字符
	 */

	str.erase(str.begin() + 1);
	str.erase(str.begin() + 1, str.end() - 1);//删除[str.begin() + 1, str.end() - 1)中所有元素
	str.erase(1, 2);

	/*
	 * 清空，时间复杂度O(1)
	 */
	str.clear();

	/*
	 * substr(pos,len),返回从pos开始、长度为len的子串,时间复杂度O(len)
	 */

	str = str.substr(1, 2);

	/*
	 * 查找，时间复杂度O(nm),n,m 分别是字符串的长度
	 * ①str.find(str2),当str2是str的子串时，返回str2在str中第一次出现的位置
	 * ②str.find(str2.pos),从str的pos号位置开始匹配str2
	 * ③查找失败时，返回 string::npos ( -1 或者是 4294967295)
	 */
	bool a = str.find(str) != string::npos;// a = true,查找成功

	/*
	 * ①替换，时间复杂度 O(str.length())
	 * ②str.replace(pos,len,str2),把 str 从位置 pos 开始的、长度为 len 的子串替换为 str2
	 * ③str.replace(it,it2,str2),把str迭代器[it,it2)范围内的子串替换为str2
	 */
	str = str.replace(1, 2, str2);
	str = str.replace(str.begin(), str.begin() + 3, str2);

	return 0;
}