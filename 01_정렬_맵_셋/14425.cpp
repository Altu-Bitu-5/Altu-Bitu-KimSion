#include <iostream>
#include <set>
#include <string>

using namespace std;

int main()
{
	int n, m;
	int count = 0;
	string cmp;
	set<string> S; //set을 이용하여 집합 S 생성

	// 문자열을 입력받아 집합 S에 넣음
	cin >> n >> m;
	while (n--) {
		string input;
		cin >> input;
		S.insert(input);
	}

	// 문자열이 집합 S에 포함되는지 확인
	while (m--) {
		string str;
		cin >> str;
		if (S.find(str) != S.end()) count++; //문자열이 집합 S에 포함되지 않을 경우 S.find(str)은 S.end()와 같은 값을 반환 - 포함되면 count를 1 증가시킨다.
	}

	cout << count;

	return 0;
}