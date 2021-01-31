#include<iostream>
#include<queue>
#include<string>
using namespace std;

int main() {
	/*
	 * 队列操作时间复杂度O(1)
	 */

	queue<int> q;
	for (int i = 1; i <= 5; i++) {
		q.push(i);//入队列

	}

	//使用front()、back()前判断是否为空
	printf("%d", q.front());//输出队首元素
	printf("%d", q.back());//输出队尾元素

	q.pop();//出队列

	bool a = q.empty();

	int size = q.size();


	/*
	 * 优先队列，priority_queue，堆实现，队首元素是当前队列中优先级最高的
	 * 默认大堆顶
	 * priority_queue<double, vector<double>, less<int>> 大顶堆：表示其他都比堆顶小
	 * priority_queue<char, vector<char>, greater<int>> 小顶堆：表示其他都比堆顶大
	 */

	priority_queue<int> pq;//priority_queue<int, vector<int>, less<int>> ,less<int>是对第一个参数的比较类

	pq.push(1);//入队列，时间复杂度O(logN)

	int front = pq.top();//取队首元素，即堆顶

	pq.pop();//队首元素出队列，时间复杂度O(logN)

	bool a = pq.empty();
	int size = pq.size();

	/*
	 * 结构体优先级设置
	 */

	struct fruit
	{
		string name;
		int price;
	} f1, f2, f3; //定义三个结构体变量

	struct cmp
	{
		bool operator() (const fruit &f1, const fruit &f2) // 重载括号
		{
			return f1.price > f2.price; // 等同于less,大堆顶
		}
	};

	priority_queue<fruit, vector<fruit>, cmp > q2;
	f1.name = "桃子";
	f1.price = 3;
	f2.name = "梨子";
	f2.price = 4;
	f3.name = "苹果";
	f3.price = 1;

	q2.push(f1);
	q2.push(f2);
	q2.push(f3);

	printf("%s %d", (q2.top().name).c_str(), q2.top().price);//输出: 梨子 4

	return 0;
}