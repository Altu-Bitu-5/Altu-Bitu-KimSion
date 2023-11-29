#include <iostream>
#include <vector>

using namespace std;

const int MAX = 101;

// 상하좌우 이동 방향
int dx[] = { 1, 0, -1, 0 };
int dy[] = { 0, -1, 0, 1 };

int grid[MAX][MAX];

int main() {
    // 드래곤 커브의 개수 N 입력
    int N;
    cin >> N;

    while (N--) {
        // 드래곤 커브의 시작점(x, y), 시작 방향 d, 세대 g 입력
        int x, y, d, g;
        cin >> x >> y >> d >> g;

        // 벡터 directions에 방향 d값 저장
        vector<int> directions;
        directions.push_back(d);

        // 드래곤 커브의 방향을 미리 계산
        for (int i = 0; i < g; i++) {
            int size = directions.size();
            for (int j = size - 1; j >= 0; j--) {
                // 현재 방향에서 1을 더한 값(다음 세대의 방향)을 directions에 저장 - 4로 나눈 나머지로 0, 1, 2, 3 반복
                directions.push_back((directions[j] + 1) % 4);
            }
        }

        // (x, y) 점이 드래곤 커브의 일부라면 grid[y][x]값에 1 저장
        // 드래곤 커브 시작 지점
        grid[y][x] = 1;

        // 드래곤 커브 그리기
        for (int dir : directions) {
            x += dx[dir];
            y += dy[dir];
            grid[y][x] = 1;
        }
    }

    // 정사각형의 꼭짓점이 모두 드래곤 커브의 일부인지 확인
    int squares = 0;
    for (int i = 0; i < MAX - 1; i++) {
        for (int j = 0; j < MAX - 1; j++) {
            // 정사각형의 좌측 상단, 좌측 하단, 우측 상단, 우측 하단 꼭짓점의 값이 모두 1이라면
            if (grid[i][j] && grid[i + 1][j] && grid[i][j + 1] && grid[i + 1][j + 1]) {
                // 드래곤 커브에 포함된 정사각형의 개수 1 증가
                squares++;
            }
        }
    }

    cout << squares << '\n';

    return 0;
}