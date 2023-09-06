#include <iostream>
#include <vector>
#include <sstream>

using namespace std;

int main() {
    const int SIZE = 1000000;
    // n 이하의 소수 구하기 (에라토스테네스의 체 활용)
    vector<bool> is_prime(SIZE + 1, true);
    // 0과 1은 소수가 아니므로 먼저 false로 바꾼다
    is_prime[0] = is_prime[1] = false;

    for (int p = 2; p * p <= SIZE; p++) {
        if (is_prime[p]) {
            // 소수 p의 배수는 값을 모두 false로 바꾼다
            for (int i = p * p; i <= SIZE; i += p) {
                is_prime[i] = false;
            }
        }
    }

    // 입력받은 숫자를 저장하는 벡터
    vector<int> numbers;
    string line;
    while (getline(cin, line)) {
        if (line == "0") {
            break;
        }
        int n;
        istringstream iss(line);
        iss >> n;
        numbers.push_back(n);
    }

    for (int n : numbers) {
        // n을 만드는 두 홀수 소수 a, b를 찾음
        int a = 3;
        while (a <= n / 2) {
            int b = n - a;
            // a와 b가 둘 다 소수이면 그 값을 출력
            if (is_prime[a] && is_prime[b]) {
                cout << n << " = " << a << " + " << b << endl;
                break;
            }
            a += 2; // 다음 홀수를 시도
        }

        // 두 홀수 소수로 n을 만들 수 없는 경우
        if (a > n / 2) {
            cout << "Goldbach's conjecture is wrong." << endl;
        }
    }

    return 0;
}
