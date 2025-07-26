#include<iostream>
#include<string> //getline함수를 이용하기 위해 헤더에 선언


using namespace std;

int main() {
	string a, b;
	cout << "1: ";
	getline(cin, a);
	cout << "2: ";
	getline(cin, b);
	// 문자열 a,b를 선언 후, getline함수를 이용하여 문자열을 입력받는다.  
	int anum = 0, bnum = 0; //anum과 bnum은 각각 a와 b의 정수형 값이다. 
	
	int aDigit = 1; //adigit은 a의 자릿수 계산을 할 때 사용된다. 
	for (int i = a.length() - 1; i > -1; i--) {//가장 낮은자리부터 정수형으로 바꾸기 위한 반복문이다.
		for (int j = 48; j < 58; j++) { //정수는 ASCII 코드값으로 48인 0부터 시작하여 57인 9까지 존재한다.
			if (a[i] == j) { //만약 문자열의 i번째 문자의 아스키코드 값이 j이면
				anum += (j-48)*aDigit; //anum에 해당 숫자(j-48)과 자릿수(adigit)을 곱하여 더한다. 
				aDigit = aDigit * 10;// 한번 계산이 끝나면, 다음 자릿수를 계산하기위해 adigit에 10을 곱한다.
			}
		}
	}

	int bDigit = 1;
	for (int i = b.length() - 1; i > -1; i--) {
		for (int j = 48; j < 58; j++) {
			if (b[i] == j) {
				bnum += (j - 48) * bDigit;
				bDigit = bDigit * 10;
			}
		}
	}
	// 두번째 문자열인 b를 정수형으로 변환하는 작업이다. 작동은 위와 동일하다. 

	cout << anum + bnum << endl << anum - bnum << endl << anum * bnum; //바꾼 정수를 가지고 사칙연산 출력.
	return 0;

}