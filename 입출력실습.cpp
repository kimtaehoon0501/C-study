#include<iostream>
using namespace std;
/* 입 / 출력을 수행하기위해 iostream을 헤더에 포함시켰고, std 이름공간 키워드를 생략하기위해
using namespace std를 작성해줬다.
*/


int main() {
	int hour = 0;
	int min = 0;
	int lapse = 0;// h는 시, m은 분을 의미하는 변수를 생성한다. lapse는 경과(분)을 의미한다.
	cout << "현재 시각을 입력하세요 : ";
	cin >> hour >> min; //현재시각을 입력받음
	cout << "경과된 시간을 분으로 입력하세요 : ";
	cin >> lapse; //경과된 시간을 입력받음

	min = min + lapse; // 원래 시간의 분에 경과된 시간을 더해준다.
	while (min >= 60) {
		hour++;
		min = min - 60; 
		/*분이 60분을 넘어가면, 분에서 60을 빼주고, 시간을 1 더해준다.
		해당작업은 '분'이 60 이하가 될때까지 반복한다.*/
	}
	if (hour > 24) {
		hour = hour - 24;
	}// 시가 25를 넘어가면 24를 빼서 시의 범위를 0~24로 맞춰준다. 
	cout << hour << " " << min; // 시와 분을 나타내어준다. 공백으로 둘을 구분해준다. 

	return 0;

}