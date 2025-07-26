#include<iostream>

#define MAX 100 //배열의 최대 크기를 상수로 선언.  
using namespace std;

int main() {
	char a[MAX];
	char b[MAX]; //문자 배열 2개를 MAX의 크기를 갖도록 선언해준다. 
	cin.getline(a, MAX);
	cin.getline(b, MAX);// cin.getline()을 이용해서 두 문자열에 값을 입력시켜준다.
	cout << ((strcmp(a, b)<0) ? a : b);
	// strcmp를 사용하여 문자열을 비교해준다. -1이면 a, 1이면 b가 출력되도록 삼항연산자를 사용함.
	return 0;
}