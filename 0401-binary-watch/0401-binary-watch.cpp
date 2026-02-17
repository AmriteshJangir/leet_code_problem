class Solution {
public:
    int countBits(int n) {
        int c = 0;
        while(n) {
            c += n & 1;
            n >>= 1;
        }
        return c;
    }
    vector<string> readBinaryWatch(int turnedOn) {
        vector<string> ans;
        for(int h = 0; h < 12; h++) {
            for(int m = 0; m < 60; m++) {
                if(countBits(h) + countBits(m) == turnedOn) {
                    string time = to_string(h) + ":";
                    if(m < 10) time += "0";
                    time += to_string(m);           
                    ans.push_back(time);
                }
            }
        }
        return ans;
    }
};
