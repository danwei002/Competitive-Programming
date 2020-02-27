#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

struct Edge {
    int src, dst; 
    ll cost;
    int f;
};

int ranks[100001], nodes[100001], ranks2[100001], nodes2[100001];
vector<Edge*> edges;
int N, M, P, Q;

void init() {
    for (int i = 0; i <= 100000; i++) {ranks[i] = 0; nodes[i] = i;}
    for (int i = 0; i <= 100000; i++) {ranks2[i] = 0; nodes2[i] = i;}
}

bool comp(Edge *a, Edge *b) {return a -> cost < b -> cost;}

int findSet(int n) {
    while (nodes[n] ^ n) {nodes[n] = nodes[nodes[n]]; n = nodes[n];}
    return n;
}

int findSet2(int n) {
    while (nodes2[n] ^ n) {nodes2[n] = nodes2[nodes2[n]]; n = nodes2[n];}
    return n;
}

void unionSet(int n1, int n2) {
    int p1 = findSet(n1); int p2 = findSet(n2);
    if (ranks[p1] > ranks[p2]) {nodes[p2] = p1; ranks[p1] += ranks[p2];}
    else {nodes[p1] = p2; ranks[p2] += ranks[p1];}
}

void unionSet2(int n1, int n2) {
    int p1 = findSet2(n1); int p2 = findSet2(n2);
    if (ranks2[p1] > ranks2[p2]) {nodes2[p2] = p1; ranks2[p1] += ranks2[p2];}
    else {nodes2[p1] = p2; ranks2[p2] += ranks2[p1];}
}

int main() {
    scanf("%d%d%d%d", &N, &M, &P, &Q); init(); ll total  = 0; ll s = 0;
    int rows = N; int cols = M;
    for (int i = 0; i < P; i++) {
        int a, b, c; scanf("%d%d%d", &a, &b, &c);
        total += (ll) c * N;
        Edge *e = new Edge(); e -> src = a; e -> dst = b; e -> cost = c; e -> f = 1;
        edges.push_back(e);
    }
    
    for (int i = 0; i < Q; i++) {
        int x, y, z; scanf("%d%d%d", &x, &y, &z);
        total += (ll) z * M;
        Edge *e = new Edge(); e -> src = x; e -> dst = y; e -> cost = z; e -> f = 0;
        edges.push_back(e);
    }
    
    sort(edges.begin(), edges.end(), comp);
    for (int i = 0; i < edges.size(); i++) {
        Edge *e = edges[i];
        int A = e -> src; int B = e -> dst;
        if (e -> f == 1 and findSet(A) ^ findSet(B)) {
            s += (ll) e -> cost * rows;
            cols--;
            unionSet(A, B);
        } else if (e -> f == 0 and findSet2(A) ^ findSet2(B)) {
            s += (ll) e -> cost * cols;
            rows--;
            unionSet2(A, B);
        }
    }
    
    printf("%lld\n", total - s);
    return 0;
}