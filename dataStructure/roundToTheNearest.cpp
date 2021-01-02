#include<iostream>

/*
 *将一个小数四舍五入保留两位小数 
 */

double roundToTheNearest(double value) {
	int temp = (int)(value * 1000 + 5) / 10;

	return (double)temp / 100.0;
}

int main() {
	double value;
	std::cin >> value;
	std::cout << roundToTheNearest(value);

}