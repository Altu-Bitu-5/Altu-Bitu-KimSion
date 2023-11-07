#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// 주어진 길이 length로 나눠줄 수 있는지 확인하는 함수
bool distribute(vector<int>& snacks, int length, int num) {
    int total_count = 0;
    // snacks 벡터의 모든 원소를 길이로 나눈 값을 total_count에 더함
    for (int i = 0; i < snacks.size(); i++) {
        total_count += snacks[i] / length;
        // total_count가 조카의 수 이상이 되면 true 리턴
        if (total_count >= num) {
            return true;
        }
    }
    return false;
}

int main() {
    // 조카의 수 M과 과자의 수 N을 입력받음
    int M, N;
    cin >> M >> N;
    // 과자의 길이 n개를 입력받아 snacks 벡터에 저장
    vector<int> snacks(N);
    for (int i = 0; i < N; i++) {
        cin >> snacks[i];
    }

    // 최소 길이는 1로 설정
    int left = 1;
    // 최대 길이는 snacks 벡터의 원소 중 최댓값으로 설정
    int right = *max_element(snacks.begin(), snacks.end());
    // 조카 1명에게 줄 수 있는 과자의 최대 길이
    int result = 0;

    // 이분 탐색으로 최대 길이 찾기
    while (left <= right) {
        int mid = (left + right) / 2;

        // 현재 길이로 조카들에게 나눠줄 수 있다면
        if (distribute(snacks, mid, M)) {
            // result의 값을 현재 길이와 기존 result 중 더 큰 값으로 업데이트
            result = max(result, mid);
            // 현재 길이보다 값이 더 큰 구간에서 다음 반복 수행
            left = mid + 1;
        }
        // 현재 길이로 조카들에게 나눠줄 수 없다면
        else {
            // 현재 길이보다 값이 더 작은 구간에서 다음 반복 수행
            right = mid - 1;
        }
    }

    cout << result << '\n';

    return 0;
}