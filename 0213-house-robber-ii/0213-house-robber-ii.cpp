class Solution{
    public:
    int rob(vector<int>& nums) {
        if (nums.size() == 1) return nums[0];
        function<int(int, int)> robRange = [&](int start, int end) {
            int prev = 0, curr = 0;
            for (int i = start; i <= end; i++) {
                int temp = max(curr, prev + nums[i]);
                prev = curr;
                curr = temp;
            }
            return curr;
        };
        return max(robRange(0, nums.size() - 2), robRange(1, nums.size() - 1));
    }
};