#include <iostream>
#include <vector>

using namespace std;

const int MAX = 50;

// 최대 50x50의 크기를 가지는 map과 각 지점의 방문 여부를 저장할 bool 배열 visited
int w, h;
int map[MAX][MAX];
bool visited[MAX][MAX];

// 이동 방향: 상, 하, 좌, 우, 대각선
int dx[] = { -1, 1, 0, 0, -1, -1, 1, 1 };
int dy[] = { 0, 0, -1, 1, -1, 1, -1, 1 };

// 입력받은 지점과 연결된 육지 하나가 끝날 때까지 재귀 호출하는 함수
void dfs(int x, int y) {
    // 입력받은 지점의 방문 여부를 true로 변경
    visited[x][y] = true;

    // 입력받은 지점과 이웃한 8개 지점에 대해 반복
    for (int i = 0; i < 8; ++i) {
        int nx = x + dx[i];
        int ny = y + dy[i];

        // 맵의 범위에서 벗어나지 않는지, 해당 지점이 육지(1)인지, 방문한 적이 없는 지점인지 체크
        if (nx >= 0 && nx < h && ny >= 0 && ny < w && map[nx][ny] == 1 && !visited[nx][ny]) {
            // 위의 조건에 모두 해당되는 경우, 그 지점과 이웃한 8개 지점에 대해 다시 dfs 함수를 호출
            dfs(nx, ny);
        }
    }
}

// dfs 함수를 호출해 육지의 개수를 세어 반환하는 함수
int countIslands() {
    int cnt = 0;
    // 맵의 크기에 따라 모든 지점에 대해 반복
    for (int i = 0; i < h; ++i) {
        for (int j = 0; j < w; ++j) {
            // 어떤 지점이 육지이고 방문한 적이 없다면 dfs 함수를 호출
            if (map[i][j] == 1 && !visited[i][j]) {
                // dfs 함수가 종료되었다는 것은 하나의 육지 조사가 끝났음을 의미하므로 육지의 개수를 1 더한다
                dfs(i, j);
                cnt++;
            }
        }
    }

    return cnt;
}

int main() {
    while (true) {
        // 맵의 너비 w와 높이 h 입력
        cin >> w >> h;

        // w와 h 값이 모두 0인 경우 반복문에서 빠져나와 프로그램 종료
        if (w == 0 && h == 0) {
            break;
        }

        // 입력받은 값으로 맵을 초기화 - 이때 모든 지점의 방문 여부는 false로 저장
        for (int i = 0; i < h; ++i) {
            for (int j = 0; j < w; ++j) {
                cin >> map[i][j];
                visited[i][j] = false;
            }
        }

        // 해당 맵에서 육지의 개수 출력
        int num_islands = countIslands();
        cout << num_islands << '\n';
    }

    return 0;
}
