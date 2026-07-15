/*
Author: sashi-does
date: 19 june, 2026

"A year from now, you'll wish you had started today."
*/

#include <bits/stdc++.h>
using namespace std;


int main() {

    // iskander got bored -> decided to draw in yura's notebook
    // took a row and drew horizontal lines (some are long, short, empty)
    // page is denoted as s
    // '*' - empty part of paper
    // '#' - 1cm
    int t;
    cin >> t;
    while(t--) {
        int len;
        cin >> len;
        string line;
        cin >> line;
        
        int curr = 0;
        int maxTime = 0;
        for(int i = 0; i < len; i++) {
            if(line[i] == '#') curr++;
            else {
                maxTime = max(maxTime, (curr % 2 == 0 ? curr / 2 : curr / 2 + 1));
                curr = 0;
            }
        }
        
        cout << maxTime << endl;
    }
}
