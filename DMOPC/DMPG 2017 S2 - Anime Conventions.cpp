#include <bits/stdc++.h>

using namespace std;

int N, Q;
int nodes[100001]; int ranks[100001];

void init() {
    for (int i = 0; i <= N; i++) {nodes[i] = i; ranks[i] = 0;}
}

int findSet(int n) {
    if (nodes[n] == n) {return n;}
    nodes[n] = findSet(nodes[n]);
    return nodes[n];
}

void unionSet(int n1, int n2) {
    int p1 = findSet(n1); int p2 = findSet(n2);
    if (ranks[p1] > ranks[p2]) {nodes[p2] = p1;}
    else if (ranks[p1] < ranks[p2]) {nodes[p1] = p2;}
    else {nodes[p2] = p1; ranks[p1]++;}
}

int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);
    cin >> N >> Q; init();
    for (int i = 0; i < Q; i++) {
        char c; int x, y; cin >> c >> x >> y;
        if (c == 'A') {unionSet(x, y);} 
        else {
            if (findSet(x) != findSet(y)) {cout << "N\n";}
            else {cout << "Y\n";}
        }
    }
    return 0;
}