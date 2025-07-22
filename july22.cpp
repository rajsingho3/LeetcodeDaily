// Problem link
// https://leetcode.com/problems/maximum-erasure-value/?envType=daily-question&envId=2025-07-22
#include <bits/stdc++.h>
using namespace std;

int maximumUniqueSubarray(vector<int>& nums) {
    unordered_set<int> seen;
    int left = 0, right = 0;
    int curr_sum = 0, max_sum = 0;

    while (right < nums.size()) {
        while (seen.count(nums[right])) {
            curr_sum -= nums[left];
            seen.erase(nums[left]);
            left++;
        }
        curr_sum += nums[right];
        seen.insert(nums[right]);
        max_sum = max(max_sum, curr_sum);
        right++;
    }

    return max_sum;
}

int main() {
    vector<int> nums1 = {4, 2, 4, 5, 6};
    vector<int> nums2 = {5, 2, 1, 2, 5, 2, 1, 2, 5};

    cout << maximumUniqueSubarray(nums1) << endl; // Output: 17
    cout << maximumUniqueSubarray(nums2) << endl; // Output: 8

    return 0;
}
