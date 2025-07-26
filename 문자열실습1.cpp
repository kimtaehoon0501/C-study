#include<iostream> //cout을 사용하기 위해 작성
#include<string>// getline함수를 사용하기 위해 string을 헤더에 넣어준다.

using namespace std; // std이름공간을 생략하기 위해 작성

int main() {
	string a; //문자열 변수 a를 선언(문장을 입력받는다)
	for (int i = 0; i < 3; i++) {
		getline(cin, a); // 문자열 a에 사용자로부터 문장을 입력받는다.
		cout << a << endl << endl; //a 출력
	} // 반복문으로 입력받는것과 출력하는것을 3번 반복한다.

	return 0;
}