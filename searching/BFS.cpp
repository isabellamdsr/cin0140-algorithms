#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <algorithm>
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
    g.adj[v].push_back(u);
}

int get_index(vector<string> &names, vector<int> &rank, string &name) {
    for (int i = 0; i < names.size(); i++)
        if (names[i] == name) return i;

    names.push_back(name);
    rank.push_back(-1);
    return names.size()-1;
}

void BFS_rank(Graph &g, vector<int> &rank, int start) {
    queue<int> q;
    q.push(start);

    while (!q.empty()) {
        int v = q.front(); q.pop();
        for (int w : g.adj[v]) {
            if (rank[w] == -1) {
                rank[w] = rank[v] + 1;
                q.push(w);
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    while (n--) {
        vector<string> names;
        vector<int> rank;
        vector<vector<int>> teams;

        int num_teams;
        cin >> num_teams;

        names.push_back("Ahmad"); 
        rank.push_back(0); // inicialização do ranking de ahmad

        for (int i = 0; i < num_teams; i++) {
            string team[3];
            for (int k = 0; k < 3; k++) cin >> team[k];

            vector<int> inds(3);
            for (int k = 0; k < 3; k++)
                inds[k] = get_index(names, rank, team[k]);

            teams.push_back(inds);
        }

        Graph g;
        create_graph(g, names.size());
        for (int l = 0; l < num_teams; l++) {
            add_edge(g, teams[l][0], teams[l][1]);
            add_edge(g, teams[l][0], teams[l][2]);
            add_edge(g, teams[l][1], teams[l][2]);
        }

        BFS_rank(g, rank, 0);

        int max_rank = *max_element(rank.begin(), rank.end());
        cout << names.size() << "\n";

        for (int rk = 0; rk <= max_rank; rk++) {
            vector<string> contestants, undefined;
            
            for (int i = 0; i < names.size(); i++) {
                if (rank[i] == rk) contestants.push_back(names[i]);
                else if (rank[i] == -1) undefined.push_back(names[i]);
            }

                sort(contestants.begin(), contestants.end());
                sort(undefined.begin(), undefined.end());

            for (auto &name : contestants)
                cout << name << " " << rk << "\n";

            if (rk == max_rank) {
                for (auto &name : undefined)
                cout << name << " undefined" << "\n";
            }
        }
    }
}