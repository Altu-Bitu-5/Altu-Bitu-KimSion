#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cctype>

using namespace std;

struct serial { // 시리얼 번호 구조체: 시리얼 번호 문자열, 시리얼 번호 중 숫자인 자리수의 합
	string serial_num;
    int serial_sum;
};

//시리얼 번호 중 숫자인 자리수의 합을 계산하는 함수
int serialSum(const string& serial_num) {
    int sum = 0;
    for (char c : serial_num) {
        if (isdigit(c)) sum += c - '0'; // 해당 문자가 숫자라면 문자를 숫자로 변환해서 더함 (문자 '0'을 빼면 아스키 코드로 해당 숫자를 구할 수 있음)
    }
    return sum;
}

// 비교 함수
bool cmpSerial(const serial& s1, const serial& s2) {
	if (s1.serial_num.length() != s2.serial_num.length()) {// 시리얼 번호 길이가 증가하는 순서
		return s1.serial_num.length() < s2.serial_num.length();
	}
	if (s1.serial_sum != s2.serial_sum) {// (시리얼 번호 길이가 같으면) 자리수 합이 증가하는 순서
		return s1.serial_sum < s2.serial_sum;
	}
	return s1.serial_num < s2.serial_num; // (시리얼 번호 길이가 같고 자리수 합도 같다면) 사전순(숫자가 알파벳보다 작음)
}

/*
* 시리얼 번호를 구조체에 저장
* 정렬 방법을 비교 함수에 추가
*/

int main()
{
	int n;
	vector<serial> guitars;

	// 입력
	cin >> n;
	guitars.assign(n, {});
	for (int i = 0; i < n; i++) { // 시리얼 번호를 받음
		cin >> guitars[i].serial_num;
        guitars[i].serial_sum = serialSum(guitars[i].serial_num);
	}

	// 연산
	sort(guitars.begin(), guitars.end(), cmpSerial);

	// 출력
	for (int i = 0; i < guitars.size(); i++) {
		cout << guitars[i].serial_num << '\n';
	}

	return 0;
}