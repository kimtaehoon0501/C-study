#include<iostream>
using namespace std;

int count = 0; // 소수의 개수를 나타내는 변수이다. 


// N까지 존재하는 소수를 출력하는 함수. 
void getPrimes(int N, int*& primes, int& count);

int main() {
	// N을 입력받는다. 
	int N;
	cout << "N 입력: ";
	cin >> N;

	// 소수의 배열을 다룰 포인터 변수. 
	int* primes;

	getPrimes(N, primes, ::count);
	cout << "소수 목록: ";
	for (int i = 0; i < ::count; i++) {
		cout <<primes[i]<<" ";
	}
	cout << endl << "총 소수 개수: " << ::count;

	delete[] primes;

	return 0;
}

void getPrimes(int N, int*& primes, int& count) {
	//count는 우선 0으로 선언되어있으므로 크기가 0인배열이 된다. 
	primes = new int[count];
	int i;
	// N까지의 숫자를 검사한다.1은 소수가 아니므로 소수인지 아닌지는 2부터 검사한다. 
	for (i = 2; i <= N; i++) {
		//i가 j로 나누어지는지 확인한다. 변수 p의 변화로 이를 구별한다. 
		int p = 0;
		for (int j = 1; j < i; j++) {
			if (j == 1) {
				continue;
			}
			else if (i % j == 0) {
				p = 1;
			}
		}
		// 소수임이 증명되면, primes를 삭제하고 크기가 1 증가한 배열을 동적으로 선언, 해당 소수를 넣어준다. 
		if (p == 0) {
			// tmp에 기존에 존재하던 배열의 원소들을 복사해준다. 
			int* tmp = new int[count];
			for (int k = 0; k < count; k++) {
				tmp[k] = primes[k];
			}
			// 소수가 발견되면 크기가 증가한 새로운 배열 생성.
			delete[]primes;
		
			count++;
			primes = new int[count];
			for (int k = 0; k < count-1; k++) {
				primes[k] = tmp[k];
			}
			delete[]tmp;
			primes[count-1] = i;
		}

	}
}