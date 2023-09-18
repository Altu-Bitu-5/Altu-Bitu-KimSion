#include <iostream>
#include <string>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int m;
    cin >> m;

    // int의 32비트 중 20개 비트를 사용하여 집합을 표현
    int bitset = 0;

    while (m--) {
        // 계산 명령어 입력받음
        string operation;
        cin >> operation;

        if (operation == "add") {
            int x;
            cin >> x;
            // x를 집합에 추가 - x를 0부터 시작하는 인덱스로 변환하여 해당 비트를 1로 설정
            bitset |= (1 << (x - 1)); // x-1 비트를 왼쪽으로 shift하고 bitset에 합침
        }
        else if (operation == "remove") {
            int x;
            cin >> x;
            // x를 집합에서 제거 -  x를 0부터 시작하는 인덱스로 변환하여 해당 비트를 0으로 설정
            bitset &= ~(1 << (x - 1)); // x-1 비트를 왼쪽으로 shift하고 반전시키면 x번째 비트만 1이 된다. and 연산자로 원래 x번째 비트가 원래 1이었다면 0이 되고 0이었다면 그대로
        }
        else if (operation == "check") {
            int x;
            cin >> x;
            // x가 집합에 있는지 확인 - x를 0부터 시작하는 인덱스로 변환하여 해당 비트 값을 확인
            int result = (bitset >> (x - 1)) & 1; // bitset을 x-1만큼 오른쪽으로 shift하고 가장 오른쪽 비트 1과 and 연산을 통해 result에는 bitset의 가장 오른쪽 비트 값이 저장됨
            cout << result << '\n';
        }
        else if (operation == "toggle") {
            int x;
            cin >> x;
            // x가 집합에 있으면 제거, 없으면 추가 - x를 0부터 시작하는 인덱스로 변환하여 해당 비트를 토글
            bitset ^= (1 << (x - 1)); // 1을 왼쪽으로 x-1만큼 shift하고 bitset과 xor 연산을 통해 그 결과를 bitset에 넣음
        }
        else if (operation == "all") {
            // 모든 원소를 추가
            bitset = (1 << 20) - 1; // 20개 비트를 1로 설정
        }
        else if (operation == "empty") {
            // 집합 비우기
            bitset = 0; // 모든 비트를 0으로 설정
        }
    }

    return 0;
}