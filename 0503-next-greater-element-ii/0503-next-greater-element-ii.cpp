class Solution {
    public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();
        vector<int> result(n, -1);
        stack<int> s; // Stack to store indices of elements
        for (int i = 0; i < 2 * n; ++i) {
            int index = i % n; // Wrap around using modulo
            while (!s.empty() && nums[s.top()] < nums[index]) {
                result[s.top()] = nums[index];
                s.pop();
            }
            if (i < n) { // Only push indices from the first pass
                s.push(index);
            }
        }
        return result;
    }
};