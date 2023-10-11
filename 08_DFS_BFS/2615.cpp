#include <iostream>
#include <vector>
#include <queue>

using namespace std;
// 정수를 저장할 2차원 벡터 타입을 vec_vec으로 정의
typedef vector<vector<int>> vec_vec;

// 이동 방향 (상, 하, 좌, 우, 대각선)
int dx[] = { -1, 1, 0, 0, -1, -1, 1, 1 };
int dy[] = { 0, 0, -1, 1, -1, 1, -1, 1 };

// start 지점의 좌표와 2차원 벡터 그래프, color(검은색 1, 흰색 2)를 입력받아 연속으로 배치된 돌의 개수를 리턴하는 함수
int bfs(pair<int, int> start, vec_vec& graph, int color) {
    int cnt = 1;
    int rows = graph.size();
    int cols = graph[0].size();
    // 해당 좌표에 있는 돌의 방문 여부를 저장하는 2차원 bool 벡터 visited 정의
    vector<vector<bool>> visited(rows, vector<bool>(cols, false));
    // q에는 정수 한 쌍(좌표)이 저장된다
    queue<pair<int, int>> q;

    // 시작 지점의 좌표를 큐에 저장하고 visited 벡터에서 true로 값을 변경
    q.push(start);
    visited[start.first][start.second] = true;

    while (!q.empty()) {
        // 큐의 front 위치에 있는 노드를 선택하고 큐에서 제거
        pair<int, int> node = q.front();
        q.pop();

        // 이동 방향으로 1씩 이동하고 좌표를 변경하며 체크
        for (int i = 0; i < 8; ++i) {
            int nx = node.first + dx[i];
            int ny = node.second + dy[i];

            // 바둑판 범위에서 벗어나지 않는지, 입력받은 돌의 색과 일치하는지, 방문한 적이 없는 좌표인지 체크
            if (nx >= 0 && nx < rows && ny >= 0 && ny < cols && graph[nx][ny] == color && !visited[nx][ny]) {
                // 큐에 해당 좌표를 push하고 visited 벡터에서 true로 값을 변경
                q.push({ nx, ny });
                visited[nx][ny] = true;
                // 연속된 돌의 개수 카운트
                cnt++;
            }
        }
    }
    return cnt;
}

int main() {
    // 바둑판의 크기
    const int rows = 19;
    const int cols = 19;

    // 2차원 벡터 grid에서 모든 값을 0으로 초기화
    vec_vec grid(rows, vector<int>(cols, 0));

    // 바둑판의 정보를 입력 받아서 2차원 벡터 grid에 저장
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cin >> grid[i][j];
        }
    }

    // grid에서 열과 행을 따라 반복
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            // start 변수에 해당 시작 지점의 좌표를 저장
            pair<int, int> start = { i, j };
            // 시작 지점의 값이 1 또는 2인 경우 (돌이 놓여있는 경우)
            if (grid[i][j] == 1 || grid[i][j] == 2) {
                // 그 칸에 놓여있는 돌의 색을 color에 저장
                int color = grid[i][j];
                // 연속된 같은 색 돌의 개수가 5 이상이면 그 돌의 색과 좌표를 출력
                if (bfs(start, grid, color) >= 5) {
                    cout << color << '\n';
                    cout << i + 1 << " " << j + 1;
                    return 0;
                }
            }
        }
    }

    // 1 또는 2가 5번 연속해서 있는 상황이 없는 경우
    cout << 0 << '\n';

    return 0;
}
