#include <iostream>
#include <string>

using namespace std;

int main() {
    int n;
    cin >> n;

    // 첫 번째 종말의 수는 666으로 초기화
    int end_num = 666;
    // 몇 번째 종말의 수인지 카운트
    int count = 0;
    
    while (true) {
        // 종말의 수에서 666이라는 문자열을 발견하지 못했을 때 npos를 리턴
        // 문자열 666을 발견한 경우에는 count를 1증가
        if (to_string(end_num).find("666") != string::npos) {
            count++;
        }
        // n번째 종말의 수를 찾으면 출력하고 종료
        if (count == n) {
            cout << end_num << endl;
            break;
        }
        // 다음 숫자 검사
        end_num++;
    }
    return 0;
}
