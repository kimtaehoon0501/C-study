#include<iostream>
#include<string>
using namespace std;
//Student클래스
class Student {
private:
	string name;
	int mid; //중간시험 성적
	int final; // 기말시험 성적
public:
	// 학생의 정보를 화면에 출력해주는 함수이다. 
	void print() {
		cout << "이름: " <<name<< endl;
		cout << "중간점수 : " << mid << endl << "기말점수 : " << final;
		cout << endl << "합계: " << mid + final;
	}
	//학생의 성적의 평균을 리턴하는 함수. 
	int getaverage() {
		return (mid + final) / 2;
	}
	// 생성자이다. 객체 배열에서는 기본생성자만이 작동하므로 기본생성자로 작성. 
	Student() {
		cout << "이름: ";
		cin >> name;
		cout << "중간 및 기말점수: ";
		cin >> mid >> final;
	};
};

//Class클래스
class Class {
private:
	Student* s;
	int n;//학생수를의미. 
public:
	// Class객체의 생성자. 학생수를 입력받고, 그 수만큼 동적으로 Student객체 생성.
	Class() {
		cout << "학생의 수를 입력해 주세요: ";
		cin >> this->n;
		s = new Student[n];
	};

	//소멸자. 메모리 해제를 위해 작성.
	~Class() {
		delete []s;
	}
	Student getTop() { // 성적이 제일 높은 학생을 리턴.
		Student* max = s;
		for (int i = 0; i < n; i++) {
			
			if (max->getaverage() < (s + i)->getaverage()) {
				max = s + i;
			}
		}
		return *max;
	}
};

int main() {
	// 문제에 제시된대로 작동시키기 위해 알맞게 작성.
	Class a;
	a.getTop().print();
	return 0;
}