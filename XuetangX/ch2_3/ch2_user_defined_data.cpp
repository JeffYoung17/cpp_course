#include <iostream>
using namespace std;

enum GameResult {
    WIN,
    LOSE,
    TIE,
    CANCEL
};

int main() {
    GameResult result;
    GameResult omit = CANCEL;
    for (int count = WIN; count <= CANCEL; ++count) {
        result = GameResult(count);
        if (result == omit) {
            cout << "Game was cancelled" << endl;
        } else {
            cout << "Game was played";
            if (result == WIN) {
                cout << " and win";
            }
            if (result == LOSE) {
                cout << " and lose";
            }
            cout << endl;
        }
    }
    return 0;
}