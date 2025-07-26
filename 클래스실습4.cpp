#include<iostream> //입/출력을 위해 선언
#include<string> // string 클래스를 이용하기 위해 선언. 

using namespace std;

// Dictionary 클래스를 선언. 
class Dictionary {
    //private 영역에 해당 사전에 존재하는 단어들을 선언해줬다. 
private:
    string words[100] = {
         "apple", "banana", "cherry", "date", "elderberry", "fig", "grape", "honeydew", "kiwi", "lemon",
         "mango", "nectarine", "orange", "papaya", "quince", "raspberry", "strawberry", "tangerine", "ugli", "vanilla",
         "watermelon", "xigua", "yellowfruit", "zucchini", "almond", "blackberry", "coconut", "dragonfruit", "eggplant", "figtree",
         "grapefruit", "hibiscus", "indigo", "jackfruit", "kumquat", "lime", "mulberry", "nutmeg", "olive", "peach",
         "plum", "rhubarb", "soursop", "tomato", "uva", "walnut", "yam", "zebrafruit", "apricot", "blueberry",
         "cranberry", "damson", "eucalyptus", "fennel", "gooseberry", "huckleberry", "iceberg", "jambul", "kiwifruit", "loquat",
         "mandarin", "nectar", "olivefruit", "persimmon", "quinoa", "rosehip", "saffron", "tamarind", "ugandanfruit", "vanillabean",
         "wolfberry", "xanthium", "yumberry", "zostera", "acorn", "barberry", "caper", "dill", "echinacea", "fennelseed",
         "ginkgo", "hawthorn", "ilama", "jalapeno", "kale", "lychee", "macadamia", "nut", "onion", "pumpkin",
         "radish", "spinach", "turnip", "ugliapple", "valenciaorange", "watercress", "yuzu", "ziziphus", "amaranth", "basil"
    };
public:
    // 단어를 검색해주는 search()함수의 선언부. 
    void search();
};

//단어를 검색해주는 serach()함수의 구현부.
void Dictionary::search() {
    // 찾고자 하는 단어를 string변수 a로 선언.
    string a;
    while (1) {
        // 사용자로부터 단어를 입력받는다.  
        cout << "찾으려는 단어를 입력해 주세요: ";
        cin >> a;
        // 만약 0을 입력하면 해당 반복문을 종료한다. 
        if (a=="0") {
            cout << "사전을 종료합니다.";
            break; // 반복문 밖으로 빠져나간다. 
        }
        else {
            bool n = 0;// 단어가 없는 경우를 처리하기 위해 선언. bool형이고 0으로 초기화.  
            // for반복문. i는 0부터 (해당 배열의 크기 - 1)까지 1씩 증가한다. 
            for (int i = 0; i < sizeof(words)/sizeof(words[0]); i++) {
                // 단어를 찾은 경우. 
                if (a == words[i]) { 
                    cout << a << "는 " << i << "번째에 있습니다." << endl;
                    n = 1;
                    break; // 반복중이던 for문 종료. 
                }
            }
            // 단어를 찾는 for반복문이 처음부터 끝까지 실행됐음에도, 입력한 단어를 찾지 못한 경우. 
            if (n == 0) {
                cout << a <<"는 사전에 없습니다." << endl;

            }
        }

    }
}
// main함수.
int main() {
    // Dictionary 클래스 a를 선언. 
    Dictionary a;
    // 단어를 찾는 함수가 실행됨. 
    a.search();

    return 0;
}