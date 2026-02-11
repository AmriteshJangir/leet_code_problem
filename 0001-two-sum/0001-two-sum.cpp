class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();
        vector<pair<int, int>> numIdx;
        for (int i = 0; i < n; ++i)
            numIdx.push_back({nums[i], i});
        
        sort(numIdx.begin(), numIdx.end());
        
        int left = 0, right = n - 1;
        while (left < right) {
            int sum = numIdx[left].first + numIdx[right].first;
            if (sum == target) {
                return {numIdx[left].second, numIdx[right].second};
            } else if (sum < target) {
                ++left;
            } else {
                --right;
            }
        }
        return {};
    }
};
