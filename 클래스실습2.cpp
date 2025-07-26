#include<iostream> // 입/출력.
#include<string> // string 클래스를 사용하기위해 선언. 
using namespace std;

class book {
// 책의 이름, 저자, 페이지 수를 private에 선언. 
private:
	string name;
	string writer;
	int page;
public:
	// 생성자. 매개변수로 n,w,p를 받고 해당 객체의 멤버변수들을 초기화한다. 
	book(string n, string w, int p) {
		name = n;
		writer = w;
		page = p;
		// 객체 생성 및 멤버변수 초기화 후, 객체의 정보를 화면에 출력해준다. 
		cout << "제목: " << name << endl;
		cout << "저자: " << writer << endl;
		cout << "페이지 수: " << page << endl;
	};
};



int main() {
	// book객체의 멤버변수에 입력해줄 문자열변수와 정수형변수를 선언한다. 
	string n, w;
	int p;
	
	// 사용자로부터 제목, 저자, 페이지를 입력받는다.
	getline(cin, n);
	getline(cin, w);
	cin >> p;

	// book 객체 b를 생성한다. 
	book b(n, w, p);

	return 0;
}