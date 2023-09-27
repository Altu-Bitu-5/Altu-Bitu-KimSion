#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

string makePalindrome(string input) {
    // A부터 Z까지 알파벳의 개수 26개
    const int alphabet_num = 26;
    // input에서 각 알파벳의 개수를 저장하는 배열
    int charCount[alphabet_num] = { 0 };

    // 각 알파벳의 개수 카운트
    for (char c : input) {
        charCount[c - 'A']++;
    }

    // 문자열 앞 부분
    string firstHalf = "";
    // 문자열 가운데에 올 문자
    string middle = "";

    // 팰린드롬을 만들 수 있는지 확인 (A부터 Z까지 반복문 돌리면서 일일이 확인)
    for (int i = 0; i < alphabet_num; i++) {
        char c = 'A' + i;

        // 홀수 개수의 문자는 한 번만 중앙에 올 수 있음
        if (charCount[i] % 2 == 1) {
            // 가운데에 올 문자가 이미 할당되어 있는 경우 팰린드롬을 만들 수 없다
            if (!middle.empty())
                return "I'm Sorry Hansoo";
            // 가운데에 올 문자가 비어있는 경우 홀수 개수의 해당 문자를 middle에 지정
            middle = c;
            charCount[i]--;
        }

        // firstHalf 문자열에 문자 c를 count/2번 추가
        firstHalf += string(charCount[i] / 2, c);
    }

    // 문자열 앞 부분을 뒷 부분에 복사하고 순서를 뒤집는다
    string secondHalf = firstHalf;
    reverse(secondHalf.begin(), secondHalf.end());

    // 팰린드롬 문자열 완성
    string palindrome = firstHalf + middle + secondHalf;
    return palindrome;
}

int main() {
    string input;

    // 문자열 입력받기
    cin >> input;

    // 팰린드롬 생성 함수 호출, 결과 출력
    string palindrome = makePalindrome(input);
    cout << palindrome << '\n';

    return 0;
}