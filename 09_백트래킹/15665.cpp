#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// 입력받은 숫자의 개수 N과 선택할 수열에서 숫자의 개수 M
int N, M;
// 입력받은 수열을 저장할 numbers 벡터와 그 중에서 숫자를 선택해 만들 수열 sequence
vector<int> numbers;
vector<int> sequence;

// 백트래킹 함수
void backtracking(int k) {
    // 탈출 조건: k 값이 선택할 수열의 길이 M과 같아졌을 때
    if (k == M) {
        // sequence 벡터에 있는 모든 숫자를 출력
        for (int num : sequence) {
            cout << num << ' ';
        }
        cout << '\n';
        return;
    }

    // N번 반복
    for (int i = 0; i < N; i++) {
        // sequence에 해당 인덱스의 숫자를 저장
        sequence.push_back(numbers[i]);
        // k 값을 1 증가시킨 다음 backtracking 함수 재귀 호출
        backtracking(k + 1);
        // sequence 벡터의 맨 뒤에 있는 숫자를 제거해 원래대로 되돌린다
        sequence.pop_back();
    }
}

int main() {
    // 자연수 N과 M의 값을 입력받아 numbers 벡터의 사이즈를 N으로, sequence 벡터의 사이즈를 M으로 설정
    cin >> N >> M;
    numbers.resize(N);
    sequence.reserve(M);

    // 사이즈가 N인 numbers 벡터에 입력 받은 숫자를 저장
    for (int i = 0; i < N; ++i) {
        cin >> numbers[i];
    }

    // 오름차순 출력을 위해 numbers 벡터를 정렬
    sort(numbers.begin(), numbers.end());
    // 중복인 숫자 제거
    auto last = unique(numbers.begin(), numbers.end());
    numbers.erase(last, numbers.end());
    // N 값 업데이트
    N = numbers.size();

    // 초기 k 값을 0으로 하여 backtracking 함수 호출
    backtracking(0);

    return 0;
}