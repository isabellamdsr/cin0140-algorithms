#include <iostream>
#include <vector>
#include <queue>
#include <climits>
using namespace std;

typedef long long ll;

struct Graph {
    int V;
    vector<vector<pair<int, ll>>> adj; // (vizinho, peso)
};

void create_graph(Graph &g, int n) {
    g.V = n;
    g.adj.resize(n);
}

void add_edge(Graph &g, int u, int v, int weight) {
    g.adj[u].push_back({v, weight});
    g.adj[v].push_back({u, weight});
}

ll dijkstra(Graph &g, int s, int t, vector<ll> &D, vector<int> &P) {
    priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> heap;
    
    D[s] = 0;
    heap.push({0, s});
    
    while (!heap.empty()) {
        ll dist = heap.top().first;
        int v = heap.top().second;
        heap.pop();

        if (dist > D[v]) continue;
        if (v == t) return dist;
        
        for (int i =0; i < g.adj[v].size(); i++) {
            int w = g.adj[v][i].first;
            ll weight = g.adj[v][i].second;
            
            if (D[v] + weight < D[w]) {
                D[w] = D[v] + weight;
                P[w] = v;
                heap.push({D[w], w});
            }
        }
    }
    return LLONG_MAX;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;

    for (int i = 1; i <= N; i++) {
        int n, m, S, T;
        cin >> n >> m >> S >> T;
        Graph g;
        create_graph(g, n);

        for (int j = 0; j < m; j++) {
            int s1, s2, w;
            cin >> s1 >> s2 >> w;
            add_edge(g, s1, s2, w);
        }

        vector<ll> D(n, LLONG_MAX);
        vector<int> P(n, -1);
        ll dist = dijkstra(g, S, T, D, P);

        if (dist == LLONG_MAX) {
            cout << "Case #" << i << ": unreachable" << "\n";
        }

        else {
            cout << "Case #" << i << ": " << dist << "\n";
        }
    }
}