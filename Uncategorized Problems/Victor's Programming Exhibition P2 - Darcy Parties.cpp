#include <bits/stdc++.h>

using namespace std;

int main() {
    int N; scanf("%d", &N);
    int slices[N]; int total = 0;
    for (int i = 0; i < N; i++) {scanf("%d", &slices[i]); total += slices[i];}
    int mistakes = 0;
    for (auto p: slices) {if (p > total / N or p < total / N) {mistakes++;}}
    printf("%d\n", mistakes);
    return 0;
}