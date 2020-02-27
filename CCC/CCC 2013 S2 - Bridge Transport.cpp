#include <bits/stdc++.h>

using namespace std;

int main() {
    int W, N; scanf("%d%d", &W, &N);
    int cars[N + 4]; cars[0] = 0; cars[1] = 0; cars[2] = 0;
    for (int i = 3; i < N + 4; i++) {scanf("%d", &cars[i]);}
    int totalCars = 0;
    for (int i = 3; i < N + 4; i++) {
        int weight = cars[i] + cars[i - 1] + cars[i - 2] + cars[i - 3];
        if (weight <= W) {totalCars++;} 
        else {break;}
    }
    if (totalCars == N + 1) {totalCars--;}
    printf("%d\n", totalCars);
}