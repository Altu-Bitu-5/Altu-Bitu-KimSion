// 2615번 오목: https://www.acmicpc.net/problem/2615
#include <iostream>
#include <vector>

using namespace std;

// 2차원 정수혀 벡터 타입을 matrix로 정의
typedef vector<vector<int>> matrix;
// 바둑판 크기와 빈칸 상태 정의
const int SIZE = 20, EMPTY = 0;

// 방향에 따른 좌표 증가량
// 맨 왼쪽 위 돌을 기준으로 검사하기 때문에 오른쪽+아래쪽으로 향하는 방향만 정의 (-1,1), (0,1), (1,1), (1,0)
const vector<int> dx = {-1, 0, 1, 1};
const vector<int> dy = {1, 1, 1, 0};

// 2차원 벡터 board, 좌표 x, y와 color 값(흰색or검은색)을 받아
bool isValid(matrix &board, int x, int y, int color) {
    // 좌표 범위가 바둑판 안에 있는지, 해당 좌표의 돌 색깔이 입력받은 color와 일치하는지 검사해 true/false 리턴
    return (x > 0 && x < SIZE && y > 0 && y < SIZE && board[x][y] == color);
}

//해당 좌표(x, y)부터 연속적으로 5알이 놓이는지 확인
bool checkWin(matrix &board, int x, int y) {
    // color 값에 (x, y)의 돌 색을 저장
    int color = board[x][y];

    // 4 방향에 대해 검사
    for (int idx = 0; idx < 4; idx++) {
        // 같은 방향에 놓인 같은 색 돌의 개수를 cnt에 저장 - 현재 돌도 개수에 포함해야 하므로 1로 초기화
        int cnt = 1;
        // 같은 방향에서 이전 좌표 (prev_x, prev_y)
        int prev_x = x - dx[idx], prev_y = y - dy[idx];
        // 같은 방향에서 다음 좌표 (next_x, next_y)
        int next_x = x + dx[idx], next_y = y + dy[idx];

        // 같은 방향에서 그 이전에도 같은 색 돌이 있었다면 패스 (-> 여섯 알 이상 놓이는 경우를 제외하기 위함)
        if (isValid(board, prev_x, prev_y, color)) {
            continue;
        }

        // 연속적으로 놓인 5알이 같은 색인지 확인
        while (isValid(board, next_x, next_y, color) && cnt < 6) {
            // 다음 좌표가 유효한 범위에 있고 색이 일치하며 6알 미만이라면 next_x와 next_y를 각각 같은 방향에서 다음 좌표로 업데이트
            next_x += dx[idx];
            next_y += dy[idx];
            // 같은 방향에 같은 색의 돌의 개수를 +1하고 반복
            cnt++;
        }
        // cnt가 5일 때만 true 리턴 (-> 다섯 알보다 적거나 다섯 알보다 많이 놓이는 경우를 제외)
        if (cnt == 5) {
            return true;            
        }
    }
    // 4 방향에 대해 모두 검사했을 때 true를 리턴하지 않는다면 오목의 조건에 맞지 않는 경우이므로 false 리턴
    return false;
}

int main() {
    // SIZE X SIZE 크기의 2차원 벡터 board 정의
    matrix board(SIZE, vector<int>(SIZE, 0));
    // i, j를 SIZE까지 증가시키며 반복문 실행
    for (int i = 1; i < SIZE; i++) {
        for (int j = 1; j < SIZE; j++) {
            // 입력받은 숫자를 board의 (i,j) 위치에 저장
            cin >> board[i][j];
        }
    }

    // x, y를 SIZE까지 증가시키며 반복문 실행
    for (int y = 1; y < SIZE; y++) {
        for (int x = 1; x < SIZE; x++) {
            // 해당 좌표(x, y)가 빈 칸이면 패스
            if (board[x][y] == EMPTY) {
                continue;
            }
            // 해당 좌표(x, y)부터 연속적으로 5알이 놓인 경우 (checkWin 함수에서 true가 리턴된 경우)
            if (checkWin(board, x, y)) {
                // 해당 좌표의 색을 먼저 출력하고 다음 줄에 맨 왼쪽 상단에 있는 돌의 좌표를 출력
                cout << board[x][y] << '\n'
                     << x << ' ' << y;
                return 0;
            }
        }
    }
    // 바둑판 위의 모든 좌표에 대해 반복문을 실행했을 때 checkWin에서 true가 출력되지 않았다면 오목이 없는 상황이므로 0을 출력
    cout << 0;
}