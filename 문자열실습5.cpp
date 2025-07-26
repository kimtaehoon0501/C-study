#include<iostream>
#include<string> //문자열을 다루기 위해 선언.

using namespace std;

int main() {
	string a;
	getline(cin, a);
	// 문자열을 입력받는다. 
	int m = a.length();// m은 문자열의 길이이다.
	for (int i = m-1; i >= 0; i--) {
		cout << a[i];
	}// 마지막에서부터 처음인덱스까지 문자열에서 문자를 출력. 
	return 0;
}