#include <bits/stdc++.h>
using namespace std;

class DSU {
    int *p, *r;

public:
    DSU(int n) : p(new int[n]), r(new int[n]) {
        fill(p, p + n, -1);
        fill(r, r + n, 1);
    }

    int find(int i) { return p[i] == -1 ? i : p[i] = find(p[i]); }

    void unite(int x, int y) {
        int s1 = find(x), s2 = find(y);
        if (s1 != s2) {
            (r[s1] < r[s2]) ? p[s1] = s2 : ((r[s1] > r[s2]) ? p[s2] = s1 : (p[s2] = s1, r[s1] += 1));
        }
    }
};
class Graph {
    vector<vector<int>> e;
    int V;

public:
    Graph(int V) : V(V) {}

    void addEdge(int x, int y, int w) { e.push_back({w, x, y}); }

    void kruskals_mst() {
        sort(e.begin(), e.end());
        DSU s(V);
        int ans = 0;
        cout << "Edges in MST:" << endl;
        for (const auto &edge : e) {
            int w = edge[0], a = edge[1], b = edge[2];
            if (s.find(a) != s.find(b)) {
                s.unite(a, b);
                ans += w;
                cout << a << " - " << b << " --> " << w << endl;
            }
        }
        cout << "MST Cost: " << ans;
    }
};
int main() {
    Graph g(4);
    g.addEdge(0, 1, 10);
    g.addEdge(1, 3, 15);
    g.addEdge(2, 3, 4);
    g.addEdge(2, 0, 6);
    g.addEdge(0, 3, 5);
    g.kruskals_mst();
    return 0;
}
