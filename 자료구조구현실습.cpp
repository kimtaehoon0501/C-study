#include<iostream>
using namespace std;
// BaseArray클래스 생성. 
class BaseArray {
protected:
	// 최대 원소 수
	int capacity;
	// 현재 원소 수
	int size;
	// 동적할당으로 배열의 주소를 입력받을 pointer.
	int* data;
public:
	// 생성자에서 배열을 동적으로 선언.
	BaseArray(int capacity=0, int size=0) {
		this->capacity = capacity;
		this->size = size;
		data = new int[capacity];
	}
};

class Stack : public BaseArray {
public:
	//top
	int top;
	// 생성자. BaseArray(capacity,size)를 호출함
	Stack(int capacity = 0, int size = 0) : BaseArray(capacity,size) {
		//top은 -1로 초기화.
		this->top = -1;

	}
	//stack의 push연산. 
	void push(int a) {
		if (top == capacity - 1) {
			cout << "Stack is full"<<endl;
			return;
		}
		// top을 1증가시키고 원소를 넣는다. 
		data[++top] = a;
		size++;
	}

	// stack의 pop연산
	int pop() {
		if (top < 0) {
			// stack이 비어있으면 -1리턴
			cout << "Stack is empty" << endl;
			return-1;
		}
		// 현재 top위치에있는 원소 리턴
		int a = data[top];
		// top과 size는 1씩 감소.
		top--;
		size--;
		return a;
	}
	// 출력 함수.
	void show() {
		cout << "Stack(top to bottom): ";
		for (int i = top; i >=0; i--) {
			cout << data[i] << " ";
		}
		cout << endl;
		
	}

};

//Queue클래스 생성
class Queue : public BaseArray {
public:
	// front와 rear선언.
	int front;
	int rear;
	// front와 rear은 -1로 초기화, BaseArray호출
	Queue(int capacity = 0, int size = 0) :BaseArray(capacity, size) {
		front = -1;
		rear = -1;
	}
	// enqueue연산 구현. 
	void enqueue(int a) {
		if (rear >= capacity-1) {
			cout << "Cannot enqueue" << endl;
			return;
		}
		//rear만 1증가 후 원소삽입
		data[++rear] = a;
		//size 1증가.
		size++;
	}

	// dequeue연산 구현
	int dequeue() {
		if (front == rear) {
			cout << "queue is empty" << endl;
			return -1;
		}
		//front만 증가
		int a = data[++front];
		// size는 1감소.
		size--;
		return a;
	}
	// 출력 함수. 
	void show() {
		cout << "Queue(front to back): ";
		for (int i = front+1; i <= rear; i++) {
			cout << data[i] << " ";
		}
		cout << endl;
	}
};

int main() {
	//Stack s선언->capacity:5, size:0
	Stack s(5);
	s.push(10);
	s.push(20);
	s.push(30);
	s.show();
	// Queue q선언->Capacity:5, size:0
	Queue q(5);
	q.enqueue(1);
	q.enqueue(2);
	q.enqueue(3);
	q.show();
	s.pop();
	s.show();

	q.dequeue();
	q.show();

	return 0;
}