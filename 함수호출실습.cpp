#include<iostream>
using namespace std;

//swap함수 구현. 매개변수로는 주소를 의미하는 포인터 변수를 받는다.
void swap(int* a, int* b) {
	int tmp;
	// 주소에 해당하는 값을 직접 바꿈으로써 실제로 교환이 이루어짐
	tmp = *a;
	*a = *b;
	*b = tmp;
}

int main() {
	// 값을 바꿀 정수형 변수 2개를 선언한다. 
	int a, b;
	cin >> a >> b;
	cout << "swap() 전" << endl;
	// 바꾸기 전 두 변수의 값과 주소 출력.
	cout << "i1: " << a << endl << "i1's address: " << &a << endl;
	cout << "i2: " << b << endl << "i2's address: " << &b << endl;

	//swap함수 실행.
	swap(&a, &b);

	// 바꾼 이후의 해당 변수들의 값과 주소를 출력한다. 
	cout << "swap() 후" << endl;
	cout << "i1: " << a << endl << "i1's address: " << &a << endl;
	cout << "i2: " << b << endl << "i2's address: " << &b << endl;

	return 0;

}