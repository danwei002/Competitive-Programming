#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int N;
    cin >> N;
    int occ[1001];
    memset(occ, 0, sizeof(occ));
    for (int i = 0; i < N; i++) {
        int x; 
        cin >> x;
        occ[x]++;
    }
    
    vector<int> large;
    int maxi = 0;
    for (int i = 1; i <= 1000; i++) {
        if (occ[i] > maxi) {
            large.clear();
            maxi = occ[i];
            large.push_back(i);
        } else if (occ[i] == maxi) {
            large.push_back(i);
        }
    }
    
    vector<int> sLarge;
    int max2 = 0;
    if (large.size() == 1) {
        for (int i = 1; i <= 1000; i++) {
            if (occ[i] > max2 and occ[i] != maxi) {
                sLarge.clear();
                max2 = occ[i];
                sLarge.push_back(i);
            } else if (occ[i] == max2 and occ[i] != maxi) {
                sLarge.push_back(i);
            }
        }
    }
    
    sort(large.begin(), large.end());
    sort(sLarge.begin(), sLarge.end());
    
    if (large.size() > 1) {
        cout << abs(large[0] - large[large.size() - 1]) << "\n";
    } else {
        int diff = 0;
        for (auto p: sLarge) {
            diff = max(diff, abs(large[0] - p));
        }
        cout << diff << "\n";
    }
    
    return 0;
}