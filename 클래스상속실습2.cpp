#include<iostream>
#include<string>
using namespace std;

// Shape클래스 생성.
class Shape {
	//파생클래스 접근 가능.
protected:
	string name;
	int x;
	int y;
public:
	// 가상함수로 getArea()선언 (오버라이딩용)
	virtual double getArea() {
		return x * y;
	}
	//가상 소멸자
	virtual~Shape(){}
	// name리턴.
	string getName() {
		return name;
	}
	// 생성자.
	Shape(string name, int x, int y) {
		this->name = name;
		this->x = x;
		this->y = y;
	}
};

//Oval클래스를 Shape클래스를 상속받아 작성. 
class Oval : public Shape {
public:
	// 생성자 - 부모클래스 호출
	Oval(string name, int x, int y) :Shape(name, x, y) {}
	// 오버라이딩.
	virtual double getArea() {
		return 3.14 * x * y;
	}

};

// Rect 클래스를 Shape클래스를 상속받아 생성.
class Rect : public Shape {
public:
	Rect(string name, int x, int y) :Shape(name, x, y) {}
	// 오버라이딩
	virtual double getArea() {
		return x * y;
	}
};
// Triangular 클래스를 Shape클래스를 상속받아 생성.
class Triangular : public Shape {
public:
	Triangular(string name, int x, int y) :Shape(name, x, y) {}
	//오버라이딩
	virtual double getArea() {
		return x * y * 0.5;
	}
};

int main() {
	Shape* p[3];
	// 업캐스팅 - 파생클래스 자식을 부모클래스 포인터에 할당
	p[0] = new Oval("빈대떡", 10, 20);
	p[1] = new Rect("찰떡", 30, 40);
	p[2] = new Triangular("토스트", 30, 40);
	// 배열의 처음부터 끝까지에 대해 화면에 출력. 
	for (int i = 0; i < 3; ++i) {
		//getName()은 부모클래스에 있는 함수가 실행
		// getArea는 오버라이딩 된 파생클래스의 함수가 실행. 
		cout << p[i]->getName() << " 넓이는 " << p[i]->getArea() << endl;
	}
	// 메모리 해제
	for (int i = 0; i < 3; ++i) delete p[i];
}