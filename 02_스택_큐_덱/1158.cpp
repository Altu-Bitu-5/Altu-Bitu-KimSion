#include <iostream>
#include <vector>

using namespace std;

vector<int> josephus(int n, int k) {
    vector<int> elements(n);
    vector<int> sequence;

    // n개의 숫자 삽입
    for (int i = 0; i < n; i++) {
        elements[i] = i + 1;
    }

    int index = 0;
    while (!elements.empty()) {
        index = (index + k - 1) % elements.size(); // index를 다음 k번째 요소의 index로 업데이트 (index는 0부터 시작하므로 1을 뺀다)
        sequence.push_back(elements[index]); // k번째 사람을 sequence에 추가
        elements.erase(elements.begin() + index); // k번째 사람을 elements에서 제거
    }
    return sequence;
}

int main() {
    int n, k;
    // n, k 값 입력받음
    cin >> n >> k;

    // 함수 호출
    vector<int> sequence = josephus(n, k);
    
    // 결과 sequence 벡터의 모든 요소를 순서대로 출력
    cout << "<";
    for (int i = 0; i < n-1; i++) {
        cout << sequence[i] << ", ";
    }
    cout << sequence[n - 1];
    cout << ">\n";

    return 0;
}
