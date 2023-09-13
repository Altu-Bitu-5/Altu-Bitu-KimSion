#include <iostream>
#include <bitset>
using namespace std;

int main() {

    int n;
    cin >> n;

    // 1부터 20까지의 숫자를 집합에서 관리하기 위해 21비트 사용
    bitset<21> S;

    // 연산 명령어와 숫자 x 정의
    string calculate;
    int x;

    while (n--) {
        cin >> calculate;

        if (calculate == "add") {
            cin >> x;
            S.set(x, true);  // x번 비트를 1로 설정
        }
        else if (calculate == "remove") {
            cin >> x;
            S.set(x, false);  // x번 비트를 0으로 설정
        }
        else if (calculate == "check") {
            cin >> x;
            cout << S.test(x) << endl;  // x번 비트가 설정되어 있는지 확인 - 있으면 1, 없으면 0 출력
        }
        else if (calculate == "toggle") {
            cin >> x;
            S.flip(x);  // x번 비트를 반전 - 1이면 0으로, 0이면 1로
        }
        else if (calculate == "all") {
            S.set();  // 모든 비트를 1로 설정
        }
        else if (calculate == "empty") {
            S.reset();  // 모든 비트를 0으로 설정
        }
    }

    return 0;
}
