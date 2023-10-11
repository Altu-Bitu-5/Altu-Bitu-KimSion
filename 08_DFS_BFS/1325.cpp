#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>

using namespace std;

const int MAX_N = 10001;

vector<int> graph[MAX_N];
bool visited[MAX_N];

// dfs 함수에서는 한 번에 해킹할 수 있는 컴퓨터의 최댓값을 반환
int dfs(int node) {
    visited[node] = true;
    int count = 1;

    // 기준 node에 연결된 다른 정점들에 대해 dfs 함수를 재귀적으로 호출
    for (int neighbor : graph[node]) {
        if (!visited[neighbor]) {
            count += dfs(neighbor);
        }
    }
    return count;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // N, M 값을 입력받음
    int N, M;
    cin >> N >> M;

    // M개의 라인에 대해 반복
    for (int i = 0; i < M; i++) {
        // A, B 값을 입력받음
        int A, B;
        cin >> A >> B;
        // A가 B를 신뢰하는 경우이므로 B에서 A로 가는 간선을 추가
        graph[B].push_back(A);
    }

    // 해킹 가능한 컴퓨터 수와 컴퓨터 번호를 쌍으로 저장하는 벡터
    vector<pair<int, int>> result;

    // 각 컴퓨터에서 시작하여 도달 가능한 컴퓨터 수 계산
    for (int i = 1; i <= N; ++i) {
        // visited 배열을 false로 초기화
        memset(visited, false, sizeof(visited));
        int count = dfs(i);
        // result 벡터에 해킹 가능한 컴퓨터 수와 해당 컴퓨터 번호를 쌍으로 저장
        result.push_back({ count, i });
    }

    // result의 모든 요소에 대해 도달 가능한 컴퓨터 수의 최댓값을 변수 maxCount에 업데이트
    int maxCount = 0;
    for (const auto& pair : result) {
        maxCount = max(maxCount, pair.first);
    }

    for (const auto& pair : result) {
        // 해당 컴퓨터(pair)의 도달 가능한 컴퓨터 수가 최댓값과 일치하면 그 pair의 컴퓨터 번호를 출력
        if (pair.first == maxCount) {
            cout << pair.second << " ";
        }
    }

    return 0;
}