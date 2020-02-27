#include <bits/stdc++.h>

using namespace std;

int main() {
    double I;
    scanf("%lf", &I);
    
    double sum;
    for (int i = 0; i < I; i++) {
        double M;
        scanf("%lf", &M);
        sum += M;
    }
    double average;
    
    if (I == 0) {
        average = 0;
    } else {
        average = sum / I;
    }
    
    double S;
    scanf("%lf", &S);
    
    for (double j = 0.000; j < S; j++) {
        double Q;
        scanf("%lf", &Q);
        sum = average * (I + j);
        sum += Q;
        average = sum / (I + j + 1);
        cout << fixed << setprecision(3) << average << endl;
    }
}