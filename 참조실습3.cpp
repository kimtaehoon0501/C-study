#include<iostream>
#include<string> //string 객체 사용을 위해 선언. 
using namespace std;

//Country 클래스 작성. 
class Country {
	// 국가들의 이름, 메달 개수, 국가 총합은 private로 작성하였다. 
	string name;
	int bronze, silver, gold;
	static int country_count;
public:
	// 매개변수가 없는 생성자. 
	Country() : name(""), gold(0), silver(0), bronze(0) {
	}
	// 매개변수가 있는 생성자. - 생성 시 국가의 수를 나타내는 변수가 1증가 한다.  
	Country(string n, int g, int s, int b) : name(n), gold(g), silver(s), bronze(b) {
		country_count++;
	}
	// 해당 객체가 순위가 더 위라면 true, 아니면 false 출력. 
	bool isHigher(const Country& other) {
		// 금메달이 더 많은 경우 true반환. 
		if (gold > other.gold) {
			return true;
			}
		// 금메달이 같은 경우 -> 은메달 비교
		else if(gold==other.gold){
			// 은메달 개수가 더 많은 경우. 
			if (silver > other.silver) {
				return true;
			}
			// 은메달 개수가 같은 경우. 
			else if (silver == other.silver) {
				if (bronze > other.bronze) {
					return true;
				}
				else {
					return false;
				}
			}
			else {
				return false;
			}
			
		}
		else {
			return false;
		}
		

	}

	// 매달의 수가 같다면 true를, 다르면 false를 출력한다.  
	bool isEqual(const Country& other) {
		if (gold == other.gold && silver == other.silver && bronze == other.bronze) {
			return true;
		}
		return false;
	}

	// 화면에 국가의 순위를 출력해주는 함수. 
	void printWithRank(int rank) {
			cout << rank << "위 - " << name << " (Gold: " << gold << " Silver: " << silver << " bronze: " << bronze << ")" << endl;
	}
	// 전역변수를 리턴하는 함수. 
	static int getCountryCount() {
		return country_count;
	}

}; 
// 전역변수는 외부에서 초기화 해준다. 
int Country::country_count = 0;

void selectionSort(Country arr[], int n) {
	// 선택정렬을 내림차순으로 구현.  
	Country tmp;
	for (int i = 0; i < n; i++) {
		int max = i;
		for (int j = i + 1; j < n; j++) {
			if (!arr[max].isHigher(arr[j])) {
				max = j;
			}
		}
		// max 와 i번째 원소의 값을 바꾼다. 
		tmp = arr[i];
		arr[i] = arr[max];
		arr[max] = tmp;
	}
}

int main() {
	// 국가 수를 입력받는다. 
	int n;
	cout << "참가 국가 수를 입력하세요: " ;
	cin >> n;
	// 기본생성자에 의해 객체들이 생성됨. 
	Country* arr = new Country[n];
	string name;
	int gold, silver, bronze;
	//객체배열의 원소들의 멤버변수 값을 입력받는다. 
	
	cout<<endl<< "[국가 정보 입력]" << endl<<endl;

	// 국가들의 정보를 입력받는다. 
	for (int i = 0; i < n; i++) {
		cout << i+1 << "번째 국가 입력" << endl;
		cout << "국가 이름: ";
		cin >> name;
		cout << "금, 은, 동 메달 수: ";
		cin >> gold>>silver>>bronze;
		// 객체 치환. 
		arr[i] = Country(name, gold, silver, bronze);
		cout << endl;
	}
	selectionSort(arr, n);
	int rank = 1;
	//rank와 함께 국가들을 화면에 출력해준다. 
	for (int i = 0; i < n; i++) {
		// 국가를 rank와 함께 출력. 
		arr[i].printWithRank(rank);
		// 만약 다음번 국가와 메달수가 동일하다면, rank는 그대로이다. 
		if ((i!=n-1)&&arr[i].isEqual(arr[i + 1])) {
	
		}
		// 그렇지 않다면, rank는 현재 저장된 배열의 index+1이므로, i+2가 된다(i는 반복문서 1증가하기 때문에)
		else {
			rank = i+2;
		}
	}
	cout <<"총 참여 국가 수:"<< Country::getCountryCount();

	
	
}