#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> pii;

struct Edge {int src, dst, weight;};
bool comp(Edge *a, Edge *b) {return a -> weight > b -> weight;}

int nodes[10001], ranks[10001], maxWeight[10001];
bool vis[10001];
int c, r, d;
vector<Edge*> edges;
vector<pii> v[10001];

void init() {for (int i = 1; i <= c; i++) {nodes[i] = i; ranks[i] = 1;}}

int findSet(int n) {
    if (nodes[n] == n) {return n;}
    nodes[n] = findSet(nodes[n]);
    return nodes[n];
}

void unionSet(int n1, int n2) {
    int p1 = findSet(n1); int p2 = findSet(n2);
    if (ranks[p1] > ranks[p2]) {nodes[p2] = p1; ranks[p1] += ranks[p2];}
    else {nodes[p1] = p2; ranks[p2] += ranks[p1];}
}

void kruskal() {
    init();
    sort(edges.begin(), edges.end(), comp);
    for (int i = 0; i < edges.size(); i++) {
        Edge *e = edges[i];
        int A = e -> src; int B = e -> dst; int C = e -> weight;
        if (findSet(A) != findSet(B)) {
            unionSet(A, B);
            v[A].push_back({B, C}); v[B].push_back({A, C});
        }
    }
}

void dfs(int n, int w) {
    vis[n] = 1; maxWeight[n] = w;
    for (auto p: v[n]) {
        if (!vis[p.first]) {dfs(p.first, min(maxWeight[n], p.second));}
    }
}

int main() {
    scanf("%d%d%d", &c, &r, &d);
    for (int i = 0; i < r; i++) {
        int x, y, z; scanf("%d%d%d", &x, &y, &z);
        Edge *e = new Edge(); e -> src = x; e -> dst = y; e -> weight = z;
        edges.push_back(e);
    }
    kruskal();
	memset(vis, 0, sizeof(vis));
	dfs(1, 1000000);
	int ans = INT_MAX;
	for (int i = 0; i < d; i++) {
	    int city; scanf("%d", &city);
	    ans = min(ans, maxWeight[city]);
	}
	printf("%d\n", ans);
}