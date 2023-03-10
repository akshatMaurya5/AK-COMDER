#include <bits/stdc++.h>
using namespace std;

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    string s;
    cin >> s;

    unordered_map<char, int> freq;
    for (char c : s) {
        freq[c]++;
    }

    string palindrome;
    char single_char = '\0';
    for (auto p : freq) {
        char c = p.first;
        int cnt = p.second;
        if (cnt % 2 == 1) {
            // We can place at most one character in the middle of the palindrome
            if (s.size() % 2 == 0 || single_char != '\0') {
                cout << "NO SOLUTION\n";
                return 0;
            }
            single_char = c;
            cnt--;
        }
        // Add half of the characters to the left and half to the right
        for (int i = 0; i < cnt / 2; i++) {
            palindrome += c;
        }
    }
    // Construct the palindrome
    cout << palindrome << single_char;
    reverse(palindrome.begin(), palindrome.end());
    cout << palindrome << "\n";
    return 0;
}
