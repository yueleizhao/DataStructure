#include<iostream>
#include<string.h>
#include<string>
using namespace std;

const int MAX = 30;

class  Big_integer {
public:
	Big_integer() {

		d[MAX] = { 0 };
		len = 0;
	}

	void friend getBigInteger(Big_integer &b);
	int friend  compare(Big_integer b1, Big_integer b2);
	Big_integer operator+(Big_integer &b2);
	Big_integer operator-(Big_integer &b2);
	Big_integer operator*(Big_integer &b2);
	Big_integer operator/(Big_integer &b2);


	void show();


private:
	int d[MAX];
	int len;

};
Big_integer b1;
Big_integer b2;

//以字符形式读取大整数，并存入整型向量
void  getBigInteger(Big_integer &b) {

	char ch[MAX] = { 0 };
	cin.getline(ch, MAX);

	b.len = strlen(ch);
	for (int i = 0; i < b.len; i++) {
		b.d[i] = ch[b.len - 1 - i] - '0';
	}

}
//比较两个整数的大小 
int compare(Big_integer b1, Big_integer b2) {
	int i = 0;

	if (b1.len > b2.len) {
		return 1;

	}
	else if (b1.len < b2.len) {
		return -1;
	}
	else {

		for (; i < b1.len; i++) {
			if (b1.d[b1.len - 1 - i] > b2.d[b2.len - 1 - i]) {
				return 1;

			}
			else if (b1.d[b1.len - 1 - i] < b2.d[b2.len - 1 - i]) {
				return -1;

			}

		}

		return 0;
	}


}
Big_integer Big_integer::operator+(Big_integer &b2) {
	Big_integer b;
	int carry = 0;//进位
	int temp = 0;
	for (int i = 0; i < len || i < b2.len; i++) {
		temp = d[i] + b2.d[i] + carry;
		b.d[b.len++] = temp % 10;

		carry = temp / 10;
	}
	if (carry != 0) {//最后的进位赋值给最高位
		b.d[b.len++] = carry;
	}
	return b;

}

Big_integer Big_integer::operator-(Big_integer &b2) {
	Big_integer b;
	for (int i = 0; i < len || i < b2.len; i++) {
		if (d[i] < b2.d[i]) {

			d[i] += 10;

		}
		b.d[b.len++] = d[i] - b2.d[i];

	}
	while ((b.len - 1 >= 1) && (b.d[b.len - 1] == 0)) {
		b.len--;//去掉最高位的0，同时至少保留一位最低位 
	}

	return b;
}

Big_integer Big_integer::operator*(Big_integer &b2) {
	Big_integer b;
	int carry = 0;
	
	for (int i = 0; i < len; i++) {


	}


}


void Big_integer::show() {
	for (int i = 0; i < len; i++) {
		cout << d[len - 1 - i] << ' ';
	}
	cout << '\n';
}
int main() {

	Big_integer b;

	getBigInteger(b1);
	getBigInteger(b2);
	b = b1 + b2;
	b.show();

	switch (compare(b1, b2)) {//返回 0,相等;返回1,第一个数大;返回-1,第二个数大

	case 0:
	case 1:	b = b1 - b2; b.show(); break;
	case -1:b = b2 - b1; cout << "-"; b.show(); break;
	}

	return 0;

}


