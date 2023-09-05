#include <iostream>
#include <string>
#include <queue>
#include <algorithm> // reverse 함수 사용을 위해

using namespace std;

string add(const string& a, const string& b) {
    queue<int> q;
    int carry = 0;

    // a, b의 맨 뒤 숫자 인덱스를 각각 i, j에 저장
    int i = a.size() - 1;
    int j = b.size() - 1;

    while (i >= 0 || j >= 0 || carry > 0) {
        // a와 b의 특정 자리수 숫자를 구한다. 아스키코드 값에서 '0'의 아스키코드 값을 빼서 해당 문자를 숫자로 바꾼다.
        int a_sum = (i >= 0) ? (a[i] - '0') : 0;
        int b_sum = (j >= 0) ? (b[j] - '0') : 0;

        // a와 b의 같은 자리수 숫자를 더한다. 이때 전 단계 계산에서 구한 carry 값도 같이 더한다
        int sum = a_sum + b_sum + carry;
        // sum 값에서 1의 자리수는 큐에 삽입
        q.push(sum % 10);
        // sum 값이 10을 초과하면 10의 자리수는 carry에 저장하고 다음 계산에서 더한다
        carry = sum / 10;

        // 다음 자리수 계산을 위해 i, j가 가리키는 인덱스를 1씩 감소시킨다
        i--;
        j--;
    }

    string result;
    // 큐의 앞에 있는 숫자를 문자열로 바꿔 result 문자열에 이어붙인 뒤 pop
    while (!q.empty()) {
        result += to_string(q.front());
        q.pop();
    }

    // 일의 자리수부터 정렬되어 있으므로 reverse 함수로 순서를 뒤집어준다
    reverse(result.begin(), result.end());
    return result;
}

int main() {
    // 더할 수 a, b를 입력받음
    string a, b;
    cin >> a >> b;

    // 함수 호출, 결과 출력
    string sum = add(a, b);
    cout << sum;

    return 0;
}
