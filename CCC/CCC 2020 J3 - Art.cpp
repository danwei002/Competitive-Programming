#include <bits/stdc++.h>

using namespace std;

int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);
    int N;
    cin >> N;
    int coordsX[N];
    int coordsY[N];
    for (int i = 0; i < N; i++) {
        string input;
        cin >> input;
        int index = 0;
        while (input.at(index) != ',') {index++;}
        string strX = input.substr(0, index);
        string strY = input.substr(index + 1, input.length() - strX.length() - 1);
        
        coordsX[i] = stoi(strX);
        coordsY[i] = stoi(strY);
    }
    
    sort(coordsX, coordsX + N);
    sort(coordsY, coordsY + N);
    cout << coordsX[0] - 1 << "," << coordsY[0] - 1 << "\n" << coordsX[N - 1] + 1 << "," << coordsY[N - 1] + 1 << "\n";
    return 0;
}