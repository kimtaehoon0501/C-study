#include<iostream>
#include<fstream> //file입출력을 위해서 선언. 
#include<string>

using namespace std;

class Book {
	//출판연도
	int year;
	//가격
	int price;
	//책제목
	string name;
	//저자
	string author;
public:
	//기본생성자
	Book();
	//Book객체의 멤버 변수 세팅
	void setBook(int y,int p, string n, string a);
	// friend함수로 연산자 오버로딩
	friend bool operator<(const Book& a, const Book& b);
	friend bool operator>(const Book& a, const Book& b);
	//두 Book객체의 값을 바꾸는 swap함수
	friend void swap(Book& a, Book& b);
	// Book정보 출력
	void printBook();
};
// 기본생성자
Book::Book(){
	year = 0;
	price = 0;
	name = "";
	author = "";
}

// book의 멤버변수 세팅. 
void Book::setBook(int y, int p, string n, string a) {
	this->year = y;
	this->price = p;
	this->name = n;
	this->author = a;
}
// 왼쪽 객체와 오른쪽 객체를 비교하여 왼쪽객체가 더 늦게 출간되었다면 1, 아니라면 0 리턴.
bool operator<(const Book& a, const Book& b) {
	if (a.year > b.year) return 1;
	else return 0;
}

// 왼쪽 객체와 오른쪽 객체를 비교하여 왼쪽객체가 더 일찍 출간되었다면 1, 아니라면 0 리턴.
bool operator>(const Book& a, const Book& b) {
	if (a.year < b.year) return 1;
	else return 0;
}

// 두 객체의 값 교환
void swap(Book& a, Book& b) {
	Book temp;
	temp = a;
	a = b;
	b = temp;
}
// Book 객체 출력.
void Book::printBook() {
	cout << name + " (" + author + ", " << year << ") - " << price << "원" << endl;

}

int main() {
	// Books.txt에서 Book객체의 값을 읽어옴.
	ifstream input("Books.txt");
	// file이 열리지 않을 경우(존재하지 않을 경우)
	if (!input) {
		cout << "Cannot open the file";
		return 1;
	}
	else {
		// 책의 수를 num에 저장한다. 
		int num;
		input >> num;
		Book* Books = new Book[num];
		for (int i = 0; i < num; i++) {
			// file에서 읽은 값을 담아둘 변수를 선언.
			string a, n, y, p;
			// file에서 값을 읽어 변수에 대입한다. 
			input >> n >> a >> y >> p;
			// 객체배열에 값을 넣어줌
			Books[i].setBook(stoi(y), stoi(p), n, a);
		}
		// 선택정렬로 객체 배열을 정렬,  
		for (int i = 0; i < num; i++) {
			// k는 i범위 안에서의 출판연도가 가장 빠른 책의 인덱스이다.
			int k = i;
			// i+1번째 객체부터 k번째 객체와 비교한다. 
			for (int j = i + 1; j < num; j++) {
				// 만약 j번째 객체가 k번째 객체보다 출판연도가 빠르다면
				if (Books[k] < Books[j]) {
					k = j;
				}
			}
			// i와 k가 다를 경우, i번째 객체와와 k번째 객체를 바꿔준다.
			if (i != k) {
				swap(Books[i], Books[k]);
			}
		}

		// 화면에 출력.
		for (int i = 0; i < num; i++) {
			Books[i].printBook();
		}
		delete[] Books;


	}
	
	return 0;
}

