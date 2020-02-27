#include <bits/stdc++.h>

using namespace std;

struct Edge {
    int src, dst, o;
}; 

int N, M;
vector<Edge*> edges;
vector<Edge*> MST;
int nodes[100001];
int ranks[100001];

void init() {
    for (int i = 0; i <= N; i++) {ranks[i] = 0; nodes[i] = i;}
}

bool comp(Edge *e, Edge *f) {
    return e -> o < f -> o;
}

int findSet(int node) {
    if (nodes[node] == node) {return node;}
    nodes[node] = findSet(nodes[node]);
    return nodes[node];
}

void unionSet(int n1, int n2) {
    int p1 = findSet(n1); int p2 = findSet(n2);
    if (ranks[p1] > ranks[p2]) {nodes[p2] = p1;}
    else if (ranks[p1] < ranks[p2]) {nodes[p1] = p2;}
    else {nodes[p2] = p1; ranks[p1]++;}
}

int main() {
    scanf("%d%d", &N, &M);
    init();
    for (int i = 1; i <= M; i++) {
        Edge *e = new Edge();
        int u, v; scanf("%d%d", &u, &v);
        e -> src = u; e -> dst = v; e -> o = i;
        edges.push_back(e);
    }
    
    sort(edges.begin(), edges.end(), comp);
    for (int i = 0; i < edges.size(); i++) {
        Edge *e = edges[i];
        int A = e -> src; int B = e -> dst;
        if (findSet(A) != findSet(B)) {
            unionSet(A, B);
            MST.push_back(e);
        }
    }
    
    if (MST.size() != N - 1) {printf("%s\n", "Disconnected Graph"); return 0;}
    
    for (int i = 0; i < MST.size(); i++) {
        Edge *f = MST[i];
        printf("%d\n", f -> o);
    }
    return 0;
}