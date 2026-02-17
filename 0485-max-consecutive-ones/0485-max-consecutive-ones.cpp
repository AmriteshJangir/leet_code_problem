class Solution{
    public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
    int best = 0, cnt = 0;
    for (int x : nums) {
        if (x == 1) {
            cnt++;
            best = max(best, cnt);
        } else {
            cnt = 0;
        }
    }
    return best;
    }
};