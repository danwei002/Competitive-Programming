#include <bits/stdc++.h>

using namespace std;

double dist(double x1, double x2, double y1, double y2) {
    double x = abs(x2 - x1);
    double y = abs(y2 - y1);
    return sqrt(x * x + y * y);
}

int main() {
    int sheeps;
    cin >> sheeps;
    pair<double, double> coords[sheeps];
    set<int> eaten;
    for (int i = 0; i < sheeps; i++) {
        double x, y;
        cin >> x >> y;
        coords[i] = make_pair(x, y);
    }
    
    for (double i = 0; i <= 1000; i += 0.01) {
        double min = DBL_MAX;
        int minSheep = INT_MAX;
        for (int j = 0; j < sheeps; j++) {
            double x1 = coords[j].first;
            double y1 = coords[j].second;
            double x2 = i;
            double y2 = 0;
            if (dist(x1, x2, y1, y2) < min) {
                min = dist(x1, x2, y1, y2);
                minSheep = j;
            }
        }
        eaten.insert(minSheep);
    }
    
    for (auto p: eaten) {
        cout << fixed << setprecision(2) << "The sheep at (" << coords[p].first << ", " << coords[p].second << ") might be eaten." << endl;
    }
}