#include<iostream>
#include<stack>
using namespace std;
int main() {
	/*
	 * 所有操作时间复杂度都是O(1)
	 */

	stack<int> st;
	for (int i = 1; i <= 5; i++) {
		st.push(i);//入栈

	}
	st.pop();//出栈，删除栈顶元素，并不返回值

	st.top();//取栈顶元素

	bool a = st.empty();//栈为空，a = true;

	int size = st.size();//栈的大小


	return 0;
}