#include<iostream>
#include<fstream>
#include<cstdlib>
#include<ctime>
using namespace std;


int main() {
	srand(time(nullptr));

	// file을 열어서 난수를 100개 입력해줬다. 
	ofstream fout("test.txt");
	// file을 열 수 없을때. 
	if (!fout) {
		cout << "Cant open the file";
		return 1;
	}
	// 1에서 10000까지의 숫자를 랜덤하게 100개 입력. 띄워쓰기로 각 숫자들을 구분한다.
	for (int i = 0; i < 100; i++) {
		fout << rand() % 10000 + 1<<" ";
	}
	fout.close();

	// file에서 읽어올 정수형 변수들을 담을 정수형 배열이다. 
	int a[100];
	
	// file 읽기모드
	ifstream fin("test.txt");

	// a[i]에 읽은 값들을 저장해줬다. 
	for (int i = 0; i < 100; i++) {
		fin >> a[i];
	}
	int c;
	cout << "1. 오름차순 정렬 2. 내림차순 정렬 : ";
	cin >> c;
	if (c == 1) {
		// 선택정렬(오름차순)
		for (int i = 0; i < 100; i++) {
			int k=i; // 최솟값의 인덱스. 
			int min = a[i];
			// 최솟값을 찾아준다. 
			for (int j = i + 1; j < 100; j++) {
				if (min > a[j]) {
					min = a[j];
					k = j;
				}
			}
			//a[i]와 min의 값을 교환한다. 
			int tmp = a[i];
			a[i] = a[k];
			a[k] = tmp;
		}


		for (int i = 0; i < 100; i++) {
			cout << a[i] << " ";
			if ((i+1) % 25 == 0) cout << endl;
		}
	}
	else if (c == 2) {
		// 선택정렬(내림차순)
		for (int i = 0; i < 100; i++) {
			int k = i;
			int max = a[i];
			// 최댓값을 찾아준다. 
			for (int j = i + 1; j < 100; j++) {
				if (max < a[j]) {
					max = a[j];
					k = j;
				}
			}
			//a[i]와 min의 값을 교환한다. 
			int tmp = a[i];
			a[i] = a[k];
			a[k] = tmp;
		}
		for (int i = 0; i < 100; i++) {
			cout << a[i] << " ";
			if ((i+1) % 25 == 0) cout << endl;
		}
	}
	else {
		cout << "잘못된 입력값입니다. 프로그램을 종료합니다.";
	}
	

	return 0;
}