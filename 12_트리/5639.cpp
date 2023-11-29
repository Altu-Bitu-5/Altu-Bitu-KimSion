#include<iostream>
#include<vector>

using namespace std;

// 후위 순회 함수
void postOrder(int left, int right, vector<int>& tree) {
    // 범위가 역전되면 재귀 종료
	if (left > right) {
		return;
	}
    // 현재 서브트리의 루트 저장
	int root = tree[left];

	// 루트보다 처음으로 큰 노드 인덱스 찾기 -> left, right새로 설정하기 위해서!
	int tmp = left + 1;
    // left+1부터 right까지 1씩 증가시키며 반복
	for (int i = left+1 ; i <= right ; i++) {
        // 루트보다 큰 노드 인덱스를 찾으면
		if (tree[i] > root) {
            // tmp에 해당 인덱스를 저장하고 반복문 종료
			tmp = i;
			break;
		}
	}

	// 루트보다 작은 노드들을 후위 순회 순으로 다시 탐색
	postOrder(left + 1, tmp - 1,tree);
    // 루트보다 큰 노드들을 후위 순회 순으로 다시 탐색
	postOrder(tmp, right, tree);

	// left, right 탐색 끝났으므로 root 출력
	cout << root << '\n';
}

/*
* 이진 검색 트리 : 루트의 왼쪽 
* 이진 검색 트리를 전위 순회환 결과 -> 후위 순회한 결과
* 전위 순회 : 루트 왼쪽 오른쪽 -> 후위 순회 : 왼쪽 오른쪽 루트
*  -> 탐색 결과 : 루트 -> 루트보다 작은 노드(왼쪽) -> 루트보다 큰 노드(오른쪽)
*  -> 루트를 기준으로 left, right 나눠서 후위 순회 순으로 다시 탐색
*/

int main() {

	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	// 입력받을 숫자 num
	int num;
    // 입력받은 숫자를 저장할 int형 벡터 tree
	vector<int> tree;
    // num을 입력받아 벡터 tree에 저장
	while (cin >> num) {
		tree.push_back(num);
	}

	// 후위 순회 함수 호출 - left, right 인덱스로 tree의 끝과 끝 인덱스를 전달
	postOrder(0, tree.size() - 1, tree);
}