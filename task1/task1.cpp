/* 
 * C++ program that will count from 1 to 100, printing each number. 
 * If the square root of the number is a whole number, 
 * print ​ Fizz​ instead of the number. 
 * If the cube root of the number is a whole number, 
 * print ​ Buzz​ instead of the number. 
 * If the square and cube roots of the number are whole numbers, 
 * print ​ FizzBuzz​ instead of the number.
*/
#include <functional>
#include <iostream>
#include <cmath>

using namespace std;

float lzero = 1e-9;

function<bool(int)> perfSqr = [=](int n)->bool {
	double sqr = sqrt(n);
	double flr = floor(sqr);
	if (abs(sqr - flr) <= lzero) {
		return true;
	}
	return false;
};

function<bool(int)> perfCube = [=](int n)->bool {
	double cbr = cbrt(n);
	double flr = floor(cbr);
	if (abs(cbr - flr) <= lzero) {
		return true;
	}
	return false;
};

function<void(int,int)> counter = [](int s, int m)->void {
	if(s > m) {
		return;
	}
	if (perfSqr(s))
		cout << "Fizz";
	if (perfCube(s)) 
		cout << "Buzz";
	if (!perfSqr(s) && !perfCube(s))
		cout << s;
	cout << endl;
	counter(++s, m);
};

int main() {
	counter(1,100);
}
	

