#include <bits/stdc++.h>

using namespace std;

int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    vector<double> streams;
    for (int i = 0; i < n; i++) {
        double stream;
        cin >> stream;
        streams.push_back(stream);
    }
    
    while (true) {
        int action;
        cin >> action;
        if (action == 77) {
            break;
        }
        
        if (action == 99) {
            int splitNum;
            double percentage;
            cin >> splitNum >> percentage;
            splitNum -= 1;
            double old = streams[splitNum];
            streams[splitNum] *= (percentage / 100);
            double newStream = old - streams[splitNum];
            streams.insert(streams.begin() + splitNum + 1, newStream);
        } else if (action == 88) {
            int joinNum;
            cin >> joinNum;
            streams[joinNum - 1] = streams[joinNum - 1] + streams[joinNum];
            streams.erase(streams.begin() + joinNum);
        }
    }
    
    for (int i = 0; i < streams.size(); i++) {
        int f = (int) streams[i] + 0.5;
        cout << f << " ";
    }
}