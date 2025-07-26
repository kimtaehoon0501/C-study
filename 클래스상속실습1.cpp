#include<iostream>
#include<string>

using namespace std;
//Employee 클래스 작성.
class Employee {
protected:
	// 이름과 id
	string name;
	int id;
public:
	// 생성자 - 매개변수들로 멤버를 초기화한다. 
	Employee(string name, int id) : name(name), id(id) {}

	// 화면에 해당 객체의 정보를 출력한다. 
	void showBasicInfo() {
		cout << "Name: " << name << ", ID: " << id << endl;
	}
};

//Manager클래스
class Manager : public Employee {
private:
	// 기본급과 팀관리수당
	int baseSalary;
	int teamBonus;
public:
	//Manager클래스의 생성자. name,id는 부모클래스의 생성자를 호출하여 처리하고, 기본급과 팀관리수당은 별개로 입력받아 초기화.
	Manager(string name, int id, int base, int bonus) : Employee(name, id) , baseSalary(base), teamBonus(bonus) {}
	// 급여 계산 함수. 
	int computeSalary() {
		return baseSalary + teamBonus;
	}
	// 화면에 정보를 출력하는 함수이다. 
	void showInfo() {
		// 공통적인 부분은 부모클래스의 함수를 호출하여 출력.
		showBasicInfo();
		cout << "[Manager] Salary: " << computeSalary() << endl;

	}
};

class Engineer : public Employee {
private:
	//기본급과 프로젝트수당
	int baseSalary;
	int projectBonus;
public:
	//Engineer클래스의 생성자. name,id는 부모클래스의 생성자를 호출하여 처리하고, 기본급과 프로젝트수당은 별개로 입력받아 초기화.
	Engineer(string name, int id, int base, int bonus) : Employee(name, id), baseSalary(base), projectBonus(bonus) {}
	//급여 계산 함수.
	int computeSalary() {
		return baseSalary + projectBonus;
	}
	//화면에 정보를 출력하는 함수. 
	void showInfo() {
		// 공통적인 부분은 부모클래스의 함수를 호출하여 출력.
		showBasicInfo();
		cout << "[Engineer] Salary: "<<computeSalary()<<endl;

	}
};

//Intern클래스 선언.
class Intern : public Employee {
private:
	// 시급과 근무시간을 선언. 
	int base;
	int time;
public:
	// 생성자 선언 - 위 클래스들과 마찬가지로 공통되는 name,id는 부모클래스의 생성자 호출하여 처리.
	Intern (string name, int id, int base, int time) : Employee(name, id), base(base), time(time) {}
	//급여 계산 - 시급*시간을 리턴.
	int computeSalary() {
		return base * time;
	}

	void showInfo() {
		// 공통적인 부분은 부모클래스의 함수를 호출하여 처리.
		showBasicInfo();
		cout << "[Intern] Salary: " << computeSalary() << endl;

	}
};

int main() {
	//Employee* type 배열 선언.
	Employee* employee[3];
	// 각 pointer들에는 파생클래스의 객체를 동적으로 할당받는다(업캐스팅)
	employee[0] = new Manager("Alice",1001,6000,200);
	employee[1] = new Engineer("Bob", 1002, 4000, 800);
	employee[2] = new Intern("Charlie", 1003, 4, 400);
	
	cout << "직원 정보 출력:" << endl;
	// 업캐스팅된 객체가 원래 클래스의 함수를 호출할 수 없으므로, 각 객체들의 포인터를 다시 다운캐스팅해준다.
	Manager* pM = (Manager*)employee[0];
	// 다운캐스팅 후 해당 클래스의 멤버함수 호출.
	// showInfo()는 부모클래스의 함수를 호출한다. 
	pM->showInfo();
	cout << "-----------------------" << endl;
	Engineer* pE = (Engineer*)employee[1];
	pE->showInfo();
	cout << "-----------------------" << endl;
	Intern* pI = (Intern*)employee[2];
	pI->showInfo();
	cout << "-----------------------" << endl;

	return 0;
}