#include<iostream>
using namespace std;

// Matrix클래스 작성. 
class Matrix {
public:
	int cols;
	int rows;
	int** values; // 이차원 배열을 다루기 위해 이중포인터 선언.
	// 생성자. 
	Matrix(int rows, int cols) {
		
		this->rows = rows;
		this->cols = cols;
		values = new int* [rows];
		for (int i = 0; i < rows; i++) {
			values[i] = new int[cols];
		}
		// 0으로 행렬 초기화.
		for (int i = 0; i < rows; i++) {
			for (int j = 0; j < cols; j++) {
				values[i][j] = 0;
			}
		}

	}
	// 소멸자.
	~Matrix() {
		for (int i = 0; i < rows; i++) {
			delete[] values[i];
		}

		delete[]values;
	}
	// 복사 생성자. other객체의 값 복사. 
	Matrix(const Matrix& other){
		rows = other.rows;
		cols = other.cols;
		values = new int* [rows];
		for (int i = 0; i < rows; i++) {
			values[i] = new int[cols];
			for (int j = 0; j < cols; j++) {
				values[i][j] = other.values[i][j];
			}
		}
	}
	
	// 행렬간의 덧셈을 덧셈연산자 오버로딩으로 구현. 
	Matrix operator+(Matrix b) {
		Matrix result(rows, cols);
		for (int i = 0; i < rows; i++) {
			for (int j = 0; j < cols; j++) {
				result.values[i][j] = values[i][j] + b.values[i][j];
			}
		}
		return result;
	}
	// 행렬간의 뺄셈을 뺄셈연산자 오버로딩으로 구현. 
	Matrix operator-(Matrix b) {
		Matrix result(rows, cols);
		for (int i = 0; i < rows; i++) {
			for (int j = 0; j < cols; j++) {
				result.values[i][j] = values[i][j] - b.values[i][j];
			}
		}
		return result;
	}
	// 행렬간의 곱셈을 덧셈연산자 오버로딩으로 구현. 
	Matrix operator*(Matrix b) {
		Matrix result(rows, b.cols);
		for (int i = 0; i < rows; i++) {
			for (int j = 0; j < b.cols; j++) {
				for (int k = 0; k < cols; k++) {
					result.values[i][j] += values[i][k] * b.values[k][j];
				}
			}
		}
		return result;
	}
};

int main() {
	int a, b;
	cout << "행렬의 크기를 입력하세요" << endl;
	cin >> a >> b;
	// 입력받은 크기의 행렬을 선언. 
	Matrix i(a, b);
	Matrix j(a, b);
	// 1번 행렬의 값을 입력받은후 객체의 멤버변수에 대입. 
	cout << "1번 행렬의 값을 입력해 주세요" << endl;
	for (int p = 0; p < a; p++) {
		for (int q = 0; q < b; q++) {
			cin >> i.values[p][q];
		}
	}
	// 2번 행렬의 값을 입력받은 후 객체의 멤버변수에 대입. 
	cout << "2번 행렬의 값을 입력해 주세요" << endl;
	for (int p = 0; p < a; p++) {
		for (int q = 0; q < b; q++) {
			cin >> j.values[p][q];
		}
	}

	// 각 연산의 결과를 저장할 객체를 선언한다. 
	cout << "덧셈결과" << endl;
	// 오버로딩된 덧셈연산자. 복사생성자가 실행됨.
	Matrix AddMat= i+j;
	
	
	for (int p = 0; p < a; p++) {
		for (int q = 0; q < b; q++) {
			cout << AddMat.values[p][q] << " ";
		}
		cout << endl;
	}



	cout << "뺄셈결과" << endl;
	Matrix SubMat = i-j;
	// 오버로딩된 뺄셈연산자. // 오버로딩된 덧셈연산자. 복사생성자가 실행됨.
	
	for (int p = 0; p < a; p++) {
		for (int q = 0; q < b; q++) {
			cout << SubMat.values[p][q] << " ";
		}
		cout << endl;
	}

	// 행렬의 곱셈이 가능한 조건을 조건문을 통해 확인한다. 
	cout << "곱셈결과" << endl;
	if (i.cols != j.rows) {
		cout << "곱셈이 불가능 합니다." << endl;
	}
	else {
		// 오버로딩된 곱셈연산자. 복사생성자가 실행된다.
		Matrix MultiMat = i * j;
		for (int p = 0; p < i.rows; p++) {
			for (int q = 0; q < j.cols; q++) {
				cout << MultiMat.values[p][q] << " ";
			}
			cout << endl;
		}
	}
	

	return 0;
}

