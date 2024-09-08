#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

bool bfs(vector<vector<int>>& residualGraph, int src, int sink, vector<int>& parent) {
    int V = residualGraph.size();
    vector<bool> visited(V, false);
    queue<int> q;
    q.push(src);
    visited[src] = true;
    parent[src] = -1;

    while (!q.empty()) {
        int u = q.front();
        q.pop();

        for (int v = 0; v < V; v++) {
            if (!visited[v] && residualGraph[u][v] > 0) {
                parent[v] = u;
                visited[v] = true;
                if (v == sink)
                    return true;
                q.push(v);
            }
        }
    }

    return false;
}

int edmondsKarp(vector<vector<int>>& graph, int src, int sink) {
    int V = graph.size();
    vector<vector<int>> residualGraph(V, vector<int>(V));
    for (int u = 0; u < V; u++)
        for (int v = 0; v < V; v++)
            residualGraph[u][v] = graph[u][v];

    vector<int> parent(V);
    int max_flow = 0;

    while (bfs(residualGraph, src, sink, parent)) {
        int path_flow = INT_MAX;
        for (int v = sink; v != src; v = parent[v]) {
            int u = parent[v];
            path_flow = min(path_flow, residualGraph[u][v]);
        }

        for (int v = sink; v != src; v = parent[v]) {
            int u = parent[v];
            residualGraph[u][v] -= path_flow;
            residualGraph[v][u] += path_flow;
        }

        max_flow += path_flow;
    }

    return max_flow;
}

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> graph(n, vector<int>(n, 0));

    for (int i = 0; i < m; ++i) {
        int a, b, c;
        cin >> a >> b >> c;
        a--; b--;
        graph[a][b] += c;
    }

    cout << edmondsKarp(graph, 0, n - 1);

    return 0;
}
