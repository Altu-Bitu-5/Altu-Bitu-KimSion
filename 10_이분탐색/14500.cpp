#include<iostream>
#include<vector>
#include <algorithm>

using namespace std;

// 종이에 쓰여있는 수를 저장할 2차원 정수형 벡터 board
vector<vector<int>>board;
// 최댓값을 저장할 정수형 변수 ans
int ans;

// dfs 탐색 함수 - dfs 탐색으로 4개의 칸을 선택하고 합이 최대가 되는 경우의 ans 값으로 업데이트
void dfs(int x, int y, int depth, int sum) {
    // 이동 방향을 나타내는 배열 - 좌우상하로 한 칸씩 이동 가능
	vector<int> dx = { -1,0,1,0 };
	vector<int> dy = { 0,1,0,-1 };

    // 칸을 4개 선택했으면
	if (depth == 4) {
        // 기존 ans 값과 sum 중 더 큰 값으로 ans 값 업데이트
		ans = max(ans, sum);
		return;
	}

	// 아래 코드가 들어가면 가지치기가 돼 백트래킹이 돼요!
	//if (ans >= MAX * (4 - cnt) + sum) {
	//	return;
	//}

    // 상하좌우 4가지 방향에 대해 탐색
	for (int i = 0; i < 4; i++) {
		// 선택할 칸의 x좌표 = 현재 x좌표 + x방향으로 이동 여부(1 or 0)
		int nx = x + dx[i];
        // 선택할 칸의 y좌표 = 현재 y좌표 + y방향으로 이동 여부(1 or 0)
		int ny = y + dy[i];

        // 현재 선택한 칸의 좌표 (nx, ny)가 board 안 유효한 범위 안에 있거나 아직 방문하지 않은 좌표라면
		if (nx < 0 || nx >= board.size() || ny < 0 || ny >= board[0].size() || !board[nx][ny]) {
            // 패스
			continue;
		}

        // 선택한 칸의 숫자를 임시로 temp에 저장
		int temp = board[nx][ny];
        // 선택한 칸의 숫자를 0으로 설정
		board[nx][ny] = 0;

		// 다음 탐색 -> depth 1 증가 && sum값에 현재 칸의 숫자를 더해 dfs 함수 재귀 호출
		if (depth == 2) { // ㅜ 모양은 현재 위치에서 다시 탐색!
			dfs(x, y, depth + 1, sum + temp);
		}
        // 나머지 블록은 선택한 위치에서 다시 탐색
		dfs(nx, ny, depth + 1, sum + temp);
        // 재방문할 수 있도록 원래 값으로 되돌림
		board[nx][ny] = temp;
	}
}

/*
* HINT : 하나의 도형은 무언가 특별한 것 같아요! or 테트로미노의 모양은 탐색의 관점에서 특징이 있는 것 같아요!
* 1. ㅜ 모양을 제외한 테트로미노의 모양은 깊이가 4인 dfs의 탐색 모양
*     -> dfs로 블록을 하나씩 선택해가면서 개수(cnt)와 합(sum)을 계산
*     -> 4개 선택하면 최댓값 갱신
* 2. 예외 : ㅜ 모양은 블록을 2개 선택했을 때 현재 블록에서 다시 블록을 선택해준다.
*/


int main() {

	// 종이의 세로 크기 n과 가로 크기 m 입력받음
	int n, m;
	cin >> n >> m;
    // 2차원 벡터 board의 크기를 n X m으로 설정하고 0으로 초기화
	board.assign(n, vector<int>(m, 0));

    // 입력받은 수를 2차원 벡터 board에 저장
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> board[i][j];
		}
	}

	// 모든 칸의 숫자에 대해 반복
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
            // temp에 (i, j) 위치의 숫자 값 저장
			int temp = board[i][j];
            // (i, j) 위치의 값은 0으로 설정
			board[i][j] = 0;
            // (i, j) 좌표를 전달하고 depth를 1로 해서 dfs 함수 호출
			dfs(i, j, 1, temp);
            // (i, j) 위치의 값을 다시 원래 숫자 값으로 되돌림
			board[i][j] = temp;
		}
	}

	// 최댓값 출력
	cout << ans;
	return 0;
}