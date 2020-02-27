#include <bits/stdc++.h>

using namespace std;

int main() {
    int N;
    cin >> N;
    double sum = 0;
    double marks[N];
    for (int i = 0; i < N; i++) {
        double s;
        cin >> s;
        marks[i] = s;
        sum += s;
    }
    
    double ave = (double) sum / N;
    double n = 0;
    for (auto p: marks) {
        if (p > ave) {
            n += 1.0;
        }
    }
    double percent = (double) n / N * 100;
    if (percent > 50.0) {
        cout << "Winnie should take the risk" << endl;
    } else {
        cout << "That's too risky" << endl;
    }
}