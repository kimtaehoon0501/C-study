#include<iostream>

using namespace std;

// 함수들의 선언부.
void swap(int& a, int& b);

void SelectionSort(int* arr, int n);



int main() {
	int* arr;
	// 원소의 개수를 입력받고 동적으로 정수형 배열 선언.
	int n;
	cout << "N 입력: ";
	cin >> n;
	arr = new int[n];

	// 배열의 원소들을 입력받는다. 
	cout << "입력: ";
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	} 
	// 정렬 전 배열 출력
	cout << "정렬 전:";
	for (int i = 0; i < n; i++) {
		cout << arr[i] << " ";
	}
	cout << endl;

	// 선택정렬 실행
	SelectionSort(arr, n);

	//정렬 후 배열을 출력.
	cout << "정렬 후:";
	for (int i = 0; i < n; i++) {
		cout << arr[i]<<" ";
	}
	// 동적으로 생성한 배열의 메모리 해제
	delete[]arr;
	return 0;

}

// 두 정수형 변수의 값을 교환하는 swap함수를 참조에 의한 호출로 구현.
void swap(int& a, int& b) {
	int tmp;
	tmp = a;
	a = b;
	b = tmp;
}

// 선택정렬 함수.
void SelectionSort(int* arr, int n) {
	// 정렬되지 않은 부분의 배열에서 최솟값을 찾은 후, 해당 값을 정렬되지 않은 부분의 맨앞으로 이동.
	int min;

	for (int i = 0; i < n; i++) {
		int tmp = i;
		min = arr[i];
		// 최솟값을 찾는 반복문.
		for (int j = i; j < n; j++) {
			if (arr[j] < min) {
				min = arr[j];
				tmp = j;
			}
			
		}
		// 최솟값을 정렬되지 않은 부분의 맨앞으로 이동시킨다.
		swap(arr[i], arr[tmp]);
	}
}
