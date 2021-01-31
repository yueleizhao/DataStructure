#include<iostream>
#include<set>
#include<functional>
using namespace std;
/*
 * 它底层使用平衡的搜索树——红黑树实现，
 * 插入删除操作时仅仅需要指针操作节点即可完成，不涉及到内存移动和拷贝，所以效率比较高。
 * 在set中元素都是唯一的，而且默认情况下会对元素自动进行升序排列，且去掉重复
 * 支持集合的交(set_intersection),差(set_difference) 并(set_union)，对称差(set_symmetric_difference) 等操作，
 * 如果需要集合中的元素允许重复那么可以使用multiset。
 */
int main() {

	/*
	 * set的创建
	 */
	set<int > seta; //默认是小于比较器less<int>的set

	set<int, greater<int> > setb; //创建一个带大于比较器的set，需包含头文件functional

	int a[5] = { 1,2,3,4,5 };
	set<int > setc(a, a + 5); //数组a初始化一个set；

	set<int > setd(setc.begin(), setc.end()); //setc初始化一个set
	//上述两例均为区间初始化

	set<int > sete(setd); //拷贝构造创建set

	/*
	 * 插入
	 * s.insert(),插入一个元素,时间复杂度O(logN)
	 */
	set<int> a[10];
	set<int> s;

	s.insert(1);
	s.insert(2);

	for (set<int>::iterator it = s.begin(); it != s.end(); it++) {
		printf("%d", *it);
	}


	/*
	 * 查找，查找一个元素，如果容器中存在，则返回对应value的迭代器；不存在该元素，返回值等于s.end()
	 * s.find(vale),时间复杂度O(logN)
	 */
	set<int>::iterator it = s.find(3);
	printf("%d", *it);//输出 3 

	s.find(2) != s.end();// 2 在set中存在


	/*
	 * 删除
	 * ①s.erase(it),i为迭代器，时间复杂度O(1)
	 * ②s.erase(value),删除value，时间复杂度O(logN)
	 * ③s.erase(ita,itb)删除[ita,itb)之间的数，时间复杂度O(itb-ita)
	 */
	s.erase(s.find(2));//用find()找到，然后删掉
	s.erase(2);//删掉 2 
	set<int>::iterator  ita = s.begin();
	set<int>::iterator  itb = s.begin();
	itb++;
	s.erase(ita, s.end());//删除全部
	s.erase(ita, itb);

	/*
	 * 修改
	 *
	 * 不能直接修改，所以只能先删除，再插入
	 */

	 /*
	  * 返回类型均为迭代器类型
	  * s.lower_bound() 返回第一个大于或等于给定关键值的元素的位置，
	  * s.upper_bound() 返回第一个大于给定关键值的元素的位置
	  * s.equal_range() 返回一对定位器，分别表示 第一个大于或等于给定关键值的元素 和 第一个大于给定关键值的元素，
						这个返回值是一个pair类型，如果这一对定位器中哪个返回失败，就会等于s.end()
	*/

	cout << "第一个大于或等于3的元素: " << *s.lower_bound(3) << endl;
	cout << "第一个大于或等于2的元素: " << *s.lower_bound(2) << endl;
	cout << "第一个大于2的元素: " << *s.upper_bound(2) << endl;

	cout << "第一个大于或等于2的元素: " << *s.equal_range(2).first << endl;
	cout << "第一个大于2的元素: " << *s.equal_range(2).second << endl;

	/*
	 * s.empty(),容器为空返回 true
	 * s.count(value),value在容器中返回 true
	 */
	bool a = s.empty();
	bool b = s.count(1);

	s.clear();// 删除set容器中的所有的元素，时间复杂度O(N)



	/*
	 * 自定义排序函数构造set
	 * a<b,有小到大排序
	 * a>b,由大到小排序
	 */

	struct cmp {
		bool operator () (const int &a, const int &b) {
			return a > b;
		}
	};
	set<int, cmp>s;
	int cnt = 1;

	s.insert(1);
	s.insert(2);
	s.insert(6);
	cout << "Test output :" << cnt << ":" << endl;
	for (set<int, cmp>::iterator it = s.begin(); it != s.end(); it++)
		cout << *it << " ";

	return 0;
}