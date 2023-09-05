#include <iostream>
#include <string>
#include <stack>
#include <vector>

using namespace std;

bool check_balance(string str) {
    stack<int> s;

    // 한 문자씩 검사
    for (int i = 0; i < str.length(); i++) {
        // 왼쪽 괄호인 경우 스택에 삽입
        if (str[i] == '(' || str[i] == '[') {
            s.push(str[i]);
        }
        // 오른쪽 괄호인 경우
        else if (str[i] == ')' || str[i] == ']') {
            // 스택이 비어있는데 오른쪽 괄호인 경우 false 리턴
            if (s.empty()) return false;
            // 스택의 top에 있는 괄호와 짝이 맞는 경우 스택에서 pop
            if ((str[i] == ')' && s.top() == '(') || (str[i] == ']' && s.top() == '[')) {
                s.pop();
            }
            // 스택의 top에 있는 괄호와 짝이 맞지 않으면 flase 리턴
            else return false;
        }
    }
}

int main() {
    vector<string> inputs; // 문자열 저장 벡터
    string input_str;

    while (true) {
        // 문자열 입력 받아 벡터에 저장
        getline(cin, input_str);
        inputs.push_back(input_str);

        // 프로그램 종료 조건: 온점
        if (input_str == ".") break;
    }

    // 벡터에 저장된 문자열을 차례대로 가져오고 함수를 호출해서 검사
    for (const string& str: inputs) {
        if (check_balance(str)) cout << "yes\n";
        else cout << "no\n";
    }

    return 0;
}
