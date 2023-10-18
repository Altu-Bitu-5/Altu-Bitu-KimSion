#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// 숫자의 개수 N
int N;
// 입력 받은 숫자와 연산자를 저장할 벡터
vector<int> numbers;
vector<int> operators;

int maxValue = -1e9;  // 초기값은 최솟값을 나타내는 -10^9로 설정
int minValue = 1e9;   // 초기값은 최댓값을 나타내는 10^9로 설정

// 백트래킹 함수
void backtracking(int idx, int result) {
    // 탈출 조건: 모든 연산자를 사용했을 때
    if (idx == N - 1) {
        // 이전 result 값과 현재 maxValue 중 더 큰 값을 maxValue로 설정
        maxValue = max(maxValue, result);
        // 이전 result 값과 현재 minValue 중 더 작은 값을 minValue로 설정
        minValue = min(minValue, result);
        return;
    }

    // + 연산자의 개수가 0보다 큰 경우 (덧셈 실행 가능한 경우)
    if (operators[0] > 0) {
        // + 연산자의 개수 -1 (하나 사용)
        operators[0]--;
        // 다음 인덱스와 현재 result에 다음 인덱스의 숫자를 더한 값을 파라미터로 전달하여 backtracking 재귀 호출
        backtracking(idx + 1, result + numbers[idx + 1]);
        // + 연산자의 개수를 원래대로 돌려놓는다
        operators[0]++;
    }

    // - 연산자의 개수가 0보다 큰 경우
    if (operators[1] > 0) {
        // - 연산자의 개수 -1
        operators[1]--;
        // 다음 인덱스와 현재 result에서 다음 인덱스의 숫자를 뺀 값을 파라미터로 전달하여 backtracking 재귀 호출
        backtracking(idx + 1, result - numbers[idx + 1]);
        // - 연산자의 개수를 원래대로 돌려놓는다
        operators[1]++;
    }

    // * 연산자의 개수가 0보다 큰 경우 
    if (operators[2] > 0) {
        // * 연산자의 개수 -1
        operators[2]--;
        // 다음 인덱스와 현재 result에 다음 인덱스의 숫자를 곱한 값을 파라미터에 전달하여 backtracking 재귀 호출
        backtracking(idx + 1, result * numbers[idx + 1]);
        // * 연산자의 개수를 원래대로 돌려놓는다
        operators[2]++;
    }

    // / 연산자의 개수가 0보다 큰 경우
    if (operators[3] > 0) {
        // / 연산자의 개수 -1
        operators[3]--;
        // 다음 인덱스와 현재 result를 다음 인덱스의 숫자로 나눈 값을 파라미터에 전달하여 backtracking 재귀 호출
        backtracking(idx + 1, result / numbers[idx + 1]);
        // / 연산자의 개수를 원래대로 돌려놓는다
        operators[3]++;
    }
    // 백트래킹을 통해 연산 순서를 바꿔가며 maxValue, minValue를 구할 수 있다.
}

int main() {
    // 숫자의 개수 N을 입력받고 numbers 벡터의 크기를 N으로 설정
    cin >> N;
    numbers.resize(N);
    // numbers 벡터에 입력받은 숫자를 저장
    for (int i = 0; i < N; i++) {
        cin >> numbers[i];
    }
    // 연산자의 개수는 4이므로 operators 벡터의 크기를 4로 설정
    operators.resize(4);
    // operators 벡터에 입력받은 연산자의 개수를 저장
    for (int i = 0; i < 4; ++i) {
        cin >> operators[i];
    }

    // 백트래킹 수행
    backtracking(0, numbers[0]);

    // 결과 출력
    cout << maxValue << endl;
    cout << minValue << endl;

    return 0;
}