#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int main() {
    // 입력 - 수열의 길이 N, 연속 부분 수열에 포함될 수 있는 같은 정수의 최대 개수 K 
    int N, K;
    cin >> N >> K;

    // 입력받은 배열을 벡터 sequence에 저장
    vector<int> sequence(N);
    for (int i = 0; i < N; i++) {
        cin >> sequence[i];
    }
    // 각 숫자의 등장 횟수를 저장하는 해시 맵 <숫자, 등장 횟수>
    unordered_map<int, int> count;

    // 연속 부분 수열의 시작 인덱스
    int start = 0;
    // 연속 부분 수열 길이의 최댓값
    int max_length = 0;

    // end 인덱스는 start에서 시작해 오른쪽으로 하나씩 이동
    for (int end = 0; end < N; end++) {
        // 현재 숫자의 등장 횟수 증가
        count[sequence[end]]++;

        // 현재 부분 수열에서 중복된 숫자의 개수가 K를 초과하면
        while (count[sequence[end]] > K) {
            // sequence[start]의 등장 횟수를 감소시키고 등장 횟수가 0이 되면 count에서 제거
            count[sequence[start]]--;
            if (count[sequence[start]] == 0) {
                count.erase(sequence[start]);
            }
            // start를 이동시켜 중복된 숫자의 개수가 K개 이하가 될 때까지 반복
            start++;
        }

        // 현재 부분 수열의 길이와 기존 max_length 값 중 더 큰 값으로 max_length 업데이트
        max_length = max(max_length, end - start + 1);
    }

    cout << max_length << '\n';

    return 0;
}