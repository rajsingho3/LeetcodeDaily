// Problem Link
// https://leetcode.com/problems/maximum-score-from-removing-substrings/description/?envType=daily-question&envId=2025-07-23

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

// Using the standard namespace to avoid prefixing with 'std::'
using namespace std;

// Function to calculate maximum gain
long long maximumGain(string s, int x, int y) {
    long long total_points = 0;
    string high_prio_pair, low_prio_pair;
    int high_prio_score, low_prio_score;

    // Determine the high and low priority pairs
    if (x > y) {
        high_prio_pair = "ab";
        high_prio_score = x;
        low_prio_pair = "ba";
        low_prio_score = y;
    } else {
        high_prio_pair = "ba";
        high_prio_score = y;
        low_prio_pair = "ab";
        low_prio_score = x;
    }

    // --- First Pass: Remove the high-priority pair ---
    // We use a temporary string 'temp_s' as a stack
    string temp_s;
    for (char c : s) {
        // Check if the current char forms a high-priority pair with the top of our stack
        if (!temp_s.empty() && temp_s.back() == high_prio_pair[0] && c == high_prio_pair[1]) {
            total_points += high_prio_score;
            temp_s.pop_back(); // Remove the first character of the pair
        } else {
            temp_s.push_back(c);
        }
    }

    // --- Second Pass: Remove the low-priority pair from the remaining string ---
    // We use 'final_s' as the stack for the second pass
    string final_s;
    for (char c : temp_s) {
        // Check for the low-priority pair
        if (!final_s.empty() && final_s.back() == low_prio_pair[0] && c == low_prio_pair[1]) {
            total_points += low_prio_score;
            final_s.pop_back();
        } else {
            final_s.push_back(c);
        }
    }

    return total_points;
}

// --- Main function for demonstration ---
int main() {
    cout << "--- Example 1 ---" << endl;
    string s1 = "cdbcbbaaabab";
    int x1 = 4;
    int y1 = 5;
    cout << "Input: s = \"" << s1 << "\", x = " << x1 << ", y = " << y1 << endl;
    cout << "Max Points ✅: " << maximumGain(s1, x1, y1) << endl; // Expected: 19

    cout << "\n--- Example 2 ---" << endl;
    string s2 = "aabbaaxybbaabb";
    int x2 = 5;
    int y2 = 4;
    cout << "Input: s = \"" << s2 << "\", x = " << x2 << ", y = " << y2 << endl;
    cout << "Max Points ✅: " << maximumGain(s2, x2, y2) << endl; // Expected: 20

    return 0;
}