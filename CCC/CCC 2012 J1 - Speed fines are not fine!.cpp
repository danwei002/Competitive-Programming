#include <iostream>

using namespace std;

int main() {
    int sLim;
    int speed;
    
    cin >> sLim;
    cin >> speed;
    
    int difference = speed - sLim;
    
    if (difference <= 0) {
        cout << "Congratulations, you are within the speed limit!"; 
    } else if (difference >= 1 && difference <= 20) {
        cout << "You are speeding and your fine is $100.";
    } else if (difference >= 21 && difference <= 30) {
        cout << "You are speeding and your fine is $270.";
    } else {
        cout << "You are speeding and your fine is $500.";
    }
}