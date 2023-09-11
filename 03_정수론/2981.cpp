#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// 최대공약수를 구하는 함수
int gcd(int a, int b) {
    if (b == 0) return a;
    return gcd(b, a % b);
}

// 입력받은 숫자 간의 차이의 최대 공약수를 계산해서 M을 찾을 수 있다

int main() {
    int N;
    cin >> N;
    // N개의 숫자를 입력받아 벡터 numbers에 저장
    vector<int> numbers(N);

    for (int i = 0; i < N; ++i) {
        cin >> numbers[i];
    }

    // 입력받은 숫자들을 정렬
    sort(numbers.begin(), numbers.end());

    // 입력받은 두 숫자 간의 차이를 diff에 저장
    int diff = numbers[1] - numbers[0];
    // numbers 벡터에 저장되어 있는 모든 숫자 간의 차이에 대해 최대공약수 계산
    for (int i = 2; i < N; ++i) {
        diff = gcd(diff, numbers[i] - numbers[0]);
    }

    // 가능한 M 값(위에서 구한 최대공약수의 약수들)을 divisors 벡터에 저장
    vector<int> divisors;

    for (int i = 1; i * i <= diff; i++) {
        if (diff % i == 0) {
            divisors.push_back(i);
            if (i != diff / i) {
                divisors.push_back(diff / i);
            }
        }
    }

    // M 값들을 정렬
    sort(divisors.begin(), divisors.end());
    // M 값들을 출력
    for (int i = 0; i < divisors.size(); i++) {
        if (divisors[i] > 1) {
            cout << divisors[i] << " ";
        }
    }

    return 0;
}
