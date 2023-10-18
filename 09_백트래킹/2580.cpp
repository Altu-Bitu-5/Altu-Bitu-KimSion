#include <iostream>
using namespace std;

// 9x9 사이즈의 스도쿠 판
const int SIZE = 9;

// 유효한 숫자인지 확인하는 함수
bool isValid(int board[SIZE][SIZE], int row, int col, int num) {
    // 행과 열에 중복된 숫자가 있는지 확인
    for (int i = 0; i < SIZE; i++) {
        if (board[row][i] == num || board[i][col] == num) {
            return false;
        }
    }

    // init_row와 init_col은 3x3 그리드에서 왼쪽 상단 모서리의 행과 열 값
    int init_row = row - row % 3;
    int init_col = col - col % 3;
    // 3x3 영역에 중복된 숫자가 있는지 확인
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[init_row + i][init_col + j] == num) {
                return false;
            }
        }
    }

    return true;
}

// 스도쿠를 해결하는 함수
bool sudoku(int board[SIZE][SIZE]) {
    // 모든 칸에 대해 그 칸의 값이 0인지 검사
    for (int row = 0; row < SIZE; row++) {
        for (int col = 0; col < SIZE; col++) {
            // 값이 0인 칸인 경우
            if (board[row][col] == 0) {
                // 그 칸에 1부터 9까지 넣어보며 체크
                for (int num = 1; num <= SIZE; num++) {
                    // 숫자 num을 넣었을 때 그 숫자가 유효하다면
                    if (isValid(board, row, col, num)) {
                        board[row][col] = num;

                        // 재귀적으로 다음 칸으로 이동
                        if (sudoku(board)) {
                            return true;
                        }

                        // 더 이상 진행이 안 되면 해당 칸을 초기화
                        board[row][col] = 0;
                    }
                }
                // 모든 숫자를 시도해봐도 해결되지 않으면 false 반환
                return false;
            }
        }
    }
    // 모든 칸이 채워져 있으면 true 반환
    return true;
}

// 스도쿠 판을 출력하는 함수
void printBoard(int board[SIZE][SIZE]) {
    for (int i = 0; i < SIZE; ++i) {
        for (int j = 0; j < SIZE; ++j) {
            cout << board[i][j] << " ";
        }
        cout << endl;
    }
}

int main() {
    // SIZExSIZE 크기의 스도쿠 판
    int board[SIZE][SIZE];

    // 스도쿠 판의 숫자를 입력받음
    for (int i = 0; i < SIZE; ++i) {
        for (int j = 0; j < SIZE; ++j) {
            cin >> board[i][j];
        }
    }

    // 스도쿠 해결 함수 호출
    if (sudoku(board)) {
        // 결과 출력
        printBoard(board);
    }
    else {
        cout << "해가 존재하지 않습니다." << endl;
    }

    return 0;
}