// Problem Link

//https://leetcode.com/problems/longest-subarray-with-maximum-bitwise-and/submissions/1716637752/?envType=daily-question&envId=2025-07-30
/*

class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int maxVal = 0;
        for (int num : nums) {
            maxVal = max(maxVal, num); // Step 1: Find max value
        }

        int maxLen = 0;
        int currLen = 0;

        for (int num : nums) {
            if (num == maxVal) {
                currLen++;                 // Continue the streak
                maxLen = max(maxLen, currLen); // Update max if longer
            } else {
                currLen = 0;              // Break the streak
            }
        }

        return maxLen;
    }
};

*/
