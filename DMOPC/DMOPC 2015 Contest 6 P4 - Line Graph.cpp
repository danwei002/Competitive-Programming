#include <bits/stdc++.h>

using namespace std;

struct Edge {int src, dst, weight;};
bool comp(Edge *a, Edge *b) {return a -> weight < b -> weight;}

int N, K;
int nodes[100001], ranks[100001];
vector<Edge*> edges;

void init() {for (int i = 0; i <= N; i++) {nodes[i] = i; ranks[i] = 1;}}
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

int main() {
    scanf("%d%d", &N, &K); init();
    
    for (int i = 1; i <= N - 1; i++) {
        Edge *e = new Edge();
        int s; scanf("%d", &s);
        e -> src = nodes[i]; e -> dst = nodes[i + 1]; e -> weight = s; edges.push_back(e);
    }
    
    int index = N;
    for (int i = 1; i + K <= N; i++) {
        Edge *e = new Edge();
        unionSet(i, i + K);
        e -> src = i; e -> dst = i + K; e -> weight = 0;
        edges.push_back(e);
    }
    
    int w = 0;
    sort(edges.begin(), edges.end(), comp);
    for (int i = 0; i < edges.size(); i++) {
        Edge *e = edges[i];
        int a = e -> src; int b = e -> dst;
        if (findSet(a) != findSet(b)) {unionSet(a, b); w += e -> weight;}
    }
    
    printf("%d\n", w);
    return 0;
}