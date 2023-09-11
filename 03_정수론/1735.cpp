#include <iostream>

using namespace std;

//반복문 이용하여 최대공약수(gcd) 구하기
int getGcdIter(int a, int b) {
    int tmp;
    while (b != 0) {
        tmp = a % b;
        a = b;
        b = tmp;
    }
    return a;
}

int main() {
    //분수 입력
    int a1, a2, b1, b2, c1, c2;
    cin >> a1 >> a2 >> b1 >> b2;

    //최대공약수
    int gcd = getGcdIter(max(a2, b2), min(a2, b2));
    //최소공배수
    int lcm = a2 * b2 / gcd;
    //통분 (분모는 lcm)
    a1 = a1 * (lcm / a2);
    b1 = b1 * (lcm / b2);
    //덧셈 결과
    c1 = a1 + b1;
    c2 = lcm;

    int gcd2 = getGcdIter(max(c1, c2), min(c1, c2));
    //결과가 기약분수인지 확인
    if (gcd2 != 1) {
        c1 /= gcd2;
        c2 /= gcd2;
    }

    //결과 출력
    cout << c1 << ' ' << c2;

    return 0;
}
