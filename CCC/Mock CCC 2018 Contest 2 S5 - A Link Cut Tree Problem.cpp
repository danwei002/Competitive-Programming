#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> pii;

struct Edge {int src, dst, weight;};
bool comp (Edge *a, Edge *b) {return a -> weight > b -> weight;}

int nodes[1001], ranks[1001], vis[1001];
vector<Edge*> edges, edges2;
vector<pii> v[5001];
int N, M, Q;

void init() {for (int i = 1; i <= N; i++) {nodes[i] = i; ranks[i] = 1;}}

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
    edges2 = edges;
    sort(edges2.begin(), edges2.end(), comp);
    for (int i = 0; i <= N; i++) {v[i].clear();}
    for (int i = 0; i < edges2.size(); i++) {
        Edge *e = edges2[i];
        int A = e -> src; int B = e -> dst; int C = e -> weight;
        if (findSet(A) != findSet(B)) {
            unionSet(A, B);
            v[A].push_back({B, C}); v[B].push_back({A, C});
        }
    }
}

void traverse(int n, int w) {
    vis[n] = true;
    for (auto p: v[n]) {
        if (!vis[p.first] and p.second >= w) {
            traverse(p.first, w);
        }
    }
}

int main() {
    scanf("%d%d", &N, &M);
    for (int i = 0; i < M; i++) {
        int a, b, c;
        scanf("%d%d%d", &a, &b, &c);
        Edge *e = new Edge();
        e -> src = a; e -> dst = b; e -> weight = c;
        edges.push_back(e);
    }
    kruskal();
    scanf("%d", &Q);
    for (int i = 0; i < Q; i++) {
        int op; scanf("%d", &op);
        if (op == 1) {
            int m, x; scanf("%d%d", &m, &x); m--;
            edges[m] -> weight = x;
            kruskal();
        } else if (op == 2) {
            int a, b, w; scanf("%d%d%d", &a, &b, &w);
            memset(vis, 0, sizeof(vis));
            traverse(a, w);
            if (vis[b]) {printf("%d\n", 1);}
            else {printf("%d\n", 0);}
        }
    }
    return 0;
}