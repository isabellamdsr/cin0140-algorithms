#include <iostream>
#include <vector>
#include <stack>
using namespace std;

struct Graph {
    int V;
    vector<vector<int>> adj;
};

void create_graph(Graph &g, int n) {
    g.V = n;
    g.adj = vector<vector<int>>(n);
}

void add_edge(Graph &g, int u, int v) {
    g.adj[u].push_back(v);
}

bool dfs_traversal(Graph &g, int v, vector<int> &mark, stack<int> &s) {
    mark[v] = 1;
    for (int w : g.adj[v]) {
        if (mark[w] == 1) return true; // ciclo
        if (mark[w] == 0 && dfs_traversal(g, w, mark, s)) return true;
    }
    mark[v] = 2;
    s.push(v);
    return false;
}

bool toposort(Graph &g, vector<int> &order) {
    vector<int> mark(g.V, 0);
    stack<int> s;

    for (int i = 0; i < g.V; i++) {
        if (mark[i] == 0) {
            if (dfs_traversal(g, i, mark, s)) return false; // ciclo
        }
    }
    while (!s.empty()) {
        order.push_back(s.top());
        s.pop();
    }
    
    return true;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t, chat, screenshots;
    cin >> t;

    while (t--) {
        cin >> chat >> screenshots;

        Graph g;
        create_graph(g, chat);

        for (int i = 0; i < screenshots; i++) {
            vector<int> order(chat);

            for (int j = 0; j < chat; j++) {
                cin >> order[j];
                order[j]--; // padronizar os indices
            }
            for (int a = 1; a < (chat - 1); a++) {
                add_edge(g, order[a], order[a+1]);
            }
        }
        vector<int> order;
        if (toposort(g, order)) cout << "YES\n";
        else cout << "NO\n";
    }
}
