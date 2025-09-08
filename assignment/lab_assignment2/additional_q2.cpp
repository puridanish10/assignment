#include <bits/stdc++.h>
using namespace std;

bool canSplit(const string &s) {
    int n = s.size();
    if (n < 3) return false;  // cannot split into 3 non-empty parts
    
    unordered_map<char, int> freq;
    for (char c : s) freq[c]++;
    
    // Case 1: any character appears at least 3 times → always possible
    for (auto &p : freq) {
        if (p.second >= 3) return true;
    }
    
    // Case 2: if no character repeats → not possible
    bool hasRepeat = false;
    for (auto &p : freq) {
        if (p.second >= 2) {
            hasRepeat = true;
            break;
        }
    }
    
    return hasRepeat;
}

int main() {
    string s;
    cin >> s;
    
    if (canSplit(s)) cout << "YES\n";
    else cout << "NO\n";
    
    return 0;
}
