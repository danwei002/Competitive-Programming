#include <bits/stdc++.h>
#include <string>

using namespace std;

int main() {
    int spreadsheet[10][9];
    string cmds[10][9];
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 9; j++) {
            cin >> cmds[i][j];
            spreadsheet[i][j] = -1;
        }
    }
    
    bool b = true;
    int count = 0;
    while (b) {
        b = false;
        for (int i = 0; i < 10; i++) {
            for (int j = 0; j < 9; j++) {
                int v = 0;
                if (cmds[i][j].at(0) >= '0' and cmds[i][j].at(0) <= '9') {
                    v += stoi(cmds[i][j]);
                    if (spreadsheet[i][j] != v) {
                        b = true;
                        spreadsheet[i][j] = v;
                    }
                } else {
                    vector<string> commands;
                    for (int k = 0; k < cmds[i][j].length(); k += 3) {
                        commands.push_back(cmds[i][j].substr(k, 2));   
                    }
                    
                    queue<pair<int, int>> numerical;
                    for (auto p: commands) {
                        int first = (int) p.at(0) - 65;
                        int second = (int) p.at(1) - 49;
                        numerical.push({first, second});
                    }
                    
                    int v = 0; int x = 0;
                    while (!numerical.empty()) {
                        int f = numerical.front().first; int s = numerical.front().second; numerical.pop();
                        v += spreadsheet[f][s];
                        if (spreadsheet[f][s] == -1) {v = -1; break;}
                    }
                    
                    if (spreadsheet[i][j] != v) {
                        b = true;
                        spreadsheet[i][j] = v;
                    }
                }
                
            }
        }
    }
    
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 9; j++) {
            if (spreadsheet[i][j] == -1) {
                cout << "* ";
            } else {
                cout << spreadsheet[i][j] << " ";
            }
        }
        cout << "\n";
    }
    return 0;
}