#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    // N, M, B 입력받음
    int N, M, B;
    cin >> N >> M >> B;

    // 땅의 높이 배열을 저장할 벡터
    vector<vector<int>> land(N, vector<int>(M));

    // 땅의 높이 정보를 저장
    int maxHeight = 0;
    int minHeight = 256;
    long long totalTime = 0;
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            cin >> land[i][j];
            maxHeight = max(maxHeight, land[i][j]);
            minHeight = min(minHeight, land[i][j]);
        }
    }

    int resultTime = 1e9; // 초기값으로 큰 값 설정
    int resultHeight = 0;

    // 높이를 0부터 최대 높이까지 모두 시도
    for (int h = 0; h <= 256; ++h) {
        long long time = 0;
        long long blocks = B;

        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < M; ++j) {
                // 현재 높이와 목표 높이의 차이
                int diff = land[i][j] - h;
                if (diff > 0) {
                    // 현재 블록을 제거하고 인벤토리에 추가
                    time += diff*2;
                    blocks += diff;
                }
                else {
                    // 목표 높이에 도달하려면 블록을 추가
                    time += (-diff);
                    blocks -= (-diff);
                }
            }
        }

        // 모든 블록을 사용할 수 있을 때
        if (blocks >= 0) {
            // 더 적은 시간이 걸리는 경우 업데이트
            if (time <= resultTime) {
                resultTime = time;
                resultHeight = h;
            }
        }
    }

    cout << resultTime << " " << resultHeight << '\n';

    return 0;
}
