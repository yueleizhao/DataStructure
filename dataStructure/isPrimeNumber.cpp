#include<iostream>

/*
 *�ж�һ�����Ƿ�Ϊ prime number
 */


void isPrimeNumber(int value) {
	int i;
	for (i = 2; i < value; i++)
		if (value%i == 0) {
			std::cout << value << " is not prime number" << "\n";
			break;
			
		}
	
	if (i == value)std::cout << value << " is prime number" << "\n";

}

int main() {
	int value;
	std::cin >> value;
	isPrimeNumber(value);
}