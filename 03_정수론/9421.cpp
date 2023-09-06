#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

// 상근수를 계산하는 함수
int calculateSanggeun(int n) {
    // n이 1이 되어 상근수인 경우, n이 4가 되어 상근수가 아닌데 무한루프가 되는 경우 반복 종료
    while (n != 1 && n != 4) {
        int sum = 0;
        // 일의 자리수부터 각 자리수의 제곱의 합을 sum에 저장
        while (n) {
            int digit = n % 10;
            sum += digit * digit;
            n /= 10;
        }
        n = sum;
    }
    return n;
}

// limit보다 작거나 같은 모든 소수 상근수를 찾는 함수
vector<int> findPrimeSanggeun(int limit) {
    vector<int> prime_sanggeun;

    for (int num = 3; num <= limit; num += 2) {
        bool is_prime = true;
        for (int i = 2; i*i <= num; i++) {
            if (num % i == 0) {
                is_prime = false;
                break;
            }
        }
        // 소수이면서 상근수이면 primes 벡터에 저장
        if (is_prime && calculateSanggeun(num) == 1) {
            prime_sanggeun.push_back(num);
        }
    }

    return prime_sanggeun;
}

int main() {
    int n;
    cin >> n;

    vector<int> prime_happy_numbers = findPrimeSanggeun(n);

    for (int prime : prime_happy_numbers) {
        cout << prime << endl;
    }

    return 0;
}
