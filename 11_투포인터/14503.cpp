#include <iostream>
#include <vector>

using namespace std;

// 청소한 칸을 나타내는 상수
const int CLEAN = 2;
// 청소한 칸 개수
int cnt = 0;

//4가지 방향: { 북, 동, 남, 서 }
int dx[4] = { 0, 1, 0, -1 };
int dy[4] = { -1, 0, 1, 0 };

// 로봇 청소기 작동 횟수
int clean(int n, int m, int r, int c, int d, vector<vector<int>>& board) {
    // 청소한 칸의 개수는 0으로 초기화
    int cnt = 0;

    while (true) {
        //1. 현재 칸이 아직 청소되지 않은 경우, 현재 칸을 청소한다.
        if (board[r][c] != CLEAN) {
            // 청소한 칸의 개수를 1 증가
            cnt++;
            // 현재 칸을 청소 완료 상태로 바꾸기
            board[r][c] = CLEAN;
        }

        // 현재 칸의 주변 4칸 중 청소되지 않은 빈 칸의 존재 여부를 find에 저장
        bool find = false;
        // 3-1. 반시계 방향으로 90도 회전 시도
        for (int i = 0; i < 4; i++) {
            // 현재 방향에서 반시계 방향으로 90도 회전한 방향 계산
            int nd = (d - i + 3) % 4;
            // 회전한 방향으로 한 칸 전진한 좌표 계산
            int nr = r + dy[nd], nc = c + dx[nd];

            // 3-2. 아직 청소되지 않은 빈 칸 발견
            if (board[nr][nc] == 0) {
                // find를 true로 설정
                find = true;
                // 로봇의 위치와 방향 업데이트
                r = nr; c = nc; d = nd;
                // 반시계 방향으로 도는 것을 멈추고 청소 계속
                break;
            }
        }
        if (find) { //3. 현재 칸의 주변 4칸 중 청소되지 않은 빈 칸이 있는 경우
            // 1번으로 돌아감
            continue;
        }

        //2. 현재 칸의 주변 4칸 중 청소되지 않은 빈 칸이 없는 경우
        // 현재 방향에서 반대 방향으로 회전하여 뒤쪽 방향을 얻음
        int bd = (d + 2) % 4;
        // 뒤쪽 방향으로 한 칸 후진한 좌표 계산
        int br = r + dy[bd], bc = c + dx[bd];

        //[바라보는 방향을 유지한 채로 한 칸 후진할 수 있는가]
        //2-2. 뒤쪽 칸이 벽이라 후진할 수 없는 경우
        if (board[br][bc] == 1) {
            // 청소를 종료하고 청소한 칸의 개수 리턴
            return cnt;
        }
        //2-1. 바라보는 방향을 유지한 채로 한 칸 후진
        r = br; c = bc;
    }
    // 청소를 종료하고 청소한 칸의 개수 리턴
    return cnt;
}

/*
[로봇 청소기 작동]
1. 현재 칸이 아직 청소되지 않은 경우, 현재 칸을 청소한다.
2. 현재 칸의 주변 4칸 중 청소되지 않은 빈 칸이 없는 경우,
    2-1. 바라보는 방향을 유지한 채로 한 칸 후진할 수 있다면 한 칸 후진하고 1번으로 돌아간다.
    2-2. 바라보는 방향의 뒤쪽 칸이 벽이라 후진할 수 없다면 작동을 멈춘다.
3. 현재 칸의 주변 4칸 중 청소되지 않은 빈 칸이 있는 경우,
    3-1. 반시계 방향으로 90º 회전한다.
    3-2. 바라보는 방향을 기준으로 앞쪽 칸이 청소되지 않은 빈 칸인 경우 한 칸 전진한다.
    3-3. 1번으로 돌아간다.
*/

int main() {
    //코드를 더 빨리 수행할 수 있게
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    //입력
    int n, m, r, c, d;
    // 방 크기 n x m을 입력받음
    cin >> n >> m;
    // 처음 로봇 청소기의 좌표 (r,c)와 처음 로봇 청소기가 바라보는 방향 d 입력받음
    cin >> r >> c >> d;

    // n x m 사이즈의 2차원 벡터 board
    vector<vector<int>> board(n, vector<int>(m, 0));
    // 2차원 배열로 입력받은 숫자를 board에 저장
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> board[i][j];
        }
    }

    //연산 & 출력
    cout << clean(n, m, r, c, d, board);

    return 0;
}