#include<iostream>
using namespace std;

// resizeAndPush함수 선언. 
void resizeAndPush(int*& arr, int& capacity, int& size, int value);

//전역변수로 선언. 
int capacity = 1;
int size = 0;

int main() {
	// 현재 capacity만큼의 배열을 선언한다. 
	int* arr = new int[capacity];
	
	// n은 사용자로부터 입력받는 정수형 변수이다. 음수가되면 입력받는것을 중단한다.
	int n;
	while (1) {
		cout << "입력: ";
		cin >> n;
		// 음수면 while loop를 중단한다. 
		if (n <= 0) {
			break;
		}
		else {
			//전역변수 size가 std::size와 혼동되지않도록 ::size로 전역변수 size임을 명시.
			//size의 크기가 capacity보다 작은경우, 기존 배열에 그대로 원소를 넣으면 된다. 
			if (::size < capacity) {
				arr[::size] = n;
				// 원소를 한개 넣을때마다 size를 1 증가시킨다. 
				::size++;
			}
			// 그렇지 않으면, resizeAndPush함수를 작동시킨다.
			else {
				resizeAndPush(arr, capacity, ::size, n);
				
			}
			
		}
	}
	
	for (int i = 0; i < ::size; i++) {
		cout << arr[i]<<" ";
	}

	cout << endl << "용량: " << capacity;
	delete[]arr;
	return 0;


}

// arr, capacity, size를 call-by-reference로 전달받아 원래 객체의 값에도 변화가 나타나도록 구현한다. 
void resizeAndPush(int*& arr, int& capacity, int& size, int value) {
	int *tmp = new int[capacity]; // 기존 정수형 배열에 존재하던 원소를 새로운 배열에 복사하기 위해 선언. 
	//tmp에 기존 배열의 값을 복사한다. 
	for (int i = 0; i < size; i++) {
		tmp[i] = arr[i];
	}
	// 기존 배열은 메모리해제. 
	delete[] arr;
	//capacity를 2배로 늘려주고, 2배길이의 배열을 선언한다. 
	capacity *= 2;
	arr = new int[capacity];
	//선언한 새로운 배열에 기존의 값들을 다시 넣어준다. 
	for (int i = 0; i < size; i++) {
		arr[i] = tmp[i];
	}
	delete[] tmp;
	arr[size] = value;
	size++;
}