#include<iostream> // 입/출력
#include<string> // string클래스 활용

using namespace std;

// 밑에 작성한 Drink구조체는 cefe클래스의 멤버 변수로서, cafe에서 판매하는 음료이다.
// 이는 name과 price를 구조체 멤버로 갖는다. 
struct Drink {
	string name;
	int price;
};

class cafe {
	// 멤버 변수로 Drink구조체 3개를 배열로 선언 및  문제에 제시된 대로 초기화하고, 총 매출을 의미하는 sum을 선언 및 0으로 초기화.
	// 이 두 변수는 private로 작성하여 외부에서 직접적인 접근을 막는다.
private:
	Drink menu[3] = { { "아메리카노", 3000}, {"카페라떼", 4000}, {"얼그레이" , 3500}};
	int sum = 0;
	
public:
	// 음료를 판매하고 매출을 기록하는 sales함수. 
	void sales();
	// 메뉴를 화면에 출력해주는 PrintMenu함수.
	void PrintMenu();
	// 소멸자. 객체가 소멸할때 총 매출을 화면에 출력한다. 
	~cafe() {
		cout << "총 매출: " << sum;
	}
};
// 메뉴를 출력하는 PrintMenu함수의 구현부. 
void cafe:: PrintMenu() {
	// for 반복문을 이용하여 Drink구조체 배열을 처음부터 끝까지 화면에 출력해준다. 
	for (int i = 0; i < 3; i++) {
		cout << i + 1 << ". " << menu[i].name + ' ';
	}
	cout << endl;
}

// 판매를 수행하고, 총 매출을 계산하는 sales함수이다. 
void cafe::sales() {
	// 정수형 변수 n을 사용자로부터 입력받아서 밑의 반복문을 수행한다. 
	int n;

	while (1) {
		// 메뉴를 화면에 출력. 
		PrintMenu();
		
		// n을 입력받는다. 
		cout << "입력해주세요: ";
		cin >> n;
		
		// n의 값이 1에서 3사이이면, 대응되는 메뉴의 가격을 총 매출에 더하고, 다시 반복한다.
		if (n >= 1 && n <= 3) {
			sum = sum + menu[n-1].price;
		}
		
		// n의 값이 0이라면 해당 반복문을 종료한다. 
		else if(n == 0) {
			break;
		}

		// n의 값이 0,1,2,3중 하나가 아니라면 다시 입력하라는 메세지를 출력한다.
		else {
			cout << "다시 입력해주세요. " << endl;
		}
		

	}
}

int main() {
	// cafe객체 c 선언.
	cafe c;

	// sales함수 실행
	c.sales();

	return 0;
}