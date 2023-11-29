#include <iostream>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;

const int MAX_N = 101;

// 뱀의 방향
const int UP = 0;
const int RIGHT = 1;
const int DOWN = 2;
const int LEFT = 3;

// 뱀의 움직임 (상, 하, 좌, 우)
const int dx[4] = { -1, 0, 1, 0 };
const int dy[4] = { 0, 1, 0, -1 };

// 뱀의 좌표와 방향을 저장하는 구조체
struct Snake {
    int x, y, dir;
};

// 보드의 크기 N, 사과의 개수 K, 뱀의 방향 변환 횟수 L 입력
int N, K, L;
// 2차원 배열 board의 값이 0이면 빈 칸, 1이면 사과, 2이면 뱀 몸통이 있다는 뜻
int board[MAX_N][MAX_N];
// 뱀의 방향 변환을 저장하는 큐 turns
queue<pair<int, char>> turns;

int simulate() {
    // 뱀의 몸통 정보를 저장하는 벡터 snake
    vector<Snake> snake;
    // 게임 경과 시간
    int time = 0;

    // 초기 상태: 뱀은 맨 위 맨 좌측에 위치하고 초기 방향은 오른쪽
    snake.push_back({ 1, 1, RIGHT });
    board[1][1] = 2;

    // 뱀의 방향 변환 정보 인덱스
    int idx = 0;

    while (true) {
        time++;

        // 뱀의 머리 이동
        int nx = snake[0].x + dx[snake[0].dir];
        int ny = snake[0].y + dy[snake[0].dir];

        // 벽 또는 자기 자신의 몸에 부딪힌 경우 게임을 종료하고 게임 경과 시간 출력
        if (nx < 1 || nx > N || ny < 1 || ny > N || board[nx][ny] == 2) {
            return time;
        }

        // 이동한 칸에 사과가 있는 경우
        if (board[nx][ny] == 1) {
            // 뱀 몸통 추가
            board[nx][ny] = 2;
            // 뱀 머리 갱신
            snake.insert(snake.begin(), { nx, ny, snake[0].dir });
        }
        // 이동한 칸에 사과가 없는 경우
        else {
            // 해당 칸에 뱀 몸통 추가
            board[nx][ny] = 2;
            // 뱀 머리 갱신
            snake.insert(snake.begin(), { nx, ny, snake[0].dir });
            // 꼬리 제거
            board[snake.back().x][snake.back().y] = 0;
            // 뱀 꼬리 갱신
            snake.pop_back();
        }

        // 방향 변환 시간에 도달하면 방향 변경
        if (!turns.empty() && turns.front().first == time) {
            // 'D' 오른쪽으로 90도 회전
            if (turns.front().second == 'D') {
                snake[0].dir = (snake[0].dir + 1) % 4;
            }
            // 'L' 왼쪽으로 90도 회전
            else {
                snake[0].dir = (snake[0].dir + 3) % 4;
            }
            // 방향 변환 정보 사용
            turns.pop();
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> K;

    // 사과 위치 입력 및 표시
    for (int i = 0; i < K; i++) {
        int x, y;
        cin >> x >> y;
        board[x][y] = 1;
    }

    cin >> L;

    // 뱀의 방향 변환 정보를 입력받아 큐 turns에 저장
    for (int i = 0; i < L; i++) {
        int X;
        char C;
        cin >> X >> C;
        turns.push({ X, C });
    }

    cout << simulate() << '\n';

    return 0;
}