#include<iostream>
#include<fstream> //file입출력을 위해서 선언
#include<string>
#include<iomanip>

using namespace std;

class Student {
	string name; // 학생의 이름
	int score[3]; // 과목 3개의 점수를 저장할 정수형 배열. 
public:
	// 기본생성자. 이름과 점수배열을 초기화
	Student() {
		name = "";
		for (int i = 0; i < 3; i++) {
			score[i] = 0;
		}
	}
	// Student객체의 값을 세팅. string과 정수형 포인터(배열)을 받는다. 
	void setStudent(string name, int *score) {
		this->name = name;
		for (int i = 0; i < 3; i++) {
			this->score[i] = score[i];
		}
	}
	// 점수의 합을 리턴하는 함수이다. 
	int getSum() {
		int sum=0;
		for(int i = 0; i < 3; i++) {
			sum = sum + score[i];
		}
		return sum;
	}
	// friend함수로 >와 < 연산자를 오버로딩하였다. - 객체끼리 비교를 가능하게 해준다. 
	friend bool operator>(Student a,Student b);
	friend bool operator<(Student a, Student b);
	// 두 객체의 값을 바꿔주는 swap함수. 
	friend void swap(Student& a, Student& b);
	// <<연산자를 friend함수로 오버로딩. 참조리턴을 사용하여 해당 스트림객체 조작후 변경내용 유지.
	friend ostream& operator<<(ofstream &a,Student s);
};

// a의 점수 총합이 크면1, 그렇지 않다면 0
bool operator>(Student a, Student b) {
	if (a.getSum() > b.getSum()) {
		return 1;
	}
	else {
		return 0;
	}
}
// a의 점수 총합이 크다면 1, 그렇지 않으면 0
bool operator<(Student a, Student b) {
	if (a.getSum() < b.getSum()) {
		return 1;
	}
	else {
		return 0;
	}
}
// 작성한 포맷대로 ofstram객체에 출력. 이후 참조를 리턴하여 연속된 연산자도 처리가능하도록 해줌.
ostream& operator<<(ofstream &a, Student s) {
	// 소수점 두번째 자리까지 출력하도록 iomanip헤더 사용.
	a << s.name << ": 총점 = " << s.getSum() << ", 평균 = " <<std::fixed<< std::setprecision(2)<<(double)s.getSum() / 3 << endl;
	return a;
}
// 두 Student객체의 값을 바꿔줌.
void swap(Student& a, Student& b) {
	Student tmp;
	tmp = a;
	a = b;
	b = tmp;
}

int main() {
	// students.txt를 연다. 
	ifstream input("students.txt");
	// 맨 첫번째 줄을 읽어서 학생수를 정수형 변수에 대입. 
	if (!input) {
		cout << "cannot open the file!";
		return 1;
	}
	int num;
	input >> num;
	// 학생들의 정보를 다룰 객체 배열 선언. 
	Student*students = new Student[num];
	// 객체 배열에 읽어온 정보를 입력해준다. 
	for (int i = 0; i < num; i++) {
		string name;
		int score[3];
		// 이름을 맨 먼저 읽어옴.
		input >> name;
	
		string s;
		for (int j = 0; j < 3; j++) {
			input >> s;
			score[j] = stoi(s);
		}
		students[i].setStudent(name, score);
	}
	// 선택정렬로 객체 배열을 정렬,  
	for (int i = 0; i < num; i++) {
		// k는 i범위 안에서의 출판연도가 가장 빠른 책의 인덱스이다.
		int k = i;
		// i+1번째 객체부터 k번째 객체와 비교한다. 
		for (int j = i + 1; j < num; j++) {
			// 만약 j번째 객체가 k번째 객체보다 출판연도가 빠르다면
			if (students[k] < students[j]) {
				k = j;
			}
		}
		// i와 k가 다를 경우, i번째 객체와와 k번째 객체를 바꿔준다.
		if (i != k) {
			swap(students[i], students[k]);
		}
	}
	// 해당 결과를 입력할 file을 열기.
	ofstream output("result.txt");
	// file을 열 수 없을때. 
	if (!output) {
		cout << "cannot open the file";
		return 1;
	}

	for (int i = 0; i < num; i++) {
		output << students[i]<<endl;
	}

	// 동적으로 생성한 배열 delete.
	delete[] students;
	return 0;
}