#include<iostream>
#include<string> //string 클래스와 입/출력 사용을 위해 두개의 헤더파일을 포함시킴.

using namespace std;

//Student 클래스 작성
class Student
{
public:
	string StudentName;		//학생이름
	string StudentMajor;	//학생의 학과
	int AdmissionYear = 0;		//학생의 입학년도
	void ShowStudent();		//학생의 정보를 출력해주는 함수
};
void Student::ShowStudent() 
{
	cout << "이름: " << this->StudentName << endl;
	cout << "학과: " << this->StudentMajor << endl;
	cout << "입학년도: " << this->AdmissionYear << endl;
}  // 멤버 함수 작성 - 학생의 정보를 출력해준다.

int main() {
	string name, major;
	int year;	//이름과 학과는 string 변수로 선언, 입학년도는 정수형 변수로 선언.
	Student a; // Student 객체를 생성
	cout << "이름: ";
	getline(cin, name);
	a.StudentName = name;
	cout << "학과: ";
	getline(cin, major);
	a.StudentMajor = major;
	cout << "입학년도: ";
	cin >> year;
	a.AdmissionYear = year;
	//getline함수로 이름, 학과를 입력받고, cin함수로 입학년도를 입력받는다.
	//입력받은 정보를 Student객체의 멤버변수에 배정한다.
	cout << endl;
	a.ShowStudent(); // 학생의 정보를 출력한다. 
	return 0;

}
