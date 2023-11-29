#include <iostream>
#include <vector>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

const int MAX_N = 100005;
vector<int> adj[MAX_N];
int subtree_size[MAX_N];

// dfs 함수 - 현재 노드와 부모 노드를 입력받아 서브트리의 size 리턴
int dfs(int node, int parent) {
    // 서브트리의 size는 1로 초기화
    int size = 1;
    // 현재 노드의 모든 자식 노드에 대해 반복
    for (int child : adj[node]) {
        if (child != parent) {
            // 현재 자식 노드에서의 서브트리 size를 재귀적으로 더함
            size += dfs(child, node);
        }
    }
    // 현재 노드에서의 서브트리 size를 저장하고 리턴
    subtree_size[node] = size;
    return size;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    FASTIO;

    // 정점의 수 N, 루트의 번호 R, 쿼리의 수 Q 입력
    int N, R, Q;
    cin >> N >> R >> Q;

    // 정점의 수만큼 반복하며 U, V 입력
    for (int i = 1; i < N; i++) {
        int U, V;
        cin >> U >> V;
        // adj 벡터를 통해 U와 V를 연결
        adj[U].push_back(V);
        adj[V].push_back(U);
    }

    // 자식 노드를 입력받은 R로, 부모 노드를 루트 노드로 하여 dfs 함수 호출
    dfs(R, 0);

    // 쿼리의 수만큼 반복하며 U 입력
    for (int i = 0; i < Q; i++) {
        int U;
        cin >> U;
        // U를 루트로 하는 서브트리에 속한 정점의 수 출력
        cout << subtree_size[U] << '\n';
    }
    return 0;
}