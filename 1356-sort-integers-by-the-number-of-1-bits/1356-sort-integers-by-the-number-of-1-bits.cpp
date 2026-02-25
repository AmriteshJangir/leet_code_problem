class Solution {
public:
    vector<int> sortByBits(vector<int>& arr) {
        sort(arr.begin(), arr.end(), [](int a, int b) {
            int c1 = __builtin_popcount(a);
            int c2 = __builtin_popcount(b);
            return c1 == c2 ? a < b : c1 < c2;
        });
        return arr;
    }
};