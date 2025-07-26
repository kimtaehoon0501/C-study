#include<iostream>
using namespace std;

//Calculator 클래스 작성. 멤버 함수만 public으로 선언한다. 
class Calculator {
public:
	// 각 기능에 맞는 함수들을 동일한 이름으로 작성하되, 매개변수는 다르게 작성. 
	// 두 정수의 덧셈
	int calculate(int a, int b);
	// 두 실수의 덧셈
	double calculate(double a, double b);
	// 정수의 제곱
	int calculate(int a);
	// 세개의 정수의 평균
	int calculate(int a, int b, int c);
};

// 각 함수의 구현부 작성. 
int Calculator::calculate(int a, int b) {
	return a + b;
}

double Calculator::calculate(double a, double b) {
	return a + b;
}

int Calculator::calculate(int a) {
	return a * a;
}

int Calculator::calculate(int a, int b,int c) {
	return (a + b + c) / 3;
}

int main() {
	Calculator a;
	// 계산 결과 출력. 
	cout << "calculate(3,4)=" << a.calculate(3, 4) << endl;
	cout << "calculate(2.5,3.1)=" << a.calculate(2.5, 3.1) << endl;
	cout << "calculate(5)=" << a.calculate(5) << endl;
	cout << "calculate(3,4,5)=" << a.calculate(3, 4,5) << endl;
	return 0;
}