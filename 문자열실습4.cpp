#include<iostream> //string과 입/출력을 위해 iostream헤더 선언
#include<string> //getline()함수를 사용하기위해 string헤더 선언


using namespace std;

int main() {
	string a, b, c;
	//문자열을 3개 선언한다.
	cout << "1: ";
	getline(cin, a);
	
	cout << "2: ";
	getline(cin, b);
	
	cout << "3: ";
	getline(cin, c);
	//선언한 3개의 문자열에 문자열을 입력받는다. 
	
	string tmp;

	if (a > b) {
		tmp = a;
		a = b;
		b = tmp;
	} //a가 b보다 사전에 늦게나오면, 두 문자열의 값을 바꿔준다. 
	if (b > c) {
		tmp = b;
		b = c;
		c = tmp;
	}//b가 c보다 사전에 늦게나오면, 두 문자열의 값을 바꿔준다. 
	if (a > b) {
		tmp = a;
		a = b;
		b = tmp;
	}//a가 b보다 사전에 늦게나오면, 두 문자열의 값을 바꿔준다. 

	// 세 문자열을 abc 순서로 본 다음, 버블정렬과 유사하게 abc를 정렬한다.
	// 문자열 자체를 바꾸는게 아니라, 해당 문자열의 값을 바꿔서 정렬해준다. 
	
	cout << a +' '+ b+' '+ c; //정렬된 문자열들을 화면에 출력해준다. 
	return 0;

}