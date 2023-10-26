#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

// 자연수를 받아 그 자연수가 소수인지 판별하는 함수
bool isPrime(int num) {
    // 1 이하의 숫자인 경우 소수가 아니므로 false 리턴
    if (num < 2) {
        return false;
    }
    // i를 2부터 num의 제곱근까지 1씩 증가시켰을 때 num을 나누어 떨어지게 하는 i가 존재하면 false 리턴
    for (int i = 2; i * i <= num; i++) {
        if (num % i == 0) {
            return false;
        }
    }
    // 소수이면 true 리턴
    return true;
}

// 문자열 numbers와 bool형 벡터 visited, 문자 current, int형 벡터 results를 파라미터로 받는 백트래킹 함수
void backtracking(string& numbers, vector<bool>& visited, string current, vector<int>& results) {
    // numbers의 각 자리 숫자에 대해 반복
    for (int i = 0; i < numbers.length(); i++) {
        // 방문하지 않은 숫자라면
        if (!visited[i]) {
            // 해당 숫자는 방문했다고 표시
            visited[i] = true;
            // current 벡터에 해당 숫자를 추가
            current.push_back(numbers[i]);
            // 해당 숫자를 정수형으로 변환하여 results 벡터에 추가
            results.push_back(stoi(current));
            // 백트래킹 함수를 재귀 호출
            backtracking(numbers, visited, current, results);
            // 해당 숫자의 방문 여부는 다시 false로 만들고 current 벡터의 끝에 있는 숫자는 제거
            visited[i] = false;
            current.pop_back();
        }
    }
}

// 문자열 numbers를 입력받아 그 숫자들로 만들 수 있는 소수의 개수를 출력하는 함수
int solution(string numbers) {
    // numbers의 숫자들을 내림차순으로 정렬
    sort(numbers.begin(), numbers.end(), greater<char>());
    // max에는 numbers를 정수형으로 변환하여 저장
    int max = stoi(numbers);
    // 해당 숫자가 소수인지 판별하는 bool형 벡터 is_prime - 크기는 max+1이고 true로 초기화 (0과 1은 false)
    vector<bool> is_prime(max + 1, true);
    is_prime[0] = is_prime[1] = false;

    // i를 2부터 max의 제곱근까지 1씩 증가시키며 소수인지 확인
    for (int i = 2; i * i <= max; i++) {
        if (is_prime[i]) {
            // j를 i^2부터 max까지 i씩 증가시키며 해당 숫자들은 모두 false를 저장
            for (int j = i * i; j <= max; j += i) {
                is_prime[j] = false;
            }
        }
    }

    // 문자열 numbers의 모든 문자에 대해 visited 벡터에는 false를 저장
    vector<bool> visited(numbers.length(), false);
    // numbers의 숫자들로 만들 수 있는 수를 저장할 벡터 results
    vector<int> results;

    // 백트래킹 함수 호출
    backtracking(numbers, visited, "", results);

    // 만들 수 있는 소수의 개수 answer는 0으로 초기화
    int answer = 0;
    // results의 원소들을 오름차순으로 정렬하고 중복 제거
    sort(results.begin(), results.end());
    results.erase(unique(results.begin(), results.end()), results.end());

    // results 벡터에 있는 원소 중 소수의 개수를 answer에 저장
    for (int num : results) {
        if (is_prime[num]) {
            answer++;
        }
    }
    // 만들 수 있는 소수의 개수 answer 반환
    return answer;
}

int main() {
    // 숫자를 입력받고 문자열로 변환한 다음 solution 함수의 결과값 출력
    int number;
    cin >> number;
    cout << solution(to_string(number)) << endl;

    return 0;
}