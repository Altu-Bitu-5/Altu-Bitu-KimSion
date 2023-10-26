#include <iostream>
#include <vector>

using namespace std;

// int형 durability와 bool형 is_robot이 컨베이어 벨트 위의 각 칸에 할당된다
struct Belt {
    int durability;
    bool is_robot;
};

int main() {
    // N, K 입력받음
    int N, K;
    cin >> N >> K;

    // 컨베이어 벨트의 durability, is_robot 정보를 담고 있는 벡터 conveyor의 크기를 2N으로 초기화
    vector<Belt> conveyor(2 * N);

    // 컨베이어 벨트 위 모든 칸의 durability를 입력받고 is_robot은 false로 초기화
    for (int i = 0; i < 2 * N; ++i) {
        cin >> conveyor[i].durability;
        conveyor[i].is_robot = false;
    }

    // step 1부터 시작하고 그 step에서 durability 값이 0인 칸의 개수를 zero_count에 저장
    int step = 1;
    int zero_count = 0;

    while (true) {
        // 1. 벨트 회전
        // 한 칸씩 회전한 컨베이어 벨트 정보는 new_conveyor에 저장
        vector<Belt> new_conveyor(2 * N);
        for (int i = 1; i < 2 * N; i++) {
            new_conveyor[i] = conveyor[i - 1];
        }
        // new_conveyor의 첫 번째 원소는 conveyor의 마지막 원소가 된다
        new_conveyor[0] = conveyor.back();
        // conveyor에 new_conveyor를 복사
        conveyor = new_conveyor;
        // 내리는 위치(N-1)에 로봇이 있다면 로봇이 내린다
        if (conveyor[N - 1].is_robot) {
            conveyor[N - 1].is_robot = false;
        }

        // 2. 로봇 이동
        // 인덱스 N-2부터 0까지 1씩 감소시키며 각 칸에 대해 체크
        for (int i = N - 2; i >= 0; i--) {
            // 해당 칸에 로봇이 있고 다음 칸에는 로봇이 없으며 다음 칸의 durability가 0보다 클 때
            if (conveyor[i].is_robot && !conveyor[i + 1].is_robot && conveyor[i + 1].durability > 0) {
                // 로봇이 이동하여 다음 칸의 is_robot은 true, 해당 칸의 is_robot은 false가 된다
                conveyor[i + 1].is_robot = true;
                conveyor[i].is_robot = false;
                // 다음 칸의 durability는 1 감소
                conveyor[i + 1].durability--;
            }
        }
        // 내리는 위치(N-1)에 로봇이 있다면 로봇이 내린다
        if (conveyor[N - 1].is_robot) {
            conveyor[N - 1].is_robot = false;
        }

        // 3. 로봇 올리기
        // 올리는 위치(0)에 로봇이 없고 해당 칸의 durability가 0보다 크다면 로봇을 올리고 durability는 1 감소
        if (!conveyor[0].is_robot && conveyor[0].durability > 0) {
            conveyor[0].is_robot = true;
            conveyor[0].durability--;
        }

        // step이 끝날 때마다 컨베이어 벨트에서 durability가 0인 칸의 수를 세야 하므로 0으로 초기화
        zero_count = 0;
        // 컨베이어 벨트 위 durability가 0인 칸의 수를 zero_count에 저장
        for (const Belt& belt : conveyor) {
            if (belt.durability == 0) {
                zero_count++;
            }
        }

        // zero_count가 K 이상이면 반복문 탈출
        if (zero_count >= K) {
            break;
        }

        // 한 번의 step이 종료될 때마다 step 값은 1 증가
        step++;
    }

    // 종료된 step 출력
    cout << step << endl;

    return 0;
}