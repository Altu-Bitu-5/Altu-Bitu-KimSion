#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

long long calculateMinVel(vector<long long> velocity) {
    // 역순으로 탐색을 시작하는 지점
    auto i = velocity.rbegin();
    // 현재 값을 min_vel로 복사하고 반복자 i를 다음 원소로 이동
    long long min_vel = *(i++);

    // 벡터를 역순으로 탐색
    while (i != velocity.rend()) {
        long long current_vel = *(i++);
        // 최소 시작 속도가 현재 속도보다 크면
        if (min_vel > current_vel) {
            // 최소 시작 속도가 현재 속도의 배수이면 처음 반복문으로 돌아간다
            if (min_vel % current_vel == 0)
                continue;
            // 최소 시작 속도 = 현재 속도 * ((최소 시작 속도 / 현재 속도) + 1)로 업데이트
            min_vel = current_vel * ((min_vel / current_vel) + 1);
        }
        // 최소 시작 속도가 현재 속도보다 작거나 같으면 최소 시작 속도를 현재 속도로 업데이트
        else if (min_vel <= current_vel)
            min_vel = current_vel;
    }
    return min_vel;
}

int main() {
    // 행성의 개수 n 입력
    int n;
    cin >> n;

    long long vel;
    // 숫자 입력받아 velocity 벡터에 저장
    vector<long long> velocity;
    for (int i = 0; i < n; i++) {
        cin >> vel;
        velocity.push_back(vel);
    }

    // 지구에서 올려야 하는 속도의 최솟값 출력
    long long min_vel = calculateMinVel(velocity);
    cout << min_vel;

    return 0;
}
