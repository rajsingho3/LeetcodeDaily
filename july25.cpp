// https://leetcode.com/problems/maximum-unique-subarray-sum-after-deletion/description/?envType=daily-question&envId=2025-07-25
 /*
 class Solution {
public:
    int maxSum(vector<int>& nums) {
        const int mx = ranges::max(nums);
    if (mx <= 0)
      return mx;
    unordered_set<int> numsSet(nums.begin(), nums.end());
    return accumulate(numsSet.begin(), numsSet.end(), 0,
                      [](int acc, int num) { return acc + max(0, num); });
  }
        
    
};
 */