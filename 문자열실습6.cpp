#include<iostream>
#include<string> // string클래스와 find, length 함수를 사용하기위해 선언.
using namespace std;

int main() {
	string s;
	getline(cin, s);
	string a;
	cout << "찾고자 하는 문자열을 입력하세요: ";
	cin>> a; // a에 찾고자 하는 문자열을 입력받는다. 
	int c = 0; // 찾고자 하는 문자열의 개수를 의미한다. 
	int p;
	p = s.find(a); //p는 해당 문자열의 첫번째 문자의 인덱스이다. 
	if (p == -1) { // 찾고자 하는 문자열이 존재하지 않을때. 존재하지 않는다는 메세지를 출력해준다. 
		cout << "찾고자 하는 문자열이 존재하지 않습니다.";
	}
	else { //찾고자 하는 문자열이 대상 문자열에 1개 이상 존재하는 경우. 해당 문자열을 제외한 나머지 문자열에 대해서도 검색한다. 
		cout << "인덱스: ";
		do {
			cout << p<<" ";
			c++;
		} while ((p=s.find(a, p+a.length()))!=-1);
		cout <<endl<<"횟수"<< c;
		
	}
	

	return 0;

	}