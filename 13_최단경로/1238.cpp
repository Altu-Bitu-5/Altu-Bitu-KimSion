#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

// 간선의 정보를 담고있는 구조체
struct Edge {
    int to;
    int cost;
};

// 우선순위 큐에서 거리가 가장 짧은 정점부터 꺼내기 위한 비교 연산자 정의
struct Compare {
    bool operator()(pair<int, int>& a, pair<int, int>& b) {
        return a.second > b.second;
    }
};

// 다익스트라 알고리즘
vector<int> dijkstra(int start, int n, vector<vector<Edge>>& graph) {
    // 각 정점까지의 최단거리를 저장하는 배열
    vector<int> dist(n + 1, INT_MAX);
    // 비교자로 Compare 구조체를 사용해 거리가 가장 짧은 정점부터 꺼내는 우선순위 큐
    priority_queue<pair<int, int>, vector<pair<int, int>>, Compare> pq;

    dist[start] = 0;
    pq.push({ start, 0 });

    while (!pq.empty()) {
        // 현재 정점의 번호
        int current = pq.top().first;
        // 현재 정점까지의 (현재까지 알려진) 최단거리
        int current_dist = pq.top().second;
        pq.pop();

        // dist 배열에서 알려진 거리가 새로 계산한 최단거리보다 더 짧은 경우에는 패스
        if (dist[current] < current_dist) continue;

        for (const Edge& edge : graph[current]) {
            int next = edge.to;
            int cost = edge.cost;

            // 현재 정점까지의 거리에 다음 정점까지의 거리를 더한 값이 다음 정점까지의 최단거리보다 작다면 dist[next] 값 업데이트
            if (dist[current] + cost < dist[next]) {
                dist[next] = dist[current] + cost;
                // 다음 정점을 우선순위 큐에 넣음
                pq.push({ next, dist[next] });
            }
        }
    }

    return dist;
}

int main() {
    // 학생(마을)의 수 N, 단방향 도로의 수 M, 모이는 마을의 번호 X 입력
    int N, M, X;
    cin >> N >> M >> X;

    // 각 정점에서 나가는 간선들을 저장하는 2차원 벡터 graph
    vector<vector<Edge>> graph(N + 1);

    // 도로의 수 M만큼 반복하며 입력받은 값(end, cost 쌍)을 graph에 저장
    for (int i = 0; i < M; i++) {
        int start, end, cost;
        cin >> start >> end >> cost;
        graph[start].push_back({ end, cost });
    }

    // 다익스트라 알고리즘으로 X에서 시작하여 모든 정점까지의 최단 거리 계산
    vector<int> dist_from_X = dijkstra(X, N, graph);

    // 2차원 벡터 역방향 그래프 생성
    vector<vector<Edge>> reverse_graph(N + 1);

    // 마을의 수 N만큼 반복하며 graph에 저장된 Edge 값들을 (출발, 도착 지점을 바꿔서) reverse_graph에 저장
    for (int i = 1; i <= N; i++) {
        for (const Edge& edge : graph[i]) {
            reverse_graph[edge.to].push_back({ i, edge.cost });
        }
    }

    // 다익스트라 알고리즘을 각 정점에서 시작하여 X까지의 최단 거리 계산
    vector<int> dist_to_X = dijkstra(X, N, reverse_graph);

    int max_dist = 0;

    // X를 경유해서 가는 경우(X까지 거리+X부터 거리) 가장 큰 값 찾기
    for (int i = 1; i <= N; i++) {
        int total_dist = dist_from_X[i] + dist_to_X[i];
        max_dist = max(max_dist, total_dist);
    }

    // 가장 오래 걸리는 학생의 소요 시간 출력
    cout << max_dist << '\n';

    return 0;
}