#include <bits/stdc++.h>
using namespace std;

// Problem Link
// https://leetcode.com/problems/delete-characters-to-make-fancy-string/description/?envType=daily-question&envId=2025-07-21

int main() {
    string s = "leeetcode";
    string ans = "";

    for (int i = 0; i < s.length(); ++i) {
        // If the last two characters in 'ans' are the same as current, skip it
        if (ans.size() >= 2 && ans[ans.size() - 1] == s[i] && ans[ans.size() - 2] == s[i]) {
            continue;
        }
        ans += s[i];
    }

    cout << ans << endl; // Output: leetcode
    return 0;
}

