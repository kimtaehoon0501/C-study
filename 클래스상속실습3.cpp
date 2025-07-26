#include <iostream>
#include <string>

using namespace std;

// 부모클래스. 
class Shape {
public:
    Shape* next = nullptr;
    // 가상함수로 선언.
    virtual void draw() = 0;
    virtual ~Shape() {}
};

// Shape를 상속받은 Line클래스. 
class Line : public Shape {
public:
    // draw()를 오버라이딩하여 구현.
    void draw() {
        cout << "Line" << endl;
    }
};

// Shape클래스를 상속받은 Circle클래스 
class Circle : public Shape {
public:
    // draw()를 오버라이딩하여 구현. 
    void draw(){
        cout << "Circle" << endl;
    }
};
// Shape클래스를 상속받은 Rect클래스
class Rect : public Shape {
public:
    // draw()를 오버라이딩하여 구현. 
    void draw(){
        cout << "Rectangle" << endl;
    }
};

// UI클래스에서 해당 클래스형을 사용한다. 
class GraphicEditor; 

// UI클래스 작성. 
class UI {
public:
    // 그래픽에디터 시작. 
    static void start(GraphicEditor* g);
    // 메뉴 보여주는 함수.
    static int showMenu();
    // 도형을 보여주는 함수.
    static int showShapeType();
    // 삭제할 시, 도형을 보여주는 함수.
    static int deleteShapeType();
};

// 그래픽에디터 클래스.
class GraphicEditor {
private:
    // 시작 도형 pointer.
    Shape* pStart = nullptr;
    // 끝나는 도형 pointer.
    Shape* pLast = nullptr;
    // 도형의 개수. 
    int numShapes = 0;

public:
    // 도형을 추가하는 함수. 
    void insertShape() {
        // 추가할 도형의 타입 입력받음.
        int type = UI::showShapeType();

        // s->새로 추가할 도형(맨 마지막에 추가)
        Shape* s = nullptr;
        if (type == 1) s = new Line();
        else if (type == 2) s = new Circle();
        else if (type == 3) s = new Rect();
        else return;

        s->next = nullptr;

        // 도형이 한개도 없는 상황일 경우.
        if (pStart == nullptr) {
            pStart = pLast = s;
        }
        else {
            // 마지막에 도형 추가. 
            pLast->next = s;
            pLast = s;
        }

        numShapes++;
    }
    // 도형을 삭제하는 함수. 
    void deleteShape() {
        int index = UI::deleteShapeType();
        if (index < 0 || index >= numShapes) {
            cout << "삭제할 수 없습니다." << endl;
            return;
        }
        // prev는 p 이전의 도형을 의미한다. 
        Shape* p = pStart;
        Shape* prev = nullptr;

        // index만큼 도형을 이동시킨다. 
        for (int i = 0; i < index; i++) {
            prev = p;
            p = p->next;
        }

        if (prev == nullptr) {
            // 첫 번째 도형 삭제한다. 
            pStart = p->next;
            if (pStart == nullptr) pLast = nullptr;
        }
        else {
            // 삭제할 도형 이전의 도형의 next를 삭제할 도형의 next주소로 이어준다.
            prev->next = p->next;
            if (prev->next == nullptr) pLast = prev;
        }
        // p를 할당해제 후 도형의 개수 1감소. 
        delete p;
        numShapes--;
    }
    // 존재하는 모든 도형을 출력하는 함수이다. 
    void viewAll() {
        Shape* s = pStart;
        int i = 0;
        while (s != nullptr) {
            cout << i << ": ";
            s->draw();
            s = s->next;
            i++;
        }
    }
};

// UI 함수 정의 

// 메뉴를 보여주는 함수. 정수를 입력받아 리턴한다. 
int UI::showMenu() {
    int a;
    cout << "삽입:1, 삭제:2, 모두보기:3, 종료:4 >> ";
    cin >> a;
    return a;
}
// 도형의 타입을 보여주는 함수. 정수를 입력받아 리턴.
int UI::showShapeType() {
    int a;
    cout << "선:1, 원:2, 사각형:3 >> ";
    cin >> a;
    return a;
}
// 삭제할 도형의 타입을 선택하는 함수이다. 
int UI::deleteShapeType() {
    int a;
    cout << "삭제를 원하는 도형의 인덱스 >> ";
    cin >> a;
    return a;
}
//매개변수로 GraphicEditor*g를 받는다. 
void UI::start(GraphicEditor* g) {
    cout << "그래픽 에디터입니다." << endl;
    while (1) {
        int c = showMenu();
        //입력받은 c에따라 다른 기능을 수행
        switch (c) {
        case 1:
            g->insertShape();
            break;
        case 2:
            g->deleteShape();
            break;
        case 3:
            g->viewAll();
            break;
        case 4:
            return;
        default:
            cout << "잘못된 입력입니다." << endl;
        }
    }
}

int main() {
    GraphicEditor *editor = new GraphicEditor();
    UI::start(editor);
    return 0;
}
