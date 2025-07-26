#include<iostream> // 입/출력을 위해 헤더에 선언
using namespace std;

int main() {
	int n;
	cin >> n; //n은 배열의 크기를 의미한다. 

	int* p = new int[n]; // 크기가 n인 정수형 배열을 동적할당으로 생성. 포인터변수 p에 주소 전달.
	int m;
	// 반복문을 통해 배열에 값을 입력해준다. 
	for (int i = 0; i < n; i++) {
		cin >> m;
		*(p + i) = m;
	}
	// 생성한 정수형 배열의 원소들을 모두 출력해준다. 
	for (int i = 0; i < n; i++) {
		cout << *(p + i) << endl;
	}

	// 생성했던 배열을 메모리해제한다.
	free(p);
}