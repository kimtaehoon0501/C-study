#include<iostream>

using namespace std;

// MyArray클래스 작성
class MyArray {
	// 배열을 다룰 포인터 변수
	int* ptr;
	//배열의 사이즈 
	int size;
public:
	// 매개변수가 존재하는 생성자. 
	MyArray(int size) {
		this->size = size;
		cout << "[생성자 호출]" << endl;
		// size만큼의 배열을 동적으로 할당받는다. 
		ptr = new int[size];
		
		// 배열 초기화
		for (int i = 0; i < size; i++) {
			
			ptr[i] = i+1;
		}
	}
	
	// 복사생성자
	MyArray(const MyArray& arr) {
		cout << "[깊은 복사생성자 호출]" << endl;
		size = arr.size;
		// 해당 생성자로 생성된 객체의 ptr에 새롭게 동적으로 배열을 할당받는다. 
		ptr = new int[size];
		for (int i = 0; i < size; i++) {
			ptr[i] = arr.ptr[i];
		}
	}

	// a번째 원소를 b로 바꾸는 함수. 
	void set(int a, int b) {
		ptr[a] = b;
	}

	// 배열을 화면에 출력해주는 함수. 
	void print() {
		for (int i = 0; i < size; i++) {
			cout << ptr[i] << " ";
		}
		cout << endl;
	}
	// 소멸자 - 동적으로 할당 받은 배열을 메모리 해제. 
	~MyArray() {
		cout << "[소멸자 호출]" << endl;
		delete[] ptr;
	}
};

// 문제에 제시된 대로의 메인함수. 
int main() {
	// 배열의 크기를 입력받는다. 
	int n;
	cout << "크기 입력: ";
	cin >> n;
	// 매개변수가 존재하는 생성자로 객체 생성. 
	MyArray a(n);
	cout << "a: "; a.print();
	// 복사생성자를 통한 객체 생성. 
	MyArray b = a;
	// 값 바꾸기.
	b.set(0, 99);
	cout << "(b 수정 후, a 원소)" << endl;
	cout << "a: "; a.print();
	cout << "b: "; b.print(); cout << endl;
	
	return 0;
}