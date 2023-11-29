#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    // 학생의 수 N, 키 비교 횟수 M 입력
    int N, M;
    cin >> N >> M;

    // 초기화
    const int INF = 987654321;
    // (N+1)*(N+1) 크기의 2차원 벡터 graph (초기값: INF)
    vector<vector<int>> graph(N + 1, vector<int>(N + 1, INF));

    // 자기 자신으로의 경로는 0으로 초기화
    for (int i = 1; i <= N; i++) {
        graph[i][i] = 0;
    }

    // 입력 받은 비교 결과를 graph에 저장
    for (int i = 0; i < M; i++) {
        int a, b;
        cin >> a >> b;
        graph[a][b] = 1;
    }

    // (플로이드-워셜 알고리즘) i에서 j까지의 최단거리 업데이트
    for (int k = 1; k <= N; k++) {
        for (int i = 1; i <= N; i++) {
            for (int j = 1; j <= N; j++) {
                graph[i][j] = min(graph[i][j], graph[i][k] + graph[k][j]);
            }
        }
    }

    int answer = 0;

    // N명의 모든 학생에 대해 반복
    for (int i = 1; i <= N; i++) {
        bool can_determine = true;

        // i에서 모든 다른 노드로의 경로를 확인하여 자신의 키 순서를 알 수 있는지 판단
        for (int j = 1; j <= N; j++) {
            // 학생 i와 j 간의 비교 결과가 없는 경우 학생 i의 키 순서를 알 수 없으므로 반복을 멈추고 다음 학생으로 넘어감
            if (i != j && (graph[i][j] == INF && graph[j][i] == INF)) {
                can_determine = false;
                break;
            }
        }

        // 자신의 키 순서를 알 수 있는 학생이라면 answer값 1 증가
        if (can_determine) {
            answer++;
        }
    }

    cout << answer << '\n';

    return 0;
}