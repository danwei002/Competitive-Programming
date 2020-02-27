#include <bits/stdc++.h>

using namespace std;

int find(int size, int H, int houses[]) {
    size *= 2;
    int ans = H;
    int i = 0;
    while (i < H and houses[i] <= houses[0] + size) {
        int cur = 1;
        int end = houses[i];
        int j = i + 1;
        while (j < H and houses[j] < houses[i] - size + 1000000) {
            if (houses[j] > end) {
                end = houses[j] + size;
                cur++;
            }
            j++;
        }
        ans = min(cur, ans);
        i++;
    }
    return ans;
}

int main() {
    int H;
    scanf("%d", &H);
    int houses[H];
    for (int i = 0; i < H; i++) {
        scanf("%d", &houses[i]);
    }
    
    int n = sizeof(houses) / sizeof(houses[0]);
    sort(houses, houses + n);
    
    int k;
    scanf("%d", &k);
    
    int min = -1; int max = 1000000;
    while (min < max - 1) {
        int mid = (min + max) / 2;
        if (find(mid, H, houses) > k) {
            min = mid;
        } else {
            max = mid;
        }
    }
    cout << max;
}