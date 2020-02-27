#include <bits/stdc++.h>

using namespace std;

int main() {
    int set1[5], set2[5];
    for (int i = 0; i < 5; i++) {scanf("%d", &set1[i]);}
    for (int i = 0; i < 5; i++) {scanf("%d", &set2[i]);}
    int n = sizeof(set1) / sizeof(set1[0]);
    sort(set1, set1 + n); sort(set2, set2 + n);
    printf("%d\n", max(set1[1] + set1[2] + set1[3] + set1[4], set2[1] + set2[2] + set2[3] + set2[4]));
    return 0;
}