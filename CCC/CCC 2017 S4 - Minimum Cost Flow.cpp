#include <bits/stdc++.h>

using namespace std;

struct Edge {
    int src, dst, cost, order;
    bool active;
};

int N, M, D;
int nodes[100001];
int ranks[100001];
vector<Edge*> edges;
vector<Edge> MST;

void init() {
    for (int i = 0; i <= N; i++) {nodes[i] = i; ranks[i] = 0;}
}

bool isEqual(Edge *a, Edge *b) {
    if (a -> src  == b -> src && a -> dst == b -> dst && a -> cost == b -> cost) {return true;} 
    else {return false;}
}

bool compare(Edge *a, Edge *b) {
    if (a -> cost == b -> cost) {return a -> order < b -> order;}
    return a -> cost < b -> cost;    
}

int findSet(int node) {
    if (nodes[node] == node) {return node;}
    nodes[node] = findSet(nodes[node]);
    return nodes[node];
}

void unionSet(int node1, int node2) {
    int parent1 = findSet(node1);
    int parent2 = findSet(node2);
    if (ranks[parent1] > ranks[parent2]) {nodes[parent2] = parent1;}
    else if (ranks[parent1] < ranks[parent2]) {nodes[parent1] = parent2;}
    else {
        nodes[parent2] = parent1; ranks[parent1]++;
    }
}

int main() {
    scanf("%d%d%d", &N, &M, &D);
    int days = 0; init();
    int heaviest = INT_MIN;
    for (int i = 0; i < M; i++) {
        int A, B, C; scanf("%d%d%d", &A, &B, &C);
        Edge *e = new Edge();
        e -> src = A; e -> dst = B; e -> cost = C; e -> order = i;
        if (i < N - 1) {e -> active = true;}
        else {e -> active = false;}
        edges.push_back(e);
    }
    
    sort(edges.begin(), edges.end(), compare);
    
    for (int i = 0; i < edges.size(); i++) {
        Edge *e = edges[i];
        int A = e -> src; int B = e -> dst;
        if (findSet(A) != findSet(B)) {
            unionSet(A, B);
            MST.push_back(*e);
            int C = e -> cost;
            heaviest = max(heaviest, C);
            if (!(e -> active)) {days++;}
        }
    }
    
    Edge *f = edges[edges.size() - 1];

    init();
    for (int i = 0; i < edges.size(); i++) {
        Edge *e = edges[i];
        int A = e -> src; int B = e -> dst;
        if (findSet(A) != findSet(B)) {
            if (e -> cost < heaviest or (e -> cost == heaviest and e -> active)) {unionSet(A, B);}
            else if (e -> active and e -> cost <= D) {printf("%d\n", days - 1); return 0;}
        }
    }

    printf("%d\n", days);
}