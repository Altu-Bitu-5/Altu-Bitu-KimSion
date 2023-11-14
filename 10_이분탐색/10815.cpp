#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

// 이분탐색 결과 nums 벡터에 key 값이 존재하면 1 리턴, 없으면 0 리턴
int binarySearch(int n, int key, vector<int>& nums) {
    int left = 0;
    int right = n - 1;
    int mid;
    // 키 값의 존재여부 구하기
    while (left <= right) {
        mid = (left + right) / 2;
        if (nums[mid] == key) {   // key 값이 배열의 중앙값과 같을 때
            return 1;
        }
        else if (nums[mid] > key) { // key 값이 배열의 중앙값보다 작을 때-> 더 작은 값 탐색
            right = mid - 1;
        }
        else {  // key 값이 배열의 중앙값보다 클때-> 더 큰 값 탐색
            left = mid + 1;
        }
    }
    return 0;
}

int main(void) {
    cin.tie(0); cout.tie(0);
    ios_base::sync_with_stdio(NULL);

    int n, m, key;
    // 입력
    cin >> n;
    // 크기가 n인 nums 벡터에 입력받은 숫자 카드의 값 저장
    vector<int> nums(n);
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    // 배열 오름차순 정렬
    sort(nums.begin(), nums.end());

    // m개의 key를 입력받을 때마다 이분탐색 실행
    cin >> m;
    while (m--) {
        cin >> key;
        // 결과 출력
        cout << binarySearch(n, key, nums) << ' ';
    }
    return 0;
}