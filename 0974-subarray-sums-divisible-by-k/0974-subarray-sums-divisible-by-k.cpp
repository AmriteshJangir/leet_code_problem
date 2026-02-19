class Solution {
    public:
    int subarraysDivByK(vector<int>& nums, int k) {
        int n = nums.size();
        int ans = 0;
        unordered_map<int, int> count;
        count[0] = 1; // prefix sum of 0 has one occurrence
        int prefixSum = 0;

        for (int i = 0; i < n; i++) {
            prefixSum += nums[i];
            int mod = ((prefixSum % k) + k) % k; // handle negative mod

            if (count.find(mod) != count.end()) {
                ans += count[mod]; // add the number of times this mod has been seen
            }
            count[mod]++; // increment the count for this mod
        }

        return ans;
    }
};