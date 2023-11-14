#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    // 입력 - 벨트에 놓인 접시의 수 N, 초밥의 가짓수 d, 연속해서 먹는 접시의 수 k, 쿠폰 번호 c
    int N, d, k, c;
    cin >> N >> d >> k >> c;

    // 벨트의 한 위치부터 시작해 회전 방향을 따라갈 때 초밥의 종류를 입력받아 벡터 belt에 저장
    vector<int> belt(N);
    for (int i = 0; i < N; i++) {
        cin >> belt[i];
    }

    // 먹은 초밥의 가짓수를 저장하기 위한 집합
    unordered_set<int> kinds;
    // 초밥의 종류별 먹은 개수를 저장하는 벡터
    vector<int> count(d + 1, 0);

    // 손님이 먹을 수 있는 초밥 가짓수의 최댓값
    int max_kind = 0;

    // 초기 상태에서 연속한 k개의 초밥 가짓수 계산
    for (int i = 0; i < k; i++) {
        // belt[i]의 값을 집합 kinds에 추가하고 count 증가
        kinds.insert(belt[i]);
        count[belt[i]]++;
    }

    // 쿠폰으로 먹을 수 있는 초밥을 집합 kinds에 추가하고 count 증가
    kinds.insert(c);
    count[c]++;

    // 초기 상태에서의 초밥 가짓수를 기준으로 최댓값 업데이트
    max_kind = kinds.size();

    // 연속해서 먹는 구간을 이동하면서 초밥 가짓수 갱신
    for (int start = 0; start < N; start++) {
        // 원형 벨트에서 연속해서 먹는 초밥의 마지막 인덱스
        int end = (start + k) % N;

        // 현재 구간에서 먹은 초밥의 첫 번째 초밥 개수 감소
        count[belt[start]]--;

        // 현재 구간에서 먹은 초밥의 개수가 0이 되면 집합에서 제거
        if (count[belt[start]] == 0) {
            kinds.erase(belt[start]);
        }

        // 다음 구간에서 먹은 초밥의 개수 증가
        count[belt[end]]++;

        // 다음 구간에서 먹은 초밥이 처음 먹은 것이면 집합에 추가
        if (count[belt[end]] == 1) {
            kinds.insert(belt[end]);
        }

        // 쿠폰으로 먹을 수 있는 초밥을 집합 kinds에 추가하고 count 증가
        kinds.insert(c);
        count[c]++;

        // 현재 초밥 가짓수와 기존 최댓값 중 더 큰 값으로 최댓값 업데이트
        max_kind = max(max_kind, static_cast<int>(kinds.size()));
    }

    cout << max_kind << '\n';

    return 0;
}