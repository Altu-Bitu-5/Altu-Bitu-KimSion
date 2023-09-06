#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
    // 바퀴의 칸의 수 N과 바퀴를 돌리는 횟수 K 입력
    int N, K;
    cin >> N >> K;

    // 모르는 칸의 문자는 ?로 초기화
    vector<char> wheel(N, '?');

    int changes = 0;
    int current = 0;

    while (K--) {
        // 화살표가 가리키는 글자가 몇 번 바뀌었는지를 나타내는 S와 회전을 멈췄을 때 가리키는 글자 input_char 입력
        int S;
        char input_char;
        cin >> S >> input_char;

        // 바퀴를 회전하며 화살표가 가리키는 글자 변경 횟수를 더한다
        changes += S;

        // 원형이므로 바퀴의 칸 수로 나눴을 때 나머지가 현재 칸의 인덱스가 된다
        current = (current + S) % N;

        // 이미 글자가 적혀 있고, 입력받은 글자와 다를 경우, '!' 출력 후 종료
        if (wheel[current] != '?' && wheel[current] != input_char) {
            cout << "!";
            return 0;
        }
        // 다른 칸에 해당 문자가 이미 있는 경우에도 '!' 출력 후 종료
        for (int i = 0; i < N; i++) {
            if (wheel[i] == input_char) {
                cout << "!";
                return 0;
            }
        }

        // 아니라면 현재 칸에 글자를 업데이트
        wheel[current] = input_char;
    }

    // 시계 방향으로 바퀴에 적힌 글자 출력
    for (int i = 0; i < N; ++i) {
        // 음수가 되지 않게 현재 위치에 N을 더하고 시계 방향이므로 현재 위치에서 1씩 뺀다. 원형이므로 바퀴의 칸 수로 나눴을 때 나머지가 인덱스가 된다
        int index = (current + N - i) % N;
        cout << wheel[index];
    }

    return 0;
}
